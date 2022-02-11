#include "chart.h"

Chart::Chart(Model* m, std::string n) : name(n), data(m) {};
Model* Chart::getModel() const{return data;};
std::string Chart::getName() const {return name;};
void Chart::setName(std::string n) {name=n;};
