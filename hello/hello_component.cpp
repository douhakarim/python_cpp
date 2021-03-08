#include <pybind11/pybind11.h>

struct Country {
Country (const std::string &name) : name(name) { }
void setName(const std::string &name_) { name = name_; }
const std::string &getName() const { return name; }
void setCapital(const std::string &capital_) { capital = capital_; }
const std::string &getCapital() const { return capital; }


std::string name;
std::string capital;
};

namespace py = pybind11;


PYBIND11_MODULE(hello_component, m) {
py::class_<Country>(m, "Country")
.def(py::init<const std::string &>())
.def("setName", &Country::setName)
.def("getName", &Country::getName)
.def("setCapital",&Country::setCapital)
.def("getCapital",&Country::getCapital);
}

