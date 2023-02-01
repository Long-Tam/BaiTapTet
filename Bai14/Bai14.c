#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
//#include <stdlib.h> 
#define size 4
struct stack {
	int dat[size];
	int pre;
	int count;
};
void isEmpty(struct stack stack) {
	if (stack.count == 0) printf("True\n");
	else printf("False\n");
}
void isFool(struct stack stack) {
	if (stack.count == size) printf("True\n");
	else printf("False\n");
}
void push(struct stack* stack) {

	if (stack->count < size) {
		printf("watt to push: ");
		scanf_s("%d", &(stack->dat[stack->count]));
		(*stack).count += 1;
	}
	else printf("stack is full\n");
}
void pop(struct stack* stack) {
	if (stack->count >= stack->pre) {
		(stack->count) -= 1;
	}
	else printf("stack is empty\n");
}

int main() {
	struct stack stack;
	stack.count = 0;
	stack.pre = 1;
	int state;
	printf("type 1 to check for stack's emptiness ");
	printf("\ntype 2 to check if stack is full ");
	printf("\ntype 3 to push a number on top of stack ");
	printf("\ntype 4 to take the number out");
	printf("\ntype 5 to get out\n");
	while (1) {
		printf("\nenter here: ");
		scanf_s("%d", &state);
		switch (state) {
		case 1:
			isEmpty(stack);
			break;
		case 2:
			isFool(stack);
			break;
		case 3:
			push(&stack);
			break;
		case 4:
			pop(&stack);
			break;
		case 5:
			goto end;
			break;
		}
		for (int i = 0; i < stack.count; i++) {
			printf("|%d|", stack.dat[i]);
		}
		printf("\n");
	}

end:
	return 0;
}
