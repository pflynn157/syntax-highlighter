#include <QTextEdit>
#include <QStringLiteral>
#include <iostream>

#include "window.hpp"
#include "highlighter.hpp"
#include "repository.hpp"

Window::Window() {
    this->setWindowTitle("Qt5 Template");
    this->resize(700, 500);
    
    Repository::themeList();
    Repository::syntaxList();
    
    QString syntax_def = Repository::defForName("C");
    std::cout << "SYNTAX DEF: " << syntax_def.toStdString() << std::endl;
    
    QString theme_def = Repository::themeForName("Classic");
    std::cout << "THEME DEF: " << theme_def.toStdString() << std::endl;
    
    QTextEdit *edit = new QTextEdit;
    SyntaxHighlighter *highlight = new SyntaxHighlighter(edit->document());
    highlight->setLanguage("c");
    this->setCentralWidget(edit);
}

Window::~Window() {
}

