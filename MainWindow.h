//
// Created by szymon on 3/11/25.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "game/GameScreen.h"
#include "menu/MenuScreen.h"


QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

public slots:
    void handleNavigateToMainMenu() const;
    void handleNavigateToNewGame() const;

private:
    Ui::MainWindow *ui;
    MenuScreen main_menu;
    GameScreen game_screen;
};


#endif //MAINWINDOW_H
