#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
public slots:
    void cent2fahr(int);
    void cent2kelvin(int);
    void fahr2cent(int);
    void fahr2kelvin(int);
    void kelvin2cent(int);
    void kelvin2fahr(int);
private:
    Ui::Principal *ui;
};
#endif // PRINCIPAL_H
