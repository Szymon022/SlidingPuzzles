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

class GameWonDialog : public QDialog {
    Q_OBJECT

public:
    explicit GameWonDialog(QWidget *parent = nullptr);

    ~GameWonDialog() override;

    void setBestMoves(const QString &bestMoves) const;

    void setYourMoves(const QString &yourMoves) const;

    void setBestTime(const QString &bestTime) const;

    void setYourTime(const QString &yourTime) const;

private:
    Ui::GameWonDialog *ui;
};


#endif //GAMEWONDIALOG_H
