#include "htmldocument.h"

HtmlDocument::HtmlDocument(QWidget *parent) :
    QTextEdit(parent)
{
    //highlighter_html = new srchiliteqt::Qt4SyntaxHighlighter(this->document());
    //highlighter_html->init("html.lang");
}

HtmlDocument::~HtmlDocument()
{
    //delete highlighter_html;
}

void HtmlDocument::addBoilerPlateHtml(){
    load("boiler.html");
}

bool HtmlDocument::load(const QString &f)
{
    if (!QFile::exists(f))
            return false;
        QFile file(f);
        if (!file.open(QFile::ReadOnly))
            return false;

        QByteArray data = file.readAll();
        QString str = QString::fromLocal8Bit(data);

        this->setPlainText(str);

        filename = f;
        return true;
}

void HtmlDocument::fileOpen(){
    QString fn = QFileDialog::getOpenFileName(this,tr("Open File..."),
                                              QString(),tr("HTML files (*.htm *.html);;All Files (*)"));

    if (!fn.isEmpty())
        load(fn);
   // QDir currentDir =

}

bool HtmlDocument::fileSave()
{
    if (filename.isEmpty())
        return fileSaveAs();

    QTextDocumentWriter writer(filename);
    writer.setFormat("plaintext");
    bool success = writer.write(this->document());
    if (success)
        this->document()->setModified(false);
    return success;
}

bool HtmlDocument::fileSaveAs()
{
    QString fn = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                              QString(), tr("HTML-Files (*.htm *.html);;All Files (*)"));
    if (fn.isEmpty())
        return false;
    if (! (fn.endsWith(".htm", Qt::CaseInsensitive)) || (fn.endsWith(".html", Qt::CaseInsensitive)) )
        fn += ".html"; // default
    filename = fn;
    return fileSave();
}
