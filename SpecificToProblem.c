/*
    These functions are compulsory for tree search algorithms but they are specific
    to problems. More clearly, you must must update their blocks but do not change
    their input and output parameters.

    Also, if you need, you can add new functions at the end of file by declaring them in TREE_SEARCH.h
*/

#include "GRAPH_SEARCH.h"
#include "data_types.h"
#include <stdio.h>
#include <stdlib.h>

//______________________________________________________________________________
State* Create_State()
{
	State *state = (State*)malloc(sizeof(State));
    if(state==NULL)
    	Warning_Memory_Allocation();

   	for(state->city=b11; state->city<=b55; state->city++){
    	printf("%d --> ", state->city);
        Print_State(state);
        printf("\n");
   	}

   	do{
    	printf("Enter the code of the state: ");
        scanf("%d", &state->city);
   	}while(state->city<0 && state->city>=CITY_NUMBER);

    return state;
}

//______________________________________________________________________________
void Print_State(const State *const state)
{
    switch(state->city){
case b11:       printf("b11"); break;
case b12:       printf("b12"); break;
case b13:       printf("b13"); break;
case b14:       printf("b14"); break;
case b15:       printf("b15"); break;
case b21:       printf("b21"); break;
case b22:       printf("b22"); break;
case b23:       printf("b23"); break;
case b24:       printf("b24"); break;
case b25:       printf("b25"); break;
case b31:       printf("b31"); break;
case b32:       printf("b32"); break;
case b33:       printf("b33"); break;
case b34:       printf("b34"); break;
case b35:       printf("b35"); break;
case b41:       printf("b41"); break;
case b42:       printf("b42"); break;
case b43:       printf("b43"); break;
case b44:       printf("b44"); break;
case b45:       printf("b45"); break;
case b51:       printf("b51"); break;
case b52:       printf("b52"); break;
case b53:       printf("b53"); break;
case b54:       printf("b54"); break;
case b55:       printf("b55"); break;
    }
}

//______________________________________________________________________________
void Print_Action(const enum ACTIONS action)
{
   switch(action){
        case Go_b11:       printf("Go_b11"); break;
case Go_b12:       printf("Go_b12"); break;
case Go_b13:       printf("Go_b13"); break;
case Go_b14:       printf("Go_b14"); break;
case Go_b15:       printf("Go_b15"); break;
case Go_b21:       printf("Go_b21"); break;
case Go_b22:       printf("Go_b22"); break;
case Go_b23:       printf("Go_b23"); break;
case Go_b24:       printf("Go_b24"); break;
case Go_b25:       printf("Go_b25"); break;
case Go_b31:       printf("Go_b31"); break;
case Go_b32:       printf("Go_b32"); break;
case Go_b33:       printf("Go_b33"); break;
case Go_b34:       printf("Go_b34"); break;
case Go_b35:       printf("Go_b35"); break;
case Go_b41:       printf("Go_b41"); break;
case Go_b42:       printf("Go_b42"); break;
case Go_b43:       printf("Go_b43"); break;
case Go_b44:       printf("Go_b44"); break;
case Go_b45:       printf("Go_b45"); break;
case Go_b51:       printf("Go_b51"); break;
case Go_b52:       printf("Go_b52"); break;
case Go_b53:       printf("Go_b53"); break;
case Go_b54:       printf("Go_b54"); break;
case Go_b55:       printf("Go_b55"); break;
    }
}

//______________________________________________________________________________
int Result(const State *const parent_state, const enum ACTIONS action, Transition_Model *const trans_model)
{
    State new_state;
	const int PATH_COSTS[CITY_NUMBER][ACTIONS_NUMBER] =
        {
            { 0, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, 0,  1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1,  1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{  1, -1, -1, -1, -1, 0,  1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1,  1, 0,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1,  1, 0,  1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1,  1, -1, -1, -1,  1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, 0, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, 0, -1, -1, -1, -1,  1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, 0, -1, -1, -1, -1,  1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, 0,  1, -1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, 0,  1, -1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, 0,  1, -1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, 0,  1 },
{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1,  1, 0 }
		};
	     //    A    B    C    D    E    F    G    H    I    L    M    N    O    P    R    S    T    U    V    Z

         if(PATH_COSTS[parent_state->city][action]<=0)
              return FALSE;
         else{
              new_state.city = action;
              trans_model->new_state = new_state;
              trans_model->step_cost = PATH_COSTS[parent_state->city][action];
         }
         return TRUE;
}

float Compute_Heuristic_Function(const State *const state, const State *const goal)
{
      const float SLD[CITY_NUMBER][CITY_NUMBER] =   // CALCULATED ROUGHLY!!!
        {   {  0,  1,  2,  3,  4,  1,  2,  3,  4,  5,  2,  3,  4,  5,  6,  3,  4,  5,  6,  7,  4,  5,  6,  7,  8},
{  1,  0,  1,  2,  3,  2,  1,  2,  3,  4,  3,  2,  3,  4,  5,  4,  3,  4,  5,  6,  5,  4,  5,  6,  7},
{  2,  1,  0,  1,  2,  3,  2,  1,  2,  3,  4,  3,  2,  3,  4,  5,  4,  3,  4,  5,  6,  5,  4,  5,  6},
{  3,  2,  1,  0,  1,  4,  3,  2,  1,  2,  5,  4,  3,  2,  3,  6,  5,  4,  3,  4,  7,  6,  5,  4,  5},
{  4,  3,  2,  1,  0,  5,  4,  3,  2,  1,  6,  5,  4,  3,  2,  7,  6,  5,  4,  3,  8,  7,  6,  5,  4},
{  1,  2,  3,  4,  5,  0,  1,  2,  3,  4,  1,  2,  3,  4,  5,  2,  3,  4,  5,  6,  3,  4,  5,  6,  7},
{  2,  1,  2,  3,  4,  1,  0,  1,  2,  3,  2,  1,  2,  3,  4,  3,  2,  3,  4,  5,  4,  3,  4,  5,  6},
{  3,  2,  1,  2,  3,  2,  1,  0,  1,  2,  3,  2,  1,  2,  3,  4,  3,  2,  3,  4,  5,  4,  3,  4,  5},
{  4,  3,  2,  1,  2,  3,  2,  1,  0,  1,  4,  3,  2,  1,  2,  5,  4,  3,  2,  3,  6,  5,  4,  3,  4},
{  5,  4,  3,  2,  1,  4,  3,  2,  1,  0,  5,  4,  3,  2,  1,  6,  5,  4,  3,  2,  7,  6,  5,  4,  3},
{  2,  3,  4,  5,  6,  1,  2,  3,  4,  5,  0,  1,  2,  3,  4,  1,  2,  3,  4,  5,  2,  3,  4,  5,  6},
{  3,  2,  3,  4,  5,  2,  1,  2,  3,  4,  1,  0,  1,  2,  3,  2,  1,  2,  3,  4,  3,  2,  3,  4,  5},
{  4,  3,  2,  3,  4,  3,  2,  1,  2,  3,  2,  1,  0,  1,  2,  3,  2,  1,  2,  3,  4,  3,  2,  3,  4},
{  5,  4,  3,  2,  3,  4,  3,  2,  1,  2,  3,  2,  1,  0,  1,  4,  3,  2,  1,  2,  5,  4,  3,  2,  3},
{  6,  5,  4,  3,  2,  5,  4,  3,  2,  1,  4,  3,  2,  1,  0,  5,  4,  3,  2,  1,  6,  5,  4,  3,  2},
{  3,  4,  5,  6,  7,  2,  3,  4,  5,  6,  1,  2,  3,  4,  5,  0,  1,  2,  3,  4,  1,  2,  3,  4,  5},
{  4,  3,  4,  5,  6,  3,  2,  3,  4,  5,  2,  1,  2,  3,  4,  1,  0,  1,  2,  3,  2,  1,  2,  3,  4},
{  5,  4,  3,  4,  5,  4,  3,  2,  3,  4,  3,  2,  1,  2,  3,  2,  1,  0,  1,  2,  3,  2,  1,  2,  3},
{  6,  5,  4,  3,  4,  5,  4,  3,  2,  3,  4,  3,  2,  1,  2,  3,  2,  1,  0,  1,  4,  3,  2,  1,  2},
{  7,  6,  5,  4,  3,  6,  5,  4,  3,  2,  5,  4,  3,  2,  1,  4,  3,  2,  1,  0,  5,  4,  3,  2,  1},
{  4,  5,  6,  7,  8,  3,  4,  5,  6,  7,  2,  3,  4,  5,  6,  1,  2,  3,  4,  5,  0,  1,  2,  3,  4},
{  5,  4,  5,  6,  7,  4,  3,  4,  5,  6,  3,  2,  3,  4,  5,  2,  1,  2,  3,  4,  1,  0,  1,  2,  3},
{  6,  5,  4,  5,  6,  5,  4,  3,  4,  5,  4,  3,  2,  3,  4,  3,  2,  1,  2,  3,  2,  1,  0,  1,  2},
{  7,  6,  5,  4,  5,  6,  5,  4,  3,  4,  5,  4,  3,  2,  3,  4,  3,  2,  1,  2,  3,  2,  1,  0,  1},
{  8,  7,  6,  5,  4,  7,  6,  5,  4,  3,  6,  5,  4,  3,  2,  5,  4,  3,  2,  1,  4,  3,  2,  1,  0}   // Z
		};
	     //    A    B    C    D    E    F    G    H    I    L    M    N    O    P    R    S    T    U    V    Z

        return SLD[state->city][goal->city];
}

// ==================== WRITE YOUR OPTIONAL FUNCTIONS ==========================
