//
// Created by szymon on 3/23/25.
//

#ifndef GAMEWONDIALOG_H
#define GAMEWONDIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE

namespace Ui {
    class GameWonDialog;
}

QT_END_NAMESPACE

/**
 * Represents game won dialog. It shows user and best times and moves counter. It offers the user to play again or exit to main menu.
 */
class GameWonDialog : public QDialog {
    Q_OBJECT

signals:
    /**
     * Emitted when user clicked exit to main menu button.
     */
    void exitToMainMenu();

    /**
     * Emitted when user clicked play again button.
     */
    void playAgain();

public:
    /**
     * Creates GameWonDialog with placeholder information. Use appropriate set*() methods to set actual values.
     * @param parent parent of this dialog
     */
    explicit GameWonDialog(QWidget *parent = nullptr);

    ~GameWonDialog() override;

    /**
     * Sets label of the best moves section.
     * @param bestMoves label to be shown in the best moves section.
     */
    void setBestMoves(const QString &bestMoves) const;

    /**
     * Sets label of the user's moves counter section.
     * @param yourMoves label to be shown in the user's moves section.
     */
    void setYourMoves(const QString &yourMoves) const;

    /**
     * Sets label of the best time section.
     * @param bestTime label to be shown in the best time section.
     */
    void setBestTime(const QString &bestTime) const;

    /**
     * Sets label of the user's time section.
     * @param yourTime label to be shown in the user's time section.
     */
    void setYourTime(const QString &yourTime) const;

private:
    Ui::GameWonDialog *ui;
};


#endif //GAMEWONDIALOG_H
