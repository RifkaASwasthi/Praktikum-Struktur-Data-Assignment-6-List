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