struct Stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct Stack* sp);
int isEMPTY(struct Stack *ptr);
int isFULL(struct Stack *ptr);
void PUSH(struct Stack* ptr, char val);
char POP(struct Stack* ptr);
int precedence(char ch);
char* infixToPostfix(char* infix);
int isOperator(char ch);
int isOperand(char ch);

