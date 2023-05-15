#include "../Headers/Node.h"
#include "../Headers/Edge.h"
#include <iostream>

using namespace std;

//? Constructor and Destructor--------------------------------
Node::Node(int id, bool final){
    this->id = id;
    this->position = 0;
    this->final = final;

    this->next_node = nullptr;
    this->first_edge = nullptr;
    this->last_edge = nullptr;
}

Node::~Node(){
    Edge* next_edge = this->first_edge;

    while(next_edge != nullptr){
        Edge* aux_edge = next_edge->getNextEdge();
        delete next_edge;
        next_edge = aux_edge;
    }
}
//? Getters --------------------------------------------------
int Node::getId(){
    return this->id;
}

int Node::getPosition(){
    return this->position;
}

bool Node::getFinal(){
    return this->final;
}

Node* Node::getNextNode(){
    return this->next_node;
}

Edge* Node::getFirstEdge(){
    return this->first_edge;
}

Edge* Node::getLastEdge(){
    return this->last_edge;
}

Edge* Node::getEdge(int target_id){
    for(Edge *auxEdge = this->first_edge; auxEdge != nullptr; auxEdge = auxEdge->getNextEdge()){
        if(auxEdge->getTargetId() == target_id)
            return auxEdge;
    }
    return nullptr;
}

//? Setters --------------------------------------------------
void Node::setNextNode(Node* node){
    this->next_node = next_node;
}

void Node::setPosition(int position){
    this->position = position;
}

//? Others methods -------------------------------------------
bool Node::searchEdge(int target_id){
    if(this->first_edge != nullptr){
        for(Edge* aux = this->first_edge; aux != nullptr; aux = aux->getNextEdge())
            if(aux->getTargetId() == target_id)
                return true;
    }
    return false;
}

void Node::insertEdge(int target_id, int target_position, char letter, char movement){
    if(this->first_edge != nullptr){
        Edge* edge = new Edge(target_id, target_position, letter, movement);
        this->last_edge->setNextEdge(edge);
        this->last_edge = edge;
    }
    else{
        Edge* edge = new Edge(target_id, target_position, letter, movement);
        this->last_edge = this->first_edge;
    }
}

void Node::removeAllEdges(){
    if(this->first_edge != nullptr){
        Edge* next = nullptr;
        Edge* aux = this->first_edge;
        while(aux != nullptr){
            next = aux->getNextEdge();
            delete aux;
        }
    }
    this->first_edge = this->last_edge = nullptr;
}