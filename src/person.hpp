#include <iostream>
#include <string>
#include <vector>
#include <thread>

namespace pyWrap {

void helloWorld()
{
    std::cout << "Hello World!" << std::endl;
}

class Person
{
private:
    std::string m_name;
    int m_age;

public:
    Person() = default;
    Person(std::string name, int age) :
        m_name(name), m_age(age) { }
    ~Person() = default;

    void set_name(std::string value)
    {
        if (this->m_name != value)
        {
            this->m_name = value;
        }
    }

    std::string get_name()
    {
        return this->m_name;
    }

    void set_age(int value)
    {
        if (value < 0)
        {
            std::cout << "value " << value << " < 0" << std::endl;
            throw std::runtime_error("Age must be greater than 0");
        }

        if (this->m_age != value)
        {
            this->m_age = value;
        }
    }

    int get_age()
    {
        return this->m_age;
    }

    std::string greetings()
    {
        return "My name is "
                + this->m_name
                + " and my age is "
                + std::to_string(this->m_age);
    }

    void add_years(int years)
    {
        if (years < 0)
        {
            std::runtime_error("Years must be greater than 0");
        }

        this->m_age += years;
    }

    void hello_world(size_t index)
    {
        std::cout << "Hello World! - " << index << std::endl;
    }

    void p_hello_world(size_t index, size_t n, size_t thread_numbers)
    {
        while (index < n)
        {
            this->hello_world(index);
            index += thread_numbers;
        }
    }

    void parallel_hello_world(size_t n, size_t thread_numbers = std::thread::hardware_concurrency())
    {
        std::vector<std::thread> threads_collection(thread_numbers);

        for (size_t ii_thread = 0; ii_thread < thread_numbers; ii_thread++)
        {
            threads_collection.at(ii_thread) = std::thread(&Person::p_hello_world, this, ii_thread, n, thread_numbers);
        }

        for (size_t ii_thread = 0; ii_thread < thread_numbers; ii_thread++)
        {
            threads_collection.at(ii_thread).join();
        }
    }
};
}
