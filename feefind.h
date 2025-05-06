#ifndef feefind_H
#define feefind_H

#include <QWidget>

namespace Ui {
class feefind;
}

class feefind : public QWidget
{
    Q_OBJECT

public:
    explicit feefind(QWidget *parent = 0);
    ~feefind();

private slots:
    void on_stu_money_queryButton_clicked();

    void on_stu_money_backButton_clicked();

private:
    Ui::feefind *ui;
};

#endif // feefind_H
