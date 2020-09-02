//
// Created by poovarasan on 31/08/20.
//

#ifndef OFFICEAPP_PROXYSETTINGDIALOG_H
#define OFFICEAPP_PROXYSETTINGDIALOG_H


#include <QDialog>
#include "ui_proxysettingdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ProxySettingDialog; }
QT_END_NAMESPACE

class ProxySettingDialog : public QDialog {
Q_OBJECT

public:
    ProxySettingDialog(QWidget *parent = nullptr);
    ~ProxySettingDialog();

private:
    Ui::ProxySettingDialog *ui;
};

#endif //OFFICEAPP_PROXYSETTINGDIALOG_H
