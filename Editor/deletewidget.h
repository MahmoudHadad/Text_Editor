class Text_Editor;
#ifndef DELETEWIDGET_H
#define DELETEWIDGET_H
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
class DeleteWidget;
}

class DeleteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteWidget(QWidget *parent = 0);

    ~DeleteWidget();
    explicit DeleteWidget(QString qs ,QWidget *parent = 0);
private slots:
    void on_DeleteButton_clicked();
    int deleteLine (string filename, int start, int end);

    void on_pushButton_clicked();

private:
    Ui::DeleteWidget *ui;
    QString fileAddress;
    ShowFile *sf;
    Text_Editor *text;
};

#endif // DELETEWIDGET_H
