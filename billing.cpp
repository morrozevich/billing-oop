//
//  billing.cpp
//  test2.0
//
//  Created by nastya morozevich on 28/11/2023.
//

#include <iostream>
#include "billing.h"

int Billing::billingCount = 0;

Billing::Billing(std::string userName, std::string phoneNumber){
    this->userName = userName;
    this->phoneNumber = phoneNumber;
    billingCount++;
}
Billing::Billing(const Billing &other){
    this->userName = other.userName;
    this->phoneNumber = other.phoneNumber;
    this->phoneNumbers = other.phoneNumbers;
    this->callLengths = other.callLengths;
    billingCount++;
}
Billing& Billing::operator=(const Billing &other){
    if (this != &other){
        this->userName = other.userName;
        this->phoneNumber = other.phoneNumber;
        this->phoneNumbers = other.phoneNumbers;
        this->callLengths = other.callLengths;
    }
    return *this;
}
Billing::~Billing(){
    std::cout << "Deleting phone number " << phoneNumber << ".\n";
    billingCount--;
}

void Billing::setName(std::string newUserName){
    this->userName = newUserName;
}
std::string Billing::getName() const{
    return userName;
}
std::string Billing::getNumber() const{
    return phoneNumber;
}

void Billing::addCall(std::string phoneNumber, int length){
    if (this->phoneNumber == phoneNumber || length < 0)
        throw std::invalid_argument("Invalid data\n");
    phoneNumbers.push_back(phoneNumber);
    callLengths.push_back(length);
}
void Billing::removeCall(std::string phoneNumber){
    int i = 0; int count = 0;
    for (std::string number: phoneNumbers){
        if (phoneNumber == number){
            count++;
            phoneNumbers.erase(phoneNumbers.begin() + i);
            callLengths.erase(callLengths.begin() + i);
        }
        else
            i++;
    }
    if (count == 0)
        throw std::runtime_error("Number is not in the billing.\n");
}
int Billing::totalConnectionTime() const{
    int total = 0;
    for (int length: callLengths)
        total += length;
    return total;
}
int Billing::getBillingCount() const{
    return billingCount;
}
bool Billing::operator>(const Billing &other) const{
    return callLengths.size() > other.callLengths.size();
}

std::ostream &operator<<(std::ostream &os, const Billing &b){
    os << "User: " << b.userName << ", phone number: " << b.phoneNumber << std::endl;
    for (int i = 0; i < static_cast<int>(b.phoneNumbers.size()); i++)
        os << i + 1 << ". " << b.phoneNumbers[i] << ", duration: " << b.callLengths[i] << " min.\n";
    os << "Total: " << static_cast<double>(b.totalConnectionTime()) / 60 << " h.\n";
    return os;
}
