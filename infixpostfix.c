#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

void push(char s[100],int *top,char item){
    *top=*top+1;
    s[*top]=item;
}

pop(char s[100],int *top){
    int item;
    item=s[*top];
    *top=*top-1;
    return item;
}

int IPV(char ch){
    if(ch=='+'||ch=='-')return 1;
    if(ch=='*'||ch=='/')return 3;
    if(ch=='(')return 9;
    if(ch==')')return 0;
    if(ch=='^')return 6;
    return 7;
}

void main(){
    char infix[100],post[100],s[10],ch;
    int i,j=0,top=-1;

    clrscr();
    printf("Enter the valid infix expression");
    scanf("%s",infix);

    push(s,&top,'#');

    for(i=0;i<strlen(infix);i++){
        ch=infix[i];
        if(ch=='(')push(s,&top,ch);
        else if(isalnum(ch))post[j++]=ch;
        else{
            while(IPV(ch)<SPV(s[top]))
                post[j++]=pop(s,&top);
            push(s,&top,ch);
        }
    }

    while(s[top]!='#')
        post[j++]=pop(s,&top);

    post[j]='\0';

    printf("The convert pe is %s\n",post);
    printf("bombastic side eye");
}    