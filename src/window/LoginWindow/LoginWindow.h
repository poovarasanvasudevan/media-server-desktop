//
// Created by poovarasan on 03/09/20.
//

#ifndef OFFICEAPP_LOGINWINDOW_H
#define OFFICEAPP_LOGINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow  : public QMainWindow {
Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);

    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
};


#endif //OFFICEAPP_LOGINWINDOW_H
