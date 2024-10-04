#ifndef BILLING_H
#define BILLING_H
#include <vector>
#include <string>

class Billing{
    static int billingCount;
    std::string userName;
    std::string phoneNumber;
    std::vector<std::string> phoneNumbers;
    std::vector<int> callLengths;
public:
    Billing(std::string userName = "", std::string phoneNumber = "");
    Billing(const Billing &other);
    Billing &operator=(const Billing &other);
    ~Billing();
    
    void setName(std::string newUserName);
    std::string getName() const;
    std::string getNumber() const;
    
    void addCall(std::string phoneNumber, int length);
    void removeCall(std::string phoneNumber);
    int totalConnectionTime() const;
    int getBillingCount() const;
    bool operator>(const Billing &other) const;
    
    friend std::ostream &operator<<(std::ostream &os, const Billing &b);
};


#endif
