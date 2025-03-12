//
// Created by szymon on 3/11/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "game/GameScreen.h"
#include "menu/MainMenu.h"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&main_menu, SIGNAL(navigateToNewGame()), this, SLOT(handleNavigateToNewGame()));
    connect(&game_screen, SIGNAL(navigateToMainMenu()), this, SLOT(handleNavigateToMainMenu()));

    ui->stackedWidget->addWidget(&main_menu);
    ui->stackedWidget->addWidget(&game_screen);
}

void MainWindow::handleNavigateToMainMenu() const
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::handleNavigateToNewGame() const
{
    ui->stackedWidget->setCurrentIndex(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
