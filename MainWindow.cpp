//
// Created by szymon on 3/11/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "menu/MainMenu.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->stackedWidget->addWidget(new MainMenu(ui->stackedWidget));
}

MainWindow::~MainWindow() {
    delete ui;
}
