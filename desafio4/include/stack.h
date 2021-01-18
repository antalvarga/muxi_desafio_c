typedef struct stack Stack;

Stack * stackNew (void);
void stackFree (Stack * p );
void stackPush (Stack * p, int elem);
int stackPop (Stack * p, int elem);
int stackEmpty (Stack * p);
