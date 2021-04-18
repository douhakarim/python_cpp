#include <pybind11/pybind11.h>
char version[]="1.0";

char const* getVersion() {
	return version;
}

class Cle
{
    public:
        Cle(){}
        ~Cle() {}

        void initialize(std::string &cle) { 
		clePrivee=cle;
		}
		
        const std::string &getPrivateKey() const { return clePrivee; }
		const std::string &getPublicKey() const { return clePublique; }

    private:
        std::string clePrivee;
        std::string clePublique;
};
 
namespace py = pybind11;


PYBIND11_MODULE(cle_component,greetings)
{
  greetings.doc() = "greeting_object 1.0";
  greetings.def("getVersion", &getVersion, "a function returning the version");
      py::class_<Cle>(greetings, "Cle")
        .def(py::init())
        .def("initialize", &Cle::initialize)
        .def("getPrivateKey", &Cle::getPrivateKey)
        .def("getPublicKey", &Cle::getPublicKey);
}