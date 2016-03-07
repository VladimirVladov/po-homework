#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct occurance_t
{
    int hash;
    int count;
    char *words[4];
    int len;
};


int long_hash(char *word);
int get_occurance_t(struct occurance_t array[], int lenght, int hash);
void sort_strings(char *words[], int len);

int main()
{
    struct occurance_t array_of_occurance[3000];
    int  hash, lenght = 0,  index;
   
    char *word;

    while(1)
    {
        word  = (char*) malloc(sizeof(word));
        scanf("%s", word);
        hash = long_hash(word);
        index = get_occurance_t(array_of_occurance, lenght, hash);
        if(index == -1)
        {
            array_of_occurance[lenght].count = 1;
            array_of_occurance[lenght].hash = hash;
            array_of_occurance[lenght].words[0] = word;
            array_of_occurance[lenght].len = 1;
            lenght++;
        }
        else
        {
            array_of_occurance[index].count++;
            int hasWord = 0;
            int i;
            for(i = 0; i < array_of_occurance[index].len; i++)
            {
                if(strcmp(array_of_occurance[index].words[i], word) == 0)
                {
                    hasWord = 1;
                    break;
                }
            }

            if(hasWord == 0)
            {
                array_of_occurance[index].words[array_of_occurance[index].len] = word;
                array_of_occurance[index].len++;
            }

            if(array_of_occurance[index].count == 4)
            {
                sort_strings(array_of_occurance[index].words, array_of_occurance[index].len);
                printf("[%d] ", array_of_occurance[index].hash);
                for(i = 0; i < array_of_occurance[index].len; i++)
                {
                    printf("%s ", array_of_occurance[index].words[i]);
                }

                return 0;
            }
        }
    }



    return 0;
}

int long_hash(char *word)
{
    int i = 1, temp = 42, p;

    while(*word != '\0')
    {
        p = *word * i;
        temp = p + temp;

        word++;
        i++;
    }

    return temp;
}

int get_occurance_t(struct occurance_t array[], int lenght, int hash)
{
    int i;
    for(i = 0; i < lenght; i++)
    {
        if(array[i].hash == hash) {
            return i;
        }
     }

     return -1;
}

void sort_strings(char *words[], int len)
{
    int i, j;
    for(i = 0; i < len; i++)
    {
        for(j =i; j < len; j++)
        {
            if(strcmp(words[i], words[j]) > 0)
            {
                char *word = words[i];
                words[i] = words[j];
                words[j] = word;
            }
        }
    }
}

