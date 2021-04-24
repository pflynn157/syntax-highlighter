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

