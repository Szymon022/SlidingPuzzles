//
// Created by szymon on 3/23/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameWonDialog.h" resolved

#include "GameWonDialog.h"
#include "ui_GameWonDialog.h"


GameWonDialog::GameWonDialog(QWidget *parent) : QDialog(parent), ui(new Ui::GameWonDialog) {
    ui->setupUi(this);
    connect(ui->playAgainButton, &QPushButton::clicked, this, [this] { emit playAgain(); });
    connect(ui->exitToMainMenuButton, &QPushButton::clicked, this, [this] { emit exitToMainMenu(); });
}

GameWonDialog::~GameWonDialog() {
    delete ui;
}

void GameWonDialog::setBestMoves(const QString &bestMoves) const {
    ui->bestMovesLabel->setText(bestMoves);
}

void GameWonDialog::setYourMoves(const QString &yourMoves) const {
    ui->yourMovesLabel->setText(yourMoves);
}

void GameWonDialog::setBestTime(const QString &bestTime) const {
    ui->bestTimeLabel->setText(bestTime);
}

void GameWonDialog::setYourTime(const QString &yourTime) const {
    ui->yourTimeLabel->setText(yourTime);
}
