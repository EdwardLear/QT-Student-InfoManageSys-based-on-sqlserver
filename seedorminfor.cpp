#include "seedorminfo.h"
#include "ui_seedorminfo.h"
#include "globle.h"
#include "dormanage.h"
 seedorminfo:: seedorminfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui:: seedorminfo)
{
    ui->setupUi(this);
    setWindowTitle(QString("设计者，梁忠悦"));
    for(int i1=0;i1<list_all_dormstudent.size();i1++)
    {

        int row = ui->tableWidget->rowCount();

        ui->tableWidget->insertRow(row);
        QStringList rowdata=list_all_dormstudent[i1].toStringList();

        for(int i  = 0 ; i <rowdata .size() ; i++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(rowdata.at(i));
            ui->tableWidget->setItem(row , i , item);
        }

    }



}

 seedorminfo::~ seedorminfo()
{
    delete ui;
}

void  seedorminfo::on_backButton_clicked()
{
    list_all_dormstudent.clear();
    ui->tableWidget->clear();
    this->hide();

     dormanage *vb=new  dormanage;
    vb->show();
}
