//
// Created by szymon on 3/11/25.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stack>

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
    void handleNavigateToMainMenu(bool popBackStack);

    void handleNavigateToGameSettings();

    void handleNavigateToNewGame();

private:
    Ui::MainWindow *ui;
    std::stack<QWidget *> navigationStack;
};


#endif //MAINWINDOW_H
