#include<stdio.h>
#include<string.h>
struct prodRule {
	char left[30],right[30];
};

int main(){
	int rn,i,j,k,stktop;
	char temp[50],*t1,*t2,input[50],ch[2],stack[10],*matchstr;
	
	stack[0]='\0';
	
	printf("Enter the no of production rules:");
	scanf("%d",&rn);
	struct prodRule rules[rn];
	printf("Enter the rules:\n");
	for(i=0;i<rn;i++){
		scanf("%s",temp);
		t1=strtok(temp,"->");
		strcpy(rules[i].left,t1);
		t2=strtok(NULL,"->");
		strcpy(rules[i].right,t2);
	}
	/*printf("printing rules..\n");
	for(i=0;i<rn;i++){
		printf("%s->%s\n",rules[i].left,rules[i].right);
	}*/
	
	printf("enter input:");
	scanf("%s",input);
	printf("string is %s\n",input);
	i=0;
	while(1){
	
		if(i<strlen(input)){
			ch[0]=input[i];
			ch[1]='\0';
			i++;
			strcat(stack,ch);
			printf("%s\t",stack);
			
			for(k=i;k<strlen(input);k++){
				printf("%c",input[k]);	
			}
			printf("\tShift %s\n",ch);
		}
		for(j=0;j<rn;j++){
			matchstr=strstr(stack,rules[j].right);
			if(matchstr!=NULL){
				stktop=strlen(stack)-strlen(matchstr);
				stack[stktop]='\0';
				
				strcat(stack,rules[j].left);
				
				printf("%s\t",stack);
				for(k=i;k<strlen(input);k++){
				printf("%c",input[k]);	
				}
			printf("\tReduce %s->%s\n",rules[j].left,rules[j].right);
			}
		}
		if (i == strlen(input) && strcmp(stack, rules[0].left) == 0) {
        printf("Accepted\n");
        break;
    } else if (i == strlen(input)) {
        printf("Not accepted\n");
        break;
    }
	}
	
	return 0;
}
