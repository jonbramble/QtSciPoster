#include "cssdocument.h"

CssDocument::CssDocument(QWidget *parent) :
    QTextEdit(parent)
{
    //highlighter_css = new srchiliteqt::Qt4SyntaxHighlighter(this->document());
    //highlighter_css->init("css.lang");
}

CssDocument::~CssDocument()
{
    //delete highlighter_css;
}

bool CssDocument::load(const QString &f)
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

void CssDocument::fileOpen(){
    QString fn = QFileDialog::getOpenFileName(this,tr("Open File..."),
                                              QString(),tr("CSS files (*.css);;All Files (*)"));

    if (!fn.isEmpty())
        load(fn);

}

bool CssDocument::fileSave()
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

bool CssDocument::fileSaveAs()
{
    QString fn = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                              QString(), tr("CSS Files (*.css);;All Files (*)"));
    if (fn.isEmpty())
        return false;
    if (! (fn.endsWith(".css", Qt::CaseInsensitive)))
        fn += ".css"; // default
    filename = fn;
    return fileSave();
}
