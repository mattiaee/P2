#include "barchart.h"

BarChart::BarChart(Model* m, std::string n) : Chart(m,n){}
void BarChart::draw(QChart*& drawer) const {
    QBarSeries *series = new QBarSeries;
    for(auto it=getModel()->getData().begin();it!=getModel()->getData().end();++it){
        QBarSet* set = new QBarSet(QString::fromStdString((*it)->getLabel()));
        for(auto itt=(*it)->getValues().begin();itt!=(*it)->getValues().end();++itt)
            set->append(*itt);
        series->append(set);
    }
    drawer->addSeries(series);
    QStringList categories;
    for(auto it=getModel()->getRowLabels().begin();it!=getModel()->getRowLabels().end();++it)
        categories.push_back(QString::fromStdString(*it));
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    drawer->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis();
    drawer->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
}

std::string BarChart::type() const {return "Bar";};
