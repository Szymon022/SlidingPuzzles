//
// Created by szymon on 3/23/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameLostDialog.h" resolved

#include "GameLostDialog.h"
#include "ui_GameLostDialog.h"


GameLostDialog::GameLostDialog(QWidget *parent) : QDialog(parent), ui(new Ui::GameLostDialog) {
    ui->setupUi(this);
}

GameLostDialog::~GameLostDialog() {
    delete ui;
}
