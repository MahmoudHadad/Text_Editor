#include "deletewidget.h"
#include "ui_deletewidget.h"

DeleteWidget::DeleteWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteWidget)
{
    ui->setupUi(this);
}

DeleteWidget::DeleteWidget(QString qs,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteWidget)
{
    ui->setupUi(this);
    fileAddress=qs;
}

DeleteWidget::~DeleteWidget()
{
    delete ui;
}

void DeleteWidget::on_DeleteButton_clicked()
{
    string filename=fileAddress.toStdString();
    int start=ui->Startline->text().toInt();
    int end=ui->Endline->text().toInt();

    ui->Resulelabel->setText(QString::number(deleteLine(filename,start,end)));
    sf=new ShowFile(filename);
    QString qs=sf->printFile();
    if(qs!=" ")
    {
        QLabel *ll=new QLabel(qs);
        ll->show();
    }
}

int DeleteWidget::deleteLine (string filename, int start, int end)
{
    ifstream file ;
        file.open(  filename.c_str() );
        /// check open or not
         if( file.fail() )
         {
            QLabel *ll=new QLabel("\n\n Error in opening The File\n\n\n\n ");
            ll->show();
            this->close();
            return 0;
         }

         if(start < 0) return 0;

              // Load file
              vector<string>Data;
              string line;
              while( !file.eof() )
             {
                 getline( file , line);
                 Data.push_back(line);
             }

             file.close();
              /// to avoid the start is 0 and make a constant start from 1 to the end of the file
              if(start == 0) start = 1;

             /// check nmber of lines and the start
             if( start > Data.size() ) return 0;
             /// check end and the number of lines
             if(end > Data.size() ) end = Data.size() ;
             ///check end and start
             if(end < start ) end = start ;
             //////////////////////////////////////////
             // Delete the selected lines
             start--;
             end--;
             Data.erase(Data.begin()+start,Data.begin()+end+1);

             /// print vector on file
             ofstream myfile ;
             myfile.open(  filename.c_str() );

             for(int i=0 ; i<Data.size()  ;i++ )
             {
                 myfile<<Data[i];
                 if(i<Data.size()-1)myfile<<endl;
             }

             /// close the file
             myfile.close();
             return (end-start+1 );
}

void DeleteWidget::on_pushButton_clicked()
{
    text=new Text_Editor;
    text->show();
    this->close();
}
