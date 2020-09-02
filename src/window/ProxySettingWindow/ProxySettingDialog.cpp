//
// Created by poovarasan on 31/08/20.
//


#include "ProxySettingDialog.h"
#include "ui_proxysettingdialog.h"
#include <QValidator>

ProxySettingDialog::ProxySettingDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::ProxySettingDialog) {

    ui->setupUi(this);

    this->setFixedSize(QSize(430, 230));
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);


    ui->httpProxyPort->setValidator(new QIntValidator());
    ui->httpsProxyPort->setValidator(new QIntValidator());

}

ProxySettingDialog::~ProxySettingDialog() {
    delete ui;
}

