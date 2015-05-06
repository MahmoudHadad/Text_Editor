#ifndef SHOWFILE_H
#define SHOWFILE_H
#include <String>
#include <QString>
#include <fstream>
#include <sstream>
#include <vector>
#include <QWidget>
#include<QLabel>

using namespace std;
class ShowFile
{
    string fileName;
public:
    ShowFile();
    ShowFile(string fn);
    QString printFile();
};

#endif // SHOWFILE_H
