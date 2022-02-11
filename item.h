#ifndef ITEM_H
#define ITEM_H
#include<QWidget>
#include<QDoubleSpinBox>
#include<QLineEdit>
#include<QDoubleValidator>

class Item: public QWidget {
    Q_OBJECT
private:
    float value;
    QLineEdit* box;
    //QDoubleSpinBox* box;
public:
    Item(const float& val=0, QWidget* parent =0);
    //QDoubleSpinBox* getBox() const;
    QLineEdit* getBox() const;
    float getValue() const;
    ~Item() {delete  box;};
private slots:
    void setValue(float val);
};

#endif // ITEM_H
