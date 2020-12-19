#include <iostream>
using namespace std;

void fungsi(int *b)
{
  cout << "Address b: " << b << endl;
  cout << "Nilai b: " << *b << endl
       << endl; //deferencing
}

void kuadrat(int *valPtr)
{
  *valPtr = (*valPtr) * (*valPtr);
}

int main()
{
  int a = 5;
  cout << "Address a: " << &a << endl;
  cout << "Nilai a: " << a << endl
       << endl;
  fungsi(&a); //Fungsi dengan input poiter

  kuadrat(&a);
  cout << "Nilai a: " << a << endl;

  return 0;
}