#include <QTextEdit>
#include <QStringLiteral>

#include "window.hpp"
#include "highlighter.hpp"
#include "repository.hpp"

Window::Window() {
    this->setWindowTitle("Qt5 Template");
    this->resize(700, 500);
    
    Repository::themeList();
    Repository::syntaxList();
    
    QTextEdit *edit = new QTextEdit;
    SyntaxHighlighter *highlight = new SyntaxHighlighter(edit->document());
    highlight->setLanguage("c");
    this->setCentralWidget(edit);
}

Window::~Window() {
}

