//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QMainWindow>

#include <highlighter.hpp>

#include "toolbar.hpp"

class Window : public QMainWindow {
    Q_OBJECT
public:
    Window();
    ~Window();
    
    SyntaxHighlighter *getHighlighter() { return highlight; }
private:
    ToolBar *toolbar;
    SyntaxHighlighter *highlight;
};

