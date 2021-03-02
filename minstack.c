#include <stdlib.h>
#include <stddef.h>

struct b_stack{
	int val;
	int count;
	struct b_stack* next;
}b_stack;

typedef struct b_stack * Top;

struct b_stack *bs_init(){
	struct b_stack * bs = malloc(sizeof(struct b_stack));
	bs->next = NULL;
	bs->count = 0;
	return bs;
}

void bs_push(int val, Top *t){
	struct b_stack *new = bs_init();
	struct b_stack *old = *t;
	new->val = val;
	new->count = old->count + 1;
	new->next = old;
	*t = new;
}

int bs_pop(Top *t){
	Top curr = *t;
	int rval = curr->val;
	if(curr->next == NULL){
		curr->count = 0;
		curr->val = 0;
	} else { 
		*t = curr->next;
		free(curr);
	}
	return rval;	
}

void free_stack(Top t){
	while(t->count != 0){
		bs_pop(&t);
	}
	free(t);
}


