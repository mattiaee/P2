#include "model.h"
#include<QtWidgets>
Model::Model(int row, int col) : row_count(row), col_count(col) {
    for(int i=0;i<col_count;i++) data.push_back(new DataSet(0,row_count,""));
    for(int j=0;j<row_count;j++) labels.push_back("");
};
const std::vector<DataSet*>& Model::getData() const{return data;};
const std::vector<std::string>& Model::getRowLabels() const{return labels;};

void Model::addRowLabel(std::string label) {labels.push_back(label); };//inserisce sempre alla fine
void Model::setRowLabel(int pos, std::string label) {labels.at(pos) = label;};
std::string Model::getRowLabel(int pos) const {return labels.at(pos);};

void Model::setColLabel(int pos, std::string label) {data.at(pos)->setLabel(label);};
std::string Model::getColLabel(int pos) const {return data.at(pos)->getLabel();};

void Model::setData(int row, int col, float d) {data.at(col)->setValue(row,d);};
float Model::getData(int row, int col) {return data.at(col)->getValue(row);};

int Model::columnCount() {return col_count;};
void Model::setColumnCount(int col) {
    //riporto a zero il modello
    for(int i=col_count-1;i>=0;i--) removeColumn();
    for(int i=0;i<col;i++) insertColumn();
};
int Model::rowCount(){return row_count;};
void Model::setRowCount(int row) {
    //riporto a zero il modello
    for(int i=row_count-1;i>=0;i--) removeRow();
    for(int i=0;i<row;i++) insertRow();
};

void Model::insertColumn() {
    data.push_back(new DataSet(0,row_count,""));
    col_count++;
};
void Model::removeColumn() {if(col_count>0){data.pop_back();col_count--;}};

void Model::insertRow() {
    for(int i=0;i<col_count;i++) data.at(i)->addValue(float(0));
    labels.push_back("");
    row_count++;
};
void Model::removeRow() {
    if(row_count>0){
        for(int i=0;i<col_count;i++) data.at(i)->removeValue();
        labels.pop_back();
        row_count--;
    }
};
