#include "text_editor.h"
#include "ui_text_editor.h"

Text_Editor::Text_Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Text_Editor)
{
    ui->setupUi(this);
}

Text_Editor::~Text_Editor()
{
    delete ui;
}

void Text_Editor::on_ExitButton_clicked()
{
    e=new ExitDialog;
    e->show();
    this->close();
}


void Text_Editor::on_InsertButton_clicked()
{
    ins=new InsertWidget(ui->FileAddress->text());
    ins->show();
    this->close();
}

void Text_Editor::on_DeleteButton_clicked()
{
    del=new DeleteWidget(ui->FileAddress->text());
    del->show();
    this->close();
}

void Text_Editor::on_SearchButton_clicked()
{
    sfw=new SearchForWord(ui->FileAddress->text().toStdString());
    sfw->show();
    this->close();
}

void Text_Editor::on_ReplaceButton_clicked()
{
    rw=new ReplaceWidget(ui->FileAddress->text().toStdString());
    rw->show();
    this->close();
}

void Text_Editor::on_StatisticsButton_clicked()
{
    fs=new FileStatistics;
    int l,c,w;

    fs->fileCount(ui->FileAddress->text().toStdString(),c,w,l);

    QString qs="File Contains \n",qss;
    qs+=QString::number(l);
    qs+=" Lines\n";

    qs+=QString::number(w);
    qs+=" Words\n";

    qs+=QString::number(c);
    qs+=" Characters\n\n\n";

    qs+="File Information \nLast modification date \n";
//    qs+=QString::fromStdString(fs->fileInfo(ui->FileAddress->text().toStdString()));

    QLabel *ll=new QLabel(qs);
    ll->show();
// problem because of system
}

void Text_Editor::on_ShowButton_clicked()
{
    sf=new ShowFile(ui->FileAddress->text().toStdString());
    QString qs=sf->printFile();

    if(qs!=" ")
    {
        QLabel *ll=new QLabel(qs);
        ll->show();
    }

}
