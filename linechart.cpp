#include "linechart.h"

LineChart::LineChart(Model* m, std::string n) : Chart(m,n){}

void LineChart::draw(QChart*& drawer) const {
    auto it_col=getModel()->getData().begin();
    it_col++;
    for(;it_col!=getModel()->getData().end();++it_col) {
        int row=0;
        QLineSeries* serie = new QLineSeries;
        for(auto it_row=(*it_col)->getValues().begin();it_row!=(*it_col)->getValues().end();++it_row){
            serie->append(QPointF(getModel()->getData(row,0),*it_row));
            row++;
        }
        serie->setName(QString::fromStdString((*it_col)->getLabel()));
        drawer->addSeries(serie);
    }
    drawer->createDefaultAxes();
}

std::string LineChart::type() const {return "Line";};
