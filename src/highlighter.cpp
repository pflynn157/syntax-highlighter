#include "highlighter.hpp"

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent) {
    // Test: Keywords
    SyntaxRule rule;
    rule.multiLine = false;
    
    rule.format = QTextCharFormat();
    rule.format.setForeground(Qt::darkGreen);
    rule.format.setFontWeight(QFont::Bold);
    
    QString keywords[] = {
        QStringLiteral("\\bconst\\b"), QStringLiteral("\\bint\\b"), QStringLiteral("\\bvoid\\b")
    };
    for (QString &keyword : keywords) {
        rule.pattern = QRegularExpression(keyword);
        syntaxRules.append(rule);
    }
    
    // Quotations
    rule.format = QTextCharFormat();
    rule.format.setForeground(Qt::red);
    rule.pattern = QRegularExpression(QStringLiteral("\".*\""));
    syntaxRules.append(rule);
    
    // Double-line comments
    rule.multiLine = true;
    
    rule.format = QTextCharFormat();
    rule.format.setFontWeight(QFont::Bold);
    rule.format.setForeground(Qt::blue);
    
    // /* */
    rule.pattern = QRegularExpression(QStringLiteral("/\\*"));
    rule.endPattern = QRegularExpression(QStringLiteral("\\*/"));
    syntaxRules.append(rule);
    
    // /+ +/
    rule.pattern = QRegularExpression(QStringLiteral("/\\+"));
    rule.endPattern = QRegularExpression(QStringLiteral("\\+/"));
    syntaxRules.append(rule);
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
    
    // Handle double-line rules
    setCurrentBlockState(0);
    int startIndex = 0;
    
    for (SyntaxRule rule : syntaxRules) {
        if (!rule.multiLine) continue;
        
        if (previousBlockState() != 1)
            startIndex = text.indexOf(rule.pattern);
            
        while (startIndex >= 0) {
            QRegularExpressionMatch match = rule.endPattern.match(text, startIndex);
            int endIndex = match.capturedStart();
            int commentLength = 0;
            
            if (endIndex == -1) {
                setCurrentBlockState(1);
                commentLength = text.length() - startIndex;
            } else {
                commentLength = endIndex - startIndex + match.capturedLength();
            }
            
            setFormat(startIndex, commentLength, rule.format);
            startIndex = text.indexOf(rule.pattern, startIndex + commentLength);
        }
    }
}

