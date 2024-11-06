#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
    char nama[22];
    char gender;
    struct Mahasiswa* next;
};

// Fungsi untuk membuat mahasiswa baru
struct Mahasiswa* buatMahasiswa(char nama[], char gender) {
    struct Mahasiswa* baru = (struct Mahasiswa*)malloc(sizeof(struct Mahasiswa));
    if (baru == NULL) {
        printf("alokasi memory gagal lur!\n");
        exit(1);
    }
    strcpy(baru->nama, nama);
    baru->gender = gender;
    baru->next = NULL;
    return baru;
}

// Fungsi untuk menambahkan mahasiswa ke lingkaran api
void tambahMahasiswa(struct Mahasiswa** head, char nama[], char gender) {
    struct Mahasiswa* baru = buatMahasiswa(nama, gender);

    if (*head == NULL) {
        *head = baru;
        (*head)->next = *head; //  circular
    } else {
        struct Mahasiswa* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = baru;
        baru->next = *head; // Circular
    }
}

// Fungsi untuk menampilkan seluruh mahasiswa dalam lingkaran api
void tampilkanLingkaran(struct Mahasiswa* head) {
    if (head == NULL) {
        printf("Lingkaran kosong.\n");
        return;
    }
    struct Mahasiswa* temp = head;
    do {
        printf("Nama: %s, Jenis Kelamin: %c\n", temp->nama, temp->gender);
        temp = temp->next;
    } while (temp != head);
}

// Fungsi untuk memisahkan lingkaran mahasiswa dan mahasiswi
void lingkaranmendua(struct Mahasiswa* head, struct Mahasiswa** lingkaranpria, struct Mahasiswa** lingkaranwanita) {
    if (head == NULL) {
        printf("Lingkaran kosong, tidak ada yang bisa dipisahkan.\n");
        return;
    }
    struct Mahasiswa* temp = head; 
    struct Mahasiswa* tailpria = NULL; 
    struct Mahasiswa* tailwanita = NULL; 

    do {
        struct Mahasiswa* baru = buatMahasiswa(temp->nama, temp->gender);
        if (temp->gender == 'L') {
            if (*lingkaranpria == NULL) {
                *lingkaranpria = baru;
                tailpria = baru;
                tailpria->next = *lingkaranpria; 
            } else {
                tailpria->next = baru;
                tailpria = baru;
            }
            tailpria->next = *lingkaranpria; 
        } else if (temp->gender == 'P') {
            if (*lingkaranwanita == NULL) {
                *lingkaranwanita = baru;
                tailwanita = baru;
                tailwanita->next = *lingkaranwanita; 
            } else {
                tailwanita->next = baru;
                tailwanita = baru;
            }
            tailwanita->next = *lingkaranwanita; 
        }
        temp = temp->next; 
    } while (temp != head);

    //  tail berhubungan head
    if (tailpria) {
        tailpria->next = *lingkaranpria;
    }
    if (tailwanita) {
        tailwanita->next = *lingkaranwanita;
    }

    printf("Lingkaran telah dipisahkan antara mahasiswa dan mahasiswi.\n");
}

// Fungsi untuk menghapus mahasiswa berdasarkan nama
void hapusMahasiswa(struct Mahasiswa** head, char nama[]) {
    if (*head == NULL) {
        printf("Lingkaran kosong, tidak ada yang bisa dihapus.\n");
        return;
    }

    struct Mahasiswa *current = *head, *prev = NULL;
    int found = 0;

    do {
        if (strcmp(current->nama, nama) == 0) {
            found = 1;
            if (prev == NULL) {              
                struct Mahasiswa* temp = *head;
                while (temp->next != *head) {
                    temp = temp->next;
                }
                temp->next = current->next; 
                *head = current->next; 
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Mahasiswa %s telah dihapus.\n", nama);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != *head);

    if (!found) {
        printf("Mahasiswa dengan nama %s tidak ditemukan.\n", nama);
    }
}

// Menu baru setelah pemisahan lingkaran api
void menuSetelahPemisahan(struct Mahasiswa* lingkaranpria, struct Mahasiswa* lingkaranwanita) {
    int mt;
    do {
        printf("\nMENU SETELAH PEMISAHAN LINGKARAN:\n");
        printf("1. Tampilkan Lingkaran Mahasiswa Laki-Laki\n");
        printf("2. Tampilkan Lingkaran Mahasiswi Perempuan\n");
        printf("3. Kembali ke Menu Utama\n");
        printf("Pilih: ");
        scanf("%d", &mt);

        switch (mt) {
            case 1:
                printf("\nLingkaran Mahasiswa Laki-Laki:\n");
                tampilkanLingkaran(lingkaranpria);
                break;
            case 2:
                printf("\nLingkaran Mahasiswi Perempuan:\n");
                tampilkanLingkaran(lingkaranwanita);
                break;
            case 3:
                printf("Kembali ke menu utama...\n");
                break;
            default:
                printf("angka yang anda masukkan tidak valid.\n");
        }
        if (mt == 1 || mt == 2) {
            printf("Tekan Enter untuk melanjutkan...");
            getchar(); 
            getchar(); 
            system("cls");
        }
    } while (mt != 3);
}  

int main() {
    struct Mahasiswa* lingkaran = NULL;
    struct Mahasiswa* lingkaranpria = NULL;
    struct Mahasiswa* lingkaranwanita = NULL;
    int menpil;
    int count = 0; 

    do {
    	printf("MAU PILIH YANG MANA HAYOO\n");
        printf("1. Tambah nama Mahasiswa Laki-Laki\n");
        printf("2. Tambah nama Mahasiswi Perempuan\n");
        printf("3. Tampilkan Lingkaran api unggun\n");
        printf("4. Mahasiswa yang ingin keluar dari lingkaran api unggun\n");
        printf("5. Pisahkan Lingkaran api unggun\n");
        printf("6. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &menpil);

        switch (menpil) {
            case 1: {
                if (count >= 20) {
                    printf("Jumlah maksimum mahasiswa telah tercapai (20 mahasiswa).\n");
                    break;
                }
                char nama[50];
                printf("Masukkan Nama mahasiswa: ");
                scanf("%s", nama);
                tambahMahasiswa(&lingkaran, nama, 'L');
                count++; 
                system("cls");
                break;
            }
            case 2: {
                if (count >= 20) {
                    printf("Jumlah maksimum mahasiswa telah tercapai (20 mahasiswa).\n");
                    break;
                }
                char nama[50];
                printf("Masukkan Nama mahasiswi: ");
                scanf("%s", nama);
                tambahMahasiswa(&lingkaran, nama, 'P');
                count++; 
                system("cls");
                break;
            }
            case 3:
                printf("\nLingkaran Saat Ini:\n");
                tampilkanLingkaran(lingkaran);
                printf("Tekan Enter untuk melanjutkan...");
                getchar(); 
                getchar();
                system("cls");
                break;
            case 4: {
                char nama[50];
                printf("Masukkan Nama Mahasiswa yang Ingin keluar: ");
                scanf("%s", nama);
                hapusMahasiswa(&lingkaran, nama);
                count--;
                system("cls"); 
                break;
            }
            case 5:
                lingkaranmendua(lingkaran, &lingkaranpria, &lingkaranwanita);
                menuSetelahPemisahan(lingkaranpria, lingkaranwanita);
                break;
            case 6:
                printf("Keluar dari program \n");
				printf("TERIMAKASIH!!!\n");
                break;
            default:
                printf("opsi yang anda masukkan tydack valid.\n");
        }
    } while (menpil != 6);

    return 0;
}
