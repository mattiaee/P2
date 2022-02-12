#include "piechart.h"

PieChart::PieChart(Model* m, std::string n) : Chart(m,n){}

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
