#include "piechart.h"

PieChart::PieChart(Model* m, std::string n) : Chart(m,n){
    //inizializzato a 5 righe e 1 colonne da esempio
    /*getModel()->setColumnCount(1);
    getModel()->setRowCount(5);
    //mette la prima label "values"
    getModel()->setColLabel(0, "values");
    getModel()->setRowLabel(0, "first label");*/
}
/*
void PieChart::addLabel(std::string l) {labels.push_back(l);}

void PieChart::removeLabel(){labels.pop_back();};//rimuove sempre dalla fine per il momento

std::list<std::string> PieChart::getLabels() const {return labels;}
*/
void PieChart::draw(QChart*& drawer) const {
    QPieSeries *serie = new QPieSeries;
    QPieSlice* slice = nullptr;
    int i=0;

    if(!getModel()->getData().empty()){
        for(auto it=getModel()->getData().front()->getValues().begin();it!=getModel()->getData().front()->getValues().end();++it){
            slice = new QPieSlice((!getModel()->getRowLabels().empty() && !getModel()->getRowLabel(i).empty())?QString::fromStdString(getModel()->getRowLabel(i)):"",*it);
            serie->append(slice);
            i++;
        }
    }
    drawer->addSeries(serie);
}

std::string PieChart::type() const {return "Pie";};
