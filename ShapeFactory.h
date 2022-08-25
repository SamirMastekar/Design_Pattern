#pragma once
#include <iostream>

class Shape {
protected:
    int id;
    static int total;
public:
    Shape() {
        id = total++;
    }
    virtual void Draw() = 0; //Pure Virtual Method
};

class Circle : public Shape {
public:
    void Draw() {
        std::cout << "Cirle ID:- " << id << std::endl;
    }
};

class Ellipse : public Shape {
public:
    void Draw() {
        std::cout << "Ellipse ID:- " << id << std::endl;
    }
};

class Squar : public Shape {
public:
    void Draw() {
        std::cout << "Square ID:- " << id << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void Draw() {
        std::cout << "Rectangle ID:- " << id << std::endl;
    }
};
