struct b_stack{
	int val;
	int count;
	struct b_stack* next;
}b_stack;

typedef struct b_stack * Top;

struct b_stack *bs_init();

void bs_push(int val, Top *t);

int bs_pop(Top *t);

void free_stack(Top t);


