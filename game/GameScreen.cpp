//
// Created by szymon on 3/12/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameScreen.h" resolved

#include "GameScreen.h"

#include "ui_GameScreen.h"
#include "dialog/GameWonDialog.h"

GameScreen::GameScreen(const int boardSize, QWidget *parent) : QWidget(parent), ui(new Ui::GameScreen) {
    ui->setupUi(this);

    viewModel = new GameScreenViewModel(boardSize);
    this->boardSize = boardSize;

    this->rows = std::vector<QHBoxLayout *>();
    this->buttons = std::vector<QPushButton *>();

    for (int i = 0; i < boardSize; i++) {
        auto row = new QHBoxLayout();
        row->setParent(qobject_cast<QWidget *>(ui->boardBaseVerticalLayout));
        row->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Fixed));
        for (int j = 0; j < boardSize; j++) {
            const auto button = new QPushButton("");
            button->setParent(dynamic_cast<QWidget *>(row));
            auto font = button->font();
            font.setPointSize(50);
            font.setBold(true);
            button->setFont(font);
            connect(button, &QPushButton::clicked, this, [this, i, j] { viewModel->onBoardClick(i, j); });

            row->addWidget(button);
            buttons.push_back(button);
        }
        row->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Fixed));
        ui->boardBaseVerticalLayout->addLayout(row);
        rows.push_back(row);
    }

    connect(ui->navigateToMainMenuButton, &QPushButton::clicked, this, &GameScreen::onNavigateToMainMenu);
    connect(ui->restartBoardButton, &QPushButton::clicked, this, [this] { viewModel->onRestartClick(); });

    connect(viewModel, &GameScreenViewModel::updateMovesCounterState, this, &GameScreen::updateMovesCounterLabel);
    connect(viewModel, &GameScreenViewModel::updateTimerState, this, &GameScreen::updateTimerLabel);
    connect(viewModel, &GameScreenViewModel::updateBoardState, this, &GameScreen::updateBoard);
    connect(viewModel, &GameScreenViewModel::updateGameWonState, this, &GameScreen::updateGameWonState);

    connect(viewModel, &GameScreenViewModel::showGameWonDialog, this, &GameScreen::showGameWonDialog);

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
    for (int i = 0; i < board.size(); i++) {
        buttons[i]->setText(board[i]);
    }
}

void GameScreen::updateGameWonState(const bool isGameWon) const {
    if (isGameWon) {
        qDebug("GAME WON!");
    }
}

void GameScreen::resizeButtons() {
    const int boardSizePx = std::min(window()->height() - 150, window()->width() - 500);
    const int tileSizePx = boardSizePx / boardSize;

    for (int i = 0; i < buttons.size(); i++) {
        buttons[i]->setMinimumSize(tileSizePx, tileSizePx);
        buttons[i]->setMaximumSize(tileSizePx, tileSizePx);
    }
}

void GameScreen::showGameWonDialog(QString yourMoves, QString bestMoves, QString yourTime, QString bestTime) {
    const auto gameWonDialog = new GameWonDialog(this);

    connect(gameWonDialog, &GameWonDialog::playAgain, this, [this, gameWonDialog] {
        gameWonDialog->close();
        viewModel->onRestartClick();
    });

    connect(gameWonDialog, &GameWonDialog::exitToMainMenu, this, [this, gameWonDialog] {
        gameWonDialog->close();
        navigateToMainMenu(true);
    });

    gameWonDialog->setYourMoves(yourMoves);
    gameWonDialog->setBestMoves(bestMoves);

    gameWonDialog->setYourTime(yourTime);
    gameWonDialog->setBestTime(bestTime);

    gameWonDialog->open();
}

void GameScreen::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    resizeButtons();
}

GameScreen::~GameScreen() {
    for (int i = 0; i < buttons.size(); i++) {
        delete buttons[i];
    }
    for (int i = 0; i < rows.size(); i++) {
        delete rows[i];
    }
    delete viewModel;
    delete ui;
}
