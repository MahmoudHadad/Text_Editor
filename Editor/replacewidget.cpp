#include "replacewidget.h"
#include "ui_replacewidget.h"

ReplaceWidget::ReplaceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReplaceWidget)
{
    ui->setupUi(this);
}

ReplaceWidget::ReplaceWidget(string s,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReplaceWidget)
{
    ui->setupUi(this);
    fileName=s;
}

ReplaceWidget::~ReplaceWidget()
{
    delete ui;
}

void ReplaceWidget::on_ReplaceButton_clicked()
{
    replace(fileName,ui->oldLine->text().toStdString(),ui->newLine->text().toStdString());
    ui->doneLabel->setText("\tReplacing Operation Done");
    sf=new ShowFile(fileName);
    QLabel *qll=new QLabel(sf->printFile());
    qll->show();
}

void ReplaceWidget::replace (string filename, string word, string newWord)
{
    ifstream myfile;
        myfile.open(filename.c_str());

        if(myfile.fail())
        {
            QLabel *ql=new QLabel("\n\n\nError: file not found please make sure of the entered address\n\n\n");
            ql->show();
            return ;
        }

        string line,linewords;
        vector<string>file;

        while(!myfile.eof())
        {
            getline(myfile,line);

            if(line.find(word)!=string::npos)
            {
                stringstream ss(line);
                ss>>linewords;

                if(linewords==word)
                line=newWord;
                else line=linewords;

                while(ss>>linewords)
                {
                    if(linewords==word)	line=line+" "+newWord;

                    else line=line+" "+linewords;
                }
            }
            file.push_back(line);
        }
        myfile.close();

        ofstream printfile;
        printfile.open(filename.c_str());

        for(int i=0;i<file.size();i++)
        {
            printfile<<file[i];
            if(i<file.size()-1)printfile<<endl;
        }
        printfile.close();
}

void ReplaceWidget::on_BackButton_clicked()
{
    text=new Text_Editor;
    text->show();
    this->close();
}
