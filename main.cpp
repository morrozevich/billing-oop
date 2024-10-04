//
//  main.cpp
//  test2.0
//
//  Created by nastya morozevich on 28/11/2023.
//

#include <iostream>
#include "billing.h"

int main(int argc, const char * argv[]) {
    Billing b1("123456789", "User1");
        Billing b2("987654321", "User2");

        b1.addCall("987654321", 10);
        b1.addCall("111111111", 5);
        b2.addCall("123456789", 15);

        std::cout << b1;
        std::cout << b2;

        b1.removeCall("987654321");

        std::cout << "Total billings count: " << b1.getBillingCount() << std::endl;
    return 0;
}
