%{
#include <stdio.h>
int word_count = 0;
%}

%%
[a-zA-Z]+    { word_count++; }        // Match words (sequences of letters)
\n           { printf("Words: %d\n", word_count); word_count = 0; } // Print count at each newline
[ \t]+       { /* Ignore whitespace */ } // Ignore spaces and tabs
.            { /* Ignore other characters */ } // Ignore non-alphabetic characters

%%

int yywrap() {
    return 1;  // Required for Flex to indicate the end of file
}

int main() {
    yylex();  // Start lexing
    return 0;
}

