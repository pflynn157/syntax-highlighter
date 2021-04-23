#include <QTextEdit>
#include <QTextCharFormat>
#include <QStringLiteral>

#include "window.hpp"
#include "highlighter.hpp"

Window::Window() {
    this->setWindowTitle("Qt5 Template");
    this->resize(700, 500);
    
    QTextEdit *edit = new QTextEdit;
    SyntaxHighlighter *highlight = new SyntaxHighlighter(edit->document());
    this->setCentralWidget(edit);
    
    // Add keywords
    QTextCharFormat format = QTextCharFormat();
    format.setForeground(Qt::darkGreen);
    format.setFontWeight(QFont::Bold);
    
    QString keywords[] = {
        QStringLiteral("\\bconst\\b"), QStringLiteral("\\bint\\b"), QStringLiteral("\\bvoid\\b")
    };
    for (QString &keyword : keywords) {
        highlight->addSingleRule(format, keyword);
    }
    
    // Add quotes
    format.setForeground(Qt::red);
    highlight->addSingleRule(format, QStringLiteral("\".*\""));
    
    // Double-line comments
    format.setFontWeight(QFont::Bold);
    format.setForeground(Qt::blue);
    
    highlight->addDoubleRule(format, QStringLiteral("/*"), QStringLiteral("*/"));
    highlight->addDoubleRule(format, QStringLiteral("/+"), QStringLiteral("+/"));
    
    //highlight->addDoubleRule(format, QStringLiteral("/\\*"), QStringLiteral("\\*/"));
    //highlight->addDoubleRule(format, QStringLiteral("/\\+"), QStringLiteral("\\+/"));
}

Window::~Window() {
}

