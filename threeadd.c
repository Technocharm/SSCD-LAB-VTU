// 5. Design, develop and implement a C/Java program to generate the machine code using Triples
// for the statement A = -B * (C +D) whose intermediate code in three-address form:

// T1 = -B
// T2 = C + D
// T3 = T1 + T2
// A = T3

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char op[2],arg1[5],arg2[5],res[5];
void main()
{
 FILE *fp1,*fp2;
 fp1=fopen("input.txt","r");
 fp2=fopen("output.txt","w");
 while(!feof(fp1))
 {
  fscanf(fp1,"%s%s%s%s",res,arg1,op,arg2);
  if(strcmp(op,"+")==0)
  {
   fprintf(fp2,"LD R0,%s\n",arg1);
   fprintf(fp2,"ADD R0,%s\n",arg2);
   fprintf(fp2,"ST %s,R0\n\n",res);
  }
  if(strcmp(op,"-")==0)
  {
   fprintf(fp2,"LD R0,%s\n",arg1);
   fprintf(fp2,"SUB R0,%s\n",arg2);
   fprintf(fp2,"ST %s,R0\n\n",res);
  }
  if(strcmp(op,"*")==0)
  {
   fprintf(fp2,"LD R0,%s\n",arg1);
   fprintf(fp2,"MUL R0,%s\n",arg2);
   fprintf(fp2,"ST %s,R0\n\n",res);
  }
  if(strcmp(op,"/")==0)
  {
   fprintf(fp2,"LD R0,%s\n",arg1);
   fprintf(fp2,"DIV R0,%s\n",arg2);
   fprintf(fp2,"ST %s,R0\n\n",res);
  }
  if(strcmp(op,"=")==0)
  {
   fprintf(fp2,"LD R0,%s\n",arg1);
   fprintf(fp2,"ST %s,R0\n\n",res);
  }
}
 fclose(fp1);
 fclose(fp2);
}