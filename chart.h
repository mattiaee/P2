#ifndef CHART_H
#define CHART_H
#include<QChart>

#include<string>

#include "model.h"

class Chart {
private:
    std::string name;
    Model* data;
public:
    Chart(Model* m, std::string n="");
    std::string getName() const;
    void setName(std::string n);
    Model* getModel() const; //da valutare mettere data protected perchè è giusto che si veda dentro tutta la gerarchia
    virtual std::string type() const=0;
    virtual void draw(QChart*& drawer) const = 0;
    virtual ~Chart() = default;
};

#endif // CHART_H
