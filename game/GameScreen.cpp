//
// Created by szymon on 3/12/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameScreen.h" resolved

#include "GameScreen.h"

#include <QStackedWidget>

#include "ui_GameScreen.h"


GameScreen::GameScreen(QWidget* parent) :
    QWidget(parent), ui(new Ui::GameScreen)
{
    ui->setupUi(this);

    int x[3][3] = {{2, 8, 6}, {7, 1, 5}, {4, 3, 0}};
    this->board = new Board(x);
    renderBoard();

    QPushButton* buttons[3][3] = {
        {ui->pushButton, ui->pushButton_2, ui->pushButton_3},
        {ui->pushButton_4, ui->pushButton_5, ui->pushButton_6},
        {ui->pushButton_7, ui->pushButton_8, ui->pushButton_9}
    };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            buttons[i][j]->setMinimumSize(200, 200);
            buttons[i][j]->setMaximumSize(200, 200);
            auto font = buttons[i][j]->font();
            font.setPointSize(50);
            font.setBold(true);
            buttons[i][j]->setFont(font);
            connect(buttons[i][j], &QPushButton::clicked, this, [this, i, j] { onTileClick(i, j); });
        }
    }
}

void GameScreen::onTileClick(int row, int column)
{
    board->onTileClick(row, column);
    checkWinCondition();
    renderBoard();
}

void GameScreen::checkWinCondition() const
{
    if (board->isSolved())
    {
        qDebug() << "GAME WIN";
    }
}


void GameScreen::renderBoard()
{
    QPushButton* buttons[3][3] = {
        {ui->pushButton, ui->pushButton_2, ui->pushButton_3},
        {ui->pushButton_4, ui->pushButton_5, ui->pushButton_6},
        {ui->pushButton_7, ui->pushButton_8, ui->pushButton_9}
    };
    for (int i = 0; i < this->board->getBoardRows(); i++)
    {
        for (int j = 0; j < this->board->getBoardCols(); j++)
        {
            int tile = board->getTile(i, j);
            if (tile == 0)
            {
                buttons[i][j]->setText("");
            }
            else
            {
                buttons[i][j]->setText(QString::number(tile));
            }
        }
    }
}

void GameScreen::onNavigateToMainMenu()
{
    emit navigateToMainMenu();
}

GameScreen::~GameScreen()
{
    delete board;
    delete ui;
}
