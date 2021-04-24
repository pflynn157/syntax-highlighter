#pragma once

#include <QStringList>
#include <QString>

class Repository {
public:
    static QStringList syntaxList();
    static QStringList themeList();
private:
    static QStringList getEntries(QString path);
    static QString getName(QString path);
};

