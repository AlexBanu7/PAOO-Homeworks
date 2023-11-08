#ifndef CREDIT_CARD_HPP
#define CREDIT_CARD_HPP


namespace credit_card {

class CreditCard {
private:
    char* number;
    char* expiry_date;
    char* owner;
    char* cvv;

public:
    CreditCard(const char* given_number, const char* given_expiry_date, const char* given_owner, const char* given_cvv);  

    ~CreditCard();

    CreditCard(const CreditCard& another_card);

    CreditCard& operator=(const CreditCard& another_card);

public:
    char* get_number();

    char* get_expiry_date();

    char* get_owner();

    char* get_cvv();
};

} // namespace credit_card

#endif



