//
// Created by szymon on 3/11/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "game/GameScreen.h"
#include "menu/MenuScreen.h"
#include "settings/GameSettingsScreen.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    navigationStack = std::stack<QWidget *>();

    handleNavigateToMainMenu(false);
}

void MainWindow::handleNavigateToMainMenu(const bool popBackStack = false) {
    if (popBackStack) {
        while (!navigationStack.empty()) {
            auto topWidget = navigationStack.top();
            if (dynamic_cast<MenuScreen *>(topWidget) != nullptr) {
                break;
            }
            ui->stackedWidget->removeWidget(topWidget);
            navigationStack.pop();
            ui->stackedWidget->setCurrentIndex(navigationStack.size() - 1);
            delete topWidget;
        }
        return;
    }
    const auto menuScreen = new MenuScreen();

    connect(menuScreen, &MenuScreen::navigateToGameSettings, this, &MainWindow::handleNavigateToGameSettings);

    navigationStack.push(menuScreen);
    ui->stackedWidget->addWidget(menuScreen);
    ui->stackedWidget->setCurrentIndex(navigationStack.size() - 1);
}

void MainWindow::handleNavigateToGameSettings() {
    const auto gameSettings = new GameSettingsScreen();

    connect(gameSettings, &GameSettingsScreen::navigateToGameScreen, this, &MainWindow::handleNavigateToNewGame);
    connect(gameSettings, &GameSettingsScreen::navigateToMainMenu, this, &MainWindow::handleNavigateToMainMenu);

    navigationStack.push(gameSettings);
    ui->stackedWidget->addWidget(gameSettings);
    ui->stackedWidget->setCurrentIndex(navigationStack.size() - 1);
}

void MainWindow::handleNavigateToNewGame() {
    const auto gameScreen = new GameScreen();

    connect(gameScreen, &GameScreen::navigateToMainMenu, this, &MainWindow::handleNavigateToMainMenu);

    navigationStack.push(gameScreen);
    ui->stackedWidget->addWidget(gameScreen);
    ui->stackedWidget->setCurrentIndex(navigationStack.size() - 1);
}

MainWindow::~MainWindow() {
    while (!navigationStack.empty()) {
        delete navigationStack.top();
        navigationStack.pop();
    }
    delete ui;
}
