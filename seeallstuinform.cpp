#include "seeallstuinform.h"
#include "ui_seeallstuinform.h"
#include "globle.h"
#include "stuinformanage.h"
 seeallstuinform:: seeallstuinform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui:: seeallstuinform)
{
    ui->setupUi(this);
    setWindowTitle(QString("设计者,梁忠悦"));

    for(int i1=0;i1<list_all_student.size();i1++)
    {

        int row = ui->tableWidget->rowCount();

        ui->tableWidget->insertRow(row);
        QStringList rowdata=list_all_student[i1].toStringList();

        for(int i  = 0 ; i <rowdata .size() ; i++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(rowdata.at(i));
            ui->tableWidget->setItem(row , i , item);
        }

    }

}

 seeallstuinform::~ seeallstuinform()
{
    delete ui;
}

void  seeallstuinform::on_backButton_clicked()
{
    this->hide();
    list_all_student.clear();
    ui->tableWidget->clear();

    stuinformanage *f1=new stuinformanage;

    f1->show();
}
