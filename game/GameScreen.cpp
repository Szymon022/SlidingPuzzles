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
    connect(ui->navigateToMainMenuButton, &QPushButton::clicked, this, &GameScreen::onNavigateToMainMenu);
}

void GameScreen::onNavigateToMainMenu()
{
    emit navigateToMainMenu();
}

GameScreen::~GameScreen()
{
    delete ui;
}
