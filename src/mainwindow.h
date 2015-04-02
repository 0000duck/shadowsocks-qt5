/*
 * MainWindow class
 * Lots of variables, functions are included in this class
 * Copyright 2014-2015 Symeon Huang <hzwhuang@gmail.com>
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QCloseEvent>
#include "connection.h"

#ifdef UBUNTU_UNITY
#undef signals
extern "C"
{
#include <libappindicator/app-indicator.h>
#include <gtk/gtk.h>
}
#define signals public
#endif

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    void minimizeToSysTray();

private slots:
    inline void onAbout() { QMessageBox::about(this, tr("About"), aboutText); }
    void showWindow();
    void onSystrayActivated(QSystemTrayIcon::ActivationReason);

private:
    QString jsonconfigFile;
    QMenu *systrayMenu;
    QSystemTrayIcon *systray;
    static const QString aboutText;
    Ui::MainWindow *ui;
#ifdef UBUNTU_UNITY
    GtkWidget *showItem;
#endif
    void createSystemTray();
    void showNotification(const QString &);
    void blockChildrenSignals(bool);

protected:
    void closeEvent(QCloseEvent *);
};

#endif // MAINWINDOW_H
