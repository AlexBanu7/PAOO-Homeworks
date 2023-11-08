#include <credit_card/credit_card_config.hpp>
#include <credit_card/credit_card.hpp>
#include <cstring>


namespace credit_card {
using namespace std; // Allows you to use standard library functions without "std::"

CreditCard::CreditCard(const char* given_number, const char* given_expiry_date, const char* given_owner, const char* given_cvv) {
    number = static_cast<char*>(malloc(strlen(given_number) + 1));
    expiry_date = static_cast<char*>(malloc(strlen(given_expiry_date) + 1));
    owner = static_cast<char*>(malloc(strlen(given_owner) + 1));
    cvv = static_cast<char*>(malloc(strlen(given_cvv) + 1));
    strcpy(number, given_number);
    strcpy(expiry_date, given_expiry_date);
    strcpy(owner, given_owner);
    strcpy(cvv, given_cvv);
}   

CreditCard::~CreditCard() {
    free(number);
    free(expiry_date);
    free(owner);
    free(cvv);
}

CreditCard::CreditCard(const CreditCard& another_card){
    number = static_cast<char*>(malloc(strlen(another_card.number) + 1));
    expiry_date = static_cast<char*>(malloc(strlen(another_card.expiry_date) + 1));
    owner = static_cast<char*>(malloc(strlen(another_card.owner) + 1));
    cvv = static_cast<char*>(malloc(strlen(another_card.cvv) + 1));
    strcpy(number, another_card.number);
    strcpy(expiry_date, another_card.expiry_date);
    strcpy(owner, another_card.owner);
    strcpy(cvv, another_card.cvv);
}

CreditCard& CreditCard::operator=(const CreditCard& another_card) {
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

char* CreditCard::get_number() {
    return number;
}

char* CreditCard::get_expiry_date() {
    return expiry_date;
}

char* CreditCard::get_owner() {
    return owner;
}

char* CreditCard::get_cvv() {
    return cvv;
}
} // namespace credit_card