#include <iostream>
#include "PilhaEncadeada.h"
#include <cstdlib> // Necessário para a funcao abort()

using namespace std;

// ===================================
// I. CONSTRUTOR E DESTRUTOR (Ciclo de Vida)
// ===================================

// Construtor: Inicializa a pilha como vazia

Pilha::Pilha(){
    // O Ponteiro 'topo' comeca como NULL, indicando que nao há nós alocados.
    topo = NULL;
    // O contador de elementos é zerado.
    count = 0;
}

// Destrutor: É chamado quando o objeto Pilha é destruído.
Pilha::~Pilha(){
    clear();
}

// ===================================
// II. MÉTODOS DE CONSULTA (Inspeção)
// ===================================

// Verifica se a Pilha está vazia
bool Pilha::isEmpty() {
    // A pilha está vazia se o contador for zero (ou se topo for NULL).
    return count == 0;
}

// Verifica se está cheio
bool Pilha::isFull() {
    // Em pilhas encadeadas, não há valor fixo
    return false;
}

// Retorna o tamanho atual da Pilha

int Pilha::size() {
    return count;
}

// pré: !isEmpty | Pós: Retorna o valor do topo (SEM MOVER)
void Pilha::getTop(StackEntry &x) {
    if(isEmpty()) {
        cerr << "ERRO: LISTA VAZIA." << endl;
        abort();
    }
// Acessa o dado 'Entry' do nó apontado pelo ponteiro 'topo' e o armazena em 'x' (por referência)
    x = topo->entry;
}

// ===================================
// III. MÉTODOS DE MODIFICAÇÃO (Ação)
// ===================================

// Pré: --- | Pós: Adiciona 'x' ao topo.
void Pilha::push(StackEntry x){
    // 1. Alocacao de memória para um novo nó (StackNode).
    StackPointer newNode;
    newNode = new StackNode;

    // Verificacao de Erro: Se 'new' falhar por falta de memória.
    if(newNode == NULL){
        cerr << "Erro: Falta de memoria" << endl;
        abort();
    }
    
    // 2. Preenchimento do Dado
    newNode->entry = x;

    // 3. Ligacao: O novo nó APONTA para o nó que atualmente é o topo.
    newNode->nextNode = topo;

    // 4. Atualicacão: O 'topo' passa a apontar para o nó (o novo topo)
    topo = newNode;

    // 5. Contagem
    count++;
}

// Pré: !isEmpty() | Pós: remove o nó do topo
void Pilha::pop(StackEntry &x) {
    // 1. Verificacão
    if(isEmpty()) {
        cerr << "Erro: as pilhas ja estao vazias" << endl;
        abort();
    }
    // 2. Salvar o Valor: O dado do topo é copiado para variável 'x' do usuário.
    x = topo->entry;

    // 3. Referência temporária: Guarda o endereco do nó atual do topo (o que será deletado)
    StackPointer p;
    p = topo;

    // 4. Mover o topo: O 'topo' avanca para o próximo nó.
    topo = topo->nextNode;

    // 5. Liberacao de memória: Deleta o nó antigo (que p estava segurando).
    delete p;

    // 6. Contagem
    count --;
}

// Pré: -- | Pós Deleta todos os nós e ZERA a pilha
void Pilha::clear() {
    StackPointer p;

    // 1. Loop: enquanto o 'topo' não for NULL.
    while(topo !=NULL) {
        p = topo; // Guarda o endereco do nó atual

        // 2. Avanca o Topo: Move o 'topo' para o nó seguinte antes de deletar o atual.
        topo = topo->nextNode;

        // 3. Deleta: Libera a memória do nó antigo.
        delete p;
    }
    // Garante que o contador seja zerado.
    count = 0;
}