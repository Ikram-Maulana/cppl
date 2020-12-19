#include <iostream>
// Maksimum data queue
#define max_queue 15
using namespace std;

//Deklarasi struct antrian
struct Queue
{
  int front, rear, data[max_queue];
} q;

// cek apakah antrian penuh
bool isFull()
{
  return q.rear == max_queue;
}

// cek apakah antrian kosong
bool isEmpty()
{
  return q.rear == 0;
}

// menampilkan queue
void printQueue()
{
  if (isEmpty())
  {
    cout << "Antrian kosong" << endl;
  }
  else
  {
    cout << "QUEUE : ";
    for (int i = q.front; i < q.rear; i++)
      // Menambah koma jika data awal tidak ada di antrian pertama
      cout << q.data[i] << ((q.rear - 1 == i) ? "" : ",");
    cout << endl;
  }
}

//manambahkan data ke antrian
void enqueue()
{
  if (isFull())
  {
    cout << "Antrian penuh!" << endl;
  }
  else
  {
    int data;
    //menambahkan data ke antrian
    cout << "Masukkan Data : ";
    cin >> data;
    q.data[q.rear] = data;
    //menempatkan tail pada elemen data terakhir yang ditambahkan
    q.rear++;
    cout << "Data ditambahkan\n";
    printQueue();
  }
}

// mengambil data dari antrian
void dequeue()
{
  if (isEmpty())
  {
    cout << "Antrian masih kosong" << endl;
  }
  else
  {
    cout << "Mengambil data \"" << q.data[q.front] << "\"..." << endl;
    //menggeser antrian data ke head
    for (int i = q.front; i < q.rear; i++)
      q.data[i] = q.data[i + 1];
    //menempatkan tail pada data terakhir yang digeser
    q.rear--;
    printQueue();
  }
}

int main()
{
  int choose;
  do
  {
    //Tampilan menu
    cout << "-------------------\n"
         << "   Menu Pilihan\n"
         << "-------------------\n"
         << " [1] Enqueue \n"
         << " [2] Dequeue\n"
         << " [3] Keluar \n\n"
         << "-------------------\n"
         << "Masukkan pilihan : ";
    cin >> choose;
    switch (choose)
    {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
      break;
    default:
      cout << "Pilihan tidak tersedia";
      break;
    }
  } while (choose != 3);
  return 0;
}
