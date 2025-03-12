//
// Created by szymon on 3/11/25.
//

#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui
{
    class MainMenu;
}

QT_END_NAMESPACE

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget* parent = nullptr);

    ~MainMenu() override;

signals:
    void navigateToNewGame();

private slots:
    void onNewGameClicked();
    void onExitGameClicked();

private:
    Ui::MainMenu* ui;
};


#endif //MAINMENU_H
