#ifndef  seeallstuinform_H
#define  seeallstuinform_H

#include <QWidget>

namespace Ui {
class  seeallstuinform;
}

class  seeallstuinform : public QWidget
{
    Q_OBJECT

public:
    explicit  seeallstuinform(QWidget *parent = 0);
    ~ seeallstuinform();

private slots:
    void on_backButton_clicked();

private:
    Ui:: seeallstuinform *ui;
};

#endif //  seeallstuinform_H
