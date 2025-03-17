//
// Created by szymon on 3/12/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameScreen.h" resolved

#include "GameScreen.h"

#include <QStackedWidget>

#include "ui_GameScreen.h"
#include "board/tiles/EmptyTile.h"
#include "board/tiles/NumberTile.h"


GameScreen::GameScreen(QWidget *parent) : QWidget(parent), ui(new Ui::GameScreen) {
    ui->setupUi(this);

    this->board = new Board(
        {
            new NumberTile(1, 2),
            new NumberTile(7, 8),
            new NumberTile(5, 6),
            new NumberTile(6, 7),
            new NumberTile(0, 1),
            new NumberTile(4, 5),
            new NumberTile(3, 4),
            new NumberTile(2, 3),
            new EmptyTile(8),
        }
    );

    QPushButton *buttons[3][3] = {
        {ui->pushButton, ui->pushButton_2, ui->pushButton_3},
        {ui->pushButton_4, ui->pushButton_5, ui->pushButton_6},
        {ui->pushButton_7, ui->pushButton_8, ui->pushButton_9}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            buttons[i][j]->setMinimumSize(200, 200);
            buttons[i][j]->setMaximumSize(200, 200);
            auto font = buttons[i][j]->font();
            font.setPointSize(50);
            font.setBold(true);
            buttons[i][j]->setFont(font);
            connect(buttons[i][j], &QPushButton::clicked, this, [this, i, j] { onTileClick(i, j); });
        }
    }
    renderBoard();
}

void GameScreen::onTileClick(int row, int column) {
    board->onTileClick(row, column);
    checkWinCondition();
    renderBoard();
}

void GameScreen::checkWinCondition() const {
    if (board->isSolved()) {
        qDebug() << "GAME WIN";
    }
}


void GameScreen::renderBoard() {
    QPushButton *buttons[3][3] = {
        {ui->pushButton, ui->pushButton_2, ui->pushButton_3},
        {ui->pushButton_4, ui->pushButton_5, ui->pushButton_6},
        {ui->pushButton_7, ui->pushButton_8, ui->pushButton_9}
    };
    for (int i = 0; i < this->board->getSize(); i++) {
        for (int j = 0; j < this->board->getSize(); j++) {
            auto tile = board->getTile(i, j);
            if (dynamic_cast<EmptyTile *>(tile) != nullptr) {
                buttons[i][j]->setText("");
            } else if (auto numberTile = dynamic_cast<NumberTile *>(tile); numberTile != nullptr) {
                buttons[i][j]->setText(QString::number(numberTile->getValue()));
            }
        }
    }
}

void GameScreen::onNavigateToMainMenu() {
    emit navigateToMainMenu();
}

GameScreen::~GameScreen() {
    delete board;
    delete ui;
}
