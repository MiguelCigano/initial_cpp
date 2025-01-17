#include <stdio.h>

#define IN      1
#define OUT     0

void fn_count_l_w_c() 
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++ nc;
        if (c == '\n') {
            ++nl;
        }    
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT; 
        }
        else if (state == OUT) {
            state == IN;
            ++nw;
        }
    }
    printf("%d %d %d \n\n", nl, nw, nc);
}


int main () 
{
    printf ("Hola mundo \n");
    fn_count_l_w_c();
    return 0;
}