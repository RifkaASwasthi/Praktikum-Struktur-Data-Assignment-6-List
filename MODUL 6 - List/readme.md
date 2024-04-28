# <h1 align="center">Laporan Praktikum Modul 6 LIST </h1>
<p align="center">Rifka Annisa Swasthi</p>

## Dasar Teori
List mengalokasikan ruang untuk setiap elemen untuk setiap elemen secara terpisah di bloknya sendiri. Daftar yang didapat adalah keseluruhan dangan menggunakan pointer untuk menghubungkan semua nodenya bersama-sama seperti tautan dalam sebuah rantai. [1] Setiap node berisi dua bidang yaitu bidang data untuk menyimpan jenis elemen apapun yang dimiliki daftar dan kolom berikutnya yang merupakan petunjuk yang digunakan untuk mengubungkan satu node ke node berukutnya.
Konsep dasar dari linked list adalah bahwa setiap data mengandung dua bagian utama yaitu data dan pointer. Data mewakili informasi yang ingin disimpan, misalnya bilangan, teks atau obyek lain. sementara pointer disebut next pointer menunjuk simpil berikutnya dalam urutan.


Penambahan elemen:

1. Penambahan di awal/insertion at the begining

Mengisi node baru, mnegisi datanya dan mengatu rpointer node baru untuk mennjuk ke node yang saat ini menjadi head

2. Penambahan di akhir/ insertion at the end

Membuat node baru, mengisi data dan mengatur pointer node terakhir dalam linked list menunjuk ke node baru.

3. Penambahan di tengah/ Insertion in the middle

Membuat node baru, emngisi datnya dan mencari posisi yagn tepat dimana node baru ditambahkan.

Penghapusan elemen

1. Penghapusna di awal / Deletion at the begining dengan mengubah pointer head untuk menunjuk ke node kedua dalam linked list

2. Penghapusan di akhir/ deletion in the middle dengan mencari node terakhir dan mengubah pointer node sebelumnya mennunjuk ke null

3. Penghapusan di tengah/ deletion inthe middle dengan cara mencari posisi node yang ingin dihapus [2]

Tipe Linked List

1. Singly Linked List

Hanya bisa melewati satu kali, memiliki efisiensi yang besar karena hanya referense per node, insertion dan deletion operasi lebih mudah karena hanya membutuhkan update references di satu perintah

2. Doublly Linked List

Mempunyai tranversal di dua perintah yaitu selanjutnya dan sebelunya, membutuhkan lebih banyak memori jika dibandingkan dnegan linked list karena setiap node punya dua pointer yatu next and previous
membutuhkan mengupdate tiap perintah forward dan backward yang dapat memengaruhi compleksitas dan performance.

3. Circular Linked Liat

Ketika node terakhir kembali ke node awal mengguankan circle atau loop, efisiean dibagian ketika node di pertengahan tidak perlu kembali ke awal karena struktur ini akna menyelesaikan dahulu sampai akhir baru kembali ke awal. memory effisiensy hampir sama dnegan singled link list [3]

Struktur data linked-listdigunakan karena 
karakter dari linked-list yang berbentuk sekuen (urutan) dengan alokasi memori dinamis yang dinilai lebih efisien 
dibandingkan dengan list berbasis array yang kebutuhan memorinya bersifat statis.[4] 

Dalam penerapannya Linked list banyak  dipilih karena stok data selalu tumbuh. [5]


## Guided 

### 1. Latihan Single Linked List

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}

```
Kode di atas digunakan untuk memberikan contoh penggunaab Linked List Non- Circular dengan beberapa operasi dasar seperti penambahan, penghapusan, peribahan, dan penampilan data pada linked list. dengan mendelkarasikan struct node menggunakan variabel untuk menyimpan alamat dari node pertama head dan tail untuk menyimoan alamat node terakhir. fungsi init digunkan yntyk menginisialisasi linked list dengan mengatur heas dan tail. fuungsi main linked list diinisaisi fungsi init, di sertai insertDepan, insertBelakang, hapusDepan, hapusBelakang, insertTengah, hapusTengah, ubahDepan, ubahBelakang, ubahTengah, dan tampil untuk menunjukkan hasil operasi tersebut pada Linked List.

### 2. Latihan Double Linked List


```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}

```
Kode di atas adalah contoh dari double linked list. Node memiliki tiga atribut int data, Node prev dan Node Next.menggunakan fungsi main yang terdapat objek double linked list, program menampilkan menu pilihan untuk menambah data , menghaous data, memperbaharui data, menghapus semua data, menampilkan data dan keluar dari program. program menggunakan switch untuk memproses pilihan pengguna dan memanggil metode yang sesuai dari objek.

### 3. Circular and circular list

```C++
#include <iostream>
using namespace std;

///Program Single Linked List Circular

// Deklarasi Struct Node
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init(){
    head = NULL;
    tail = head;
}

//Pengecekan
int isEmpty() {
    if (head == NULL)
        return 1; //true
    else
        return 0; //false
}

// Buat Node Baru
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL){
        jumlah++;
        bantu = bantu -> next;
    }

    return jumlah;
}

// Tambah depan
void insertDepan(string data) {
    //Buat Node baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah belakang
void insetBelakang(string data) {
    //Buat Node Baru
    buatNode(data);

    if(isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;

        //transvering
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if(hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        }else{
            while (tail->next != hapus){
                tail = tail->next;  
            }
            head = head->next;
            tail->next= head;
            hapus->next=NULL;
            delete hapus;
        }
    } else{
        cout << "Liat masih kosong!" << endl;
    }
}
// Hapus Belakang
void hapusbelakang (){
    if (isEmpty() == 0){
        hapus = head;
        tail = head;

        if(hapus-> next ==  head){
            head = NULL;
            tail = NULL;
            delete hapus;
        } else{
            while (hapus->next != head){
                hapus = hapus-> next;
            }
            while (tail ->next!= hapus){
                tail = tail->next;
            }
            tail-> next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }else{
        cout << "List masih kosing!" << endl;
    }

}
//Hapus Tengah
void Hapustengah (int posisi) {
    if (isEmpty() == 0) {
        //transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi -1){
            bantu = bantu ->next;
            nomor++;
        }
        
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList(){
    if (head != NULL){
        hapus = head->next;

        while ( hapus != head){
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
         }
         delete head;
         head = NULL;
    }
    cout << "List berhasil terhpus!" << endl;
}
// Tampilkan list
void tampil() {
    if(isEmpty()== 0){
        tail = head;

        do {
            cout << tail->data << ends;
            tail = tail->next;
        }while (tail != head);

        cout << endl;
        
    } else {
        cout << "List masih kosong!" << endl;
    }
}
 int main(){
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insetBelakang("Cicak"); 
    tampil();
    insetBelakang("Domba");
    tampil();
    hapusbelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    Hapustengah(2);
    tampil();
    return 0;
 }
```
Kode di atas adalah contoh dari single linked list circular menggunakan deklarasi struct node yang memiliki dua atribut yaitu string data utnuk menyimpan data dan node next untuk menunjukkna node selanjutnya. menggunakan deklarasi head, tail, baru, bantu, hapus. metode init unutk menginisiasi head dan tail menjadi null. metode is empty untuk mengembalikan 1 jika linked list kosong, metode buatnode unthk menambahkan node baru, metode hitung list untuk menghitung jumlah node dalam linked list dst. fungsi main untuk meneginisiasi menggunakan init, program melakukan serangkaian operasi seperti menambahkan node di depan, belakang, tengah, menhapus node dan menampilkan isi linked list. setiap operasi diikuti pemanggilan tampil(), untuk menampilkan isi linked list.

## Unguided 

### 1. Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. 
```C++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[50];
    char nim[20];
    struct node* next;
} Node;

Node* createNode(char* name, char* nim) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->nim, nim);
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, char* name, char* nim) {
    Node* newNode = createNode(name, nim);
    newNode->next = *head;
    *head = newNode;
}

void addEnd(Node** head, char* name, char* nim) {
    Node* newNode = createNode(name, nim);
    Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void addMiddle(Node** head, char* name, char* nim) {
    Node* newNode = createNode(name, nim);
    Node* temp = *head;
    Node* prev = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        newNode->next = prev->next;
        prev->next = newNode;
    }

    printf("Data telah ditambahkan\n");
}

void updateFront(Node** head, char* newName, char* newNim) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    strcpy((*head)->name, newName);
    strcpy((*head)->nim, newNim);
    printf("Data %s telah diganti dengan data %s\n", newName, (*head)->name);
}

void updateEnd(Node** head, char* newName, char* newNim) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    strcpy(temp->name, newName);
    strcpy(temp->nim, newNim);
    printf("Data %s telah diganti dengan data %s\n", newName, temp->name);
}

void updateMiddle(Node** head, char* newName, char* newNim, char* targetNim) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* temp = *head;
    while (temp != NULL && strcmp(temp->nim, targetNim) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("NIM tidak ditemukan.\n");
        return;
    }

    strcpy(temp->name, newName);
    strcpy(temp->nim, newNim);
    printf("Data telah diganti untuk NIM %s\n", targetNim);
}

void deleteFront(Node** head) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    printf("Data %s berhasil dihapus\n", temp->name);
    free(temp);
}

void deleteEnd(Node** head) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* prev = NULL;
    Node* current = *head;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }

    printf("Data %s berhasil dihapus\n", current->name);
    free(current);
}

void deleteMiddle(Node** head, char* targetNim) {
    if (*head == NULL) {
        printf("List kosong.\n");
        return;
    }

    Node* prev = NULL;
    Node* current = *head;

    while (current != NULL && strcmp(current->nim, targetNim) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("NIM tidak ditemukan.\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    printf("Data %s berhasil dihapus\n", current->name);
    free(current);
}

void freeList(Node** head) {
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("Nama: %s, NIM: %s\n", temp->name, temp->nim);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    int choice;
    char name[50], nim[20], targetNim[20];

    while (1) {
        printf("\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR\n");
        printf("1. Tambah Depan\n");
        printf("2. Tambah Belakang\n");
        printf("3. Tambah Tengah\n");
        printf("4. Ubah Depan\n");
        printf("5. Ubah Belakang\n");
        printf("6. Ubah Tengah\n");
        printf("7. Hapus Depan\n");
        printf("8. Hapus Belakang\n");
        printf("9. Hapus Tengah\n");
        printf("10. Hapus List\n");
        printf("11. TAMPILKAN\n");
        printf("0. KELUAR\n");
        printf("Pilih Operasi : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan Nama: ");
                scanf("%s", name);
                printf("Masukkan NIM: ");
                scanf("%s", nim);
                addNode(&head, name, nim);
                break;
            case 2:
                printf("Masukkan Nama: ");
                scanf("%s", name);
                printf("Masukkan NIM: ");
                scanf("%s", nim);
                addEnd(&head, name, nim);
                printf("Data telah ditambahkan\n");
                break;
            case 3:
                printf("Masukkan Nama: ");
                scanf("%s", name);
                printf("Masukkan NIM: ");
                scanf("%s", nim);
                addMiddle(&head, name, nim);
                break;
            case 4:
                printf("Masukkan Nama Baru: ");
                scanf("%s", name);
                printf("Masukkan NIM Baru: ");
                scanf("%s", nim);
                updateFront(&head, name, nim);
                break;
            case 5:
                printf("Masukkan Nama Baru: "); 
                scanf("%s", name);
                printf("Masukkan NIM Baru: ");
                scanf("%s", nim);
                updateEnd(&head, name, nim);
                break;
            case 6:
                printf("Masukkan Nama Baru: ");
                scanf("%s", name);
                printf("Masukkan NIM Baru: ");
                scanf("%s", nim);
                printf("Masukkan NIM Target: ");
                scanf("%s", targetNim);
                updateMiddle(&head, name, nim, targetNim);
                break;
            case 7:
                deleteFront(&head);
                break;
            case 8:
                deleteEnd(&head);
                break;
            case 9:
                printf("Masukkan NIM Target: ");
                scanf("%s", targetNim);
                deleteMiddle(&head, targetNim);
                break;
            case 10:
                freeList(&head);
                printf("Semua data telah dihapus.\n");
                break;
            case 11:
                displayList(head);
                break;
            case 0:
                exit(0);
            default:
                printf("Operasi tidak valid.\n");
        }
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-04-29 023347](https://github.com/RifkaASwasthi/Praktikum-Struktur-Data-Assignment-6-List/assets/162097297/f82c26c1-0a34-481d-80e9-61c22258b88e)


Kode di atasadalah contoh dari single linked list non-circular. menggunaakn strultur node string nama, int nim dan node next. menggunakan metode tambah node, tambah depan, tambah belaknang, tampilkan list dan fungsi main utnuk menginisiasi head dengan null. program membarikan menu operasi yang terdapat menambahkan data di depan atau belakagf, mengubah data, menghapus data dan menampilkan data. setiap operasi diimplementasikan menggunakan metode yang teah didefinisikan sebelumnya.

#### Full code Screenshot:
![Screenshot 2024-04-29 023438](https://github.com/RifkaASwasthi/Praktikum-Struktur-Data-Assignment-6-List/assets/162097297/e1459fff-5ec4-4da1-8180-3d323274f51f)



## Kesimpulan

Linked-list merupakan pengembangan atau modifikasi dari struktur data list dan terbentuk dari serangkaian objek-objek, 
yang disebut dengan node. Kebutuhan memori pada linked-list bersifat dinamis dimana kebutuhan memori akan bertambah ketika terdapat elemen list yang baru terdapat empat jenisa macam linked list yitu circular linked list, non circular linked list, double linked list dan single linked list.

## Referensi
[1] Nick Parlante. 2001, "Linked List
Basics", San Fransisco Bay Area: Cslibrary stanford edu.

[2] Riczky Pratama. 2023, "Panduan Lengkap Mengenai Linked List: Definisi, Implementasi, dan Penggunaan dalam Pemrograman", Medium.

[3] Sule-Balogun Olanrewaju Ganiu. 2024, "What is a Linked list? Types of Linked List with Code Examples"
, Free Code Camp.

[4] Danang Wahyu Wicaksono, Mohammad Isa Irawan, dan Alvida Mustika Rukmi. 2014, "Sistem Deteksi Kemiripan Antar Dokumen Teks 
Menggunakan Model Bayesian Pada Term 
Latent Semantic Analysis (LSA)"
,Matematika, Fakultas Matematika dan Ilmu Pengetahuan Alam, Institut Teknologi Sepuluh Nopember (ITS)
Jl. Arief Rahman Hakim, Surabaya 60111 Indonesia: JURNAL SAINS DAN SENI POMITS Vol. 3, No. 2.

[5] Doohan Kristiawan1, Rosita Herawati2. 2018, "COMPARISON OF STOCK PRICE PREDICTION 
ACCURACY WITH VARIATION NUMBER OF HIDDEN 
LAYER CELL IN BACKPROPAGATION ALGORITHM"
, Program Studi Teknik Informatika, Fakultas Ilmu Komputer, Universitas Katolik 
Soegijapranata: PROXIES VOL. 2 NO. 1.