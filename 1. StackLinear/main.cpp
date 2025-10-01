#include <iostream>
#include <stdexcept>
#include "Pilha.h"

using namespace std;

// Funcao que testa todas as funcionalidades da Pilha
void testarPilha() {
    Pilha p(3);
    cout << "--- Inicializacao ---" << endl;
    cout << "Pilha criada. Capacidade: " << p.capacity() << endl;
    cout << "Vazia?" << (p.isEmpty() ? "Sim" : "Nao") << "| Tamanho: " << p.size() << endl;

    // 2. OPERACOES PUSH (Empilhamento)
    cout << "\n--- Empilhando (Push) ---" << endl;

    p.push(10);
    cout << "Push 10. Topo: " << p.top() << ", Tamanho: " << p.size() << endl;

    p.push(20);
    cout << "Push 20. Topo: " << p.top() << ", Tamanho: " << p.size() << endl;

    p.push(30);
    cout << "Push 30. Topo: " << p.top() << ", Tamanho: " << p.size() << endl;

    
    // TESTE PARA VER SE ESTÁ CHEIA
    cout << "Cheia? " << (p.isFull() ? "Sim" : "Nao") << endl;


    // 3. OPERACOES POP (DESEMPILHAMENTO)
    cout << "--- Desempilhando (pop) ---" << endl;

    //Consulta antes de remover (LIFO: 30 deve ser o primeiro a sair, pois foi o ultimo de entrar)
    cout << "Valor removido: " << p.top() << endl;
    p.pop();

    cout << "Novo Topo: " << p.top() << ", Tamanho: " << p.size();

    // EM SEGUIDA REMOVER O 20

    cout << "Valor removido: " << p.top() << endl;
    p.pop();

    cout << "Novo Topo: " << p.top() << endl;

    // EM SEGUIDA REMOVER O 10

    cout << "Valor removido: " << p.top() << ", Tamanho: " << p.size();
    p.pop();

    cout << "Novo Topo: " << p.top() << ", Tamanho: " << p.size();  

    // TESTE FINAL
    cout << "Pilha está vazia? " << (p.isEmpty() ? "Sim" : "Nao") << endl;

    // 5. TESTE DE ERRO (POP EM PILHA VAZIA)
    cout << "\n Testando Erro: Pop em Pilha Vazia ---" << endl;
    p.pop(); //TEÓRICAMENTE AQUI DEVE-SE GERAR O ERRO (DEFINIDO EM PILHA.CPP)
}

    int main (){
        // Usamos try-catch para interceptar os erros (runtime_error) (PILHA.CPP)
        try {
            testarPilha();
        } catch (const runtime_error& e) {
            cerr << "\nERRO CATCHED: " << e.what() << endl; 
        }
        
        return 0;
    }

