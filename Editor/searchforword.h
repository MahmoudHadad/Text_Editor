class Text_Editor;
#ifndef SEARCHFORWORD_H
#define SEARCHFORWORD_H
#include <String>
#include <QString>
#include <fstream>
#include <sstream>
#include <vector>
#include <QWidget>
#include<QLabel>
#include "text_editor.h"

using namespace std;
#include <QWidget>

namespace Ui {
class SearchForWord;
}

class SearchForWord : public QWidget
{
    Q_OBJECT

public:
    explicit SearchForWord(QWidget *parent = 0);
    explicit SearchForWord(string s,QWidget *parent = 0);
    ~SearchForWord();

    string search (string filename, string word);
private slots:
    void on_SearchButton_clicked();

    void on_BackButton_clicked();

private:
    Ui::SearchForWord *ui;
    string fileName;
    Text_Editor *text;
};

#endif // SEARCHFORWORD_H


