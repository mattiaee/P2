#include "item.h"

Item::Item(const float& val, QWidget* parent) : QWidget(parent), value(val) {
    box = new QLineEdit;
    box->setValidator(new QDoubleValidator(-100,100,2));
    box->setText(QString::number(val));
}

QLineEdit* Item::getBox() const {return box;}
float Item::getValue() const {return value;}
void Item::setValue(float val) {value = val;}
