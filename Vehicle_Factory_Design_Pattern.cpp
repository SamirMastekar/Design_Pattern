#include <iostream>
#include <string>

class Vehicle {
public:
    virtual void CreateVehicle() = 0;
};

class Bike : public Vehicle {
public:
    void CreateVehicle() {
        std::cout << "Bike Creating" << std::endl;
    }
};

class Car : public Vehicle {
public:
    void CreateVehicle() {
        std::cout << "Car Creating" << std::endl;
    }
};

class VehicleFactory {
public:
    static Vehicle* GetVehicleFactory(std::string type) {
        Vehicle* vobj = NULL;
        if (type == "BIKE")
            vobj = new Bike();
        else if (type == "CAR")
            vobj = new Car();

        return vobj;
    }
};

int main() {
    //ehicleFactory obj;
    std::string type = "BIKE";
    Vehicle* object = VehicleFactory::GetVehicleFactory(type); // Without object is possible due to static method
    object->CreateVehicle();

    return 0;
}