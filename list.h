typedef struct node {
	void *element;
	struct node *next;
} node;

typedef struct list {
	node *head;
	node *tail;
	int length;
} list;

list* newList();
void traverse(list *l);
void insert(list *l, void *str, int pos);
void append(list *l, void *str);
void* remov(list *l, int pos);
int length(list *l);
void reverse(list *l);

node* create(void *str); //helper method
