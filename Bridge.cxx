/*  Bridge Design Pattern
    Decouple an abstraction from the its implementation so  that two can vary independently.
    This pattern used to separate an abstraction
*/
#include <iostream>

class PaymentSystem
{
public:
    virtual void ProcessPayment(std::string paymentSystem) = 0;
};

class CitiBankPaymentSystem : public PaymentSystem
{
public:
    virtual void ProcessPayment(std::string paymentSystem)
    {
        std::cout << "Using CitiBankPayment Gatway for " << paymentSystem << std::endl;
    }
};

class IDBIPaymentSystem : public PaymentSystem
{
public:
    virtual void ProcessPayment(std::string paymentSystem)
    {
        std::cout << "Using IDBIPaymentSystem Gatway for " << paymentSystem << std::endl;
    }
};

class Payment
{

public:
    PaymentSystem *m_paymentSystem;
    virtual void MakePayment() = 0;
};

class CardPayment : public Payment
{
public:
    void MakePayment()
    {
        m_paymentSystem->ProcessPayment("Card Payment");
    }
};

class NetBankingPayment : public Payment
{
public:
    void MakePayment()
    {
        m_paymentSystem->ProcessPayment("NetBanking Payment");
    }
};

void main()
{
    Payment *order1 = new CardPayment();
    order1->m_paymentSystem = new CitiBankPaymentSystem();
    order1->MakePayment();
}