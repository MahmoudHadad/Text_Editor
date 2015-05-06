#ifndef FILESTATISTICS_H
#define FILESTATISTICS_H
#include <String>
#include <QString>
#include <fstream>
#include <sstream>
#include <vector>
#include <QWidget>
#include<QLabel>

using namespace std;


class FileStatistics
{
public:
    FileStatistics();

    void fileCount (string filename, int& chars, int& words, int& lines);
    string fileInfo(string filename);
};

#endif // FILESTATISTICS_H
