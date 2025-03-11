//
// Created by szymon on 3/11/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainMenu.h" resolved

#include "MainMenu.h"
#include "ui_MainMenu.h"


MainMenu::MainMenu(QWidget *parent) : QWidget(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);
}

MainMenu::~MainMenu() {
    delete ui;
}
