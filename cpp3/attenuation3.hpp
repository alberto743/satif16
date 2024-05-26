#ifndef ATTEN_H
#define ATTEN_H

#include <string>
#include <memory>
#include <vector>


class Material {
    double sigma;
public:
    Material(const double& s): sigma(s) {};
    virtual ~Material() {}

    std::string show() const;
    double& get_sigma();
};



class Slab {
    double thick;
    std::shared_ptr<Material> mat;
public:
    Slab(const double& t, const std::shared_ptr<Material>& m) : thick(t), mat(m) {}
    virtual ~Slab() {}

    std::string show() const;
    double& get_thickness();
    Material& get_material();
};



class Problem {
    double source;
    std::vector<Slab> slabs;
public:
    Problem() {}
    Problem(const double& src, const std::vector<Slab>& sl) : source(src), slabs(sl) {}
    virtual ~Problem() {}

    void add_slab(Slab&);
    Slab& get_slab(int);
    std::vector<Slab>& get_slabs();
    void set_source(double);
    double& get_source();
    std::string show() const;
    double solve();
};

#endif // ATTEN_H
