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

