#ifndef classfind_H
#define classfind_H

#include <QWidget>

namespace Ui {
class classfind;
}

class classfind : public QWidget
{
    Q_OBJECT

public:
    explicit classfind(QWidget *parent = 0);
    ~classfind();

private slots:
    void on_stu_find_classqueryButton_clicked();

    void on_stu_classfindbackButton_clicked();

private:
    Ui::classfind *ui;
};

#endif // classfind_H
