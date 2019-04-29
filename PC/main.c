#include <stdio.h>
#include <legf.h>

int main(int argc, char **argv)
{
    initialize_view();
    refresh_view();
    getchar();
	comps[0].X1.Value = 300;
	refresh_view();
    getchar();
    getchar();
	return 0;
}
