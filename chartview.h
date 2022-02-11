#ifndef CHARTVIEW_H
#define CHARTVIEW_H
#include<QWidget>
#include<QChartView>
#include<QVBoxLayout>

#include "chart.h"

class ChartView: public QWidget {
    Q_OBJECT
private:
    Chart* chart;
    QChartView* chartView;
public:
    ChartView(Chart*& m, QWidget* parent =0);
    ~ChartView(){delete chartView;};
};

#endif // CHARTVIEW_H
