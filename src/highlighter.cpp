#include "highlighter.hpp"

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent) {
}

void SyntaxHighlighter::addSingleRule(QTextCharFormat format, QString expression) {
    SyntaxRule rule;
    rule.multiLine = false;
    rule.format = format;
    rule.pattern = QRegularExpression(expression);
    syntaxRules.append(rule);
}

void SyntaxHighlighter::addDoubleRule(QTextCharFormat format, QString startExpr, QString endExpr) {
    SyntaxRule rule;
    rule.multiLine = true;
    rule.format = format;
    rule.startExpr = startExpr;
    rule.endExpr = endExpr;
    rule.statePos = statePos;
    syntaxRules.append(rule);
    
    ++statePos;
}

void SyntaxHighlighter::highlightBlock(const QString &text) {
    // Handle single rules
    for (SyntaxRule rule : syntaxRules) {
        if (rule.multiLine) continue;
        QRegularExpressionMatchIterator iterator = rule.pattern.globalMatch(text);
        while (iterator.hasNext()) {
            QRegularExpressionMatch match = iterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
    
    // Handle double-line comments
    int state = previousBlockState();
    int start = 0;
    
    for (SyntaxRule rule : syntaxRules) {
        if (!rule.multiLine) continue;
        
        for (int i = 0; i<text.length(); i++) {
            if (state == rule.statePos) {
                if (text.mid(i, rule.endExpr.length()) == rule.endExpr) {
                    state = -1;
                    setFormat(start, i - start + rule.endExpr.length(), rule.format);
                }
            } else {
                if (text.mid(i, rule.startExpr.length()) == rule.startExpr) {
                    start = i;
                    state = rule.statePos;
                }
            }
        }
        
        if (state > 0)
            setFormat(start, text.length() - start, rule.format);
     
        setCurrentBlockState(state);
    }
}

