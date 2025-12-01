/*Задача 3. Рассмотрите следующую программу. Какое свойство операций * и &
демонстрирует этот пример.*/
#include <iostream>
using namespace std;

int main() 
{
    int a;int *Ptr;
    a=7; Ptr=&a;
    cout<<"Адрес a "<<&a<<"\nЗначение указателя Ptr "<<Ptr;
    cout<<"\nЗначение a="<<a<<"\nЗначение на которое указывает Ptr="<<*Ptr;
    cout<<"\n&*Ptr="<<&*Ptr<<"\n*&Ptr="<<*&Ptr<<endl;
    return 0;
}