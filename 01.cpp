#include <iostream>
using namespace std;

int main()
{
  int a = 5;

  // Pointer
  // int *aPtr = &a;

  // null pointer
  int *aPtr = nullptr;
  aPtr = &a;

  // int a mempunyai nilai dan address (alamat)
  cout << "nilai dari a: " << a << endl;
  /* cout << "Alamat dari a: " << aPtr << endl; */
  cout << "Null Pointer: " << aPtr << endl;

  // deferencing, mengambil data dari sebuah pointer
  a = 10;
  cout << "Mengambil nilai dari pointer aPtr: " << *aPtr;

  return 0;
}