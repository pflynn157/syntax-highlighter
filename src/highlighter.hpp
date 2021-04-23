#pragma once

#include <QSyntaxHighlighter>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QRegularExpression>
#include <QStringLiteral>

struct SyntaxRule {
    QRegularExpression pattern;
    QString startExpr;
    QString endExpr;
    QTextCharFormat format;
    bool multiLine;
    int statePos;
};

class SyntaxHighlighter : public QSyntaxHighlighter {
    Q_OBJECT
public:
    explicit SyntaxHighlighter(QTextDocument *parent);
    void addSingleRule(QTextCharFormat format, QString expression);
    void addDoubleRule(QTextCharFormat format, QString startExpr, QString endExpr);
protected:
    void highlightBlock(const QString &text) override;
private:
    QVector<SyntaxRule> syntaxRules;
    int statePos = 3;
};

