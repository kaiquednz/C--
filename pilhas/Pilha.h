#ifndef PILHA_H
#define PILHA_H

class Pilha{
    public:
    Pilha (int capacidade = 100);
    ~Pilha();
    bool isEmpty() const; // pré: -- | pós: retorna se é verdadeiro ou falso que a pilha está vazia (se estiver vazia = true)
    bool isFull() const; // pré: -- | pós: retorna se é verdadeiro ou falso que a pilha está cheia (se estiver cheia = true)
    void push(int valor); // pré: !isFull pois se estiver cheia não consegue adicionar | pós: Adiciona ao topo da pilha um novo elemento (valor)
    void pop(); // pré: !isEmpty pois se estiver vazia, não terpa mais nada para remover | pós: remove o elemento do topo da lista
    int top() const; // pré: !isEmpty pois se estiver vazia não tem o que o top retornar | pós: retorna o elemento que está no topo (SEM FAZER NENHUMA MODIFICAÇÃO NA ESTRUTURA PORTANTO SERVE APENAS PARA CONSULTA)
    int size() const;
    int capacity() const;

    private:
    int *dados; //array dinâmico que armazena os elementos
    int topo; // índice do topo -1 quando vazia
    int capacidade_; // capacidade da pilha

};


#endif // PILHA_H