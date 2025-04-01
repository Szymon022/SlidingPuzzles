//
// Created by szymon on 3/23/25.
//

#ifndef GAMELOSTDIALOG_H
#define GAMELOSTDIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE

namespace Ui {
    class GameLostDialog;
}

QT_END_NAMESPACE

/**
 * Dialog that is shown to the user whe he/she loses the game. It is used in a time-limited games only.
 */
class GameLostDialog : public QDialog {
    Q_OBJECT

signals:
    /**
     * Signal emitted when user clicks exit to main menu button.
     */
    void exitToMainMenu();

    /**
     * Signal emitted when user clicks play again button.
     */
    void playAgain();

public:
    /**
     * Creates a game lost dialog.
     * @param parent parent of the dialog.
     */
    explicit GameLostDialog(QWidget *parent = nullptr);

    ~GameLostDialog() override;

private:
    Ui::GameLostDialog *ui;
};


#endif //GAMELOSTDIALOG_H
