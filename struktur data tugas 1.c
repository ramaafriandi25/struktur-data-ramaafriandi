#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

// Deklarasi fungsi
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

    do {
        system("cls");
        printf("\t**********************************************\n");
		printf("\t*   SELAMAT DATANG PENIKMAT STRUKTUR DATA    *\n");
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
    node *pNew;

    system("cls");
    printf("Masukkan bilangan: ");
    scanf("%d", &bil);
    
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = *head;
        *head = pNew;
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
        pNew->next = NULL;

        if (*head == NULL) {
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != NULL) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
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
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->next;
    }

    pNew = (node *)malloc(sizeof(node));
    if (pCur == NULL) {
        printf("node tidak ditemukan");
        getch();
    } else if (pNew == NULL) {
        printf("alokasi memori gagal");
        getch();
    } else {
        pNew->data = bil;
        pNew->next = pCur->next;
        pCur->next = pNew;
    }
}

//========================================================

void tranverse(node *head) {
    node *pWalker = head;

    system("cls");
    if (pWalker == NULL) {
        printf("Linked list kosong.\n");
    } else {
        while (pWalker != NULL) {
            printf("%d", pWalker->data);
            pWalker = pWalker->next;
            if (pWalker != NULL) {
                printf(" -> ");
            }
        }
        printf(" -> NULL\n");
    }
}

//========================================================

void hapusAwal(node **head) {
    if (*head == NULL) {
        printf("List kosong, tidak ada data untuk dihapus.\n");
        getch();
        return;
    }
    
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Data di awal berhasil dihapus.\n");
    getch();
}

//========================================================

void hapusTengah(node **head) {
    int pos;
    node *pCur, *pPrev;

    system("cls");
    tranverse(*head);
    printf("\nposisi data yang akan dihapus: ");
    scanf("%d", &pos);

    pCur = *head;
    pPrev = NULL;

    while (pCur != NULL && pCur->data != pos) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("Node tidak ditemukan.\n");
        getch();
        return;
    }

    if (pPrev == NULL) { // Jika yang dihapus adalah node pertama
        *head = pCur->next;
    } else {
        pPrev->next = pCur->next;
    }
    free(pCur);
    printf("Data di tengah berhasil dihapus.\n");
    getch();
}

//========================================================

void hapusAkhir(node **head) {
    if (*head == NULL) {
        printf("List kosong, tidak ada data untuk dihapus.\n");
        getch();
        return;
    }

    node *pCur = *head;
    node *pPrev = NULL;

    while (pCur->next != NULL) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pPrev == NULL) { // Hanya satu node
        *head = NULL;
    } else {
        pPrev->next = NULL;
    }
    free(pCur);
    printf("Data di akhir berhasil dihapus.\n");
    getch();
}

//========================================================

void pencarianData(node *head) {
    int bilangan;
    node *pCur = head;

    system("cls");
    printf("Masukkan bilangan yang dicari: ");
    scanf("%d", &bilangan);
    
    while (pCur != NULL) {
        if (pCur->data == bilangan) {
            printf("Data %d ditemukan.\n", bilangan);
            getch();
            return;
        }
        pCur = pCur->next;
    }
    printf("Data %d tidak ditemukan.\n", bilangan);
    getch();
}

//========================================================

void jumlahData(node *head) {
    int count = 0;
    node *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }
    printf("Jumlah data di linked list: %d\n", count);
    getch();
}

//========================================================

// Fungsi untuk menjumlahkan semua data di linked list
void penjumlahanData(node *head) {
    int sum = 0;
    node *pCur = head;

    // Looping untuk menjumlahkan data dari setiap node
    while (pCur != NULL) {
        sum += pCur->data;
        pCur = pCur->next;
    }
    // Output hasil penjumlahan
    printf("Hasil penjumlahan dari semua data di linked list: %d\n", sum);

    getch();
}
