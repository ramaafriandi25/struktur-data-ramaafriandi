#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Struktur data Stack
typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

// Menginisialisasi stack
void initializeStack(Stack *s) {
    s->top = -1; // Atur indeks top ke -1 menandakan stack kosong
}

// Mengecek apakah stack kosong
int isStackEmpty(Stack *s) {
    return s->top == -1;
}

// Mengecek apakah stack penuh
int isStackFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

// Menambahkan elemen ke dalam stack (push)
void push(Stack *s, int value) {
    if (isStackFull(s)) {
        printf("Stack penuh, tidak dapat menambah elemen\n");
    } else {
        s->data[++s->top] = value;
    }
}

// Menghapus elemen dari stack (pop)
int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack kosong, tidak ada elemen yang dihapus\n");
        return -1;  // Mengembalikan nilai -1 jika kosong
    } else {
        return s->data[s->top--];
    }
}

// Melihat elemen teratas stack tanpa menghapusnya (peek)
int peek(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack kosong, tidak ada elemen teratas untuk dilihat\n");
        return -1;
    } else {
        return s->data[s->top];
    }
}

// Menampilkan isi stack
void printStack(Stack *s) {
	int i;
    if (isStackEmpty(s)) {
        printf("Stack kosong\n");
    } else {
        printf("Isi stack: ");
        for ( i = 0; i <= s->top; i++) {
            printf("%d ", s->data[i]);
        }
        printf("\n");
    }
}

// Fungsi lainnya tetap sama
// Mengecek apakah tanda kurung dalam ekspresi seimbang
int isMatchingParenthesis(const char *expression) {
    Stack s;
    initializeStack(&s);
    int i;

    for (i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isStackEmpty(&s)) return 0;
            char top = pop(&s);
            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) return 0;
        }
    }
    return isStackEmpty(&s);
}

// Mendapatkan prioritas operator
int precedence(char operator) {
    if (operator == '+' || operator == '-') return 1;
    if (operator == '*' || operator == '/') return 2;
    return 0;
}

// Mengubah ekspresi infix menjadi postfix
void infixToPostfix(const char *infix, char *postfix) {
    Stack s;
    initializeStack(&s);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isStackEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        } else {
            while (!isStackEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (!isStackEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

// Mengevaluasi ekspresi postfix
int evaluatePostfix(const char *postfix) {
    Stack s;
    initializeStack(&s);
    int i;

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else {
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (ch) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    int choice, result;
    char expression[MAX_STACK_SIZE];
    char postfix[MAX_STACK_SIZE];

    do {
        printf("\nMenu Stack dengan Fungsi Tambahan\n");
        printf("1. Periksa Keseimbangan Tanda Kurung\n");
        printf("2. Ubah Ekspresi Infix ke Postfix\n");
        printf("3. Evaluasi Ekspresi Postfix\n");
        printf("4. Lihat Isi Stack\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Masukkan ekspresi dengan tanda kurung: ");
                scanf("%s", expression);
                if (isMatchingParenthesis(expression)) {
                    printf("Tanda kurung seimbang\n");
                } else {
                    printf("Tanda kurung tidak seimbang\n");
                }
                break;
            
            case 2:
                printf("Masukkan ekspresi infix: ");
                scanf("%s", expression);
                infixToPostfix(expression, postfix);
                printf("Ekspresi Postfix: %s\n", postfix);
                break;
            
            case 3:
                printf("Masukkan ekspresi postfix: ");
                scanf("%s", expression);
                result = evaluatePostfix(expression);
                printf("Hasil evaluasi postfix: %d\n", result);
                break;
            
            case 4:
                printf("Menampilkan isi stack:\n");
                Stack s;
                initializeStack(&s);
                printStack(&s);
                break;
            
            case 5:
                printf("Keluar dari program\n");
                break;
            
            default:
                printf("Pilihan tidak valid, silakan coba lagi\n");
        }
    } while (choice != 5);

    return 0;
}

