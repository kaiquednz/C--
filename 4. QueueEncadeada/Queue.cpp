#include <iostream>
#include <cstdlib> // Para abort ()
#include "Queue.h"

using namespace std;

// ===================================
// I. CONSTRUTOR, DESTRUTOR E CONSULTA
// ===================================

// Construtor: Inicializa a fila como vazia.
Queue::Queue() {
    // Cabeca e cauda apontam para nada
    head = tail = NULL;
    // Sem elementos.
    count = 0;
}

// Destrutor garante que toda a memória dinâmica seja liberada.
Queue::~Queue() {
    clear();
}

// Verifica se a fila está vazia.
bool Queue::isEmpty() {
    return count == 0;
    // Alternativamente: return head == NULL;
}

// Retorna o número de elementos.
int Queue::size() {
    return count;
}

// Consulta o elemento na frente (head) sem remover.
void Queue::getFront(QueueEntry &x) {
    if(isEmpty()){
        cerr << "ERRO: A QUEUE ESTÁ VAZIA, PORTANTO NENHUM ELEMENTO FOI ENCONTRADO" << endl;
        abort();
    }
    x = tail->entry;
}

// ===================================
// II. MÉTODOS DE MODIFICAÇÃO (FIFO)
// ===================================

// Append: Adiciona um elemento ao final (tail).
void Queue::append(QueueEntry x) {
    // 1. Criacao de um novo nó.
    QueuePointer newNode;
    newNode = new QueueNode;
    // Vericacao
    if(newNode == NULL) {
        cerr << "ERRO: FALHA NA ALOCACAO DE MEMORIA PARA APPEND." << endl;
        abort();
    }

    // 2. Lógica de Encadeamento
    if(isEmpty()) {
        // Se a fila estava vazia, o novo nó é o head E o tail.
        head = newNode;
    } else {
        // Se já havia elementos, o nó antigo do tail aponta para o novo nó
        tail->nextNode;
    }

    // 3. Preenchimento e Finalizacão do Nó
    newNode->entry = x;
    newNode->nextNode = NULL; // É o novo último elemento, então aponta para NULL.

    // 4. Atualizacão da Cauda (tail)
    tail = newNode; // o tail agora aponta para o novo nó.
    count++;
}

// Serve: Remove um elemento da frente (head).
void Queue::serve(QueueEntry &x) {
    if(isEmpty()) {
        cerr << "ERRO: A FILA JÁ SE ENCONTRA VAZIA, PORTANTO NÃO É POSSÍVEL REMOVER." << endl;
        abort();
    }
    // 1. Salva o valor do nó a ser removido (FIFO) -> FIRST IN, FIRST OUT.
    x = head->entry;

    // 2. Guarda o endereco do nó para deletar.
    QueuePointer p;
    p = head;

    // 3. Avanca a Cabeca (head)
    head = head->nextNode;

    // 4. Libera a memória do nó antigo.
    delete p;
    
    count --;

    // 5. CRÍTICO: Se a fila ficou vazia (head é NULL), o tail também deve ser NULL
    if(head == NULL) tail = NULL;
}

// Clear: Deleta todos os nós e zera a fila.
void Queue::clear() {
    QueuePointer p;

    // Loop continua enquanto houver um nó na frente (head).
    while(head != NULL) {
        p = head; // 1. Guarda o endereco do nó atual (para deletar).
        head = head->nextNode;  // 2. Avanca a cabeca para o próximo nó.
        delete p;   // 3. Deleta o nó antigo.
    }

    // Reseta os ponteiros de controle após limpeza, assim liberando a memória dinâmica.
    tail = NULL;
    count = 0;
}