#include <QTextEdit>

#include "window.hpp"
#include "highlighter.hpp"

Window::Window() {
    this->setWindowTitle("Qt5 Template");
    this->resize(700, 500);
    
    QTextEdit *edit = new QTextEdit;
    SyntaxHighlighter *highlight = new SyntaxHighlighter(edit->document());
    this->setCentralWidget(edit);
}

Window::~Window() {
}

