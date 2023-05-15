#ifndef MAQUINA_TURING_H_INCLUDED
#define MAQUINA_TURING_H_INCLUDED

#include "Node.h"
#include <fstream>

using namespace std;

class Maquina_Turing {
    private:
        int order;
        int position;      // Posição de inserção do novo nó;

        Node* first_node;  // Primeiro nó da máquina;
        Node* last_node;   // Último nó da máquina;

    public:
        Maquina_Turing(int order);
        ~Maquina_Turing();

        //? Getters ----------------------------------------
        int getOrder();
        Node* getFirstNode();
        Node* getLastNode();
        Node* getNode(int id);
        Node* getNodeByPosition(int position);

        //? Others methods ---------------------------------
        void insertNode(int id, bool final);
        void insertEdge(int id, int target_id, char letter, char movement);
        bool searchNode(int id);

        //? Funcionalidades --------------------------------
        bool computing(string chain);
};

#endif