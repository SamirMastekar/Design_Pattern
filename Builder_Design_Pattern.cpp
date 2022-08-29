#include <iostream>

class Desktop {
private:
    std::string ram;
    std::string Monitor;
    std::string keyboard;
    std::string mouse;
    std::string processor;
    std::string motherBoard;
    std::string speaker;
public:
    void SetRam(std::string ram) {
        this->ram = ram;
    }
    void SetMonitor(std::string monitor) {
        this->Monitor = monitor;
    }
    void SetKeyboard(std::string keyboard) {
        this->keyboard = keyboard;
    }
    void SetMouse(std::string mouse) {
        this->mouse = mouse;
    }
    void SetProcessor(std::string processor) {
        this->processor = processor;
    }
    void SetMotherBoard(std::string motherBoard) {
        this->motherBoard = motherBoard;
    }
    void Setspeaker(std::string speaker) {
        this->speaker = speaker;
    }
    void DisplaySpecification() {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "1: RAM        : " << ram         << std::endl;
        std::cout << "2: MONITOR    : " << Monitor     << std::endl;
        std::cout << "3: KEYBOARD   : " << keyboard    << std::endl;
        std::cout << "4: MOUSE      : " << mouse       << std::endl;
        std::cout << "5: PROCESSOR  : " << processor   << std::endl;
        std::cout << "6: MOTHERBOARD: " << motherBoard << std::endl;
        std::cout << "7: SPEAKER    : " << speaker     << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }
};

class DeskTopBuilder {
protected:
    Desktop* desktop;
public:
    DeskTopBuilder() {
        desktop = new Desktop();
    }
    virtual void BuildRam()         = 0;
    virtual void BuildMonitor()     = 0;
    virtual void BuildKeyBoard()    = 0;
    virtual void BuildMouse()       = 0;
    virtual void BuildProcessor()   = 0;
    virtual void BuildMotherBoard() = 0;
    virtual void BuildSpeaker()     = 0;
    virtual Desktop* GetDesktop() {
        return desktop;
    }
};

class DellDesktop : public DeskTopBuilder {
public:
    void BuildRam() {
        desktop->SetRam("Dell Ram");
    }
    void BuildMonitor() {
        desktop->SetMonitor("Dell Monitor");
    }
    void BuildKeyBoard() {
        desktop->SetKeyboard("Dell keyboard");
    }
    void BuildMouse() {
        desktop->SetMouse("Dell Mouse");
    }
    void BuildProcessor() {
        desktop->SetProcessor("Dell Processor");
    }
    void BuildMotherBoard() {
        desktop->SetMotherBoard("Dell MotherBoard");
    }
    void BuildSpeaker() {
        desktop->Setspeaker("Dell Speaker");
    }
};

class HPDesktop : public DeskTopBuilder {
public:
    void BuildRam() {
        desktop->SetRam("HP Ram");
    }
    void BuildMonitor() {
        desktop->SetMonitor("HP Monitor");
    }
    void BuildKeyBoard() {
        desktop->SetKeyboard("HP keyboard");
    }
    void BuildMouse() {
        desktop->SetMouse("HP Mouse");
    }
    void BuildProcessor() {
        desktop->SetProcessor("HP Processor");
    }
    void BuildMotherBoard() {
        desktop->SetMotherBoard("HP MotherBoard");
    }
    void BuildSpeaker() {
        desktop->Setspeaker("HP Speaker");
    }
};

class DeskTopDirector {
    DeskTopBuilder* desktopbuilder;
public:
    DeskTopDirector(DeskTopBuilder *obj) {
        desktopbuilder =obj;
    }
    Desktop* DesktopBuilder() {
        desktopbuilder->BuildRam();
        desktopbuilder->BuildMonitor();
        desktopbuilder->BuildKeyBoard();
        desktopbuilder->BuildMouse();
        desktopbuilder->BuildProcessor();
        desktopbuilder->BuildMotherBoard();
        desktopbuilder->BuildSpeaker();
        return desktopbuilder->GetDesktop();
    }
};
int main() {
    DellDesktop* dellModel = new DellDesktop();
    DeskTopDirector* dellDirector = new DeskTopDirector(dellModel);
    Desktop* dell = dellDirector->DesktopBuilder();
    dell->DisplaySpecification();

    HPDesktop* hpModel = new HPDesktop();
    DeskTopDirector* hpdirector = new DeskTopDirector(hpModel);
    Desktop* hp = hpdirector->DesktopBuilder();
    hp->DisplaySpecification();
    return 0;
}