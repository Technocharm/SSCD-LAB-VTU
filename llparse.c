/*3. Design, develop and implement YACC/C program to construct Predictive / LL(1)
Parsing Table for the grammar rules: A ->aBa , B ->bB | E. Use this table to parse the
sentence: abba$*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int i,j,k,n,col,row;
	char st[20],ip[20];
	char m[2][3][10] = {{"aBa","E","E"},{"n","bB","E"}};
	int size[2][3] = {{3,1,1},{1,2,1}};

	printf("Enter String:");
	scanf("%s",ip);
	strcat(ip,"$");
	n=strlen(ip);
	st[0] = '$';
	st[1] = 'A';
	i=1;
	j=0;

	printf("\n Stack \t\t Input\n");
	printf("______\t\t_____\n");
	while(st[i]!='$' && ip[j]!='$'){
		if(st[i]==ip[j]){
			i--;
			j++;
		}
		switch(st[i]){
		case'A':
			row=0;
			break;
		case'B':
			row=1;
			break;
		}
		switch(ip[j]){
		case 'a':
			col=0;
			if(st[i]=='$'){
				printf("Error");
				exit(0);
			}
			break;
		case 'b':
			col=1;
			if(st[i]=='$'){
				printf("Error");
				exit(0);
			}
			break;
		case'$':
			col=2;
			if(st[i]!='$'){
				printf("Error");
				exit(0);
			}
			else{
				printf("Success");
				exit(0);
			}
			break;
		}
		if(m[row][col][0]=='E'){
			printf("Error");
			exit(0);
		}
		else if(m[row][col][0]=='n'){
			i--;
		}
		else if(m[row][col][0]==ip[j]){
			for(k=size[row][col]-1;k>=0;k--){
				st[i]=m[row][col][k];
				i++;
			}
			i--;
		}
		for(k=0;k<=i;k++){
			printf("%c",st[k]);
		}
		printf("\t\t");
		for(k=j;k<=n;k++){
			printf("%c",ip[k]);
		}
		printf("\n");
	}
	k--;
	return 0;
}