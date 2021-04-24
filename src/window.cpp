#include <QTextEdit>
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
    /*QTextCharFormat format = QTextCharFormat();
    format.setForeground(Qt::darkGreen);
    format.setFontWeight(QFont::Bold);
    
    QString keywords[] = {
        QStringLiteral("\\bconst\\b"), QStringLiteral("\\bint\\b"), QStringLiteral("\\bvoid\\b")
    };
    for (QString &keyword : keywords) {
        highlight->addSingleRule("keywords", keyword);
    }
    
    // Add quotes
    highlight->addSingleRule("literal", QStringLiteral("\".*\""));
    
    // Double-line comments
    highlight->addDoubleRule("comment", QStringLiteral("/*"), QStringLiteral("/"));
    highlight->addDoubleRule("comment", QStringLiteral("/+"), QStringLiteral("+/"));*/
}

Window::~Window() {
}

