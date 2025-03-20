//
// Created by szymon on 3/20/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_BoardPreview.h" resolved

#include "BoardPreview.h"
#include "ui_BoardPreview.h"


BoardPreview::BoardPreview(int boardSize, QWidget *parent) : QWidget(parent), ui(new Ui::BoardPreview) {
    ui->setupUi(this);


    this->boardSize = boardSize;
    this->rows = std::vector<QHBoxLayout *>();
    this->buttons = std::vector<QPushButton *>();

    ui->verticalLayout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Fixed));
    for (int i = 0; i < boardSize; i++) {
        auto row = new QHBoxLayout();
        row->setParent(qobject_cast<QWidget *>(ui->verticalLayout));
        row->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Fixed));
        for (int j = 0; j < boardSize; j++) {
            int number = i * boardSize + j + 1;
            const auto button = new QPushButton(number != boardSize * boardSize ? QString::number(number) : "");
            button->setParent(dynamic_cast<QWidget *>(row));
            auto font = button->font();
            font.setPointSize(50);
            font.setBold(true);
            button->setFont(font);
            button->setEnabled(false);
            button->setMinimumSize(200, 200);
            button->setMaximumSize(200, 200);

            row->addWidget(button);
            buttons.push_back(button);
        }
        row->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Fixed));
        ui->verticalLayout->addLayout(row);
        rows.push_back(row);
    }
    ui->verticalLayout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Fixed));
}


BoardPreview::~BoardPreview() {
    delete ui;
}

void BoardPreview::onUpdateBoardPreview(int size) {
}
