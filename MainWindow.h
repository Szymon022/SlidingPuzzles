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

/**
 * Class representing the root of the whole ui - MainWindow. It encapsulates navigation logic.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

public slots:
    /**
     * Handles navigate to main menu.
     * @param popBackStack if all the widgets from top of the stack to the MainMenu screen should be popped from the stacked.
     */
    void handleNavigateToMainMenu(bool popBackStack);

    /**
     * Handles navigate to game screen.
     */
    void handleNavigateToGameSettings();

    /**
     * Handles navigate to new game screen.
     * @param boardSize size of the board that the player will solve
     * @param timeLimit time limit. It is ignored unless enableTimeLimit is set to true
     * @param enableTimeLimit enables time limit
     */
    void handleNavigateToNewGame(int boardSize, int timeLimit, bool enableTimeLimit);

private:
    Ui::MainWindow *ui;
    std::stack<QWidget *> navigationStack;
};


#endif //MAINWINDOW_H
