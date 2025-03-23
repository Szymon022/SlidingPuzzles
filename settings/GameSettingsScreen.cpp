//
// Created by szymon on 3/20/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameSettingsScreen.h" resolved

#include "GameSettingsScreen.h"
#include "ui_GameSettingsScreen.h"
#include "../game/board/BoardPreview.h"


void GameSettingsScreen::onUpdateBoardPreviewSize(const int boardSize) const {
    boardPreviewWidget->onUpdateBoardSize(boardSize);
}

GameSettingsScreen::GameSettingsScreen(QWidget *parent) : QWidget(parent), ui(new Ui::GameSettingsScreen) {
    ui->setupUi(this);
    boardSizes = {3, 4, 5, 6, 7, 8, 9, 10};
    viewModel = new GameSettingsScreenViewModel(boardSizes[0], ui->timeLimitLineEdit->text());

    for (const auto boardSize: boardSizes) {
        const auto label = QString::number(boardSize) + "x" + QString::number(boardSize);
        ui->boardSizeComboBox->addItem(label);
    }

    boardPreviewWidget = new BoardPreview(boardSizes[ui->boardSizeComboBox->currentIndex()], this);
    ui->boardPreviewVerticalLayout->addWidget(boardPreviewWidget);


    connect(ui->exitToMenuScreenButton, &QPushButton::clicked, this, [this] { emit navigateToMainMenu(true); });
    connect(ui->startGameButton, &QPushButton::clicked, this, [this] {
        if (viewModel->validateInput()) {
            emit navigateToGameScreen(viewModel->getBoardSize());
        }
    });

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
        [this](int index) {
            viewModel->onSetBoardSize(boardSizes[index]);
        }
    );

    connect(
        viewModel,
        &GameSettingsScreenViewModel::updateBoardPreviewState,
        this,
        &GameSettingsScreen::onUpdateBoardPreviewSize
    );
}

GameSettingsScreen::~GameSettingsScreen() {
    delete viewModel;
    delete ui;
}
