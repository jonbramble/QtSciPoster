#ifndef CSSDOCUMENT_H
#define CSSDOCUMENT_H

#include <QTextEdit>
#include <QFile>
#include <QFileDialog>
#include <QTextDocumentWriter>
//#include <srchiliteqt/Qt4SyntaxHighlighter.h>
//#include <srchilite/versions.h>

class CssDocument : public QTextEdit
{
    Q_OBJECT
public:
    explicit CssDocument(QWidget *parent = 0);
    ~CssDocument();
    
signals:
    
public slots:
    void fileOpen();
    bool fileSave();
    bool fileSaveAs();

private:
    //srchiliteqt::Qt4SyntaxHighlighter *highlighter_css;

    bool load(const QString &f);
    void setCurrentFileName(const QString &fileName);

    QString filename;
    
};

#endif // CSSDOCUMENT_H
