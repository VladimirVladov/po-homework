#include <stdio.h>
#include <stdlib.h>
int long_hash(char *word);
int main()
{
    int sum = 42;
    int result;
    char str[200];

    scanf("%s", str);

    result = long_hash(str);

    sum = sum + result;

    printf("%d", sum);
    return 0;
}

int long_hash(char *word)
{
    int i = 1, temp, p;

    while(*word != '\0')
    {
        p = *word * i;
        temp = p + temp;

        word++;
        i++;
    }

    return temp;
}

