#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

 
typedef struct {
    char id[15];
    char nama[50];
    char kategori[30];
    int stok;
} Barang;

Barang DataBarang[] = {
    {"BRG001", "Laptop", "Elektronik", 15},
    {"BRG002", "Meja", "Furniture", 10},
    {"BRG003", "Kursi", "Furniture", 20},
    {"BRG004", "HP", "Elektronik", 25},
    {"BRG005", "Buku", "Alat Tulis", 50},
    {"BRG006", "Printer", "Elektronik", 5},
    {"BRG007", "Papan Tulis", "Alat Tulis", 8},
    {"BRG008", "Lampu", "Elektronik", 30},
    {"BRG009", "Sapu", "Kebutuhan Rumah", 12},
    {"BRG010", "Kasur", "Furniture", 3}
    
};

 
void printDataBarang(Barang brg[], int n) {
    printf("+-------------------+-----------------------------------+-----------------------+------+\n");
    printf("| ID               | NAMA BARANG                        |KATEGORI               |STOK  |\n");
    printf("+-------------------+-----------------------------------+-----------------------+------+\n");
    int i;
    for ( i = 0; i < n; i++) {
        printf("| %-17s | %-33s | %-21s | %-6d |\n", brg[i].id, brg[i].nama, brg[i].kategori, brg[i].stok);
    }
    printf("+-------------------+-----------------------------------+-----------------------+------+\n");
    printf("\n");
}

 
void BubbleSort(Barang brg[], int n, int kolom, int ascending) {
	int i;
	int j;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            int compare = 0;
            switch (kolom) {
                case 1: 
                    compare = strcmp(brg[j].id, brg[j + 1].id);
                    break;
                case 2:  
                    compare = strcasecmp(brg[j].nama, brg[j + 1].nama);
                    break;
                case 3:  
                    compare = strcmp(brg[j].kategori, brg[j + 1].kategori);
                    break;
                case 4:  
                    compare = (brg[j].stok > brg[j + 1].stok) - (brg[j].stok < brg[j + 1].stok);
                    break;
            }

            if ((ascending && compare > 0) || (!ascending && compare < 0)) {
                Barang temp = brg[j];
                brg[j] = brg[j + 1];
                brg[j + 1] = temp;
            }
        }
    }
}

 
void SelectionSort(Barang brg[], int n, int kolom, int ascending) {
	int i;
	int j;
    for ( i = 0; i < n - 1; i++) {
        int minMaxIdx = i;
        for (j = i + 1; j < n; j++) {
            int compare = 0;
            switch (kolom) {
                case 1: 
                    compare = strcmp(brg[j].id, brg[minMaxIdx].id);
                    break;
                case 2:  
                    compare = strcasecmp(brg[j].nama, brg[minMaxIdx].nama);
                    break;
                case 3: 
                    compare = strcmp(brg[j].kategori,brg[minMaxIdx].kategori);
                    break;
                case 4:  
                    compare = (brg[j].stok > brg[minMaxIdx].stok) - (brg[j].stok < brg[minMaxIdx].stok);
                    break;
            }

            if ((ascending && compare < 0) || (!ascending && compare > 0)) {
                minMaxIdx = j;
            }
        }
        if (minMaxIdx != i) {
            Barang temp = brg[i];
            brg[i] = brg[minMaxIdx];
            brg[minMaxIdx] = temp;
        }
    }
}

 
void InsertionSort(Barang brg[], int n, int kolom, int ascending) {
	int i;
	int j;
    for (i = 1; i < n; i++) {
        Barang key = brg[i];
        j = i - 1;
        int compare;

        while (j >= 0) {
            switch (kolom) {
                case 1:  
                    compare = strcmp(key.id, brg[j].id);
                    break;
                case 2:  
                    compare = strcasecmp(key.nama, brg[j].nama);
                    break;
                case 3:  
                    compare = strcmp(key.kategori, brg[j].kategori);
                    break;
                case 4:  
                    compare = (key.stok > brg[j].stok) - (key.stok < brg[j].stok);
                    break;
            }

            if ((ascending && compare < 0) || (!ascending && compare > 0)) {
                brg[j + 1] = brg[j];
                j--;
            } else {
                break;
            }
        }
        brg[j + 1] = key;
    }
}

int jumpSearch(Barang brg[], int n, int kolom, char *key) {
    int step = 3;   
    int prev = 0;
	int i;
   
    while (prev < n && 
           	((kolom == 1 && strcmp(brg[(step < n ? step : n) - 1].id, key) < 0) ||
            (kolom == 2 && strcasecmp(brg[(step < n ? step : n) - 1].nama, key) < 0) ||
            (kolom == 3 && strcmp(brg[(step < n ? step : n) - 1].kategori, key) < 0))) {
        prev = step;
        step += 3;
        if (prev >= n) return -1;  
    }

    // Linear search dalam blok
    for ( i = prev; i < (step < n ? step : n); i++) {
        if ((kolom == 1 && strcmp(brg[i].id, key) == 0) ||
            (kolom == 2 && strcasecmp(brg[i].nama, key) == 0) ||
            (kolom == 3 && strcmp(brg[i].kategori, key) == 0)) {
            return i;  
        }
    }
    return -1;  
}


int main() {
    int n = sizeof(DataBarang) / sizeof(DataBarang[0]);
    int pilihan, kolom, ascending, flag;
    char key[50];

    do {
    	do {
    		system("cls");
        	printf("Data Barang Sebelum diurutkan:\n");
        	printDataBarang(DataBarang, n);
        	printf("Menu Pengurutan:\n");
        	printf("1. Bubble Sorting\n");
        	printf("2. Selection Sorting\n");
        	printf("3. Insertion Sorting\n");
        	printf("4. Jump Search\n");
			printf("5. Keluar\n");
        	printf("Pilih opsi (1-5): ");
        	scanf("%d", &pilihan);
        	flag = 0;
        	if (pilihan != 1 && pilihan != 2 && pilihan != 3 && pilihan != 4 && pilihan != 5) {
            	printf("Pilihan Sorting Tidak Valid\n");
            	flag = 1;
            	system("pause");
			}
			
		} while (flag == 1);
		
        if (pilihan == 5) {
            printf("Keluar dari program.\n");
			break;
		}
		
		if (pilihan == 4) {
            printf("\nPilih kolom untuk pencarian:\n");
            printf("1. ID\n");
            printf("2. Nama barang\n");
            printf("3. kategori\n");
            printf("Pilihan (1-3): ");
            scanf("%d", &kolom);

            printf("\nMasukkan nilai yang ingin dicari: ");
            scanf(" %[^\n]", key);

            int index = jumpSearch(DataBarang, n, kolom, key);

            if (index != -1) {
                printf("\nData ditemukan:\n");
            printDataBarang(&DataBarang[index], 1);
            } else {
                printf("\nData tidak ditemukan.\n");
            }
            system("pause");
        } 

        
        do {
        	if (pilihan == 4){
        		break;
			}
            printf("\nPilih kolom untuk pengurutan:\n");
            printf("1. ID\n");
            printf("2. Nama Barang\n");
            printf("3. Kategori\n");
            printf("4. Stok\n");
            printf("Pilihan (1-4): ");
            scanf("%d", &kolom);
            flag = 0;
            if (kolom != 1 && kolom != 2 && kolom != 3 && kolom != 4) {
            	printf("Pilihan Kolom Tidak Valid\n");
            	flag = 1;
			}
		} while (flag == 1);
        
        do {
        	if (pilihan == 4){
        		break;
			}
        	printf("\nPilih tipe pengurutan:\n");
            printf("1. Ascending  \n");
            printf("2. Descending \n");
            printf("Pilihan tipe (1-2): ");
            scanf("%d", &ascending);
            flag = 0;
			if (ascending != 1 && ascending != 2) {
				printf("Pilihan Tipe Pengurutan Tidak Valid\n");
				flag = 1;
			}
            ascending = (ascending == 1);
		} while (flag == 1);
            

        switch (pilihan) {
            case 1:
                BubbleSort(DataBarang, n, kolom, ascending);
                break;
            case 2:
                SelectionSort(DataBarang, n, kolom, ascending);
                break;
            case 3:
                InsertionSort(DataBarang, n, kolom, ascending);
                break;
		}
		
		if (pilihan != 4){
			printf("\nData Barang setelah diurutkan:\n");
        	printDataBarang(DataBarang, n);
        	system("pause");
		}
        

    } while (pilihan != 5);

    return 0;
}
