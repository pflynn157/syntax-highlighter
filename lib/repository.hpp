//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QStringList>
#include <QString>

class Repository {
public:
    static QStringList syntaxList();
    static QString defForName(QString name);
    static QStringList themeList();
    static QString themeForName(QString name);
private:
    static QStringList getEntries(QString path);
    static QString getName(QString path);
};

