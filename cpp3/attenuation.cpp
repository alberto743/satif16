#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <fstream>
#include "attenuation.hpp"


std::string Material::show() const
{
    std::ostringstream repr;

    repr << "Sigma: " << this->sigma;
    return repr.str();
}
double& Material::get_sigma()
{
    return this->sigma;
}

std::string Slab::show() const
{
    std::ostringstream repr;

    repr << "Thickness: " << this->thick;
    repr << ", ";
    repr << this->mat->show();
    return repr.str();
}
double& Slab::get_thickness()
{
    return this->thick;
}
Material& Slab::get_material()
{
    return *this->mat;
}

void Problem::add_slab(Slab& sl)
{
    this->slabs.push_back(sl);
}
Slab& Problem::get_slab(int idx)
{
    return this->slabs[idx];
}
std::vector<Slab>& Problem::get_slabs()
{
    return this->slabs;
}
void Problem::set_source(double src)
{
    this->source = src;
}
double& Problem::get_source()
{
    return this->source;
}
std::string Problem::show() const
{
    std::ostringstream repr;

    repr << "Source: " << this->source << std::endl;
    repr << "Layers: " << this->slabs.size();
    for (auto& it : this->slabs) {
        repr << std::endl << it.show() ;
    }
    return repr.str();
}
double Problem::solve()
{
    double intensity = this->source;
    double exponent = 0;
    for (auto& it : this->slabs) {
        exponent += it.get_thickness() * it.get_material().get_sigma();
    }
    intensity *= exp(- exponent);
    return intensity;
}
std::shared_ptr<Problem> Problem::load_input(const std::string& filename) {
    std::ifstream inputdata;
    std::string mystring;
    double thick1, thick2;
    double sig;

    auto prob = std::make_shared<Problem>();

    inputdata.open(filename);
    if (!inputdata) {
        std::cerr << "Non-existing input file" << std::endl;
    } else {
        inputdata >> mystring;
        thick1 = std::stod(mystring);
        inputdata >> mystring;
        thick2 = std::stod(mystring);

        inputdata >> mystring;
        sig = std::stod(mystring);
        auto mat1 = std::make_shared<Material>(sig);
        inputdata >> mystring;
        sig = std::stod(mystring);
        auto mat2 = std::make_shared<Material>(sig);

        auto slab1 = std::make_shared<Slab>(thick1, mat1);
        auto slab2 = std::make_shared<Slab>(thick2, mat2);

        inputdata >> mystring;

        prob->add_slab(*slab1);
        prob->add_slab(*slab2);
        prob->set_source(std::stod(mystring));
    }

    return prob;
}


int main(int argc, char* argv[])
{
    auto mat1 = std::make_shared<Material>(3.1e-3);
    auto mat2 = std::make_shared<Material>(6.82e-2);
    //std::cout << mat1->show() << std::endl;
    //std::cout << mat2->show() << std::endl;

    auto slab1 = std::make_shared<Slab>(2.1, mat1);
    auto slab2 = std::make_shared<Slab>(1.2, mat2);
    //std::cout << slab1->show() << std::endl;
    //std::cout << slab2->show() << std::endl;

    auto src = std::make_shared<double>(57.33);
    //std::cout << *src << std::endl;

    std::vector<Slab> slabs{*slab1, *slab2};
    auto prob1 = std::make_shared<Problem>(*src, slabs);
    auto intensity = prob1->solve();
    std::cout << prob1->show() << std::endl;
    std::cout << "Result: " << prob1->solve() << std::endl;

    std::cout << std::endl;

    auto prob2 = Problem::load_input("data.txt");
    std::cout << prob2->show() << std::endl;
    std::cout << "Result: " << prob2->solve() << std::endl;

    return 0;
}
