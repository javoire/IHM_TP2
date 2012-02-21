#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    /* Actions */
    createActions();

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

void MainWindow::createActions()
{
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

    connect(open_action, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(save_action, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(quit_action, SIGNAL(triggered()), this, SLOT(quitApp()));

}

void MainWindow::openFile()
{    
    filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/stud/users/promo12/dahl/IHM/TP2_QT", tr("HTML Files (*.html)"));

    /* read file */
    QFile file(filename);
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

    /* read contentns */
     QTextStream in(&file);
     htmlcontent = "";
     while (!in.atEnd()) {
        QString line = in.readLine();
        htmlcontent += qPrintable(line);
    }

    /* output to textedit */
    textedit->setHtml(htmlcontent);
}

void MainWindow::saveFile()
{
    filename = QFileDialog::getSaveFileName(this, tr("Save File"), "/stud/users/promo12/dahl/IHM/TP2_QT", tr("HTML Files (*.html)"));

    /* read file */
    QFile file(filename);
         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

    /* write to file */
    QTextStream out(&file);
    QString outputcontent = textedit->toHtml();
    out << outputcontent;

    cout << qPrintable(filename) << endl;
}

void MainWindow::quitApp()
{
    cout << "Bye bye!" << endl;
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
