#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QInputDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addTask(){
    bool ok;
    QString name = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"), &ok);
    if(ok && !name.isEmpty()){
        qDebug() << "Adding new task";
        Task* task = new Task(name);
        connect(task, &Task::removed,
                this, &MainWindow::removeTask);
        connect(task, &Task::statusChanged,this,
               &MainWindow::taskStatusChanged);
        myTasks.append(task);
        ui->taskLayout->addWidget(task);
        updateStatus();
    }

}
void MainWindow::removeTask(Task* task)
{
    myTasks.removeOne(task);
    ui->taskLayout->removeWidget(task);
    task->setParent(0);
    //Es necesario para que task no se quede con centralWidget como padre
    delete task;
    updateStatus();
}
void MainWindow::taskStatusChanged(Task* task)
{
    updateStatus();
}
void MainWindow::updateStatus()
{
    int completedCount = 0;
    for(auto t : myTasks) {
        if (t->isCompleted()) {
            completedCount++;
        }
    }
    int todoCount = myTasks.size() - completedCount;
    ui->statusLabel->setText(
        QString("Status: %1 todo / %2 completed")
            .arg(todoCount)
            .arg(completedCount));
}
