#include "insertwidget.h"
#include "ui_insertwidget.h"

InsertWidget::InsertWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InsertWidget)
{
    ui->setupUi(this);
}

InsertWidget::~InsertWidget()
{
    delete ui;
}

InsertWidget::InsertWidget(QString qt, QWidget *parent)
    :
        QWidget(parent),
        ui(new Ui::InsertWidget)
    {
        ui->setupUi(this);
        fileAddress=qt;
    }
//////////////////////////////////////////////////////////////////// Insert Button
void InsertWidget::on_InsertButton_clicked()
{
    string filename=fileAddress.toStdString();

    int pos=ui->positionToInsert->text().toInt();
    insertLine(filename,pos);
    sf=new ShowFile(filename);
    QString qs=sf->printFile();
    if(qs!=" ")
    {
        QLabel *ll=new QLabel(qs);
        ll->show();
    }
}
//////////////////////////////////////////////////////////////////////
void InsertWidget::insertLine (std::string filename, int position)
{
    ifstream file (  filename.c_str()  );


    if ( file.fail() )
        {
            QLabel *l=new QLabel;
            l->setText("\n\n Error in opening The File\n\n\n\n ");
            l->show();
            this->close();
            return;
        }

    if(position <= 0) position=1 ;

    // load file
    vector<string>Data;
    string line;
    while(!file.eof())
    {
         getline( file , line );
         Data.push_back(line);
    }

    if(position>Data.size())position=Data.size()+1;
    // insert lines
    position --;

    std:: string ins=ui->textToInsert->toPlainText().toStdString();
    Data.insert(Data.begin()+position,ins);

    file.close();

    ofstream myfile ;
    myfile.open(  filename.c_str() );

    for(int i=0 ; i<Data.size()  ;i++ )
    {
        myfile<<Data[i];
        if(i<Data.size()-1)myfile<<endl;
    }

    /// close the file
    myfile.close();

}

void InsertWidget::on_BackButton_clicked()
{
    text=new Text_Editor;
    text->show();
    this->close();
}
