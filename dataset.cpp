#include "dataset.h"

DataSet::DataSet(std::string n) : label(n) {}

DataSet::DataSet(float v, int k, std::string n) : label(n) {
    for(int i=0;i<k;i++) values.push_back(v);
}
void DataSet::setLabel(std::string l){label = l;};
std::string DataSet::getLabel() const{return label;};

const std::vector<float>& DataSet::getValues() const{ return values;};
float DataSet::getValue(int pos) const {return values.at(pos);};
void DataSet::setValue(int pos, float val) {values.at(pos) = val;};
void DataSet::addValue(float val) {values.push_back(val);};
void DataSet::removeValue() {values.pop_back();};
float& DataSet::operator[](int pos) {return values.at(pos);};
