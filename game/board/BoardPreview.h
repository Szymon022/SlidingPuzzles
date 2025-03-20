//
// Created by szymon on 3/20/25.
//

#ifndef BOARDPREVIEW_H
#define BOARDPREVIEW_H

#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class BoardPreview;
}

QT_END_NAMESPACE

class BoardPreview : public QWidget {
    Q_OBJECT

    int boardSize;
    std::vector<QHBoxLayout *> rows;
    std::vector<QPushButton *> buttons;

public:
    explicit BoardPreview(int boardSize, QWidget *parent = nullptr);

    ~BoardPreview() override;

    void onUpdateBoardPreview(int size);

private:
    Ui::BoardPreview *ui;
};


#endif //BOARDPREVIEW_H
