//
// Created by szymon on 3/12/25.
//

#ifndef GAMESCREEN_H
#define GAMESCREEN_H

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

public:
    explicit GameScreen(QWidget *parent = nullptr);

    ~GameScreen() override;

private slots:
    void onNavigateToMainMenu();

    void updateTimerLabel(const QString &label) const;

    void updateMovesCounterLabel(const QString &label) const;

    void updateBoard(const std::vector<QString> &board) const;

signals:
    void navigateToMainMenu(bool popBackStack);

private:
    Ui::GameScreen *ui;
    GameScreenViewModel *viewModel;
};


#endif //GAMESCREEN_H
