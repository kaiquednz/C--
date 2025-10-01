#ifndef STACK_H
#define STACK_H

typedef char StackEntry; // tipo de dados que as stacks armazenarão

    class Stack{
    private:
        static const int MaxEntry = 100; // adiciona o limite de pilhas (no caso 100)
        StackEntry entry[MaxEntry]; // passa esse valor para o "entry" -> para saber o limite de entradas

        int top1; // -> vai usar o getTop para armazenar informacoes da stack1
        int top2; // -> vai usar o getTop para armazenar informacoes da stack2

    public:
    Stack(); // construtor
    ~Stack(); // destructor

    bool isFull(); // verifica se está cheio
    
    // PILHA 1
    bool stack1_empty(); // verifica se s1 está vazia
    void stack1_clear(); // vai retornar -1 (que significa que a array está vazia, já que comeca no 0)
    void stack1_push(StackEntry x); // adiciona 'valor' usando o x
    void stack1_pop(StackEntry &x); // remove 'valor' e grava o valor atual no x (por referência)
    void stack1_getTop(StackEntry &x); // usa a referencia de X para apontar qual o valor que está no topo
    int stack1_size(); // diz o quantas pilhas existem ativas (tamanho)

    // PILHA 2
    bool stack2_empty();
    void stack2_clear();
    void stack2_push(StackEntry x);
    void stack2_pop(StackEntry &x);
    void stack2_getTop(StackEntry &x);
    int stack2_size();
};

#endif