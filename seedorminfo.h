#ifndef  seedorminfo_H
#define  seedorminfo_H

#include <QWidget>

namespace Ui {
class  seedorminfo;
}

class  seedorminfo : public QWidget
{
    Q_OBJECT

public:
    explicit  seedorminfo(QWidget *parent = 0);
    ~ seedorminfo();

private slots:
    void on_backButton_clicked();

private:
    Ui:: seedorminfo *ui;
};

#endif //  seedorminfo_H
