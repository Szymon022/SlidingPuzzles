//
// Created by szymon on 3/11/25.
//

#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui
{
    class MenuScreen;
}

QT_END_NAMESPACE

class MenuScreen : public QWidget
{
    Q_OBJECT

public:
    explicit MenuScreen(QWidget* parent = nullptr);

    ~MenuScreen() override;

signals:
    void navigateToGameSettings();

private slots:
    void onNewGameClicked();
    void onExitGameClicked();

private:
    Ui::MenuScreen* ui;
};


#endif //MAINMENU_H
