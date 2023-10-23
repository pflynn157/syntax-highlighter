//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
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
    highlight->setLanguage("c");
    this->setCentralWidget(edit);
}

Window::~Window() {
    delete toolbar;
}

