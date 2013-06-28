#include "posterwebpage.h"

PosterWebPage::PosterWebPage(QObject *parent) :
    QWebPage(parent)
{  
    const int width = 841; // need to change this for landscape
    this->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
    this->mainFrame()->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
    //this->setViewportSize(QSize(width,(1/1.4)*width));  //landscape
    this->setViewportSize(QSize(width,1.4*width));  //portrait

    qreal zoom = 7;              //this is poster size in inches * target dpi
    this->mainFrame()->setZoomFactor(zoom);
}

PosterWebPage::~PosterWebPage(){
}

void PosterWebPage::renderImage(){
    QProgressDialog progress("Rendering Image","Abort Render",0,100);
    progress.setWindowModality(Qt::WindowModal);
    progress.setValue(0);
    progress.show();

    // taken from webcapture qt graphics-dojo
    QSize size = this->mainFrame()->contentsSize();
    image = new QImage(size,QImage::Format_ARGB32_Premultiplied); // check what this is
    image->fill(Qt::transparent);

    QPainter p(image);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setRenderHint(QPainter::TextAntialiasing, true);
    p.setRenderHint(QPainter::SmoothPixmapTransform, true);
    this->setViewportSize(this->mainFrame()->contentsSize());
    this->mainFrame()->render(&p);
    p.end();

    #if QT_VERSION < 0x040500
    // scale, since we don't have full page zoom
    qreal factor = static_cast<qreal>(m_zoom) / 100.0;
    image = image.scaled(size * factor, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    #endif

    image->save("/home/DS/phyjpb/test.png");
    //image->save("/home/jon/test.png");
    //emit finished();

    delete image;

    progress.setValue(100);

}
