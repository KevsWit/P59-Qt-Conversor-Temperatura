#include "principal.h"
#include "ui_principal.h"

#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    // Conectar el dial de centigrados con el slot de esta clase
    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this,SLOT(cent2fahr(int)));
    // Conectar el dial de fahrenheit con el slot de esta clase
    connect(ui->inFahr, SIGNAL(valueChanged(int)),
            this,SLOT(fahr2cent(int)));

}

Principal::~Principal()
{
    delete ui;
}

void Principal::cent2fahr(int i)
{
    // Cambio de valor en el dial
    if (ui->inCent->hasFocus()){
        float fahr = (i * 9.0/5) + 32;
        ui->inFahr->setValue(fahr);
    }
}

void Principal::fahr2cent(int i)
{
    // Cambio de valor en el dial
    if (ui->inFahr->hasFocus()){
        float cent = (i - 32) * 5.0/9;
        ui->inCent->setValue(cent);
    }
}

