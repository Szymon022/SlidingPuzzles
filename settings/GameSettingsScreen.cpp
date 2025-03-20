//
// Created by szymon on 3/20/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameSettingsScreen.h" resolved

#include "GameSettingsScreen.h"
#include "ui_GameSettingsScreen.h"
#include "../game/board/BoardPreview.h"


GameSettingsScreen::GameSettingsScreen(QWidget *parent) : QWidget(parent), ui(new Ui::GameSettingsScreen) {
    ui->setupUi(this);
    const auto boardPreviewWidget = new BoardPreview(3, this);
    ui->boardPreviewVerticalLayout->addWidget(boardPreviewWidget);
    viewModel = new GameSettingsScreenViewModel();

    boardSizes = {3, 4, 5, 6, 7, 8, 9, 10};

    for (const auto boardSize: boardSizes) {
        const auto label = QString::number(boardSize) + "x" + QString::number(boardSize);
        ui->boardSizeComboBox->addItem(label);
    }

    connect(ui->exitToMenuScreenButton, &QPushButton::clicked, this, [this] { emit navigateToMainMenu(true); });
    connect(ui->startGameButton, &QPushButton::clicked, this, [this] { emit navigateToGameScreen(); });

    connect(
        ui->timeLimitLineEdit,
        &QLineEdit::textChanged,
        this,
        [this](QString text) {
            viewModel->onUpdateTimeLimit(text);
        }
    );

    connect(
        ui->boardSizeComboBox,
        &QComboBox::currentIndexChanged,
        this,
        [this, boardPreviewWidget](int index) {
            viewModel->onSetBoardSize(boardSizes[index]);
            boardPreviewWidget->onUpdateBoardSize(boardSizes[index]);
        }
    );
}

GameSettingsScreen::~GameSettingsScreen() {
    delete viewModel;
    delete ui;
}
