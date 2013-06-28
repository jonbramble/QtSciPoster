#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    posterwebpage = new PosterWebPage();
    connect(ui->actionRenderPage,SIGNAL(triggered()),this,SLOT(render_page()));
    connect(ui->actionRenderImage,SIGNAL(triggered()),posterwebpage,SLOT(renderImage()));
    connect(ui->actionNew_Project,SIGNAL(triggered()),this,SLOT(newProject()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->actionImage_Rendering,SIGNAL(triggered()),this,SLOT(openRenderSettingsDialog()));

    QNetworkProxy proxy;
    proxy.setType(QNetworkProxy::HttpProxy);
    proxy.setHostName("www-cache.leeds.ac.uk");
    proxy.setPort(3128);
    QNetworkProxy::setApplicationProxy(proxy);

    ui->webView->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    inspector = new QWebInspector;
    inspector->setPage(ui->webView->page());
    inspector->setVisible(false);

    ui->webView->show();


}

void MainWindow::render_page(){

    //QUrl base = QUrl::fromLocalFile(filename);
    QUrl base = QUrl("http://localhost/catgrid/catgrid.html",QUrl::TolerantMode);
    //qDebug() << filename;

    ui->webView->load(base);
    posterwebpage->mainFrame()->load(base);
    ui->tabWidget->setCurrentWidget(ui->tabWeb);

}

void MainWindow::newProject(){
    // save a project file and set the current working directory
    // load base files into the project and load them into the tree
    qDebug() << "New project";

    //model = new ProjectModel(0);
    //ui->treeView->setModel( model );

    QFileDialog dialog;

    dialog.setFileMode(QFileDialog::ExistingFile);
    if (dialog.exec()) {
        QStringList filenames = dialog.selectedFiles();
        //starting_dir = dialog.directory();
        filename = filenames[0];
    }
    else
    {

    }
}

void MainWindow::openRenderSettingsDialog(){
    RenderSettingsDialog *rendersettingsdialog = new RenderSettingsDialog(this);
    rendersettingsdialog->show();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete posterwebpage;
}


