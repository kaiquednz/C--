#include <iostream>
#include <cstdlib> // para ABORT();
#include "Queue.h"

using namespace std;

// ===================================
// I. CONSTRUTOR E DESTRUTOR
// ===================================

// Construtor: Inicializa a fila no estado de vazia.
Queue::Queue() {
    count = 0;
    // O head comeca no primeiro índice válido.
    head = 1;
    // O tail comeca no último índice válido
    // O próximo append fará o cálculo circular e o tail irá para a posicão 1.
    tail = maxQueue;
}

// Destrutor: Para arrays estáticos, apenas chama clear para resetar os índices.
Queue::~Queue(){
    clear();
}

// ===================================
// II. MÉTODOS DE CONSULTA
// ===================================

// Verifica se a fila está cheia (o contador atingiu o limite).
bool Queue::isFull() {
    return count == maxQueue;
}

// Verifica se a fila está vazia (o contador vazio).
bool Queue::isEmpty() {
    return count == 0;
}

// Retorna o número de elementos ativos.
int Queue::size() {
    return count;
}

// Consulta o elemento na frente (head) sem mover o ponteiro.
void Queue::getFront(QueueEntry &x) {
    if(isEmpty()){
        cerr << "ERRO: getFront em fila vazia." << endl;
        abort();
    }
    x = entry[head];
}

// Consulta o elemento final (tail) sem mover o ponteiro
void Queue::getRear(QueueEntry &x) {
    if(isEmpty) {
        cerr << "ERRO: A FILA ESTÁ VAZIA, PORTANTO NÃO FOI POSSÍVEL CONSULTAR." << endl;
    }
    x = entry[tail];
}

// ===================================
// III. MÉTODOS DE MODIFICAÇÃO (Matemática Circular)
// ===================================

// Limpa a fila (reseta os ponteiros lógicos).
void Queue::clear() {
    count = 0;
    head = 1;
    tail = maxQueue;
    // Os dados antigos permanecem no array, mas serão sobrescritos.
}

//Append: Adiciona um elemento ao final (tail).
void Queue::append(QueueEntry x) {
    if(isFull()) {
        cerr << "ERRO: A FILA JÁ ESTÁ CHEIA, PORTANTO NÃO FOI POSSÍVEL ADICIONAR." << endl;
        abort();
    }

    // 1. Cálculo Circular: Move o ponteiro tail para o próximo slot.
    // Lógica: (tail atual % maxQueue) + 1.
    // Ex: Se tail=100 (maxQueue), 1-- % 100 = 0. 0 + 1. O tail volta para o início!
    tail = (tail% maxQueue) + 1;

    // 2. Insercão: Armazena valor no novo índice do tail.
    entry[tail] = x;

    // 3. Contagem
    count ++;
}

// Serve: Remove um elemento da frente (head).
void Queue::serve(QueueEntry &x) {
    if(isEmpty()) {
        cerr << "ERRO: NÃO FOI POSSÍVEL REMOVER, POIS A FILA JÁ ESTÁ VAZIA." << endl;
        abort();
    }
    // 1. Salva o valor do head (FIFO) FIRST IN, FIRST OUT.
    x = entry[head];

    // 2. Cálculo Circular: Move o ponteiro head para o próximo elemento.
    // O espaco que o head liberou pode ser reutilizado pelo tail.
    head = ( head % maxQueue) + 1;

    // 3. Contagem
    count --;
}