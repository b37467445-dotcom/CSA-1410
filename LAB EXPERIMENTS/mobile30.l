
%{
#include <stdio.h>
%}

%%
^[1-9][0-9]{9}\r?$ {
    printf("\nMobile Number Valid\n");
}

^[0-9]+\r?$ {
    printf("\nMobile Number Invalid\n");
}

^.*$ {
    printf("\nMobile Number Invalid\n");
}
%%

int main()
{
    printf("\nEnter Mobile Number : ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
