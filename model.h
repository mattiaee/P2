#ifndef MODEL_H
#define MODEL_H

#include<vector>

#include<dataset.h>

class Model {
public:
    std::vector<std::string> labels;
    std::vector<DataSet*> data;
    int row_count;//parte da 0
    int col_count;//parte da 0
public:
    Model(int row=0, int col=0);
    ~Model() = default;
    const std::vector<DataSet*>& getData() const;
    const std::vector<std::string>& getRowLabels() const;
    void addRowLabel(std::string label="");
    void setRowLabel(int pos, std::string label);
    std::string getRowLabel(int pos) const;
    void setColLabel(int pos, std::string label);
    std::string getColLabel(int pos) const;
    void setData(int row, int col, float data);
    float getData(int row, int col);

    int columnCount();
    void setColumnCount(int col);
    int rowCount();
    void setRowCount(int row);

    void insertColumn();
    void insertRow();
    void removeColumn();
    void removeRow();
};

#endif // MODEL_H
