#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE 100

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

int getch(void) // get a (possibly pushed back) charater
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) // push character back on input
{
    if (bufp >= BUFSIZE)
        printf("ungetch:too many characters\n");
    else
        buf[bufp++] = c;
}
int getfloat(int *fp)
{
    int c, sign;

    while (isspace(c = getch())) // skip white space
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); // it's not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    for (*fp = 0; isdigit(c); c = getch())
        *fp = 10 * *fp + (c - '0');

    *fp += sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main()
{
    int c, fp;
    c = getfloat(&fp);
    printf("c=%d fp=%d", c, fp);
    return 0;
}
