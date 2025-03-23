//
// Created by szymon on 3/12/25.
//

#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>

#include "GameScreenViewModel.h"
#include "board/Board.h"


QT_BEGIN_NAMESPACE

namespace Ui {
    class GameScreen;
}

QT_END_NAMESPACE

class GameScreen : public QWidget {
    Q_OBJECT

    std::vector<QHBoxLayout *> rows;
    std::vector<QPushButton *> buttons;

public:
    explicit GameScreen(int boardSize, int timeLimitMs, bool enableTimeLimit, QWidget *parent = nullptr);

    ~GameScreen() override;

private slots:
    void onNavigateToMainMenu();

    void updateTimerLabel(const QString &label) const;

    void updateMovesCounterLabel(const QString &label) const;

    void updateBoard(const std::vector<QString> &board) const;

    void resizeButtons();

    void showGameWonDialog(QString yourMoves, QString bestMoves, QString yourTime, QString bestTime);

    void showGameLostDialog();

signals:
    void navigateToMainMenu(bool popBackStack);

private:
    Ui::GameScreen *ui;
    GameScreenViewModel *viewModel;
    int boardSize;

    void resizeEvent(QResizeEvent *event) override;
};


#endif //GAMESCREEN_H
