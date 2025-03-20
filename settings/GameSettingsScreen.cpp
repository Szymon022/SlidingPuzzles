//
// Created by szymon on 3/20/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameSettingsScreen.h" resolved

#include "GameSettingsScreen.h"
#include "ui_GameSettingsScreen.h"


GameSettingsScreen::GameSettingsScreen(QWidget *parent) : QWidget(parent), ui(new Ui::GameSettingsScreen) {
    ui->setupUi(this);

    connect(ui->exitToMenuScreenButton, &QPushButton::clicked, this, [this] { emit navigateToMainMenu(true); });
    connect(ui->startGameButton, &QPushButton::clicked, this, [this] { emit navigateToGameScreen(); });
}

GameSettingsScreen::~GameSettingsScreen() {
    delete ui;
}
