/*       Template Design Method Pattern
    It is a behaviour design Pattern which provide skelaton to a an algorithm
    where sub operation let decide to a child class.

 */

#include <iostream>

class Base
{
public:
    // Template Method
    void Display()
    {
        Display1();
        Display2();
    }
    virtual void Display1() = 0;
    virtual void Display2() = 0;
};

class Child1 : public Base
{
public:
    void Display1() { std::cout << "I am from Display1 of Child1" << std::endl; }
    void Display2() { std::cout << "I am from Display2 of Child1" << std::endl; }
};

class Child2 : public Base
{
public:
    void Display1() { std::cout << "I am from Display1 of Child2" << std::endl; }
    void Display2() { std::cout << "I am from Display2 of Child2" << std::endl; }
};

int main()
{
    Child1 *ch1 = new Child1();
    ch1->Display();

    Child2 *ch2 = new Child2();
    ch2->Display();

    return 0;

    /*
    I am from Display1 of Child1
    I am from Display2 of Child1
    I am from Display1 of Child2
    I am from Display2 of Child2
    */
}