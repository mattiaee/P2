#include "tableview.h"
#include<QDoubleSpinBox>
TableView::TableView(Model*& m, QWidget* parent) : QWidget(parent), model(m) {
    QVBoxLayout* tableLayout = new QVBoxLayout;
    table = new QTableWidget(model->rowCount()+1, model->columnCount()+1);//+1 per gestire le label che sono a disposizione per tutti i grafici
    //gestisco visualizzazione label
    for(int i=0;i<model->columnCount();i++) addColHeaderItem(i,model->getColLabel(i));//addColHeaderItem(i,model->getData().at(i)->getLabel());
    for(int j=0;j<model->rowCount();j++) addRowHeaderItem(j,model->getRowLabel(j));//addRowHeaderItem(j,model->getRowLabels().at(j));
    for(int i=0;i<model->columnCount();i++)
        for(int j=0;j<model->rowCount();j++) addItem(j,i,model->getData(j,i));
    tableLayout->addWidget(table);
    setLayout(tableLayout);
}

void TableView::addItem(int row,int col, float val) {//model row and col
    Item* item = new Item(val);
    table->setCellWidget(row+1,col+1, item->getBox());
    //connect(item->getBox(), &QDoubleSpinBox::valueChanged, this, [=] { changeValue(row,col,item->getBox()->value()); });
    connect(item->getBox(), &QLineEdit::textChanged, this, [=] { changeValue(row,col,item->getBox()->text().toFloat()); });

};
void TableView::addColHeaderItem(int col, std::string label) {//model row and col
    HeaderItem* hitem = new HeaderItem(label);
    table->setCellWidget(0,col+1, hitem->getBox());
    connect(hitem->getBox(), &QLineEdit::textChanged, this, [=] { changeColText(col,hitem->getBox()->text().toStdString()); });
};
void TableView::addRowHeaderItem(int row, std::string label) {//model row and col
    HeaderItem* hitem = new HeaderItem(label);
    table->setCellWidget(row+1,0, hitem->getBox());
    connect(hitem->getBox(), &QLineEdit::textChanged, this, [=] { changeRowText(row,hitem->getBox()->text().toStdString()); });
};

void TableView::insertColumn() {
    if(model && table) {
        table->insertColumn(table->columnCount());
        model->insertColumn();
        addColHeaderItem(model->columnCount()-1, model->getColLabel(model->columnCount()-1));//model->getData().at(model->columnCount()-1)->getLabel());
        for(int j=0;j<model->rowCount();j++) addItem(j,model->columnCount()-1, model->getData(j,model->columnCount()-1));
    }
};
void TableView::insertRow() {
    if(model && table) {
        table->insertRow(table->rowCount());
        model->insertRow();
        addRowHeaderItem(model->rowCount()-1, model->getRowLabel(model->rowCount()-1));//model->getRowLabels().at(model->rowCount()-1));
        for(int i=0;i<model->columnCount();i++) addItem(model->rowCount()-1,i, model->getData(model->rowCount()-1,i));
    }
};
void TableView::removeColumn() {
    if(model && table && table->columnCount()>1){
        table->removeColumn(table->columnCount()-1);
        model->removeColumn();
    }
};
void TableView::removeRow() {
    if(model && table && table->rowCount()>1){
        table->removeRow(table->rowCount()-1);
        model->removeRow();
    }
};

void TableView::changeValue(int row, int col, float v) {
    model->setData(row, col, v);
};

void TableView::changeColText(int col, std::string t) {model->setColLabel(col,t);};//model->getData().at(col)->setLabel(t);};
void TableView::changeRowText(int row, std::string t) {model->setRowLabel(row,t);};

void TableView::hideColLabel(){table->hideColumn(0);};
