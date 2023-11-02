#include <iostream>
#include <cstring>

using namespace std; // Allows you to use standard library functions without "std::"


class CreditCard {
private:
    char* number;
    char* expiry_date;
    char* owner;
    char* cvv;

public:
    CreditCard(const char* given_number, const char* given_expiry_date, const char* given_owner, const char* given_cvv) {
        number = static_cast<char*>(malloc(strlen(given_number) + 1));
        expiry_date = static_cast<char*>(malloc(strlen(given_expiry_date) + 1));
        owner = static_cast<char*>(malloc(strlen(given_owner) + 1));
        cvv = static_cast<char*>(malloc(strlen(given_cvv) + 1));
        strcpy(number, given_number);
        strcpy(expiry_date, given_expiry_date);
        strcpy(owner, given_owner);
        strcpy(cvv, given_cvv);
    }   

    ~CreditCard() {
        free(number);
        free(expiry_date);
        free(owner);
        free(cvv);
    }

    CreditCard(const CreditCard& another_card){
        number = static_cast<char*>(malloc(strlen(another_card.number) + 1));
        expiry_date = static_cast<char*>(malloc(strlen(another_card.expiry_date) + 1));
        owner = static_cast<char*>(malloc(strlen(another_card.owner) + 1));
        cvv = static_cast<char*>(malloc(strlen(another_card.cvv) + 1));
        strcpy(number, another_card.number);
        strcpy(expiry_date, another_card.expiry_date);
        strcpy(owner, another_card.owner);
        strcpy(cvv, another_card.cvv);
    }

    CreditCard& operator=(const CreditCard& another_card) {
        if(this == &another_card){
            return *this;
        }

        free(number);
        free(expiry_date);
        free(owner);
        free(cvv);

        number = static_cast<char*>(malloc(strlen(another_card.number) + 1));
        expiry_date = static_cast<char*>(malloc(strlen(another_card.expiry_date) + 1));
        owner = static_cast<char*>(malloc(strlen(another_card.owner) + 1));
        cvv = static_cast<char*>(malloc(strlen(another_card.cvv) + 1));
        strcpy(number, another_card.number);
        strcpy(expiry_date, another_card.expiry_date);
        strcpy(owner, another_card.owner);
        strcpy(cvv, another_card.cvv);

        return *this;
    }

    char* get_number() {
        return number;
    }

    char* get_expiry_date() {
        return expiry_date;
    }

    char* get_owner() {
        return owner;
    }

    char* get_cvv() {
        return cvv;
    }
};


int main() {
    // using the normal constructor
    CreditCard ingCard(
        "1111 2222 3333 4444",
        "08/27",
        "Costel",
        "000"
    );
    cout<<"The owner of the ingCard is: "<<ingCard.get_owner()<<endl;
    // using the copy constructor
    CreditCard bcrCard = ingCard;
    cout<<"The owner of the bcrCard is: "<<bcrCard.get_owner()<<endl;

    CreditCard brdCard(
        "4444 3333 2222 1111",
        "07/26",
        "Marian",
        "000"
    );
    // using the overloaded assignment operator ( = )
    bcrCard = brdCard;
    cout<<"The new owner of the bcrCard is: "<<bcrCard.get_owner()<<endl;
    return 0;
}