#include "mainview.h"

MainView::MainView(QWidget* parent) : QWidget(parent), model(nullptr), chart(nullptr), tableView(nullptr), chartView(nullptr) {
    QVBoxLayout *mainLayout = new QVBoxLayout;
    gridLayout = new QGridLayout;

    toolBar = new QToolBar;
    chartBar = new QToolBar;
    addMenu();
    addTableControls();
    addChartSelections();

    mainLayout->addWidget(toolBar, 0, Qt::AlignTop);
    mainLayout->addWidget(chartBar, 0, Qt::AlignTop);
    mainLayout->addLayout(gridLayout);

    setLayout(mainLayout);
}

void MainView::addChart() {
    tableView = new TableView(model);
    if(dynamic_cast<LineChart*>(chart)) tableView->hideColLabel();
    gridLayout->addWidget(tableView, 1, 0);
    addChartControls();
    /*QPushButton* create = new QPushButton("Create Chart");
    connect(create, &QPushButton::clicked, this, [=] { chartView = new ChartView(chart); gridLayout->addWidget(chartView, 1, 1); });
    gridLayout->addWidget(create, 2, 0);
    if(chart){
        QLineEdit* chartName = new QLineEdit(QString::fromStdString(chart->getName()));
        connect(chartName, &QLineEdit::textChanged, this, [=] { chart->setName(chartName->text().toStdString());});
        gridLayout->addWidget(chartName, 2, 1);
    }*/
}
/*
void MainView::newLineChart() {
    //delete, pulizia pagina
    model = new Model(5,2);
    chart = new LineChart(model,"line chart");
    tableView = new TableView(model);
    gridLayout->addWidget(tableView, 1, 0);
    addTableControls();
    QPushButton* create = new QPushButton("Create Chart");
    connect(create, &QPushButton::clicked, this, [=] { chartView = new ChartView(chart); gridLayout->addWidget(chartView, 1, 1); });
    gridLayout->addWidget(create, 2, 0);
}

void MainView::newPieChart() {
    //delete, pulizia pagina
    model = new Model(5,1);
    chart = new PieChart(model,"pie chart");
    tableView = new TableView(model);
    gridLayout->addWidget(tableView, 1, 0);
    addTableControls();
    QPushButton* create = new QPushButton("Create Chart");
    connect(create, &QPushButton::clicked, this, [=] { chartView = new ChartView(chart); gridLayout->addWidget(chartView, 1, 1); });
    gridLayout->addWidget(create, 2, 0);
}

void MainView::newBarChart() {
    //delete, pulizia pagina
    model = new Model(5,3);
    chart = new BarChart(model,"bar chart");
    tableView = new TableView(model);
    gridLayout->addWidget(tableView, 1, 0);
    addTableControls();
    QPushButton* create = new QPushButton("Create Chart");
    connect(create, &QPushButton::clicked, this, [=] { chartView = new ChartView(chart); gridLayout->addWidget(chartView, 1, 1); });
    gridLayout->addWidget(create, 2, 0);
}
*/
void MainView::openFile() {
    const QString fileName = QFileDialog::getOpenFileName(this, "Scegli file dati", "", "*.txt");
    if (!fileName.isEmpty())
        loadFile(fileName);
}

void MainView::loadFile(const QString &fileName) {
    QFile file(fileName);
    if (fileName.isEmpty())
        return;
    if (!file.open(QFile::ReadOnly | QFile::Text))
        return;
    //pulisco la vista
    clearView();
    //apro lettura file
    QTextStream stream(&file);
    //leggo prima linea file
    QString line = stream.readLine();
    //nome chart, prima riga
    QString name = line;
    line = stream.readLine();
    //tipo chart, seconda riga
    QString type = line;
    //numero righe/colonne, terza riga
    QStringList modelS;
    line = stream.readLine();
    if (!line.isEmpty())
        modelS = line.split(QLatin1Char(';'), Qt::SkipEmptyParts);
    //row labels, quarta riga
    QStringList rowLabels;
    line = stream.readLine();
    if (!line.isEmpty())
        rowLabels = line.split(QLatin1Char(';'), Qt::SkipEmptyParts);
    //row labels, quinta riga
    QStringList colLabels;
    line = stream.readLine();
    if (!line.isEmpty())
        colLabels = line.split(QLatin1Char(';'), Qt::SkipEmptyParts);
    //creo modello
    model = new Model(modelS.at(0).toInt(),modelS.at(1).toInt());
    if(type == "Bar") chart = new BarChart(model, name.toStdString());
    if(type == "Line") chart = new LineChart(model, name.toStdString());
    if(type == "Pie") chart = new PieChart(model, name.toStdString());
    //leggo dati e inserisco nel modello creato
    QStringList dataset;
    int row = 0;
    while (!stream.atEnd()) {
        line = stream.readLine();
        if (!line.isEmpty()) {
            dataset = line.split(QLatin1Char(';'), Qt::SkipEmptyParts);
            for(int col = 0; col<dataset.length();col++) {
                if(row==0)
                    model->getData().at(col)->setLabel(colLabels.value(col).toStdString());
                model->setData(row, col, dataset.value(col).toFloat());
            }
            //inserisco la row label
            model->setRowLabel(row,rowLabels.value(row).toStdString());
            row++;
        }
    };
    file.close();
    addChart();
    //statusBar()->showMessage(tr("Loaded %1").arg(fileName), 2000);
}

void MainView::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save file as", "", "*.txt");

    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text))
        return;
    //istanzio lo stream
    QTextStream stream(&file);
    stream << QString::fromStdString(chart->getName()) << "\n";
    //memorizzo tipo chart
    stream << QString::fromStdString(chart->type()) << "\n";
    //memorizzo righe e colonne
    stream << model->rowCount() << ";" << model->columnCount() << "\n";
    //memorizzo vertical labels
    QStringList rowLabels;
    for(auto it = model->getRowLabels().begin(); it!=model->getRowLabels().end();++it)
        rowLabels.push_back(QString::fromStdString(*it));
    stream << rowLabels.join(';') << "\n";
    //memorizzo horizontal labels
    QStringList colLabels;
    for (int col = 0; col < model->columnCount(); ++col)
        colLabels.append(QString::fromStdString(model->getData().at(col)->getLabel()));
    stream << colLabels.join(';') << "\n";
    //memorizzo tutti i dataset
    for (int row = 0; row < model->rowCount(); ++row) {
        QStringList dataset;
        for (int col = 0; col < model->columnCount(); ++col)
            dataset.append(QString::fromStdString(std::to_string(model->getData(row,col))));

        stream << dataset.join(';') << "\n";
    }

    file.close();
    //statusBar()->showMessage(tr("Saved %1").arg(fileName), 2000);
}

void MainView::clearView() {
    chartBar->clear();
    if(chartView){ delete chartView; chartView=nullptr;}
    if(tableView){ delete tableView; tableView=nullptr;}
    if(chart){ delete chart; chart=nullptr;}
    if(model){ delete model; model=nullptr;}
}

void MainView::addChartControls() {
    QLineEdit* chartName = new QLineEdit(QString::fromStdString(chart->getName()));
    connect(chartName, &QLineEdit::textChanged, this, [=] { chart->setName(chartName->text().toStdString());});
    chartName->setMaximumWidth(230);
    chartBar->addWidget(chartName);
    chartBar->addSeparator();
    chartBar->addAction(QIcon(":/images/create-chart-32.png"), "Create Chart", [=] { if(chartView) delete chartView; chartView=nullptr; chartView = new ChartView(chart); gridLayout->addWidget(chartView, 1, 1); });
    chartBar->addAction(QIcon(":/images/delete-chart-32.png"), "Delete Chart", [=] { if(chartView) delete chartView; chartView=nullptr;});
    chartBar->addSeparator();
}

void MainView::addMenu() {
    toolBar->addAction(QIcon(":/images/exit-32.png"), "EXIT", [=] { this->close();});
    toolBar->addAction(QIcon(":/images/open-file-32.png"), "Open", [=] { openFile();});
    toolBar->addAction(QIcon(":/images/save-file-32.png"), "Save", [=] { saveFile();});
    toolBar->addSeparator();
}

void MainView::addChartSelections() {
    toolBar->addAction(QIcon(":/images/line-chart-32.png"), "Add Line Chart", [=] { clearView(); model = new Model; chart = new LineChart(model,"chart name"); addChart(); });
    toolBar->addAction(QIcon(":/images/pie-chart-32.png"), "Add Pie Chart", [=] { clearView(); model = new Model; chart = new PieChart(model,"chart name"); addChart(); });
    toolBar->addAction(QIcon(":/images/bar-chart-32.png"), "Add Pie Chart", [=] { clearView(); model = new Model; chart = new BarChart(model,"chart name"); addChart(); });
    toolBar->addSeparator();
}

void MainView::addTableControls() {
    toolBar->addSeparator();
    toolBar->addAction(QIcon(":/images/add-row-32.png"), "Add Row", [=] {if(tableView) tableView->insertRow();});
    toolBar->addAction(QIcon(":/images/remove-row-32.png"), "Remove Row", [=] {if(tableView) tableView->removeRow();});
    toolBar->addAction(QIcon(":/images/add-column-32.png"), "Add Column", [=] {if(tableView && !(dynamic_cast<PieChart*>(chart) && model->columnCount()>0)) tableView->insertColumn();});
    toolBar->addAction(QIcon(":/images/remove-column-32.png"), "Remove Column", [=] {if(tableView) tableView->removeColumn();});
    toolBar->addSeparator();
}
