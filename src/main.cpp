//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#include <QApplication>

#include "window.hpp"
#include "global.hpp"

Window *win;

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    
    win = new Window;
    win->show();
    
    return app.exec();
}

