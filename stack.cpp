#include <iostream>
// Maksimum data stack
#define max_stack 15
using namespace std;

//Deklarasi struct tumpukan
struct Stack
{
  int top, data[max_stack];
} tumpukan;

// Iniliasisasi nilai top
void init()
{
  tumpukan.top = -1;
}

// Memeriksa apakah tumpukan kosong
bool isEmpty()
{
  return tumpukan.top == -1;
}

// Memeriksa apakah tumpukan penuh
bool isFull()
{
  return tumpukan.top == max_stack - 1;
}

// Menambahkan data ke tumpukan
void push()
{
  if (isFull())
  {
    cout << "\nTumpukan sudah penuh" << endl;
  }
  else
  {
    tumpukan.top++;
    cout << "\nMasukan data = ";
    cin >> tumpukan.data[tumpukan.top];
    cout << "Data " << tumpukan.data[tumpukan.top] << " masuk ke stack" << endl;
  }
}

// Mengambil data dari tumpukan
void pop()
{
  if (isFull())
  {
    cout << "\nData Kosong\n";
  }
  else
  {
    cout << "\nData " << tumpukan.data[tumpukan.top] << " sudah terambil" << endl;
    tumpukan.top--;
  }
}

// Menampilkan data
void printStack()
{
  if (isEmpty())
  {
    cout << "Tumpukan Kosong";
  }
  else
  {
    cout << "\nTumpukan : ";
    for (int i = tumpukan.top; i >= 0; i--)
      cout << tumpukan.data[i] << ((i == 0) ? "" : ",");
  }
}

// Menampilkan menu
int main()
{
  int pilihan;
  init();
  do
  {
    printStack();
    cout << "\n1. Input (Push)\n"
         << "2. Hapus (Pop)\n"
         << "3. Keluar\n"
         << "Masukkan Pilihan: ";
    cin >> pilihan;
    switch (pilihan)
    {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    default:
      cout << "Pilihan tidak tersedia" << endl;
      break;
    }
  } while (pilihan != 3);
}
