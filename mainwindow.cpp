#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    new_action = new QAction(tr("&New..."), this);
    menubar = menuBar();
    filemenu = menubar->addMenu(tr("&File"));

    new_action->setShortcut(tr("Ctrl+N"));
    new_action->setToolTip(tr("New file"));;
    new_action->setStatusTip(tr("New file"));

    filemenu->addAction(new_action);


}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);

    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
