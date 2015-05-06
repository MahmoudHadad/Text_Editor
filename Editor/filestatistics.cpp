#include "filestatistics.h"

FileStatistics::FileStatistics()
{
}
void FileStatistics::fileCount (string filename, int& chars, int& words, int& lines)
{
    chars=words=lines=0;
    string line,word;
    ifstream myfile;

    myfile.open( filename.c_str() );
    if(myfile.fail())
    {
        QLabel *ll=new QLabel("\n\n Error in opening The File\n\n\n\n ");
        ll->show();
        return ;
    }

    while(!myfile.eof())
        {
            getline(myfile, line);
            lines++;
            chars+=line.size();
            stringstream ss(line);
            while(ss>>word)
            {
                words++;
            }
        }
        myfile.close();

}

string FileStatistics::fileInfo(string filename)
{
    ifstream myfile;

    string data,temp;

    temp="C:\temp.txt";

    vector<string> datavec;
    filename = "dir " + filename + " > " + temp ;
    system(filename.c_str());
    myfile.open(temp.c_str());

    while(!myfile.eof())
    {
        getline(myfile, data);
        datavec.push_back(data);
    }
    data = datavec[5] + "\n" + datavec[6];
    myfile.close();
    return data;
}

