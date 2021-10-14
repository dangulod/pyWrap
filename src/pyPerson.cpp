#include "person.hpp"
#include <boost/python.hpp>


BOOST_PYTHON_MODULE(_person)
{
    using namespace boost::python;
    def("greet", pyWrap::helloWorld);

    class_<pyWrap::Person>("Person",
                           init<std::string, int>())
            .add_property("name", &pyWrap::Person::get_name, &pyWrap::Person::set_name)
            .add_property("age", &pyWrap::Person::get_age, &pyWrap::Person::set_age)
            .def("greetings", &pyWrap::Person::greetings)
            .def("add_years", &pyWrap::Person::add_years)
            .def("parallel_hello_world", &pyWrap::Person::parallel_hello_world)
            ;
}
