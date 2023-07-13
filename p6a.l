%{
#include<stdio.h>
int sl=0;
int ml=0;
%}
%%
"/*"[a-zA-Z0-9' '\t\n]+"*/" ml++;
"//".* sl++;
%%
void main(){
 yyin=fopen("input.c","r");
 yyout=fopen("output.c","w");
 yylex();
 fclose(yyin);
 fclose(yyout);
 printf("\nNo. of SLC are= %d\n",sl);
 printf("\nNo. of MLC are= %d\n",ml);
}
