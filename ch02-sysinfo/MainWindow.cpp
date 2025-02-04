#include "Mainwindow.h"
#include "./ui_MainWindow.h"
#include "sysinfo.h"
#include <QLayout>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    mCpuWidget(this)
{
    ui->setupUi(this);
    SysInfo::instance().init();
    ui->centralwidget->layout()->addWidget(&mCpuWidget);
    ui->centralwidget->layout()->addWidget(&mMemoryWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

