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

/**
 * This is a widget that represents a preview of the board.
 */
class BoardPreview : public QWidget {
    Q_OBJECT

    int boardSize;
    std::vector<QHBoxLayout *> rows;
    std::vector<QPushButton *> buttons;

    void createBoard(int boardSize);

    void resizeButtons();

    void resizeEvent(QResizeEvent *event) override;

public:
    explicit BoardPreview(int boardSize, QWidget *parent = nullptr);

    ~BoardPreview() override;

    /**
     * \brief Updates preview board size.
     *
     * @param size new size of the board
     */
    void onUpdateBoardSize(int size);

private:
    Ui::BoardPreview *ui;
};


#endif //BOARDPREVIEW_H
