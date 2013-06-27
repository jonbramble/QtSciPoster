#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    posterwebpage = new PosterWebPage();
    connect(ui->actionRenderPage,SIGNAL(triggered()),this,SLOT(render_page()));
    connect(ui->actionOpenHTML,SIGNAL(triggered()),ui->textEditHTML,SLOT(fileOpen()));
    connect(ui->actionSaveHTML,SIGNAL(triggered()),ui->textEditHTML,SLOT(fileSave()));
    connect(ui->actionRenderImage,SIGNAL(triggered()),posterwebpage,SLOT(renderImage()));

    connect(ui->actionOpen_CSS, SIGNAL(triggered()),ui->textEditCSS,SLOT(fileOpen()));
    connect(ui->actionSave_CSS, SIGNAL(triggered()),ui->textEditCSS,SLOT(fileSave()));

    connect(ui->actionNew_Project,SIGNAL(triggered()),this,SLOT(newProject()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));

     ui->tabWidget->setCurrentWidget(ui->tabHTML);

     //ui->webView->load(QUrl("http://localhost:3000"));

     ui->webView->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);

     QNetworkProxy proxy;

     proxy.setType(QNetworkProxy::HttpProxy);
     proxy.setHostName("www-cache.leeds.ac.uk");
     proxy.setPort(3128);

     QNetworkProxy::setApplicationProxy(proxy);

     inspector = new QWebInspector;
     inspector->setPage(ui->webView->page());
     inspector->setVisible(true);


     ui->webView->show();


}

void MainWindow::render_page(){
    QString html = ui->textEditHTML->toPlainText();
    QUrl base = QUrl::fromLocalFile(filename);
    //QUrl base = QUrl("http://localhost/peptide_poster/poster.html",QUrl::TolerantMode);
    qDebug() << filename;

    //ui->webView->setHtml(html,base);             // set the document txt
    ui->webView->load(base);
    //posterwebpage->mainFrame()->setHtml(html,base);
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

void MainWindow::fontSelection(){
    // need to know which form I'm on

}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete posterwebpage;
}


