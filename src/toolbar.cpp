//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <repository.hpp>
#include <highlighter.hpp>
#include <iostream>

#include "toolbar.hpp"
#include "global.hpp"

ToolBar::ToolBar() {
    themes = new QComboBox;
    syntax = new QComboBox;
    
    themes->addItems(Repository::themeList());
    syntax->addItems(Repository::syntaxList());
    
    this->addWidget(themes);
    this->addWidget(syntax);
    
    connect(themes, SIGNAL(currentTextChanged(QString)), this, SLOT(onThemeChanged(QString)));
    connect(syntax, SIGNAL(currentTextChanged(QString)), this, SLOT(onSyntaxChanged(QString)));
}

ToolBar::~ToolBar() {
    delete themes;
    delete syntax;
}

void ToolBar::onThemeChanged(QString text) {
    QString name = Repository::themeForName(text);
    win->getHighlighter()->setTheme(name);
}

void ToolBar::onSyntaxChanged(QString text) {
    QString name = Repository::defForName(text);
    win->getHighlighter()->setLanguage(name);
}

