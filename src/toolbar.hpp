//
// This software is licensed under BSD0 (public domain).
// Therefore, this software belongs to humanity.
// See COPYING for more info.
//
#pragma once

#include <QToolBar>
#include <QToolButton>
#include <QComboBox>

class ToolBar : public QToolBar {
    Q_OBJECT
public:
    ToolBar();
    ~ToolBar();
private:
    QComboBox *themes, *syntax;
private slots:
    void onThemeChanged(QString text);
    void onSyntaxChanged(QString text);
};

