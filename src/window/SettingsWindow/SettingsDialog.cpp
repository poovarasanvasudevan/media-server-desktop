//
// Created by poovarasan on 31/08/20.
//

#include "SettingsDialog.h"
#include "ui_settingsdialog.h"

#include <QStandardItem>
#include <QDebug>
#include <QFileDialog>
#include <QtMultimedia/QCameraInfo>
#include <QtMultimedia/QAudioDeviceInfo>
#include <QScreen>

SettingsDialog::SettingsDialog(QWidget *parent)
        : QDialog(parent), ui(new Ui::SettingsDialog) {

    ui->setupUi(this);
    this->setFixedSize(QSize(650, 400));
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);


    auto *model = new QStandardItemModel(ui->sidebarSettingMenu);

    model->appendRow(this->buildItem(QIcon(":/assets/icons/settings.png"), "General"));
    model->appendRow(this->buildItem(QIcon(":/assets/icons/speaker.png"), "Audio"));
    model->appendRow(this->buildItem(QIcon(":/assets/icons/video.png"), "Video"));
    model->appendRow(this->buildItem(QIcon(":/assets/icons/monitor.png"), "Screen"));
    model->appendRow(this->buildItem(QIcon(":/assets/icons/comment.png"), "Chat"));
    model->appendRow(this->buildItem(QIcon(":/assets/icons/dot.png"), "Recording"));
    model->appendRow(this->buildItem(QIcon(":/assets/icons/keyboard.png"), "Keyboard Shortcuts"));
    model->appendRow(this->buildItem(QIcon(":/assets/icons/emoji.png"), "Feedback"));
    model->appendRow(this->buildItem(QIcon(":/assets/icons/about.png"), "Help & Support"));

    ui->sidebarSettingMenu->setModel(model);

    connect(ui->sidebarSettingMenu,
            SIGNAL(clicked(const QModelIndex)),
            this,
            SLOT(onSettingItemClick(QModelIndex))
    );
    this->ui->rightSidePage->setCurrentIndex(0);
    this->initStartup();
}

void SettingsDialog::onClickRecordingFolderButton() {
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    ui->recordingPath->setText(dir);
}


SettingsDialog::~SettingsDialog() {
    delete ui;
}

QStandardItem *SettingsDialog::buildItem(QIcon icon, QString text) {

    auto item = new QStandardItem(icon, text);

    return item;
}

void SettingsDialog::onSettingItemClick(QModelIndex index) {
    qDebug() << index.row();
    this->ui->rightSidePage->setCurrentIndex(index.row());
}

struct ScreenTableData {
    QString keyData;
    QString valueData;
};

void SettingsDialog::initStartup() {

    connect(ui->chooseRecordingFolder,
            SIGNAL(released()),
            this,
            SLOT(onClickRecordingFolderButton()));

    //general tab

    this->ui->useDualMonitorCheckbox->setEnabled(QGuiApplication::screens().count() > 1);



    // loading list of cameras
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
            foreach (const QCameraInfo &cameraInfo, cameras) {
            ui->webcamComboBox->addItem(cameraInfo.description());
        }


    // loading Screens
    QList<QScreen *> screens = QGuiApplication::screens();
    for (int x = 0; x < screens.count(); x++) {
        ui->desktopScreenComboBox->addItem(screens.at(x)->model());
    }
    auto primaryScreen = QGuiApplication::primaryScreen();
    QVector<ScreenTableData> data = {
            {"Name", primaryScreen->name()},
            {"Model",        primaryScreen->model()},
            {"Manufacturer", primaryScreen->manufacturer()},
            {"Orientation",  QString::number(primaryScreen->geometry().width()) + " X " +
                             QString::number(primaryScreen->geometry().height())},
            {"Refresh Rate", QString::number(primaryScreen->refreshRate()) + " Hz"},
            {"Serial Number", primaryScreen->serialNumber()},
    };

    QString screend = "";

    Q_FOREACH(const auto &item, data) {
        screend = screend + "<b>" + item.keyData + " </b> : " + item.valueData + "<br/>";
    }

    ui->monitorInformation->setText(screend);



//    foreach (const QScreen *screenInfo :  screens) {
//            ui->des
//    }

//    //loading list of mic
//    QList<QAudioDeviceInfo> microphones = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
//            foreach(const QAudioDeviceInfo &micInfo, microphones) {
//            ui->microphoneComboBox->addItem(micInfo.deviceName());
//        }
//
//
//    //loading list of Speaker
//    QList<QAudioDeviceInfo> speakers = QAudioDeviceInfo::availableDevices(QAudio::AudioOutput);
//            foreach(const QAudioDeviceInfo &speakerInfo, speakers) {
//            ui->speakerComboBox->addItem(speakerInfo.deviceName());
//        }


}
