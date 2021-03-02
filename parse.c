#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "minstack.h"

int parse_expr(char * c,  int i, Top t){
	switch(c[i]){
		case ')':
			return (bs_pop(&t) == ')') ? parse_expr(c, i+1, t) : -1;
		case ']':
			return (bs_pop(&t) == ']') ? parse_expr(c, i+1, t) : -1;
		case '}':
			return (bs_pop(&t) == '}') ? parse_expr(c, i+1, t) : -1;
		case '{':
			bs_push('}', &t);
			return parse_expr(c, i+1, t);
		case '(':
			bs_push(')', &t);
			return parse_expr(c, i+1, t);
		case '[':
			bs_push(']', &t);
			return parse_expr(c, i+1, t);
		case '\0':
			return (t->count == 0) ? 1 : -1;
		default:
			return parse_expr(c, i+1, t);
	}
}




int main(int argv, char** argc){

	char c[2048];
	while(1){
		int i = 0;
		printf("input> ");
		scanf("%s", c);
			Top t = bs_init(0);
			i = parse_expr(c, i, t);
		printf("rvalue: %i\n", i);
	}
	return 0;
}
