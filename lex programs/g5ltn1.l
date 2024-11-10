%{
#include <stdio.h>
#include <string.h>  // Include for strlen
int len = 0, counter = 0;
%}

%%

[a-zA-Z]+ { 
    len = strlen(yytext);  // Get length of the matched word
    printf("%s:%d\n",yytext,len);
	if(len > 5 && len < 10) {  // If length is between 6 and 9
        counter++;
	return counter; 
    }
}

.   { /* Ignore non-alphabetic characters */ }

%%

int yywrap(void) {
    return 1;  // Required by Flex
}

int main() {
    printf("ENTER THE STRING\n");
    yylex();  // Start lexing
    printf("%d is the corresponding count\n", counter);
    return 0;
}

