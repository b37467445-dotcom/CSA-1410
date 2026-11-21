
%{
#include <stdio.h>
%}

%%
^[0-9]+\r?$ {
    printf("\nValid digit\n");
}

^.*$ {
    printf("\nInvalid digit\n");
}
%%

int main()
{
    printf("Enter the input: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
