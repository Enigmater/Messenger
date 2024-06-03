#ifndef NEWGROUP_H
#define NEWGROUP_H

#include <QWidget>

namespace Ui {
class NewGroup;
}

class NewGroup : public QWidget
{
    Q_OBJECT

public:
    explicit NewGroup(QWidget *parent = nullptr);
    ~NewGroup();

private:
    Ui::NewGroup *ui;

signals:
    void cancelPressed();
    void nextPressed(QString);
private slots:
    void on_cancelButton_clicked();
    void on_nextButton_clicked();
    void on_lineEdit_textEdited(const QString &arg1);
};

#endif // NEWGROUP_H
