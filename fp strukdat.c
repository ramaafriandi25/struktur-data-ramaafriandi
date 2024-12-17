#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definisi struct untuk Node linkedlist Nasabah
typedef struct Node {
    int id; // ID Nasabah
    char nama[50]; // Nama Nasabah
    struct Node*next; // Pointer untuk ke Node berikutnya
} Node;

// definisi struct untuk Node double-linkedlist Nasabah kemarin
typedef struct DoubleNode {
    int id;
    char nama[50];
    struct DoubleNode *prev;
    struct DoubleNode *next;
} DoubleNode;

// definisi struct untuk Queue
typedef struct Queue {
    Node*front;
    Node*rear;
} Queue;

// definisi struct untuk Stack
typedef struct Stack {
    Node*top;
} Stack;

// fungsi untuk membuat Node baru
Node* createNode (int id, char* nama) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> id = id;
    strcpy(newNode -> nama, nama);
    newNode -> next = NULL;

    return newNode;
} 

// fungsi initQueue
void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// fungsi enQueue - tambahkan Nasabah
void enQueue(Queue *q, int id, char *nama) {
    Node *newNode = createNode(id, nama);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Nasabah dengan ID %d dan nama %s telah ditambahkan ke antrian.\n", id, nama);
}

// fungsi deQueue - Nasabah selesai dilayani 
Node* deQueue(Queue *q) {
    if (q->front == NULL) {
        printf("Antrian kosong. Tidak ada Nasabah yang dilayani.\n");
        return NULL;
    }

    Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    temp->next = NULL;
    printf("Nasabah dengan ID %d dan nama %s selesai dilayani.\n", temp->id, temp->nama);
    return temp;
}

// fungsi printQueue - tampilkan antrian Nasabah
void printQueue(Queue *q) {
    if (q->front == NULL) {
        printf("Antrian kosong.\n");
        return;
    }
    Node* temp = q->front;
    printf("Daftar antrian Nasabah:\n");
    while (temp != NULL) {
        printf("ID: %d, Nama: %s\n", temp->id, temp->nama);
        temp = temp->next;
    }
}

// fungsi initStack
void initStack(Stack *s) {
    s->top = NULL;
    }

// fungsi push Stack - memasukkan Nasabah yang selesai dilayani ke Stack
void push(Stack *s, Node *nasabah) {
    if (nasabah == NULL) {
        return;
    }

    nasabah->next = s->top;
    s->top = nasabah;
    printf("Nasabah dengan ID %d dan nama %s telah ditambahkan ke riwayat pelayanan (Stack).\n", nasabah->id, nasabah->nama);
    }

// fungsi pop Stack - menghapus data Nasabah yang selesai dilayani dari Stack
void pop(Stack *s) {
    if (s->top == NULL) {
        printf("Riwayat pelayanan kosong.\n");
        return NULL;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    temp->next = NULL;
    printf("Nasabah dengan ID %d dan nama %s dihapus dari riwayat pelayanan (Stack).\n", temp->id, temp->nama);
    free(temp);
    return temp;
}

// fungsi printStack - menampilkan data Nasabah yang selesai dilayani hari ini
void printStack(Stack *s) {
    if (s->top == NULL) {
        printf("Riwayat pelayanan kosong.\n");
        return;
    }
    Node* temp = s->top;
    printf("Riwayat pelayanan Nasabah hari ini:\n");
    while (temp != NULL) {
        printf("ID: %d, Nama: %s\n", temp->id, temp->nama);
        temp = temp->next;
    }
}

// data statis double-linkedlist untuk menyimpan data Nasabah kemarin.

// fungsi main
int main () {
    Queue q;
    Stack s; 
	initStack(&s);

    int choice, id;
    char nama[50];

    printf("Selamat Datang di Sistem Administrasi Teller Bank Sejahtera\n");

    do {
        printf("\n===== OPSI MENU ADMINISTRASI =====\n");
        printf("1. Tambahkan Nasabah ke antrian\n");
        printf("2. Layani Nasabah\n");
        printf("3. Tampilkan antrian Nasabah\n");
        printf("4. Tampilkan riwayat pelayanan\n");
        printf("5. Hapus riwayat pelayanan\n");
        printf("6. Keluar\n");
        printf("Silahkan masukkan pilihan Anda: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:{
                printf("Masukkan ID Nasabah: ");
                scanf("%d", &id);
                getchar(); // menangkap newline setelah scanf
                printf("Masukkan Nama Nasabah: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0; // menghapus newline di akhir input
                enQueue(&q, id, nama);
            break;
            }

            case 2: {// Iqbal
                // dequeue + push stack
                Node* nasabahDilayani = deQueue(&q); // Untuk mengambil nasabah dari antrian
                push(&s, nasabahDilayani);           // Masukkan nasabah yang sudah dilayani ke stack
                break;
            }

            case 3:
    			printQueue(&q);
   			 break;
// Wildan
                // print queue
            break;

            case 4: // Tsabit
                printf ("Silahkan pilih riwayat transaksi yang ingin ditampilkan:\n");
                // Case
                    // case 1 : Hari ini (Stack)
                    // case 2 : Kemarin (Double Linked List)
                    // case 3 : Semua di urutkan dari hari ini sebagai yang paling atas(Double Linked List)
                // printstack
            break;

            case 5: // Rama
    			pop(&s);
    		break;
 // Rama
                // pop stack
            break;

            case 6:
                printf ("Terimakasih telah menggunakan sistem administrasi Teller\n");
            break;

            default:
                printf("Pilihan tidak ada dalam opsi!//INVALID//\n)");
        }
    } while (choice!=6);
    
    
    return 0;
}

