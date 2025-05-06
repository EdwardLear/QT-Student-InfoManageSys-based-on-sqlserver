#ifndef MANAGER_H
#define MANAGER_H
#include <QWidget>

namespace Ui {
class manager;
}

class manager : public QWidget
{
    Q_OBJECT

public:
    explicit manager(QWidget *parent = 0);
    ~manager();

private slots:
    void on_pushButton_9_clicked();

    void on_userloginButton_clicked();

    void on_stu_inform_guanlipushButton_clicked();

    void on_dorm_guanliButton_clicked();

    void on_award_managepushButton_clicked();

    void on_scoremanagepushButton_clicked();

    void on_course_manageButton_clicked();

    void on_class_managepushButton_clicked();

    void on_feemanagepushButton_clicked();

private:
    Ui::manager *ui;
};
#endif // MANAGER_H
