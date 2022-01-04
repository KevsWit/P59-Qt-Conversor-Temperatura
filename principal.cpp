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
    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this,SLOT(cent2kelvin(int)));
    // Conectar el dial de fahrenheit con el slot de esta clase
    connect(ui->inFahr, SIGNAL(valueChanged(int)),
            this,SLOT(fahr2cent(int)));
    connect(ui->inFahr, SIGNAL(valueChanged(int)),
            this,SLOT(fahr2kelvin(int)));
    // Conectar el dial de kelvin con el slot de esta clase
    connect(ui->inKelvin, SIGNAL(valueChanged(int)),
            this,SLOT(kelvin2cent(int)));
    connect(ui->inKelvin, SIGNAL(valueChanged(int)),
            this,SLOT(kelvin2fahr(int)));

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

void Principal::cent2kelvin(int i)
{
    // Cambio de valor en el dial
    if (ui->inCent->hasFocus()){
        float kelvin = i + 273.15;
        ui->inKelvin->setValue(kelvin);
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

void Principal::fahr2kelvin(int i)
{
    // Cambio de valor en el dial
    if (ui->inFahr->hasFocus()){
        float kelvin = (i - 32) * 5/9.0 + 273.15;
        ui->inKelvin->setValue(kelvin);
    }
}

void Principal::kelvin2cent(int i)
{
    // Cambio de valor en el dial
    if (ui->inKelvin->hasFocus()){
        float cent = i - 273.15;
        ui->inCent->setValue(cent);
    }
}

void Principal::kelvin2fahr(int i)
{
    // Cambio de valor en el dial
    if (ui->inKelvin->hasFocus()){
        float fahr = (i - 273.15) * 9.0/5 + 32;
        ui->inFahr->setValue(fahr);
    }
}

