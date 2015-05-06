class Text_Editor;
#ifndef EXITDIALOG_H
#define EXITDIALOG_H
#include <QLabel>
#include <QWidget>
#include "text_editor.h"

namespace Ui {
class ExitDialog;
}

class ExitDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ExitDialog(QWidget *parent = 0);
    ~ExitDialog();

private slots:
    void on_YESButton_clicked();

    void on_NOButton_clicked();

private:
    Ui::ExitDialog *ui;
    Text_Editor *text;
};

#endif // EXITDIALOG_H
