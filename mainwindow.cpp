#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    /* Actions */
    open_action = new QAction(tr("&Open..."), this);
    open_action->setShortcut(tr("Ctrl+N"));
    open_action->setToolTip(tr("Open file"));;
    open_action->setStatusTip(tr("Open file"));

    save_action = new QAction(tr("&Save..."), this);
    save_action->setShortcut(tr("Ctrl+N"));
    save_action->setToolTip(tr("Save file"));;
    save_action->setStatusTip(tr("Save file"));

    quit_action = new QAction(tr("&Quit..."), this);
    quit_action->setShortcut(tr("Ctrl+N"));
    quit_action->setToolTip(tr("Quit file"));;
    quit_action->setStatusTip(tr("Quit file"));

    /* Menu bars */
    menubar = menuBar();
    toolbar = addToolBar(tr("File"));

    filemenu = menubar->addMenu(tr("&File"));

    /* Add actions */
    filemenu->addAction(open_action);
    filemenu->addAction(save_action);
    filemenu->addAction(quit_action);

    toolbar->addAction(open_action);
    toolbar->addAction(save_action);
    toolbar->addAction(quit_action);

     /* Text edit widget */
    textedit = new QTextEdit(this);
    setCentralWidget(textedit);


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
