#ifndef POSTERWEBPAGE_H
#define POSTERWEBPAGE_H

#include <QWebPage>
#include <QWebFrame>
#include <QDebug>
#include <QPainter>
#include <QProgressDialog>
#include <tr1/functional>

class PosterWebPage : public QWebPage
{
    Q_OBJECT
public:
    explicit PosterWebPage(QObject *parent = 0);
    ~PosterWebPage();

public slots:
    void renderImage();

private:
    QImage *image;
};

#endif // POSTERWEBPAGE_H
