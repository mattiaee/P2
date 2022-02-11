#include "headeritem.h"

HeaderItem::HeaderItem(const std::string& val, QWidget* parent) : QWidget(parent), value(val) {
    box = new QLineEdit;
    box->setText(QString::fromStdString(val));
    QPalette palette;
    palette.setColor(QPalette::Base,QColor(244, 87, 47));
    palette.setColor(QPalette::Text,Qt::black);
    box->setPalette(palette);
    //connect(box,  &QDoubleSpinBox::valueChanged, this, [=] { setValue(box->value()); });
    //connect(box, SIGNAL(box->valueChanged(double d)), this, SLOT(setValue(box->value())));
}

QLineEdit* HeaderItem::getBox() const {return box;}
std::string HeaderItem::getValue() const {return value;}
void HeaderItem::setValue(float val) {value = val;}
