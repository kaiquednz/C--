#ifndef QUEUE_H
#define QUEUE_H

    // 1. Definicao do Tipo de Entrada
    typedef char QueueEntry; // Alias: Define que a fila irá armazenar caracteres (char)

    class Queue{
        private:
            // --- Definições Essenciais para o Encadeamento ---
    // 2. Declaracao Antecipada: Cria o tipo QueuePointer (ponteiro para um QueueNode)
    struct QueueNode;
    // 3. Alias de Ponteiro: Cria o tipo QueuePointer (ponteiro para um QueueNode)
    typedef QueueNode *QueuePointer;
    // 4. Struct Node (A caixinha)
    struct QueueNode{
        QueueEntry entry;
        QueuePointer nextNode;
    };
        // --- Ponteiros de Controle (A Cabeça(head) e a Cauda(tail)) ---
        QueuePointer head; // Ponteiro de INÍCIO/CABECA: Aponta para o PRIMEIRO nó (próximo a sair - SERVE).
        QueuePointer tail; // Ponteiro de FIM/CAUDA: Aponta para o ÚLTIMO nó (onde a insercão ocorre- APPEND).

        int count; // Contador

        public:
        Queue(); // Constructor
        ~Queue(); // Destructor

        // Métodos de Consulta
        bool isEmpty(); // Verifica se head é NULL (fila vazia).
        int size(); // Verifica tamanho da fila, retornando o valor de count

        // Métodos Action (FIFO): FIRST IN - FIRST OUT
        void clear();   // Deleta todos os nós da fila.
        void append(QueueEntry x);  // Insercao: Adiciona um nó no FIM (tail).
        void serve(QueueEntry &x);  // Remocão: remove o nó do INÍCIO (head).
        void getFront(QueueEntry &x); // Consulta: Retorna o valor do INÍCIO (head) sem REMOVER.
        void getRear(QueueEntry &x); // Consulta: Retorna o valor do FIM (tail) sem REMOVER.
    };

#endif