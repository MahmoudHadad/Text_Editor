#include "exitdialog.h"
#include "ui_exitdialog.h"

ExitDialog::ExitDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExitDialog)
{
    ui->setupUi(this);
}

ExitDialog::~ExitDialog()
{
    delete ui;
}

void ExitDialog::on_YESButton_clicked()
{
    this->close();
}

void ExitDialog::on_NOButton_clicked()
{
    text=new Text_Editor;
    text->show();
    this->close();
}

