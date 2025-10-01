#include <iostream>
#include <cstdlib> // para abort();
#include "PilhaDuplaLinear.h"

using namespace std;

Stack::Stack(){
    top1 = -1;
    top2 = MaxEntry;
};

Stack::~Stack(){
    stack1_clear();
    stack2_clear();
}

bool Stack::isFull(){
    return top2 - top1 == 1;
}

bool Stack::stack1_empty(){
    return top1 == -1;
}

bool Stack::stack2_empty(){
    return top2 == -1;
}

int Stack::stack1_size(){
    return top1 + 1;
}

int Stack::stack2_size(){
    return MaxEntry - top2;
}

void Stack::stack1_getTop(StackEntry &x){
    if(stack1_empty()) {
        cerr << "ERRO: STACK1 VAZIA" << endl;
        abort();
    }
    x = entry[top1];
}

void Stack::stack2_getTop(StackEntry &x){
    if(stack2_empty()) {
        cerr << "ERRO: STACK2 VAZIA" << endl;
        abort();
    }
    x = entry[top2];
}

void Stack::stack1_clear(){
    top1 = -1;
}

void Stack::stack2_clear(){
    top2 = MaxEntry;
}

void Stack::stack1_push(StackEntry x){
    if(isFull()) {
        cerr << "ERRO: STACK1. ARRAY COMPARTILHADO CHEIO!" << endl;
        abort();
    }
    top1++;
    entry[top1] = x;
}

void Stack::stack2_push(StackEntry x){
    if(isFull()) {
        cerr << "ERRO: STACK2. ARRAY COMPARTILHADO CHEIO!" << endl;
        abort();
    }
    top2++;
    entry[top2] = x;
}

void Stack::stack1_pop(StackEntry &x){
    if(stack1_empty()){
        cerr << "ERRO: STACK 1 JÁ ESTÁ VAZIA" << endl;
        abort();
    }
    x = entry[top1];
    top1--;
}

void Stack::stack2_pop(StackEntry &x){
    if(stack2_empty()){
        cerr << "ERRO: STACK 2 JÁ ESTÁ VAZIA" << endl;
        abort();
    }
    x = entry[top2];
    top2--;
}