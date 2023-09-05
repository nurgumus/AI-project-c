#ifndef DATA_TYPES_H
#define DATA_TYPES_H

// ==================== WRITE YOUR OPTIONAL DATA TYPES IF YOU NEED =============

enum CITIES
{
	b11,  b12,  b13,  b14,  b15,  b21,  b22,  b23,  b24,  b25,
	b31,  b32,  b33,  b34,  b35,  b41,  b42,  b43,  b44,  b45,
	b51,  b52,  b53,  b54,  b55
};


// ====== WRITE YOUR COMPULSORY (BUT SPECIFIC TO THE PROBLEM) DATA TYPES =======

enum ACTIONS // All possible actions
{
	Go_b11,  Go_b12,  Go_b13,  Go_b14,  Go_b15,   Go_b21,  Go_b22,  Go_b23,  Go_b24,  Go_b25,
	Go_b31,  Go_b32,  Go_b33,  Go_b34,  Go_b35, Go_b41,  Go_b42,  Go_b43,  Go_b44,  Go_b45,
	Go_b51,  Go_b52,  Go_b53,  Go_b54,  Go_b55
};

typedef struct State
{
    enum CITIES city;
    float h_n;   // Heuristic function

}State;

// ================== YOU DO NOT NEED TO CHANGE THIS PART ======================

enum METHODS  // This part must be updated if a new algorithm is added.
{
	BreastFirstSearch = 1,   UniformCostSearch = 2,        DepthFirstSearch = 3,
	DepthLimitedSearch= 4,   IterativeDeepeningSearch = 5, GreedySearch = 6,
    AStarSearch = 7
};

// This struct is used to determine a new state in transition model
typedef struct Transition_Model
{
    State new_state;
    float step_cost;
}Transition_Model;

typedef struct Node
{
    State state;
    float path_cost;
    enum ACTIONS action; //The action applied to the parent to generate this node
    struct Node *parent;
    int Number_of_Child; // required for depth-first search algorithms
}Node;

typedef struct Queue  // Used for frontier
{
    Node *node;
    struct Queue *next;
}Queue;



#endif
