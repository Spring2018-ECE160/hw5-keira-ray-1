#include<stdio.h>
#define MAXL 1000

int mygetline(char line[],int maxlength);\
void strcopy(char *, char *, int n);


int main()
{
    char s[MAXL],t[MAXL];
    int n;
    printf("string s is:");
    mygetline(s,MAXL);
    printf("string t is:");
    mygetline(t,MAXL);
    printf("how many character would you like to copy\n");
    scanf("%i", &n);
    strcopy(s, t, n);

    printf("%s",s);

    return 0;
}

int mygetline(char s[],int lim)
{
    int c;
    int i;
    
    for(i=0; i<lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
        s[i] = c;
    
    if(c == '\n')
        s[i] = '\0';
    

    return i;
}

void strcopy(char *s,char *t, int n)
{
    while(*t && n-->0)
    {
        *s++ = *t++;
        
    }
}
