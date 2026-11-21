
%{
#include <stdio.h>
int flag = 0;
%}

%%
^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9-]+(\.[a-zA-Z]{2,})+\r?$ {
    flag = 1;
}
\r?\n {
    if(flag == 1)
        printf("Accepted\n");
    else
        printf("Not Accepted\n");
    return 0;
}
. ;
%%

int main()
{
    printf("Enter email address:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}