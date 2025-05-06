#include "studentform.h"
#include "ui_studentform.h"
#include "mainwindow.h"
#include "globle.h"
#include  <QtDebug>
#include "allstuinform.h"
#include "findscore.h"
#include "dormfind.h"
#include "coursefind.h"
#include "awardfind.h"
#include "classfind.h"
#include "feefind.h"
studentForm::studentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::studentForm)
{
    ui->setupUi(this);

    //  MainWindow *form=new MainWindow;
    //
    //  connect(form,SIGNAL(sendData(QString)),this,SLOT(receiveData(QString)));
    //  form->show();

    QLabel *lab= ui->label_user;
    lab->setStyleSheet("color:#ff6600;");
    lab->setText("欢迎"+username_qj);
    setWindowTitle(QString("设计者，梁忠悦"));

}

studentForm::~studentForm()
{
    delete ui;
}


/*void studentForm::receiveData(QString data)
{

   // qDebug()<<"值是:"<<data;
   // ui->label_user->setText("122");
}
*/

void studentForm::on_pushButton_clicked()
{
    MainWindow *h;
    this->hide();
    h=new MainWindow  ;

    h->show();
}

/********
void studentForm::on_pushButton_3_clicked()
{

    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("studentmanager");
    db.setUserName(sqluser);
    db.setPassword(sqlpass);

    if (!db.open())
        qDebug() << "Failed to connect to root mysql admin";
    else qDebug() << "open";


    QSqlQuery query(db);
    query.exec("SET NAMES 'GBK'");
    query.exec("select id,name,sex,age,major,banji,address,phonenumber,beizhu from student");

    while(query.next())
    {
        QStringList q;
        q.clear();
        QString id = query.value(0).toString();
        QString user = query.value(1).toString();
        QString pass = query.value(2).toString();
        QString sex =query.value(3).toString();
        QString age=query.value(4).toString();
        QString major=query.value(5).toString();
        QString banji=query.value(6).toString();
        QString address=query.value(7).toString();
        QString phonenumber=query.value(8).toString();
        QString beizhu=query.value(9).toString();
        q<<id<<user<<pass<<sex<<age<<major<<banji<<address<<phonenumber<<beizhu;
        list_all_student.append(q);




    }


    for(int i=0;i<list_all_student.size();i++){
        qDebug()<<list_all_student[i];

    }

    this->hide();
    AllstuInform  *as=new AllstuInform;

    as->show();


}
*****/
void studentForm::on_pushButton_3_clicked()
{

    QSqlDatabase db;
    if(QSqlDatabase::contains("Myconnection"))
        db = QSqlDatabase::database("Myconnection");
    else{
        db = QSqlDatabase::database("Myconnection");
        QString serverName = "FANGCHANGAN";
        QString dbName = "studentmanager";
        db = QSqlDatabase::addDatabase("QODBC");//连接到ODBC驱动
        QString dsn = QString("Driver={SQL Server};Server=%1;Database=%2;Trusted_Connection=yes").arg(serverName).arg(dbName);
        db.setDatabaseName(dsn);
    }
    if (!db.open())
        qDebug() << "Failed to connect to root sql admin";
    else qDebug() << "open";


    QSqlQuery query(db);
    query.exec("SET NAMES 'GBK'");
    query.exec("select id,name,sex,age,major,banji,address,phonenumber,beizhu from student");

    while(query.next())
    {
        QStringList q;
        q.clear();
        QString id = query.value(0).toString();
        QString user = query.value(1).toString();
        QString pass = query.value(2).toString();
        QString sex =query.value(3).toString();
        QString age=query.value(4).toString();
        QString major=query.value(5).toString();
        QString banji=query.value(6).toString();
        QString address=query.value(7).toString();
        QString phonenumber=query.value(8).toString();
        QString beizhu=query.value(9).toString();
        q<<id<<user<<pass<<sex<<age<<major<<banji<<address<<phonenumber<<beizhu;
        list_all_student.append(q);




    }


    for(int i=0;i<list_all_student.size();i++){
        qDebug()<<list_all_student[i];

    }

    this->hide();
    AllstuInform  *as=new AllstuInform;

    as->show();


}

void studentForm::on_pushButton_student_findscore_clicked()
{
    this->hide();
    findscore *ff=new findscore;
    ff->show();




}

/************mysql*****
void studentForm::on_stu_find_dormButton_clicked()
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("studentmanager");
    db.setUserName(sqluser);
    db.setPassword(sqlpass);
    if (!db.open())
        qDebug() << "Failed to connect to root mysql admin";
    else qDebug() << "open";


    QSqlQuery query(db);
    db.exec("SET NAMES 'GBK'");
    query.exec("select dormnum,id,name,sex,bednum,beizhu from student");

    while(query.next())
    {
        QStringList q1;
        q1.clear();
        QString dormnum = query.value(0).toString();
        QString id = query.value(1).toString();
        QString name = query.value(2).toString();
        QString sex =query.value(3).toString();
        QString bednum=query.value(4).toString();
        QString beizhu=query.value(5).toString();

        q1<<dormnum <<id<<name<<sex<<bednum<<beizhu;
        list_all_dormstudent.append(q1);

    }

    this->hide();
    dormfind *fd=new dormfind;
    fd->show();

}

**************************/

void studentForm::on_stu_find_dormButton_clicked()
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("Myconnection"))
        db = QSqlDatabase::database("Myconnection");
    else{
        db = QSqlDatabase::database("Myconnection");
    QString serverName = "FANGCHANGAN";
    QString dbName = "studentmanager";
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");//连接到ODBC驱动
    QString dsn = QString("Driver={SQL Server};Server=%1;Database=%2;Trusted_Connection=yes").arg(serverName).arg(dbName);
    db.setDatabaseName(dsn);
    }
    if (!db.open())
        qDebug() << "Failed to connect to root sql admin";
    else qDebug() << "open";


    QSqlQuery query(db);
    query.exec("SET NAMES 'GBK'");
    query.exec("select dormnum,id,name,sex,bednum,beizhu from student");

    while(query.next())
    {
        QStringList q1;
        q1.clear();
        QString dormnum = query.value(0).toString();
        QString id = query.value(1).toString();
        QString name = query.value(2).toString();
        QString sex =query.value(3).toString();
        QString bednum=query.value(4).toString();
        QString beizhu=query.value(5).toString();

        q1<<dormnum <<id<<name<<sex<<bednum<<beizhu;
        list_all_dormstudent.append(q1);

    }

    this->hide();
    dormfind *fd=new dormfind;
    fd->show();

}



void studentForm::on_stu_find_coursebutton_clicked()
{
    this->hide();
    coursefind *fg=new coursefind;
    fg->show();

}

void studentForm::on_stu_award_button_clicked()
{
    this->hide();
    awardfind *fw=new awardfind;
    fw->show();
}

void studentForm::on_stu_classfind_infoButton_clicked()
{
    this->hide();
    classfind *fg=new classfind;
    fg->show();
}

void studentForm::on_stu_query_fee_Button_clicked()
{
    this->hide();

    feefind *fe=new feefind;
    fe->show();
}

