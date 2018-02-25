#include<stdio.h>
#define MAXL 1000

int mygetline(char line[],int maxlength);\
int strend(char *s, char *t);
int strlength(char *t);

int main()
{
    char s[MAXL],t[MAXL];
    int result;
    printf("string s is:");
    mygetline(s,MAXL);
    printf("string t is:");
    mygetline(t,MAXL);
    
    result = strend(s,t);

    printf("%i",result);

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

int strend(char *s,char *t)
{
    int length;
    length = strlength(t);
    while(*s!='\0')
        s++;
    while(*t!='\0')
        t++;
    
    while (length > 0)
    {
        if (*t == *s)
        {
            --t;
            --s;
            --length;
        }
        else
            return 0;
    }
    if (length == 0)
        return 1;
}


int strlength(char *t)
{
    char *ref;
    ref = t;
    while(*ref !='\0')
        ref++;
    return ref-t;
}


