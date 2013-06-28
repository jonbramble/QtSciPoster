#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QWebInspector>
#include <QNetworkProxy>
#include <QGraphicsWebView>
#include <QtWebKitWidgets/QtWebKitWidgets>
#include <QDir>

#include "projectmodel.h"
#include "posterwebpage.h"
#include "rendersettingsdialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void render_page();
    void newProject();
    void openRenderSettingsDialog();
    
private:
    Ui::MainWindow *ui;
    QWebInspector *inspector;
    ProjectModel *model;
    PosterWebPage *posterwebpage;


    QDir starting_dir;
    QString filename;

};

#endif // MAINWINDOW_H
