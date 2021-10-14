#include <iostream>
#include <string>

namespace pyWrap {

    class Animal
    {
    private:
        std::string m_name;
        int m_age;

    public:
        Animal(std::string name, int age):
            m_name(name), m_age(age) { }
        ~Animal() = default;

        std::string get_name()
        {
            return this->m_name;
        }

        void set_name(std::string value)
        {
            if (this->m_name != value)
            {
                this->m_name = value;
            }
        }

        int get_age()
        {
            return this->m_age;
        }

        void set_age(int value)
        {
            if (this->m_age != value)
            {
                this->m_age = value;
            }
        }

        std::string greetings()
        {
            return "My name is "
                    + this->m_name
                    + " and my age is "
                    + std::to_string(this->m_age);
        }
    };

}




