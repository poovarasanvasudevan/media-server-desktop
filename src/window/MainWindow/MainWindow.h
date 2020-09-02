//
// Created by poovarasan on 31/08/20.
//

#ifndef OFFICEAPP_MAINWINDOW_H
#define OFFICEAPP_MAINWINDOW_H


#include <QMainWindow>
#include "../ProxySettingWindow/ProxySettingDialog.h"
#include "../SettingsWindow/SettingsDialog.h"
#include "../ChatWindow/ChatDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void onProxyButtonClicked();

    void onSettingButtonClick();

    void onJoinMeetingButtonClick();

private:
    Ui::MainWindow *ui;
    ProxySettingDialog *proxySettingDialog;
    SettingsDialog *settingsDialog;
    ChatDialog *chatDialog;
};

#endif // OFFICEAPP_MAINWINDOW_H
