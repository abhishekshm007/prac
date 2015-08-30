struct stack{
	int top;
	unsigned capacity;
	int *array;
};
typedef struct stack Stack;

Stack *createStack(unsigned capacity);

int isEmpty(Stack *s);

int isFull(Stack *s);

void push(Stack *s, int data);

int pop(Stack *s);

int getTop(Stack *s);
