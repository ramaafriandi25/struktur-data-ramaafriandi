#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50 // Ukuran maksimum queue

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int count;
} Queue;

// Fungsi untuk menginisialisasi queue
void createQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Memeriksa apakah queue kosong
bool isEmpty(Queue *q) {
    return q->count == 0;
}

// Memeriksa apakah queue penuh
bool isFull(Queue *q) {
    return q->count == MAX_SIZE;
}

// Menambahkan elemen ke dalam queue
void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue penuh! Tidak dapat menambahkan item.\n");
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->items[q->rear] = item;
        q->count++;
        printf("Item %d berhasil ditambahkan ke queue.\n", item);
    }
}

// Menghapus elemen dari queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong bro! Tidak ada item untuk dihapus.\n");
        return -1;
    } else {
        int item = q->items[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        q->count--;
        printf("Item %d berhasil dihapus dari queue.\n", item);
        return item;
    }
}

// Menampilkan elemen di depan queue
int queueFront(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong! Tidak ada item di depan.\n");
        return -1;
    } else {
        return q->items[q->front];
    }
}

// Menampilkan elemen di belakang queue
int queueRear(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue kosong! Tidak ada item di belakang.\n");
        return -1;
    } else {
        return q->items[q->rear];
    }
}

// Menghitung jumlah elemen di queue
int queueCount(Queue *q) {
    return q->count;
}

// Menghancurkan queue
void destroyQueue(Queue *q) {
    createQueue(q);
    printf("Queue berhasil dihapus dan diinisialisasi ulang.\n");
}

// Menampilkan menu
void displayMenu() {
    printf("\n=== MENU QUEUE ===\n");
    printf("1. Tambahkan elemen ke queue (enqueue)\n");
    printf("2. Hapus elemen dari queue (dequeue)\n");
    printf("3. Lihat elemen di depan queue\n");
    printf("4. Lihat elemen di belakang queue\n");
    printf("5. Hitung jumlah elemen di queue\n");
    printf("6. Periksa apakah queue kosong\n");
    printf("7. Periksa apakah queue penuh\n");
    printf("8. Hancurkan queue\n");
    printf("9. Keluar\n");
    printf("===================\n");
    printf("Pilih opsi: ");
}

// Program utama
int main() {
    Queue q;
    createQueue(&q);

    int choice, value;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan elemen yang akan ditambahkan: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                value = queueFront(&q);
                if (value != -1) {
                    printf("Elemen di depan queue: %d\n", value);
                }
                break;

            case 4:
                value = queueRear(&q);
                if (value != -1) {
                    printf("Elemen di belakang queue: %d\n", value);
                }
                break;

            case 5:
                printf("Jumlah elemen di queue: %d\n", queueCount(&q));
                break;

            case 6:
                if (isEmpty(&q)) {
                    printf("Queue kosong.\n");
                } else {
                    printf("Queue tidak kosong.\n");
                }
                break;

            case 7:
                if (isFull(&q)) {
                    printf("Queue penuh.\n");
                } else {
                    printf("Queue tidak penuh.\n");
                }
                break;

            case 8:
                destroyQueue(&q);
                break;

            case 9:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 9);
   
    return 0;
}

