#include <iostream>
using namespace std;
// Definisi struktur Node
struct Node {
string data;
Node* next;
};
// Deklarasi variabel untuk front dan back
Node* front = nullptr;
Node* back = nullptr;
// Fungsi untuk mengecek apakah queue penuh (tidak relevan untuk linked list)
bool isFull() {
return false; // Linked list tidak terbatas ukuran
}
// Fungsi untuk mengecek apakah queue kosong
bool isEmpty() {
return front == nullptr;
}
// Fungsi untuk menambahkan elemen ke dalam queue
void enqueueAntrian(string data) {
Node* newNode = new Node(); // Membuat node baru
newNode->data = data; // Mengisi data pada node baru
newNode->next = nullptr; // Node baru menunjuk ke nullptr
// Jika queue kosong, set front dan back ke node baru
if (isEmpty()) {
front = back = newNode;
} else {
back->next = newNode; // Menambahkan node baru di belakang queue
back = newNode; // Update back ke node baru
}
}
// Fungsi untuk menghapus elemen dari queue
void dequeueAntrian() {
if (isEmpty()) {
cout << "Antrian kosong" << endl;
} else {
Node* temp = front; // Menyimpan node depan untuk dihapus
front = front->next; // Memindahkan front ke node berikutnya
if (front == nullptr) {
back = nullptr; // Jika queue menjadi kosong, set back ke nullptr
}
delete temp; // Menghapus node depan
}
}
// Fungsi untuk menghitung jumlah elemen dalam queue
int countQueue() {
int count = 0;
Node* temp = front;
while (temp != nullptr) {
count++;
temp = temp->next;
}
return count;
}
// Fungsi untuk menghapus semua elemen dalam queue
void clearQueue() {
while (!isEmpty()) {
dequeueAntrian();
}
}
// Fungsi untuk menampilkan elemen dalam queue
void viewQueue() {
cout << "Data antrian teller:" << endl;
Node* temp = front;
int index = 1;
while (temp != nullptr) {
cout << index << ". " << temp->data << endl;
temp = temp->next;
index++;
}
if (index == 1) {
cout << "Antrian kosong" << endl;
}
}
int main() {
// Menambahkan elemen ke dalam queue
enqueueAntrian("Andi");
enqueueAntrian("Maya");
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;
// Menghapus elemen dari queue
dequeueAntrian();
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;
// Menghapus semua elemen dari queue
clearQueue();
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;
return 0;
}