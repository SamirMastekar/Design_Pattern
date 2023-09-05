#include <iostream>
#include <unordered_map>

class Shape
{
public:
    virtual void Draw() = 0;
};

class Circle : public Shape
{
private:
    int x;
    int y;
    int radius;
    std::string colour;

public:
    Circle(std::string color) : colour(color) {}
    void SetX(int X) { x = X; }
    void SetY(int Y) { x = Y; }
    void SetRadius(int Radius) { radius = Radius; }
    void SetColor(std::string color) { colour = color; }
    void Draw() { std::cout << "Drawing Circle of colour " << colour << " :- (" << x << "," << y << ")" << std::endl; }
};

class ShapeFactory
{
    std::unordered_map<std::string, Circle *> circleMap;

public:
    Circle *GetCircle(std::string colour)
    {
        if (circleMap.find(colour) == circleMap.end())
        {
            Circle *obj = new Circle(colour);
            std::cout << "Not found " << colour << " inserting new one" << std::endl;
            circleMap.insert(std::make_pair(colour, obj));
        }
        else
        {
            std::cout << "Using existing " << colour << " object" << std::endl;
        }
        return circleMap.at(colour);
    }
};

int main()
{
    std::string colours[] = {"Red", "Blue", "Black", "Pink", "Black", "Red", "Yellow", "Green"};

    ShapeFactory shapeObj;
    for (auto colour : colours)
    {
        Circle *obj = shapeObj.GetCircle(colour);
        obj->SetX(rand() % 100);
        obj->SetY(rand() % 100);
        obj->SetRadius(rand() % 100);
        obj->Draw();
        std::cout << std::endl;
    }
    return 0;
}
