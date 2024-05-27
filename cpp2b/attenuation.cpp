#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "attenuation.hpp"


void Layer::set_thick(double t)
{
    this->thick = t;
}
double Layer::get_thick() {
    return this->thick;
}
std::array<Layer, 2> geometry;

void Element::set_sigma(double s) {
    this->sigma = s;
}
double Element::get_sigma() {
    return this->sigma;
}
std::array<Element, 2> materials;

double source;

void Problem::load_input(const std::string filename) {
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
void Problem::run() {
    intensity = source * exp(- (materials[0].get_sigma()*geometry[0].get_thick() + materials[1].get_sigma()*geometry[1].get_thick()));
    std::cout << intensity << std::endl;
}



int main(int argc, char* argv[])
{
    const std::string filename("data.txt");
    Problem study;

    study.load_input(filename);
    study.run();

    return 0;
}
