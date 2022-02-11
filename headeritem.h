#ifndef HEADERITEM_H
#define HEADERITEM_H
#include<QWidget>
#include<QLineEdit>

class HeaderItem: public QWidget {
    Q_OBJECT
private:
    std::string value;
    QLineEdit* box;
public:
    HeaderItem(const std::string& val="", QWidget* parent =0);
    QLineEdit* getBox() const;
    std::string getValue() const;
    ~HeaderItem() {delete  box;};
private slots:
    void setValue(float val);
};

#endif // HEADERITEM_H
