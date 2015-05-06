#include "showfile.h"

ShowFile::ShowFile()
{
}
ShowFile::ShowFile(string fn)
{
    fileName=fn;
}

QString ShowFile::printFile()
{
    string line;
        ifstream myfile;
        myfile.open ( fileName.c_str() );
        if(myfile.fail())
        {
            QLabel *ll=new QLabel("\n\n Error in opening The File\n\n\n\n ");
            ll->show();
            return " ";
        }

    string fileData="\tContenents of the file\n";
    while(!myfile.eof())
        {
            getline(myfile,line);
            fileData+=line;
            fileData+="\n";
        }
        myfile.close();

      //  return QString::fromUtf8(fileData.c_str());

        return QString::fromStdString(fileData);
}
