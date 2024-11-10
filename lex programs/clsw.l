%{
#include<stdio.h>
int lc=0,sc=0,wc=0,tc=0,ch=0;
%}

%%
[\n] {lc++ ; ch+=yyleng;}
[ \t] {sc++ ; ch+=yyleng;}
[^\t] {tc++; ch+=yyleng;}
[^\t\n ]+ {wc++; ch+=yyleng;}
  
%%

int yywrap(){
}


int main()
{
printf("ENTER THE SENTENCE\n");
yylex();
printf("NUMBER OF LINES:%d",lc);
printf("SPACE COUNT :%d",sc);
printf("TABS COUNT:%d \nwords count :%d \n char count :%d",tc,wc,ch);

return 0;
}
