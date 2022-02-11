#ifndef LINECHART_H
#define LINECHART_H
#include<QLineSeries>
#include<QVXYModelMapper>

#include<list>
#include "chart.h"

class LineChart : public Chart {
public:
    LineChart(Model* m, std::string n="");
    void draw(QChart*& drawer) const override;
    virtual std::string type() const override;
    virtual ~LineChart() = default;
};

#endif // LINECHART_H
