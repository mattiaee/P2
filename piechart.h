#ifndef PIECHART_H
#define PIECHART_H
#include<QPieSeries>

#include<list>
#include "chart.h"
#include "exception.h"

class PieChart : public Chart {
public:
    PieChart(Model* m, std::string n="");
    void draw(QChart*& drawer) const override;
    virtual std::string type() const override;
    virtual ~PieChart() = default;
};

#endif // PIECHART_H
