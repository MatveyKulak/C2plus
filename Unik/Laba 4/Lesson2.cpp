#include <iostream>

using namespace std;

int main() {
    char day1='1', day2='5', month='5'; // Ввести цифру(ы) дня рождения и месяца

    cout<<day1<<day2<<".0"<<month<<endl;

    cout<<static_cast<int>(day1)<<endl;

    cout<<static_cast<int>(day2)<<endl;

    cout<<static_cast<int>(month)<<endl;

    return 0;
}