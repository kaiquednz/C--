#include <iostream>   // Para entrada/saída (cout, endl)
#include <stdexcept>  // Para usar a exceção runtime_error
#include "Pilha.h"    // Inclui a sua classe Pilha

using namespace std;

// Função que testa as funcionalidades da Pilha
void testarPilha() {
    // 1. CRIAÇÃO: Cria um objeto Pilha com capacidade máxima de 3 para facilitar o teste de lotação.
    Pilha p(3); 
    cout << "--- Inicializacao ---" << endl;
    cout << "Pilha criada. Capacidade: " << p.capacity() << endl;
    cout << "Vazia? " << (p.isEmpty() ? "Sim" : "Nao") << " | Tamanho: " << p.size() << endl;

    // 2. OPERAÇÕES PUSH (Empilhamento)
    cout << "\n--- Empilhando (Push) ---" << endl;
    
    p.push(10);
    cout << "Push 10. Topo: " << p.top() << ", Tamanho: " << p.size() << endl;
    
    p.push(20);
    cout << "Push 20. Topo: " << p.top() << ", Tamanho: " << p.size() << endl;
    
    p.push(30);
    cout << "Push 30. Topo: " << p.top() << ", Tamanho: " << p.size() << endl;

    // Teste de isFull
    cout << "Cheia? " << (p.isFull() ? "Sim" : "Nao") << endl;

    // 3. OPERAÇÕES POP (Desempilhamento)
    cout << "\n--- Desempilhando (Pop) ---" << endl;
    
    // Consulta o topo antes de remover (LIFO: 30 deve ser o primeiro a sair)
    cout << "Pop. Valor removido: " << p.top() << endl; 
    p.pop(); 
    
    cout << "Novo Topo: " << p.top() << ", Tamanho: " << p.size() << endl;
    
    // Consulta o novo topo (LIFO: 20 deve sair em seguida)
    cout << "Pop. Valor removido: " << p.top() << endl; 
    p.pop(); 
    
    cout << "Novo Topo: " << p.top() << ", Tamanho: " << p.size() << endl;
    
    p.pop(); // Remove o último elemento (10)
    
    // Teste de isEmpty final
    cout << "Pilha esvaziada. Vazia? " << (p.isEmpty() ? "Sim" : "Nao") << endl;
    
    // 4. TESTE DE ERRO (PUSH em Pilha Cheia) - Descomente para testar o erro
    /*
    cout << "\n--- Testando Erro: Push em Pilha Cheia ---" << endl;
    p.push(100); // Tenta colocar 100 na pilha cheia (capacidade 3)
    p.push(200);
    p.push(300);
    p.push(400); // ESTE VAI GERAR O ERRO
    */

    // 5. TESTE DE ERRO (POP em Pilha Vazia)
    cout << "\n--- Testando Erro: Pop em Pilha Vazia ---" << endl;
    p.pop(); // ESTE VAI GERAR O ERRO
}

int main() {
    // Usamos try-catch para interceptar os erros (runtime_error) que programamos no Pilha.cpp
    try {
        testarPilha();
    } catch (const runtime_error& e) {
        // e.what() retorna a mensagem de erro que você lançou (ex: "ERRO: Pilha vazia!...")
        cerr << "\nERRO CATCHED: " << e.what() << endl;
    }

    return 0;
}