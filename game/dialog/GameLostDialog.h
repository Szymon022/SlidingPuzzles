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

class GameLostDialog : public QDialog {
    Q_OBJECT

public:
    explicit GameLostDialog(QWidget *parent = nullptr);

    ~GameLostDialog() override;

private:
    Ui::GameLostDialog *ui;
};


#endif //GAMELOSTDIALOG_H
