#include "rendersettingsdialog.h"
#include "ui_rendersettingsdialog.h"

RenderSettingsDialog::RenderSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RenderSettingsDialog)
{
    ui->setupUi(this);
}

RenderSettingsDialog::~RenderSettingsDialog()
{
    delete ui;
}
