//
// Created by szymon on 3/12/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameScreen.h" resolved

#include "GameScreen.h"

#include <QStackedWidget>
#include <QTimer>

#include "ui_GameScreen.h"

GameScreen::GameScreen(QWidget *parent) : QWidget(parent), ui(new Ui::GameScreen) {
    ui->setupUi(this);

    viewModel = new GameScreenViewModel();

    QPushButton *buttons[3][3] = {
        {ui->pushButton, ui->pushButton_2, ui->pushButton_3},
        {ui->pushButton_4, ui->pushButton_5, ui->pushButton_6},
        {ui->pushButton_7, ui->pushButton_8, ui->pushButton_9}
    };

    connect(ui->navigateToMainMenuButton, &QPushButton::clicked, this, &GameScreen::onNavigateToMainMenu);
    connect(ui->restartBoardButton, &QPushButton::clicked, this, [this] { viewModel->onRestartClick(); });

    connect(viewModel, &GameScreenViewModel::updateMovesCounterState, this, &GameScreen::updateMovesCounterLabel);
    connect(viewModel, &GameScreenViewModel::updateTimerState, this, &GameScreen::updateTimerLabel);
    connect(viewModel, &GameScreenViewModel::updateBoardState, this, &GameScreen::updateBoard);
    connect(viewModel, &GameScreenViewModel::updateGameWonState, this, &GameScreen::updateGameWonState);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            buttons[i][j]->setMinimumSize(200, 200);
            buttons[i][j]->setMaximumSize(200, 200);
            auto font = buttons[i][j]->font();
            font.setPointSize(50);
            font.setBold(true);
            buttons[i][j]->setFont(font);
            connect(buttons[i][j], &QPushButton::clicked, this, [this, i, j] { viewModel->onBoardClick(i, j); });
        }
    }

    viewModel->getInitialState();
}

void GameScreen::onNavigateToMainMenu() {
    emit navigateToMainMenu(true);
}


void GameScreen::updateTimerLabel(const QString &label) const {
    ui->timerLabel->setText(label);
}

void GameScreen::updateMovesCounterLabel(const QString &label) const {
    ui->movesCounterLabel->setText(label);
}

void GameScreen::updateBoard(const std::vector<QString> &board) const {
    QPushButton *buttons[9] = {
        ui->pushButton, ui->pushButton_2, ui->pushButton_3,
        ui->pushButton_4, ui->pushButton_5, ui->pushButton_6,
        ui->pushButton_7, ui->pushButton_8, ui->pushButton_9
    };

    for (int i = 0; i < 9; i++) {
        buttons[i]->setText(board[i]);
    }
}

void GameScreen::updateGameWonState(const bool isGameWon) const {
    if (isGameWon) {
        qDebug("GAME WON!");
    }
}

GameScreen::~GameScreen() {
    delete viewModel;
    delete ui;
}
