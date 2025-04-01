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

/**
 * Represents game screen.
 */
class GameScreen : public QWidget {
    Q_OBJECT

    std::vector<QHBoxLayout *> rows;
    std::vector<QPushButton *> buttons;

public:
    /**
     * Creates a GameScreen with provided information.
     * @param boardSize board size that the game should start with.
     * @param timeLimitMs time limit of the game. Respected only if the enableTimeLimit flag is set to true.
     * @param enableTimeLimit enables or disables time limit.
     * @param parent parent of this screen.
     */
    explicit GameScreen(int boardSize, int timeLimitMs, bool enableTimeLimit, QWidget *parent = nullptr);

    ~GameScreen() override;

private slots:
    /**
     * Handles navagation to main menu.
     */
    void onNavigateToMainMenu();

    /**
     * Handles timer label update.
     * @param label label of the timer label in format: m:ss. Example: 1:35
     */
    void updateTimerLabel(const QString &label) const;

    /**
     * Handles moves counter label update.
     * @param label label of the moves counter.
     */
    void updateMovesCounterLabel(const QString &label) const;

    /**
     * Handles board labels update.
     * @param board board symbols representation represented in 1D vector in row-wise order.
     */
    void updateBoard(const std::vector<QString> &board) const;

    /**
     * Handles button resize.
     */
    void resizeButtons();

    /**
     * Handles show game dialog with all the information.
     * @param yourMoves user moves label
     * @param bestMoves best moves label
     * @param yourTime user time label
     * @param bestTime best time label
     */
    void showGameWonDialog(QString yourMoves, QString bestMoves, QString yourTime, QString bestTime);

    /**
     * Handles show game lost dialog.
     */
    void showGameLostDialog();

signals:
    /**
     * Emitted when user is navigating back to the main menu.
     * @param popBackStack should this screen be dropped from the navigation stack.
     */
    void navigateToMainMenu(bool popBackStack);

private:
    Ui::GameScreen *ui;
    GameScreenViewModel *viewModel;
    int boardSize;

    void resizeEvent(QResizeEvent *event) override;
};


#endif //GAMESCREEN_H
