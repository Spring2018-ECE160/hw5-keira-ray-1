#include<stdio.h>
#define MAXL 1000

void mygetline(char line[],int maxlength);
void stcat(char *,char *);

int main(void)
{
    int length;
    char s[MAXL],t[MAXL];

    printf("string s is:");
    mygetline(s,MAXL);
    printf("string t is:");
    mygetline(t,MAXL);
    
    stcat(s,t);

    printf("%s",s);

    return 0;
}

void mygetline(char s[],int lim)
{
    int c;
    int i;
    
    for(i=0; i<lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
        s[i] = c;
    
    if(c == '\n')
        s[i] = '\0';
    

    return;
}

void stcat(char *s,char *t)
{
    while(*s!='\0')
        s++;
    while((*s=*t)!='\0')
    {   
        s++;
        t++;
    }
}
