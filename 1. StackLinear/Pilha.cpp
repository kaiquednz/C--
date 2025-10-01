#include "Pilha.h"
#include <iostream>
#include <stdexcept> // serve para usar a exceção std::runtime_error

using namespace std;

// --- ATRIBUTOS PRIVADOS DA CLASSE --

// int *dados; (Ponteiro para o array)
// topo;       (Índice do topo, -1 = vazio)
// int capacidade_; (Tamanho alocado)

// ==============================
// 1. CONSTRUTOR E DESTRUTOR
// ==============================

// Construtor: Inicializa a pilha, alocando memória dinamicamente.
Pilha::Pilha(int capacidade) {
    // 1. Armazena a capacidade máxima definida pelo usuário.
    capacidade_ = capacidade;

    // 2. Aloca um array de inteiros (dados) na memória dinâmica (heap).
    dados = new int[capacidade_];

    // 3. Inicializa o topo para -1, indicando que a pilha está vazia.
    topo = -1;
}

// Destrutor: é chamado quando o objeto Pilha é destruído.
    Pilha::~Pilha() {
        //Libera a memória alocada pelo array 'dados' para evitar memory leaks.
        delete[] dados;
    }

// ==============================
// 2. MÉTODOS DE CONSULTA (CONST)
// ==============================

//pré: -- | pós: retorna se está vazia.
bool Pilha::isEmpty() const {
    // A pilha está vazia se o índice do topo for o valor inicial -1..
    return topo == -1;
}

//pré: -- | pós: retorna se está cheia.
bool Pilha::isFull() const {
    return topo == capacidade_ -1;
}

//pré: !isEmpty | pós: retorna o valor do topo, sem alterar a estrutura.
int Pilha::top() const {
    if(isEmpty()) {
        //usa o std::runtime_error para um tratamento de erro mais robusto.
        throw runtime_error("ERRO: Pilha vazia! Não há elemento no topo.");
    }
    // Retorna o valor do elemento que está no índice atual do topo.
    return dados[topo];
}

// pré: -- | pós: retorna o número atual de elementos.
int Pilha::size() const {
    // O tamanho é o índice do topo + 1 (pois 'topo' começa em -1 para 0 elementos)
    return topo + 1;
}

//pré: -- | pós: Retorna a capacidade máxima.
int Pilha::capacity() const {
    // Retorna o valor fixo da capacidade máxima da pilha.
    return capacidade_;
}

// ==============================
// 3. MÉTODOS DE MODIFICAÇÃO
// ==============================

// pré: !isFull | pós: Adiciona 'valor' ao topo
void Pilha::push (int valor) {
    // 1. Verifica a pré-condição: Se estiver cheia, lança um erro e não executa o push.
    if(isFull()) {
        throw runtime_error("ERRO: Pilha cheia! nao e possivel adicionar mais elementos");
    }
    
    // 2. incrementa o índice do topo (topo++). O topo agora aponta para a nova posição 
    topo++;
    
    // 3. Insere o novo valor no novo índice do topo.
    dados[topo] = valor;
}

// pré: !isEmpty | pós: remove o elemento do topo
void Pilha::pop() {
    // 1. Verifica a pré condição: Se estiver vazio, lança um erro e não executa o pop.
    if(isEmpty()) {
    throw runtime_error("ERRO: Pilha vazia! nao e possivel remover mais elementos");
    }
    
    // 2. O valor em dados[topo] é conceitualmente removido (ignorado).
    // O valor do topo é simplesmente decrementado. o novo topo é o elemento abaixo.
    topo--;
    // NOTA: O valor antigo continua na memória, mas será sobrescrito em um futuro push.
}