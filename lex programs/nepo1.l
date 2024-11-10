%{
#include <stdio.h>
int pos = 0, neg = 0;  // Counters for positive and negative numbers
%}

%%

[-][0-9]+  { neg++;  printf("%s IS NEGATIVE\n", yytext); }  // Match negative numbers
[0-9]+     { pos++;  printf("%s IS POSITIVE\n", yytext); }  // Match positive numbers
END   {return 0;}  
%%

 int yywrap() {
    return 1;  // Return 1 to indicate end of input
}

int main() {
    printf("ENTER THE NUMBER\n");
    yylex();  // Start lexing
    printf("NO OF NEGATIVES: %d\nNO OF POSITIVES: %d\n", neg, pos);  // Output counts
    return 0;
}

