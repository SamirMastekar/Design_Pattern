#include <iostream>
#include <vector>
#include <memory>

class Command
{
public:
    ~Command() {}
    virtual void Execute() = 0;
};

class Light
{
public:
    void ON() { std::cout << "Light is ON" << std::endl; }
    void OFF() { std::cout << "Ligh is OFF" << std::endl; }
};

class LightONCommand : public Command
{
    Light *m_light;

public:
    LightONCommand(Light *light) : m_light(light) {}
    void Execute() { this->m_light->ON(); }
};

class LightOFFCommand : public Command
{
    Light *m_light;

public:
    LightOFFCommand(Light *light) : m_light(light) {}
    void Execute() { this->m_light->OFF(); }
};

class Remote
{
    std::vector<Command *> m_remote;

public:
    void SetCommand(Command *obj) { m_remote.push_back(obj); }
    void PressedButton(int i) { m_remote[i]->Execute(); }
};

int main()
{
    std::shared_ptr<Remote *> remoteObj = std::make_shared<Remote *>();
    std::shared_ptr<Light *> lightObj = std::make_shared<Light *>();

    std::shared_ptr<LightONCommand *> onObj = std::make_shared<LightONCommand *>(lightObj);
    std::shared_ptr<LightOFFCommand *> offObj = std::make_shared<LightOFFCommand *>(lightObj);

    (*remoteObj.get())->SetCommand(*onObj);
    (*remoteObj.get())->SetCommand(*offObj);

    (*remoteObj.get())->PressedButton(0);
    (*remoteObj.get())->PressedButton(1);
};
