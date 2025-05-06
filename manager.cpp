#include "manager.h"
#include "ui_manager.h"
#include"globle.h"
#include"mainwindow.h"
#include "userlogin.h"
#include "stuinformanage.h"
#include "dormanage.h"
#include "awardmanage.h"
#include "scoremanage.h"
#include "coursemanage.h"
#include "classmanage.h"
#include "feemanage.h"
manager::manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manager)
{
    ui->setupUi(this);
    QLabel *lab= ui->label_useradmin;
    lab->setStyleSheet("color:#ff6600;");
    lab->setText("欢迎"+username_qj);

    setWindowTitle(QString("设计者，梁忠悦"));


}

manager::~manager()
{
    delete ui;
}

void manager::on_pushButton_9_clicked()
{
    MainWindow *dh;
    this->hide();
    dh=new MainWindow  ;

    dh->show();
}

void manager::on_userloginButton_clicked()
{
    this->hide();
    userlogin *ti=new userlogin;
    ti->show();
}

void manager::on_stu_inform_guanlipushButton_clicked()
{
    this->hide();
    stuinformanage *ij=new stuinformanage;
    ij->show();
}

void manager::on_dorm_guanliButton_clicked()
{
    this->hide();
    dormanage *yf=new dormanage;
    yf->show();
}

void manager::on_award_managepushButton_clicked()
{
    this->hide();

    awardmanage *nl=new awardmanage;
    nl->show();
}

void manager::on_scoremanagepushButton_clicked()
{
    this->hide();
    scoremanage *pk=new scoremanage;
    pk->show();

}

void manager::on_course_manageButton_clicked()
{
    this->hide();
    coursemanage *ew=new coursemanage;
    ew->show();
}

void manager::on_class_managepushButton_clicked()
{
    this->hide();
    classmanage *wq=new classmanage;
    wq->show();
}

void manager::on_feemanagepushButton_clicked()
{
    this->hide();
    feemanage *eg=new feemanage;
    eg->show();
}
