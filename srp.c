#include<stdio.h>
#include<string.h>

struct prodRule{
	char left[20],right[20];
};

int main(){
	int np,i;
	struct prodRule rules[20];
	char temp[30],*t1,*t2;
	char input[10],stack[20],ch[2],*match;
	int stacktop;
	
	//input productions
	printf("enter no of productions:");
	scanf("%d",&np);
	printf("enter productions:");
	for(i=0;i<np;i++){
		scanf("%s",temp);
		t1=strtok(temp,"->");
		t2=strtok(NULL,"->");
		strcpy(rules[i].left,t1);
		strcpy(rules[i].right,t2);	
	}
	//input the string
	printf("enter the strings:");
	scanf("%s",input);
	
	stack[0]='\0';
	
	printf("Stack\tInput\tAction\n");
	i=0;
	while(1){
		//Shift
		ch[0]=input[i];
		ch[1]='\0';
		strcat(stack,ch);
		printf("%s\t",stack);
		
		for(int k=i;k<strlen(input);k++){
			printf("%c",input[k]);
		}
		printf("\tShift %s\n",ch);
		//Reduce
		for(int j=0;j<np;j++){
			match=strstr(stack,rules[j].right);
			if(match!=NULL){
				stacktop=strlen(stack)-strlen(match);
				stack[stacktop]='\0';
				strcat(stack,rules[j].left);
				printf("%s\t",stack);
				for(int k=i;k<strlen(input);k++){
					printf("%c",input[k]);
				}
				printf("\tReduce %s->%s\n",rules[j].left,rules[j].right);
			}
		}
		i++;
		if(strlen(input)==i){
			break;
		}
	}
	if(strcmp(stack,rules[0].left)==0){
		printf("string accepted\n");
	}
	else{
		printf("string is not accepted\n");
	}
	return 0;
}
