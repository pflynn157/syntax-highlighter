#include <QFile>
#include <QtXml>
#include <QMap>
#include <iostream>

#include "highlighter.hpp"

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent) {
    QString text = "";
    QFile file(":/data/theme/default.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cout << "Unable to open theme." << std::endl;
        return;
    }
    
    // Parse
    QDomDocument doc("default");
    if (!doc.setContent(&file)) {
        std::cout << "Unable to read theme." << std::endl;
        file.close();
        return;
    }
    file.close();
    
    QDomElement element = doc.documentElement();
    QDomNode node = element.firstChild();
    
    while (!node.isNull()) {
        element = node.toElement();
        if (element.isNull()) {
            node = node.nextSibling();
            continue;
        }
        
        if (element.tagName() == "name") {
            node = node.nextSibling();
            continue;
        } else if (element.tagName() != "category") {
            std::cout << "Unknown tag name: " << element.tagName().toStdString() << std::endl;
            node = node.nextSibling();
            continue;
        }
        
        QString name = element.attribute("id", "");
        if (name.length() == 0) {
            std::cout << "Error: Expected ID tag" << std::endl;
            node = node.nextSibling();
            continue;
        }
        
        QTextCharFormat format;
        QDomNode syntaxNode = element.firstChild();
        
        while (!syntaxNode.isNull()) {
            QDomElement syntaxElement = syntaxNode.toElement();
            if (syntaxElement.isNull()) {
                syntaxNode = syntaxNode.nextSibling();
                continue;
            }
            
            if (syntaxElement.tagName() == "fg") {
                format.setForeground(QColor(syntaxElement.text()));
            } else if (syntaxElement.tagName() == "bg") {
                //TODO
            } else if (syntaxElement.tagName() == "b") {
                if (syntaxElement.text() == "true") {
                    format.setFontWeight(QFont::Bold);
                }
            } else if (syntaxElement.tagName() == "i") {
                //TODO
            }
            
            syntaxNode = syntaxNode.nextSibling();
        }
        
        formatMap[name] = format;
        node = node.nextSibling();
    }
}

void SyntaxHighlighter::addSingleRule(QString category, QString expression) {
    SyntaxRule rule;
    rule.multiLine = false;
    rule.format = formatMap[category];
    rule.pattern = QRegularExpression(expression);
    syntaxRules.append(rule);
}

void SyntaxHighlighter::addSingleRule(QTextCharFormat format, QString expression) {
    SyntaxRule rule;
    rule.multiLine = false;
    rule.format = format;
    rule.pattern = QRegularExpression(expression);
    syntaxRules.append(rule);
}

void SyntaxHighlighter::addDoubleRule(QString category, QString startExpr, QString endExpr) {
    SyntaxRule rule;
    rule.multiLine = true;
    rule.format = formatMap[category];
    rule.startExpr = startExpr;
    rule.endExpr = endExpr;
    rule.statePos = statePos;
    syntaxRules.append(rule);
    
    ++statePos;
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

