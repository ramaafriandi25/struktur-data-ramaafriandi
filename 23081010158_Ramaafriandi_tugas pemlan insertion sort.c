#include <stdio.h>
#include <string.h>

#define MAX_MAHASISWA 15 // Jumlah mahasiswa yang diinisialisasi adalah 15

// Struk untuk menyimpan data mahasiswa
typedef struct {
    char nama[50];
    char prodi[50];
    float ipk;
    long long npm; // Menggunakan long long untuk memastikan cukup besar
} Mahasiswa;

// Fungsi untuk menampilkan data mahasiswa
void tampilkan_data(Mahasiswa mahasiswa[], int n) {
    int i;
    printf("-----------------------------------------------------------------------\n");
    printf("| %-15s | %-25s | %-8s | %-10s |\n", "Nama", "Prodi", "IPK", "NPM");
    printf("-----------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        if (mahasiswa[i].npm != 0) {
            printf("| %-15s | %-25s | %-8.2f | %-10lld |\n", mahasiswa[i].nama, mahasiswa[i].prodi, mahasiswa[i].ipk, mahasiswa[i].npm);
        }
    }
    printf("-----------------------------------------------------------------------\n");
}

// Fungsi untuk mengurutkan data mahasiswa berdasarkan NPM secara ascending
void urutkan_npm_ascending(Mahasiswa mahasiswa[], int n) {
    Mahasiswa temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (mahasiswa[i].npm > mahasiswa[j].npm) {
                temp = mahasiswa[i];
                mahasiswa[i] = mahasiswa[j];
                mahasiswa[j] = temp;
            }
        }
    }
}

// Fungsi untuk mengurutkan data mahasiswa berdasarkan NPM secara descending
void urutkan_npm_descending(Mahasiswa mahasiswa[], int n) {
    Mahasiswa temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (mahasiswa[i].npm < mahasiswa[j].npm) {
                temp = mahasiswa[i];
                mahasiswa[i] = mahasiswa[j];
                mahasiswa[j] = temp;
            }
        }
    }
}

// Fungsi untuk mengurutkan data mahasiswa berdasarkan Nama secara ascending
void urutkan_nama_ascending(Mahasiswa mahasiswa[], int n) {
    Mahasiswa temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(mahasiswa[i].nama, mahasiswa[j].nama) > 0) {
                temp = mahasiswa[i];
                mahasiswa[i] = mahasiswa[j];
                mahasiswa[j] = temp;
            }
        }
    }
}

// Fungsi untuk mengurutkan data mahasiswa berdasarkan Nama secara descending
void urutkan_nama_descending(Mahasiswa mahasiswa[], int n) {
    Mahasiswa temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(mahasiswa[i].nama, mahasiswa[j].nama) < 0) {
                temp = mahasiswa[i];
                mahasiswa[i] = mahasiswa[j];
                mahasiswa[j] = temp;
            }
        }
    }
}

// Fungsi untuk mengurutkan data mahasiswa berdasarkan IPK secara ascending
void urutkan_ipk_ascending(Mahasiswa mahasiswa[], int n) {
    Mahasiswa temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (mahasiswa[i].ipk > mahasiswa[j].ipk) {
                temp = mahasiswa[i];
                mahasiswa[i] = mahasiswa[j];
                mahasiswa[j] = temp;
            }
        }
    }
}

// Fungsi untuk mengurutkan data mahasiswa berdasarkan IPK secara descending
void urutkan_ipk_descending(Mahasiswa mahasiswa[], int n) {
    Mahasiswa temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (mahasiswa[i].ipk < mahasiswa[j].ipk) {
                temp = mahasiswa[i];
                mahasiswa[i] = mahasiswa[j];
                mahasiswa[j] = temp;
            }
        }
    }
}

int main() {
    Mahasiswa mahasiswa[MAX_MAHASISWA] = {
        {"Ngasiman", "Sistem Informasi", 3.40, 2308273834},
        {"Budi Wahono", "Sistem Informasi", 3.50, 2308273840},
        {"Martono", "Bisnis Digital", 3.60, 2308473831},
        {"Ahmad Sapii", "Informatika", 3.75, 2308173821},
        {"Syaripudin", "Bisnis Digital", 3.65, 2308473835},
        {"Priyadi", "Sains Data", 3.90, 2308373830},
        {"Basirah", "Sistem Informasi", 3.80, 2308273838},
        {"Supardiono", "Bisnis Digital", 3.50, 2308473832},
        {"Hari Wibowo", "Sains Data", 3.60, 2308373826},
        {"Lasiman", "Informatika", 3.85, 2308173822},
        {"Marko", "Bisnis Digital", 3.40, 2308473842},
        {"Suparlan", "Informatika", 3.55, 2308173825},
        {"Tamijah", "Sistem Informasi", 3.25, 2308273837},
        {"Suprapto", "Informatika", 3.95, 2308173828},
        {"Mariyem", "Sains Data", 3.80, 2308373827}
    };

    int pilihan, sub_pilihan;

    while (1) {
        printf("\nData Mahasiswa:\n");
        tampilkan_data(mahasiswa, MAX_MAHASISWA);

        printf("\nPilih Kriteria Pengurutan Data Mahasiswa:\n");
        printf("1. Berdasarkan NPM\n");
        printf("2. Berdasarkan Nama\n");
        printf("3. Berdasarkan IPK\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan (1-4): ");
        if (scanf("%d", &pilihan) != 1) {
            printf("Input tidak valid! Silakan masukkan angka yang benar.\n");
            while (getchar() != '\n');
            continue;
        }

        if (pilihan == 4) {
            printf("Terima kasih, program selesai.\n");
            break;
        }

        printf("\nPilih Urutan:\n");
        printf("1. Ascending\n");
        printf("2. Descending\n");
        printf("Masukkan pilihan (1-2): ");
        if (scanf("%d", &sub_pilihan) != 1) {
            printf("Input tidak valid! Silakan masukkan angka yang benar.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (pilihan) {
            case 1:
                if (sub_pilihan == 1) {
                    urutkan_npm_ascending(mahasiswa, MAX_MAHASISWA);
                } else {
                    urutkan_npm_descending(mahasiswa, MAX_MAHASISWA);
                }
                break;
            case 2:
                if (sub_pilihan == 1) {
                    urutkan_nama_ascending(mahasiswa, MAX_MAHASISWA);
                } else {
                    urutkan_nama_descending(mahasiswa, MAX_MAHASISWA);
                }
                break;
            case 3:
                if (sub_pilihan == 1) {
                    urutkan_ipk_ascending(mahasiswa, MAX_MAHASISWA);
                } else {
                    urutkan_ipk_descending(mahasiswa, MAX_MAHASISWA);
                }
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
                continue;
        }

        printf("\nData Mahasiswa Setelah Diurutkan:\n");
        tampilkan_data(mahasiswa, MAX_MAHASISWA);
    }

    return 0;
}

