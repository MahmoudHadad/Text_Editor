#include "searchforword.h"
#include "ui_searchforword.h"

SearchForWord::SearchForWord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchForWord)
{
    ui->setupUi(this);
}

SearchForWord::SearchForWord(string s,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchForWord)
{
    fileName=s;
    ui->setupUi(this);
}

SearchForWord::~SearchForWord()
{
    delete ui;
}

string SearchForWord::search (string filename, string word)
{
    ifstream myfile;
    myfile.open(filename.c_str());

    if(myfile.fail())
    {
        return "\n\nError programe can't open the file make sure of the file's address\n\n\n";
    }

    int numOfLines=0;
    string line;

    // Check if we search for a part of word

        if(word[word.size()-1]=='*')
        {
            word.erase(word.size()-1,1);

            string wordInLine;
            bool wordFound;

            while(!myfile.eof())
            {
                wordFound=false;
                numOfLines++;

                getline(myfile,line);
                // read words of the line
                stringstream ss(line);
                while(ss>>wordInLine)
                {
                    if(wordInLine.find(word)==0)
                    {
                        wordFound=true;
                        break;
                    }
                }

                if(wordFound)
                {
                    myfile.close();
                    stringstream ss;
                    ss<<numOfLines;
                    return "\n\nI found the word " + wordInLine + " at line " + ss.str()+ ": \n" +line + "\n\n\n";
                }
            }

            myfile.close();
            return "\n\nWord: "+word+" not found in the file "+filename+"\n\n\n";
        }
        ///////////////////////////
        string wordInLine;
            while(!myfile.eof())
            {
                numOfLines++;
                getline(myfile,line);
                // read words of the line
                stringstream ss(line);
                while(ss>>wordInLine)
                {
                    if(word==wordInLine)
                    {
                        stringstream ss;
                        ss<<numOfLines;
                        myfile.close();
                        return "\n\nI found the word "+word+" at line "+ss.str()+": \n"+line+"\n\n\n";
                    }
                }
            }

            myfile.close();
            return "\n\nWord: "+word+" not found in the file "+filename+"\n\n\n";
}

void SearchForWord::on_SearchButton_clicked()
{
    string res=search(fileName,ui->SearchLine->text().toStdString());
    QString qs=QString::fromStdString(res);
    ui->ResultLabel->setText(qs);
}

void SearchForWord::on_BackButton_clicked()
{
    text=new Text_Editor;
    text->show();
    this->close();
}
