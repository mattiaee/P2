#ifndef DATASET_H
#define DATASET_H

#include<vector>
#include<string>

class DataSet {
private:
    std::vector<float> values;
    std::string label;
public:
    DataSet(std::string n="");
    DataSet(float v, int k, std::string n="");
    std::string getLabel() const;
    void setLabel(std::string l);
    const std::vector<float>& getValues() const;
    float getValue(int pos) const ;
    void setValue(int pos, float val);
    void addValue(float val);
    void removeValue();
    float& operator[](int pos);
    ~DataSet() = default;
};

#endif // DATASET_H
