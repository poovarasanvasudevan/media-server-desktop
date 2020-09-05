//
// Created by poovarasan on 31/08/20.
//

#include <QDebug>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QSystemTrayIcon>
#include <QAction>
#include "MainWindow.h"
#include "ui_mainwindow.h"


void MainWindow::closeEvent(QCloseEvent *event) {

}

void MainWindow::createActions() {

}

void MainWindow::createTrayIcon() {
    QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/assets/icons/room.png"));
    trayIcon->setVisible(true);
}

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->setFixedSize(QSize(450, 320));
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    createTrayIcon();

    proxySettingDialog = new ProxySettingDialog();
    settingsDialog = new SettingsDialog();
    chatDialog = new ChatDialog();
    loginWindow = new LoginWindow(this);

    connect(ui->proxySettingButton, SIGNAL(released()), this, SLOT(onProxyButtonClicked()));
    connect(ui->settingsButton, SIGNAL(released()), this, SLOT(onSettingButtonClick()));
    connect(ui->joinMeeting, SIGNAL(released()), this, SLOT(onJoinMeetingButtonClick()));

    connect(ui->signInButton, &QPushButton::released, [=]() {
        if(loginWindow->isVisible()) {
            loginWindow->activateWindow();
        } else {
            loginWindow->show();
        }
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onProxyButtonClicked() {
    if (!proxySettingDialog->isVisible()) {
        proxySettingDialog->show();
    } else {
        proxySettingDialog->activateWindow();
    }
}

void MainWindow::onSettingButtonClick() {

    if (!settingsDialog->isVisible()) {
        settingsDialog->show();
    } else {
        settingsDialog->activateWindow();
    }
}

void MainWindow::onJoinMeetingButtonClick() {

    if (!chatDialog->isVisible()) {
        chatDialog->show();
    } else {
        chatDialog->activateWindow();
    }
}