#include "linechart.h"

LineChart::LineChart(Model* m, std::string n) : Chart(m,n){
    //inizializzato a 5 righe e 2 colonne da esempio
    /*getModel()->setColumnCount(2);
    getModel()->setRowCount(5);
    //mette la prima label "x-values"
    getModel()->setColLabel(0, "x values");
    getModel()->setColLabel(1, "y values");
    getModel()->setRowLabel(0, "first set");*/
}

void LineChart::draw(QChart*& drawer) const {
    for(auto it_col=getModel()->getData().begin();it_col!=getModel()->getData().end();++it_col) {
        int row=0;
        QLineSeries* serie = new QLineSeries;
        for(auto it_row=(*it_col)->getValues().begin();it_row!=(*it_col)->getValues().end();++it_row){
            //serie->append(getModel()->getData(row,0),*it_row);//getModel()->getData().front()->getValues()[i], *it_row);
            serie->append(QPointF(getModel()->getData(row,0),*it_row));//QPointF(getModel()->getData().front()->getValues()[i], *it_row));
            row++;
        }
        serie->setName(QString::fromStdString((*it_col)->getLabel()));
        drawer->addSeries(serie);
    }
    drawer->createDefaultAxes();
}

std::string LineChart::type() const {return "Line";};
