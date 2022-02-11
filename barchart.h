#ifndef BARCHART_H
#define BARCHART_H
#include<QBarSeries>
#include<QBarSet>
#include<QBarCategoryAxis>
#include<QValueAxis>

#include<list>
#include "chart.h"

class BarChart : public Chart {
public:
    BarChart(Model* m, std::string n="");
    void draw(QChart*& drawer) const override;
    virtual std::string type() const override;
    virtual ~BarChart() = default;
};
#endif // BARCHART_H
