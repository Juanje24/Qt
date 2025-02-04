#include "Mainwindow.h"
#include "./ui_MainWindow.h"
#include "sysinfo.h"
#include <QLayout>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    mCpuWidget(this),
    mMemoryWidget(this)
{
    ui->setupUi(this);
    SysInfo::instance().init();
    QWidget *mainWidget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(mainWidget);
    layout->addWidget(&mCpuWidget);
    layout->addWidget(&mMemoryWidget);
    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

