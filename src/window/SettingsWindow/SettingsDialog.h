//
// Created by poovarasan on 31/08/20.
//

#ifndef OFFICEAPP_SETTINGSDIALOG_H
#define OFFICEAPP_SETTINGSDIALOG_H

#include <QDialog>
#include <QStandardItem>
#include "ui_settingsdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SettingsDialog; }
QT_END_NAMESPACE

class SettingsDialog : public QDialog {
Q_OBJECT

public:
    SettingsDialog(QWidget *parent = nullptr);

    ~SettingsDialog();

    QStandardItem *buildItem(QIcon icon, QString text);

private slots:

    void onSettingItemClick(QModelIndex modelIndex);

    void onClickRecordingFolderButton();

    void initStartup();

private:
    Ui::SettingsDialog *ui;
};


#endif //OFFICEAPP_SETTINGSDIALOG_H
