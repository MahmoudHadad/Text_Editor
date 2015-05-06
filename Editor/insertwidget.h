class Text_Editor;
#ifndef INSERTWIDGET_H
#define INSERTWIDGET_H
#include "showfile.h"
#include <String>
#include <iostream>
#include <QString>
#include <fstream>
#include <sstream>
#include <vector>
#include <QWidget>
#include<QLabel>
#include "text_editor.h"
using namespace std;

namespace Ui {
class InsertWidget;
}

class InsertWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InsertWidget(QWidget *parent = 0);
    ~InsertWidget();
    explicit InsertWidget(QString qs,QWidget *parent = 0);
private slots:
    void on_InsertButton_clicked();
    void insertLine (std::string filename, int position);

    void on_BackButton_clicked();

private:
    Ui::InsertWidget *ui;
    QString fileAddress;
    ShowFile *sf;
    Text_Editor *text;
};

#endif // INSERTWIDGET_H
