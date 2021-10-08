/*
Christian Hernandez Najera
HNCO200217
4-. C
ED1
08/10/2021
*/


#include <stdio.h>

struct Word {
    char Letter;
    struct Word *Next;
};

struct Employee {
    char Name[100];
    char CURP[18];
};

struct Word* getNode();

void push(struct Word *queue, char item);

void readQueue(struct Word *queue);

int main(int argc, char const *argv[])
{
    int opt = 0;
    struct Word *Queue;
    
    while (opt != 4)
    {
    
        printf("Introduce an option: \n");
        printf(" 1.- Insert employee \n 2.- Test Palindrome word \n 3.- Show Employees \n 4.- Exit \n \n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("1 \n");
            break;
        
        case 2:

	        char str[100];
            char charAt;
        	printf("Enter a word: \n");
            scanf("%s", &str);

            int i = 0;
	        while((charAt = str[i]) != '\0')
	        {
		        push(&Queue, charAt);
		        i++;
	        }

            readQueue(Queue);

            break;

        case 3:
            printf("3 \n");
            break;

        case 4:
            printf("bye \n");
            break;

        default:
            printf("incorrect option \n");
            break;
        }
    
    }    

    return 0;
}

struct Word* getNode()
{
	struct Word *newNode = (struct Word*)malloc(sizeof(struct Word));
	return newNode;
}

void push(struct Word *queue, char item)
{
	struct Word another = *queue;
	queue = getNode();
	queue->Letter = item;
	queue->Next = &another;
}

void readQueue(struct Word *queue){
    if(queue == NULL){
        printf ("Doesn't exist \n");
    }else{
        while(queue != NULL){
            printf ("%c ->", queue->Letter);
            queue = queue->Next;
        }
    }    
}