#ifndef PILHA_H
#define PILHA_H

// 1. Tipo de Entrada: Define o tipo de dado que a pilha armazena (fácilmente mutável)
typedef char StackEntry;

class Pilha{
    private:
    // --- Estrutura do Nó e Ponteiro ---
    // 2. Ponteiro de Nó (StackPointer): Cria um alias para o ponteiro do nó, por clareza
    struct StackNode;
    typedef StackNode *StackPointer;
    
    // 3. O Nó (StackNode): A "caixinha" de dados.
    struct StackNode {
        StackEntry entry;   // dado real (char, int e etc.)
        StackPointer nextNode; // Ponteiro para o PRÓXIMO NÓ (o que está abaixo dele)
    };

    // --- Variáveis de Controle ---

    StackPointer topo;
    int count;

    public:
    Pilha();    // Construtor
    ~Pilha();   // Destrutor

    // Inspecao/Consulta
    bool isEmpty(); // Verifica se está vazio
    bool isFull(); // Verifica se está cheio
    int size(); // Retorna 'count'
    void getTop(StackEntry &x); //Consulta o top sem remover
    
    // Acao
    void clear();
    void push(StackEntry x); // Adiciona um nó no topo.
    void pop(StackEntry &x); // Remove o nó do topo.
};

#endif