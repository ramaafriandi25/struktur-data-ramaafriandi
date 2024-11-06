#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
    struct node *prev;  // Pointer ke node sebelumnya
};

typedef struct node node;

// Pendeklarasi fungsi yang akan digunakan untuk menjalankan program ini
void tambahAwal(node **head);
void tambahAkhir(node **head);
void tambahData(node **head);
void tranverse(node *head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void pencarianData(node *head);
void jumlahData(node *head);
void penjumlahanData(node *head);

//========================================================

int main() {
    node *head = NULL;
    char pilih;
    // Pembuatan menu yang akan di tampilkan kepada user
    do {
        system("cls");
        printf("\t**********************************************\n");
        printf("\t*    SELAMAT DATANG PENIKMAT STRUKTUR DATA   *\n");
        printf("\t**********************************************\n");
        printf("Masukkan pilihan\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir\n");
        printf("4. Hapus data di awal\n");
        printf("5. Hapus data di tengah\n");
        printf("6. Hapus data di akhir\n");
        printf("7. Pencarian data\n");
        printf("8. Jumlah data\n");
        printf("9. Penjumlahan semua data\n");
        printf("10. Cetak isi list\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        fflush(stdin);
        scanf("%c", &pilih);
        // Eksekusi pilihan
        if (pilih == '1') {
            tambahAwal(&head);
        } else if (pilih == '2') {
            tambahData(&head);
        } else if (pilih == '3') {
            tambahAkhir(&head);
        } else if (pilih == '4') {
            hapusAwal(&head);
        } else if (pilih == '5') {
            hapusTengah(&head);
        } else if (pilih == '6') {
            hapusAkhir(&head);
        } else if (pilih == '7') {
            pencarianData(head);
        } else if (pilih == '8') {
            jumlahData(head);
        } else if (pilih == '9') {
            penjumlahanData(head);
        } else if (pilih == '10') {
            tranverse(head);
            getch();
        }
    } while (pilih != 'q');

    return 0;
}

//========================================================

void tambahAwal(node **head) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan: ");
    scanf("%d", &bil);
    
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        
        if (*head == NULL) {
            pNew->next = pNew;
            pNew->prev = pNew; // Jika list kosong, node pertama menunjuk dirinya sendiri
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pNew->next = *head;
            pNew->prev = pCur;
            pCur->next = pNew;
            (*head)->prev = pNew;  // Update prev dari head lama
            *head = pNew;          // Node baru menjadi head
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan: ");
    scanf("%d", &bil);
    
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;

        if (*head == NULL) {
            pNew->next = pNew;
            pNew->prev = pNew;
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->next = *head;
            pNew->prev = pCur;
            (*head)->prev = pNew; // Update prev dari head
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi penyisipan setelah data bernilai: ");
    scanf("%d", &pos);
    printf("bilangan: ");
    scanf("%d", &bil);

    pCur = *head;
    do {
        if (pCur->data == pos) {
            break;
        }
        pCur = pCur->next;
    } while (pCur != *head);

    if (pCur == *head && pCur->data != pos) {
        printf("Node tidak ditemukan");
        getch();
        return;
    }

    pNew = (node *)malloc(sizeof(node));
    if (pNew == NULL) {
        printf("Alokasi memori gagal");
        getch();
        return;
    }

    pNew->data = bil;
    pNew->next = pCur->next;
    pNew->prev = pCur;
    pCur->next->prev = pNew;
    pCur->next = pNew;
}

//========================================================

void tranverse(node *head) {
    node *pWalker = head;

    system("cls");
    if (head == NULL) {
        printf("Linked list kosong.\n");
    } else {
        do {
            printf("%d", pWalker->data);
            pWalker = pWalker->next;
            if (pWalker != head) {
                printf(" <-> ");
            }
        } while (pWalker != head);
        printf(" <-> HEAD\n");
    }
}

//========================================================

void hapusAwal(node **head) {
    if (*head == NULL) {
        printf("List kosong, tidak ada data untuk dihapus.\n");
        getch();
        return;
    }
    
    node *pCur = *head;

    if (pCur->next == *head) { // Hanya ada 1 node
        free(*head);
        *head = NULL;
    } else {
        node *pLast = (*head)->prev; // Node terakhir
        pCur = *head;
        pLast->next = (*head)->next;
        (*head)->next->prev = pLast;
        *head = (*head)->next;
        free(pCur);
    }

    printf("Data di awal berhasil dihapus.\n");
    getch();
}

//========================================================

void hapusTengah(node **head) {
    int pos;
    node *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi data yang akan dihapus: ");
    scanf("%d", &pos);

    if (*head == NULL) {
        printf("List kosong.\n");
        getch();
        return;
    }

    pCur = *head;

    do {
        if (pCur->data == pos) {
            break;
        }
        pCur = pCur->next;
    } while (pCur != *head);

    if (pCur == *head && pCur->data != pos) {
        printf("Node tidak ditemukan.\n");
        getch();
        return;
    }

    if (pCur == *head) { // Jika yang dihapus adalah node pertama
        hapusAwal(head);
    } else {
        pCur->prev->next = pCur->next;
        pCur->next->prev = pCur->prev;
        free(pCur);
        printf("Data di tengah berhasil dihapus.\n");
        getch();
    }
}

//========================================================

void hapusAkhir(node **head) {
    if (*head == NULL) {
        printf("List kosong, tidak ada data untuk dihapus.\n");
        getch();
        return;
    }

    node *pCur = *head;

    if (pCur->next == *head) { // Hanya ada satu node
        free(*head);
        *head = NULL;
    } else {
        node *pLast = (*head)->prev; // Node terakhir
        pLast->prev->next = *head;   // Menghubungkan node sebelum terakhir ke head
        (*head)->prev = pLast->prev; // Mengupdate prev dari head
        free(pLast);
    }

    printf("Data di akhir berhasil dihapus.\n");
    getch();
}

//========================================================

void pencarianData(node *head) {
    int bil, found = 0;
    node *pCur = head;

    system("cls");
    printf("Masukkan bilangan yang dicari: ");
    scanf("%d", &bil);

    if (head == NULL) {
        printf("Linked list kosong.\n");
    } else {
        do {
            if (pCur->data == bil) {
                printf("Data %d ditemukan di linked list.\n", bil);
                found = 1;
                break;
            }
            pCur = pCur->next;
        } while (pCur != head);

        if (!found) {
            printf("Data %d tidak ditemukan di linked list.\n", bil);
        }
    }
    getch();
}

//========================================================

void jumlahData(node *head) {
    int jumlah = 0;
    node *pCur = head;

    system("cls");
    if (head == NULL) {
        printf("Linked list kosong.\n");
    } else {
        do {
            jumlah++;
            pCur = pCur->next;
        } while (pCur != head);
        printf("Jumlah data dalam linked list: %d\n", jumlah);
    }
    getch();
}

//========================================================

void penjumlahanData(node *head) {
    int total = 0;
    node *pCur = head;

    system("cls");
    if (head == NULL) {
        printf("Linked list kosong.\n");
    } else {
        do {
            total += pCur->data;
            pCur = pCur->next;
        } while (pCur != head);
        printf("Penjumlahan semua data: %d\n", total);
    }
    getch();
}


