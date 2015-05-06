class Text_Editor;
#ifndef REPLACEWIDGET_H
#define REPLACEWIDGET_H
#include "showfile.h"
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
class ReplaceWidget;
}

class ReplaceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReplaceWidget(QWidget *parent = 0);
    explicit ReplaceWidget(string s,QWidget *parent = 0);
    ~ReplaceWidget();

private slots:
    void on_ReplaceButton_clicked();
    void replace (string filename, string word, string newWord);
    void on_BackButton_clicked();

private:
    Ui::ReplaceWidget *ui;
    string fileName;
    ShowFile *sf;
    Text_Editor *text;
};

#endif // REPLACEWIDGET_H
