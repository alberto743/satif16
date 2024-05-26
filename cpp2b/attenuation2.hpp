#ifndef ATTEN_H
#define ATTEN_H

#include <array>
#include <string>


class Layer {
    double thick;
public:
    Layer() {}
    virtual ~Layer () {}
    Layer(double t): thick(t) {}

    void set_thick(double);
    double get_thick();
};
extern std::array<Layer, 2> geometry;


class Element {
    double sigma;
public:
    Element() {}
    virtual ~Element () {}
    Element(double s): sigma(s) {}

    void set_sigma(double);
    double get_sigma();
};
extern std::array<Element, 2> materials;


extern double source;


class Problem {
    double intensity;
public:
    Problem() {}
    virtual ~Problem() {}

    void load_input(const std::string);
    void run();
};


//int main(int argc, char**);

#endif // ATTEN_H
