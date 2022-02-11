#ifndef ROWDATA_H
#define ROWDATA_H

#include<vector>
#include<string>

#include "dataset.h"

class RowData {
private:
    ColumnData* cols;
    std::string label;
public:
    RowData(std::string n="");
    std::string getLabel() const;
    ColumnData& operator[](int i) {return cols}
    ~RowData() {};
};

#endif // ROWDATA_H
