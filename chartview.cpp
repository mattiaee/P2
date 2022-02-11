#include "chartview.h"

ChartView::ChartView(Chart*& c, QWidget* parent) : QWidget(parent), chart(c) {
    QVBoxLayout* chartLayout = new QVBoxLayout;
    chartView = new QChartView;
    QChart* drawer = new QChart;
    drawer->setAnimationOptions(QChart::AllAnimations);
    chart->draw(drawer);
    chartView->setChart(drawer);
    chartLayout->addWidget(chartView);
    setLayout(chartLayout);
}
