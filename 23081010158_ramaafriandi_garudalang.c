#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

// Struktur data Stack
typedef struct {
    char data[MAX_STACK_SIZE];
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

// Menambahkan elemen ke dalam stack (push)
void push(Stack *s, char value) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Stack penuh, tidak dapat menambah elemen\n");
    } else {
        s->data[++s->top] = value;
    }
}

// Menghapus elemen dari stack (pop)
char pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack kosong, tidak ada elemen yang dihapus\n");
        return '\0';  // Mengembalikan karakter null jika kosong
    } else {
        return s->data[s->top--];
    }
}

// Fungsi untuk memeriksa keseimbangan tanda kurung
int isMatchingParenthesis(const char *expression) {
    Stack s;
    initializeStack(&s);

int i;
    for ( i = 0; expression[i] != '\0'; i++) {
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

int main() {
    char expression[MAX_STACK_SIZE];
    
    printf("Masukkan ekspresi dengan tanda kurung: ");
    scanf("%s", expression);
    
    if (isMatchingParenthesis(expression)) {
        printf("Tanda kurung seimbang\n");
    } else {
        printf("Tanda kurung tidak seimbang\n");
    }

    return 0;
}

