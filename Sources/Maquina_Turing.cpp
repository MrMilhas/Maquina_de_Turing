#include <iostream>
#include <string>

#include "../Headers/Edge.h"
#include "../Headers/Maquina_Turing.h"
#include "../Headers/Node.h"

//? Constructor and Destructor--------------------------------
Maquina_Turing::Maquina_Turing(int order){
    this->order = order;
    this->position = 0;

    this->first_node = nullptr;
    this->last_node = nullptr;
}

Maquina_Turing::~Maquina_Turing(){
    Node *next_node = this->first_node;

    while (next_node != nullptr)
    {
        next_node->removeAllEdges();
        Node *aux_node = next_node->getNextNode();
        delete next_node;
        next_node = aux_node;
    }
}

//? Getters --------------------------------------------------
int Maquina_Turing::getOrder(){
    return this->order;
}

Node* Maquina_Turing::getFirstNode(){
    return this->first_node;
}

Node* Maquina_Turing::getLastNode(){
    return this->last_node;
}

Node* Maquina_Turing::getNode(int id){
    Node *node = first_node;

    while (node != nullptr){
        if (node->getId() == id)
            return node;
        node = node->getNextNode();
    }
    return nullptr;
}

Node* Maquina_Turing::getNodeByPosition(int position){
    Node *node = first_node;

    while (node != nullptr){
        if (node->getPosition() == position)
            return node;

        node = node->getNextNode();
    }
    return nullptr;
}

//? Others methods -------------------------------------------
void Maquina_Turing::insertNode(int id, bool final){
     if (first_node != nullptr)
    {
        //caso tenha, cria um novo node, aponta o ultimo pro novo e o novo de torna o ultimo
        Node *novo_node = new Node(id, final);
        novo_node->setPosition(this->position);
        last_node->setNextNode(novo_node);
        last_node = novo_node;
    }
    else
    {
        //caso nao tenha, cria um novo node e ele se torna o ultimo e o primeiro
        Node *novo_node = new Node(id, final);
        novo_node->setPosition(this->position);
        first_node = novo_node;
        last_node = novo_node;
    }
    this->position = this->position + 1;
}

void Maquina_Turing::insertEdge(int id, int target_id, char letter, char movement){

}

bool Maquina_Turing::searchNode(int id){
    Node *node = getNode(id);

    if (node == nullptr)
        return false;
    else
        return true;
}