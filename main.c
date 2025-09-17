#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    char nome[30];
    int idade;
} Pessoa;

typedef struct {
    Pessoa itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->total == 0;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->total == MAX;
}

// Inserir elemento (enqueue)
void enqueue(Fila *f, Pessoa p) {
    if(filaCheia(f)) {
        printf("Fila cheia. Não é possível inserir.\n");
        return;
    }
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}

// Remover elemento (dequeue)
Pessoa dequeue(Fila *f) {
    Pessoa p = {"", 0};
    if(filaVazia(f)) {
        printf("Fila vazia. Não é possível remover.\n");
        return p;
    }
    p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
    return p;
}

// Mostrar fila
void mostrarFila(Fila *f) {
    if(filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila atual:\n");
    for(int i = 0; i < f->total; i++) {
        int idx = (f->inicio + i) % MAX;
        printf("%s - %d anos\n", f->itens[idx].nome, f->itens[idx].idade);
    }
}

int main() {
    Fila f;
    inicializarFila(&f);

    Pessoa p1 = {"Alice", 25};
    Pessoa p2 = {"Bruno", 30};

    enqueue(&f, p1);
    enqueue(&f, p2);

    mostrarFila(&f);

    Pessoa removido = dequeue(&f);
    printf("\nRemovido: %s - %d anos\n\n", removido.nome, removido.idade);

    mostrarFila(&f);

    return 0;
}
