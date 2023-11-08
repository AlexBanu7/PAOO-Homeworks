#include <credit_card/credit_card.hpp>
#include <iostream>

using namespace std;

int main() {
    // using the normal constructor
    credit_card::CreditCard ingCard(
        "1111 2222 3333 4444",
        "08/27",
        "Costel",
        "000"
    );
    cout<<"The owner of the ingCard is: "<<ingCard.get_owner()<<endl;
    // using the copy constructor
    credit_card::CreditCard bcrCard = ingCard;
    cout<<"The owner of the bcrCard is: "<<bcrCard.get_owner()<<endl;

    credit_card::CreditCard brdCard(
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