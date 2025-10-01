#ifndef QUEUE_H
#define QUEUE_H

// Tipo de Dado: Definimos o que a fila armazena
typedef int QueueEntry;

class Queue{
    private:
    // --- Variáveis de controle Contíguas --- //
    // Capacidade máxima
    static const int maxQueue = 100;

    // O Array: Alocado estatisticamente. Usamos maxQueue + 1 para a convencão de índice.
    QueueEntry entry[maxQueue + 1];

    // Contador de Elementos: Essencial para distinguir Vazio (count=0) de Cheio (cont=maxQueue).
    int count;

    // Índice da cabeca: Aponta para o PRIMEIRO elemento (próximo a sair).
    int head;

    // Índice da cauda: Aponta para o ÚLTIMO elemento inserido
    int tail;

    public:
    Queue(); // Constructor
    ~Queue(); // Destructor

    // Métodos de Consulta (inspect)
    bool isEmpty(); // Verifica se está vazio.
    bool isFull(); // Verifica se está cheio.
    int size(); // Verifica o tamanho (count).
    void getFront(QueueEntry &x); // Verifica o primeiro elemento (head) - SEM REMOVER.
    void getRear(QueueEntry &x); // Verifica o último elemento (tail) - SEM REMOVER.

    // Métodos Acao (action)
    void append(QueueEntry x); // Insercão: Usa a matemática circular no 'tail'.
    void serve(QueueEntry &x); // Remocão: Usa a matemática circular no 'head'.
    void clear(); // Reseta os índices para o estado inicial
};

#endif