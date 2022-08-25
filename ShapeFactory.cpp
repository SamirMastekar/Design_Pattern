#include "ShapeFactory.h"
#include <memory>

int Shape::total = 0;
class Factory {
public:
    virtual Shape* CreateCurveInstance() = 0;
    virtual Shape* CreateStraightInstance() = 0;
};

class SimpleFactory : public Factory {
public:
    Shape* CreateCurveInstance() {
        return new Circle;
    }
    Shape* CreateStraightInstance() {
        return new Squar;
    }
};

class ComplexFactory : public Factory {
public:
    Shape* CreateCurveInstance() {
        return new Ellipse;
    }
    Shape* CreateStraightInstance() {
        return new Rectangle;
    }
};

int main() {
    int val = 1;

    Factory* fact = new SimpleFactory;


    Shape* shapes[2];

    shapes[0] = fact->CreateCurveInstance();
    shapes[1] = fact->CreateStraightInstance();

    int opt = 1;
    //auto newFactory;
    switch (opt)
    {
        case 1: 
        {
            auto newFactory = std::make_unique<SimpleFactory>();
            break;
        }
        case 2:
        {
            auto newFactory = std::make_unique<ComplexFactory>();;
            break;
        }

    }

    for (int i = 0; i < 2; i++) {
        shapes[i]->Draw();
    }


    return 0;
}