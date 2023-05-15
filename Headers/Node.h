#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>
#include <string>
#include "Edge.h"

using namespace std;

class Node {
    private:
        int id;            // Id do estado;
        int position;      // Posição do estado;
        bool final;        // Define se o estado é de aceitação;
        
        Node* next_node;   // Próximo estado;
        
        Edge* first_edge;  // Primeira transição;
        Edge* last_edge;   // Última transição;

    public:
        Node(int id, bool final);
        ~Node();

        //? Getters ----------------------------------------
        int getId();
        int getPosition();
        bool getFinal();
        Node* getNextNode();
        Edge* getFirstEdge();
        Edge* getLastEdge();
        Edge* getEdge(int target_id);

        //? Setters ----------------------------------------
        void setNextNode(Node *node);
        void setPosition(int position);

        //? Others methods ---------------------------------
        bool searchEdge(int target_id);
        void insertEdge(int target_id, int target_position, char letter, char movement);
        void removeAllEdges();
};

#endif