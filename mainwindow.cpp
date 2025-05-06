#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include<globle.h>
#include "manager.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect(ui->LoginButton, SIGNAL(clicked()), this, SLOT(on_LoginButton_clicked()));
    // ui->hide();
    // connect(ui->LoginButton, SIGNAL(clicked()), this, SLOT(show2()));
    ui->Login_password->setEchoMode(QLineEdit::Password);
    ui->Login_username->setText("xh");
    ui->Login_password->setText("1234567");
    ui->radioButton_2->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoginButton_clicked()
{
    QString username = ui->Login_username->text();
    QString password = ui->Login_password->text();
    qDebug()<<"用户名："<<username<<"密码:"<<password;

    //************连接sqlserver 数据库************

//连接方法一
    QSqlDatabase myDB;
    if(QSqlDatabase::contains("Myconnection"))//处理返回后再登陆情况
        myDB = QSqlDatabase::database("Myconnection");
    else{
    QString serverName = "FANGCHANGAN";
    QString dbName = "studentmanager";
    myDB = QSqlDatabase::addDatabase("QODBC","Myconnection");//连接到ODBC驱动，连接名称
    QString dsn = QString("Driver={SQL Server};Server=%1;Database=%2;Trusted_Connection=yes").arg(serverName).arg(dbName);
    myDB.setDatabaseName(dsn);
    }

//连接方法二
    /******
    QSqlDatabase myDB = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    QString dsn = QString::fromLocal8Bit("QTsqlserver");      //ODBC数据源名称
    myDB.setHostName("127.0.1.1");                        //选择本地主机，127.0.1.1
    myDB.setDatabaseName(dsn);                            //设置数据源名称
    ******/


    if(myDB.open())
    {
        printf("connect to server successfully\n");
        qDebug() << "db open successfully(from qdebug)";
       // myDB.close();
    }
    else
    {
        printf("connect to server failed\n");
        //printf("%s\n",myDB.lastError().text().toLatin1().data());
    }
    if( ui->radioButton->isChecked()){
        QSqlQuery query(myDB);//QSqlQuery query=QSqlQuery(myDB);

        query.exec("select id,username,password from admin");
        bool T1=false;
        while(query.next())
        {
            QString user = query.value(1).toString();
            QString pass = query.value(2).toString();
            qDebug() << user << pass ;
            if(username.compare(user)==0&&password.compare(pass)==0){
                password_qj=password;
                username_qj=username;
                T1=true;
                this->hide();
                m=new manager;
                //    emit sendData(username+"&"+password);
                m->show();
            }
        }
        if(T1==false)
            QMessageBox::information(this, "警告", "用户名或密码错误");
    }

    if( ui->radioButton_2->isChecked()){
        QSqlQuery query(myDB);
        query.exec("select id,name,password from student");
        bool T=false;
        while(query.next())
        {
            QString user = query.value(1).toString();
            QString pass = query.value(2).toString();
            qDebug() << user << pass ;
            if(username.compare(user)==0&&password.compare(pass)==0){
                password_qj=password;
                username_qj=username;
                T=true;
                this->hide();
                f=new studentForm;
                //     emit sendData(username+"&"+password);
                f->show();
            }
        }
        if(T==false)
            QMessageBox::information(this, "警告", "用户名或密码错误");
    }


}


    /**********mysql数据库连接***********/
/*************
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
    if( ui->radioButton->isChecked()){
        QSqlQuery query(db);
        db.exec("SET NAMES 'GBK'");
        query.exec("select id,username,password from admin");
        bool T1=false;
        while(query.next())
        {
            QString user = query.value(1).toString();
            QString pass = query.value(2).toString();
            qDebug() << user << pass ;
            if(username.compare(user)==0&&password.compare(pass)==0){
                password_qj=password;
                username_qj=username;
                T1=true;
                this->hide();
                m=new manager;
                //    emit sendData(username+"&"+password);
                m->show();
            }


        }


        if(T1==false)
            QMessageBox::information(this, "警告", "用户名或密码错误");


    }

    if( ui->radioButton_2->isChecked()){


        QSqlQuery query(db);
        db.exec("SET NAMES 'GBK'");
        query.exec("select id,name,password from student");
        bool T=false;
        while(query.next())
        {
            QString user = query.value(1).toString();
            QString pass = query.value(2).toString();
            qDebug() << user << pass ;
            if(username.compare(user)==0&&password.compare(pass)==0){
                password_qj=password;
                username_qj=username;
                T=true;
                this->hide();
                f=new studentForm;
                //     emit sendData(username+"&"+password);
                f->show();

            }
        }

        if(T==false)
            QMessageBox::information(this, "警告", "用户名或密码错误");


    }


}

  **************  *************/
void MainWindow::show2(){
    this->hide();
    f=new studentForm;
    //  connect(f-)

    f->show();


}



void MainWindow::on_remitButton_clicked()
{
    ui->Login_username->clear();
    ui->Login_password->clear();
}
