#ifndef dormanage_H
#define dormanage_H

#include <QWidget>

namespace Ui {
class dormanage;
}

class dormanage : public QWidget
{
    Q_OBJECT

public:
    explicit dormanage(QWidget *parent = 0);
    ~dormanage();

private slots:
    void on_dorm_queryButton_clicked();

    void on_dorm_addButton_clicked();

    void on_dorm_deleteButton_clicked();

    void on_updateButton_clicked();

    void on_dorm_backButton_clicked();

    void on_see_all_dorm_Button_clicked();

private:
    Ui::dormanage *ui;
};

#endif // dormanage_H
