#include "linkedstack.h"


typedef struct {
	int R;
	int C;
} POS_t[1], *POS;


void* struct_constructor(int r, int c)
{
	POS pos = (POS)malloc(sizeof(POS));
	pos->R = r;
	pos->C = c;
	return pos;
}

void print_matrix(int M[][8])
{
	int i, j;
	for ( i = 0; i < 8; i++)
	{
		for ( j = 0; j < 8; j++)
		{
			printf("%3d ", M[i][j]);
		}
		printf("\n");
	}
}

void solve_maze() {
	int M[8][8] = {
		/* R\C   0  1  2  3  4  5  6  7 */
		/* 0 */ {0, 0, 0, 1, 0, 0, 0, 0},
		/* 1 */ {0, 1, 1, 1, 0, 0, 1, 0},
		/* 2 */ {0, 1, 0, 1, 0, 0, 1, 0},
		/* 3 */ {0, 1, 0, 1, 1, 1, 1, 0},
		/* 4 */ {0, 1, 0, 0, 0, 0, 1, 1},
		/* 5 */ {0, 1, 1, 0, 1, 1, 1, 0},
		/* 6 */ {0, 0, 0, 0, 1, 0, 0, 0},
		/* 7 */ {0, 0, 0, 0, 1, 0, 0, 0},
	};
	printf("\n\nINITIAL MATRIX\n-------------------------\n\n");
	print_matrix(M);
	int I, J, R = 0, C = 3;
	LINKED_STACK stack;
	stack = linked_stack_init();
	linked_stack_push(stack, struct_constructor(R, C));
	do
	{
		POS pos = struct_constructor(R, C);
		M[R][C] = 2;

		// testing up/right/down/left  ->  /North/East/South/West
		if (R != 0 && M[R-1][C] == 1)
		{
			R = R-1;
			linked_stack_push(stack, struct_constructor(R, C));
		}
		else if (C != 7 && M[R][C+1] == 1)
		{
			C = C+1;
			linked_stack_push(stack, struct_constructor(R, C));
		}
		else if (R != 7 && M[R+1][C] == 1)
		{
			R = R+1;
			linked_stack_push(stack, struct_constructor(R, C));
		}
		else if (C != 0 && M[R][C-1] == 1)
		{
			C = C-1;
			linked_stack_push(stack, struct_constructor(R, C));
		}
		else
		{
			linked_stack_pop(stack);
			M[R][C] = -1;
			pos = linked_stack_top(stack);
			R = pos->R;
			C = pos->C;
		}
	} while (R != 7 && C != 7 && R != 0 && C != 0);
	M[R][C] = 2;

	// printing result
	printf("\n\nSOLVED MATRIX\n-------------------------\n\n");
	print_matrix(M);
}

