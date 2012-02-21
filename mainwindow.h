#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QWidget>
#include <QToolBar>
#include <QTextEdit>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QAction* open_action;
    QAction* quit_action;
    QAction* save_action;
    QMenuBar* menubar;
    QMenu* filemenu;
    QToolBar* toolbar;
    QTextEdit* textedit;

};

#endif // MAINWINDOW_H
