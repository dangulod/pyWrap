#include "animal.hpp"
#include <boost/python.hpp>


BOOST_PYTHON_MODULE(_animal)
{
    using namespace boost::python;

    class_<pyWrap::Animal>("Animal",
                           init<std::string, int>())
            .add_property("name", &pyWrap::Animal::get_name, &pyWrap::Animal::set_name)
            .add_property("age", &pyWrap::Animal::get_age, &pyWrap::Animal::set_age)
            .def("greetings", &pyWrap::Animal::greetings)
            ;
}
