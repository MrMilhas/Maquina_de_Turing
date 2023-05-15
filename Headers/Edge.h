#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#define RIGHT R
#define LEFT L
#define STAY S

using namespace std;

class Edge {
    private:
        int target_id;        // Id do estado alvo;
        int target_position;  // Posição do estado alvo;

        char letter;          // Caractere lido;
        char movement;        // Movimento na cadeia;

        Edge* next_edge;      // Próxima aresta do estado atual;

    public:
        Edge(int target_id, int target_position, char letter, char movement);
        ~Edge();

        //? Getters ----------------------------------------
        int getTargetId();
        int getTargetPosition();
        Edge* getNextEdge();
        char getLetter();
        char getMovement();

        //? Setters ----------------------------------------
        void setNextEdge(Edge* edge);
};

#endif