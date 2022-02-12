#ifndef MAINVIEW_H
#define MAINVIEW_H
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QToolBar>
#include <QTableWidget>
#include <QChartView>
#include <QFileDialog>

#include "model.h"
#include "chart.h"
#include "tableview.h"
#include "chartview.h"
#include "linechart.h"
#include "piechart.h"
#include "barchart.h"


class MainView: public QWidget {
    Q_OBJECT
private:
    Model* model;
    Chart* chart;

    QGridLayout* gridLayout;

    QChart* drawer;
    TableView* tableView;
    ChartView* chartView;
    QToolBar* toolBar;
    QToolBar* chartBar;

    void addMenu();
    void addChartControls();
    void addTableControls();
    void addChartSelections();

    void openFile();
    void saveFile();
    void loadFile(const QString &fileName);

    void addChart();
    void clearView();
public:
    MainView(QWidget* parent =0);
};

#endif // MAINVIEW_H
