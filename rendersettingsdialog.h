#ifndef RENDERSETTINGSDIALOG_H
#define RENDERSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class RenderSettingsDialog;
}

class RenderSettingsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit RenderSettingsDialog(QWidget *parent = 0);
    ~RenderSettingsDialog();
    
private:
    Ui::RenderSettingsDialog *ui;
};

#endif // RENDERSETTINGSDIALOG_H
