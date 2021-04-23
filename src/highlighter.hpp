#pragma once

#include <QSyntaxHighlighter>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QRegularExpression>

struct SyntaxRule {
    QRegularExpression pattern;
    QRegularExpression endPattern;
    QTextCharFormat format;
    bool multiLine;
};

class SyntaxHighlighter : public QSyntaxHighlighter {
    Q_OBJECT
public:
    explicit SyntaxHighlighter(QTextDocument *parent);
protected:
    void highlightBlock(const QString &text) override;
private:
    QVector<SyntaxRule> syntaxRules;
};

