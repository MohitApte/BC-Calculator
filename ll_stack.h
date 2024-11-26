typedef struct node{
	int data;
	struct node* next;
	struct node* prev;
}node;


typedef struct num{
 	node *head;
 	node *tail;
 	int sign;
}num;


typedef struct ll_stack
{
    int size;
    int top;
    num **arr;
}ll_stack;

void print_LL(node *head);
node* ReverseLL(node*head);
int length(node *head);
void init_stack(ll_stack *s, int size);
int isEmpty(ll_stack s);
int isFull(ll_stack s);
void push(ll_stack *s,num *operand);
num** pop(ll_stack *s);
void eval(char *postfix, ll_stack stk);
