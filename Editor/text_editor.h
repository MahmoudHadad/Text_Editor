class ExitDialog;
class InsertWidget;
class DeleteWidget;
class SearchForWord;
class ReplaceWidget;


#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H
#include "replacewidget.h"
#include "searchforword.h"
#include "filestatistics.h"
#include "showfile.h"
#include "deletewidget.h"
#include "insertwidget.h"
#include "exitdialog.h"
#include <QMainWindow>

namespace Ui {
class Text_Editor;
}

class Text_Editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Text_Editor(QWidget *parent = 0);
    ~Text_Editor();

private slots:
    void on_ExitButton_clicked();

    void on_InsertButton_clicked();

    void on_DeleteButton_clicked();

    void on_SearchButton_clicked();

    void on_ReplaceButton_clicked();

    void on_StatisticsButton_clicked();

    void on_ShowButton_clicked();

private:
    Ui::Text_Editor *ui;
    ExitDialog *e;
    InsertWidget *ins;
    DeleteWidget *del;
    ShowFile *sf;
    FileStatistics *fs;
    SearchForWord *sfw;
    ReplaceWidget *rw;
};

#endif // TEXT_EDITOR_H
