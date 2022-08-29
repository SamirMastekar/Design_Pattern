#include <iostream>
#include <list>

class Subscriber {
public:
    virtual void Notify(std::string msg) = 0;
};

class User : public Subscriber {
private:
    unsigned int id;
public:
    User(unsigned int id) : id(id) {}
    void Notify(std::string msg) {
        std::cout << "Message Received for User "<< id << " " << msg << std::endl;
    }
};

class Group {
private :
    std::list<Subscriber*> noSubscriber;
public:
    void AddSubscriber(Subscriber* user) {
        noSubscriber.push_back(user);
    }

    void RemoveSubscriber(Subscriber* user) {
        noSubscriber.remove(user);
    }

    void SendMessage(std::string msg) {
        for (auto user : noSubscriber)
            user->Notify(msg);
    }
};

int main() {
    Group *newGroup = new Group();

    User *usr1 = new User(1);
    User *usr2 = new User(2);
    User *usr3 = new User(3);

    newGroup->AddSubscriber(usr1);
    newGroup->AddSubscriber(usr2);
    newGroup->AddSubscriber(usr3);

    newGroup->SendMessage("Hello I am samir");


    newGroup->RemoveSubscriber(usr2);
    newGroup->SendMessage("Hello, how are you");
    return 0;
}