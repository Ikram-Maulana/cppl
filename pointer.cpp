#include <iostream>
using namespace std;

void luasLing(int *xPtr)
{
  *xPtr = 3.14 * (*xPtr) * (*xPtr);
};

int main()
{
  int x = 28;
  cout << "=============================" << endl;
  cout << "Ini adalah Program Pointer" << endl;
  cout << "Mencari rata-rata lingkaran" << endl;
  cout << "Oleh: Ikram Maulana (1930511075)" << endl;
  cout << "=============================" << endl;
  cout << "Nilai dari x: " << x << endl;
  cout << "Alamat dari x: " << &x << endl
       << endl;

  luasLing(&x);
  cout << "Alamat luas: " << &x << endl;
  cout << "Hasil luas lingkaran adalah: " << x << endl;
  cout << "=============================" << endl;

  return 0;
}