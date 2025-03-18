//
// Created by szymon on 3/12/25.
//

#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QPushButton>
#include <QWidget>

#include "board/Board.h"


QT_BEGIN_NAMESPACE

namespace Ui {
    class GameScreen;
}

QT_END_NAMESPACE

class GameScreen : public QWidget {
    Q_OBJECT

public:
    explicit GameScreen(QWidget *parent = nullptr);

    void restartBoard();

    void onTileClick(int row, int column);

    void checkWinCondition() const;

    void renderBoard();

    ~GameScreen() override;

private slots:
    void onNavigateToMainMenu();

signals:
    void navigateToMainMenu(bool popBackStack);

private:
    Ui::GameScreen *ui;
    Board *board;
};


#endif //GAMESCREEN_H
