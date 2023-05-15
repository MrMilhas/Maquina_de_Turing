#include "../Headers/Edge.h"
#include <iostream>

using namespace std;

//? Constructor and Destructor--------------------------------
Edge::Edge(int target_id, int target_position, char letter, char movement){
    this->target_id = target_id;
    this->target_position = target_position;
    this->next_edge = nullptr;
    this->letter = letter;
    this->movement = movement;
}

Edge::~Edge(){
    if (this->next_edge != nullptr){
        delete this->next_edge;
        this->next_edge = nullptr;
    }
}

//? Getters --------------------------------------------------
int Edge::getTargetId(){
    return this->target_id;
}

int Edge::getTargetPosition(){
    return this->target_position;
}

Edge* Edge::getNextEdge(){
    return this->next_edge;
}

char Edge::getLetter(){
    return this->letter;
}

char Edge::getMovement(){
    return this->movement;
}

//? Setters --------------------------------------------------
void Edge::setNextEdge(Edge* edge){
    this->next_edge = edge;
}