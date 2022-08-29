#include <iostream>

class Button {
public:
    virtual void Pressed() = 0;
};

class WinButton : public Button {
public:
    void Pressed() {
        std::cout << "Window Button is Pressed" << std::endl;
    }
};

class MacButton : public Button {
public:
    void Pressed() {
        std::cout << "Mac Button is Pressed" << std::endl;
    }
};

class TextBox {
public:
    virtual void ShowTextBox() = 0;
};

class WinTextBox : public TextBox {
public:
    void ShowTextBox() {
        std::cout << "Window texxtbox is showed" << std::endl;
    }
};

class MacTextBox : public TextBox {
public:
    void ShowTextBox() {
        std::cout << "Mac texxtbox is showed" << std::endl;
    }
};

class Factory {
public:
    virtual Button* CreateButton() = 0;
    virtual TextBox* ShowTextBox() = 0;
};

class WinFactory : public Factory {
public:
    Button* CreateButton() {
        return new WinButton();
    }
    TextBox* ShowTextBox() {
        return new WinTextBox();
    }
};

class MacFactory : public Factory {
public:
    Button* CreateButton() {
        return new MacButton();
    }
    TextBox* ShowTextBox() {
        return new MacTextBox();
    }
};

class GUIFactory {
public:
    static Factory* CreateFactory(std::string osType) {
        if (osType == "WIN")
            return new WinFactory();
        else if (osType == "MAC")
            return new MacFactory();
        return NULL;
    }
};

int main() {

    Factory* factory = GUIFactory::CreateFactory("MAC");

    Button* button = factory->CreateButton();
    button->Pressed();

    TextBox* textbox = factory->ShowTextBox();
    textbox->ShowTextBox();
}