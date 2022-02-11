#ifndef TABLEVIEW_H
#define TABLEVIEW_H
#include<QWidget>
#include<QTableWidget>
#include<QVBoxLayout>

#include "model.h"
#include "item.h"
#include "headeritem.h"

class TableView: public QWidget {
    Q_OBJECT
private:
    Model* model;
    QTableWidget* table;

    void addItem(int row,int col, float val);
    //void addHeaderItem(int row,int col, std::string label);
    void addColHeaderItem(int col, std::string label);
    void addRowHeaderItem(int col, std::string label);

public:
    TableView(Model*& m, QWidget* parent =0);
    void hideColLabel();
    ~TableView() {delete table;};
public slots:
    void insertColumn();
    void insertRow();
    void removeColumn();
    void removeRow();

    void changeValue(int row, int col, float v);
    //void changeText(int row, int col, std::string t);
    void changeColText(int col, std::string t);
    void changeRowText(int row, std::string t);
};

#endif // TABLEVIEW_H
