#include <QTextEdit>
#include <QStringLiteral>
#include <iostream>

#include <highlighter.hpp>
#include <repository.hpp>

#include "window.hpp"

Window::Window() {
    this->setWindowTitle("Syntax Highlighter");
    this->resize(700, 500);
    
    toolbar = new ToolBar;
    this->addToolBar(toolbar);
    
    QTextEdit *edit = new QTextEdit;
    highlight = new SyntaxHighlighter(edit->document());
    highlight->setLanguage("cpp");
    this->setCentralWidget(edit);
}

Window::~Window() {
    delete toolbar;
}

