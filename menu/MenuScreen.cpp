//
// Created by szymon on 3/11/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainMenu.h" resolved

#include "MenuScreen.h"
#include "ui_MenuScreen.h"


MenuScreen::MenuScreen(QWidget* parent) : QWidget(parent), ui(new Ui::MenuScreen)
{
    ui->setupUi(this);

    connect(ui->newGameButton, &QPushButton::released, this, &MenuScreen::onNewGameClicked);
    connect(ui->exitGameButton, &QPushButton::released, this, &MenuScreen::onExitGameClicked);
}

void MenuScreen::onNewGameClicked()
{
    emit navigateToNewGame();
}

void MenuScreen::onExitGameClicked()
{
    QCoreApplication::quit();
}

MenuScreen::~MenuScreen()
{
    delete ui;
}
