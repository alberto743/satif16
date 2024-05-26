#include <iostream>
#include <array>
#include <fstream>
#include <cmath>


class Layer {
    double thick;
public:
    Layer() {}
    virtual ~Layer () {}
    Layer(double t): thick(t) {}

    void set_thick(double t) {
        this->thick = t;
    }
    double get_thick() {
        return this->thick;
    }
};
std::array<Layer, 2> geometry;


class Element {
    double sigma;
public:
    Element() {}
    virtual ~Element () {}
    Element(double s): sigma(s) {}

    void set_sigma(double s) {
        this->sigma = s;
    }
    double get_sigma() {
        return this->sigma;
    }
};
std::array<Element, 2> materials;


double source;


class Problem {
    double intensity;
public:
    Problem() {}
    virtual ~Problem() {}

    void load_input(const std::string filename) {
        std::ifstream inputdata;
        std::string mystring;

        inputdata.open(filename);
        if (!inputdata) {
            std::cerr << "Non-existing input file" << std::endl;
            exit(1);
        } else {
            inputdata >> mystring;
            geometry[0].set_thick(std::stod(mystring));
            inputdata >> mystring;
            geometry[1].set_thick(std::stod(mystring));
            inputdata >> mystring;
            materials[0].set_sigma(std::stod(mystring));
            inputdata >> mystring;
            materials[1].set_sigma(std::stod(mystring));
            inputdata >> mystring;
            source = std::stod(mystring);
        }
    }

    void run() {
        intensity = source * exp(- (materials[0].get_sigma()*geometry[0].get_thick() + materials[1].get_sigma()*geometry[1].get_thick()));
        std::cout << intensity << std::endl;
    }

};


int main()
{
    const std::string filename("data.txt");
    Problem study;

    study.load_input(filename);
    study.run();

    return 0;
}
