#ifndef HTMLDOCUMENT_H
#define HTMLDOCUMENT_H

#include <QTextEdit>
#include <QFile>
#include <QFileDialog>
#include <QTextDocumentWriter>
//#include <srchiliteqt/Qt4SyntaxHighlighter.h>
//#include <srchilite/versions.h>

class HtmlDocument : public QTextEdit
{
    Q_OBJECT
public:
    explicit HtmlDocument(QWidget *parent = 0);
    ~HtmlDocument();
    
signals:
    
public slots:
    void fileOpen();
    bool fileSave();
    bool fileSaveAs();
    void addBoilerPlateHtml();

private:
    //srchiliteqt::Qt4SyntaxHighlighter *highlighter_html;
    bool load(const QString &f);
    void setCurrentFileName(const QString &fileName);

    QString filename;
    
};

#endif // HTMLDOCUMENT_H
