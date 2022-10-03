#include<stdio.h>
#include<string.h>
#define grafo 28

int Vertices, Arista;

char archivo[100]="Matriz";
int arr[grafo][grafo];
  
int lee(char archivo[]) 
{
	FILE *in;
	char entrada[80];
	int i,j;
	strcpy(entrada,archivo);
	strcat(entrada,".txt");
	in=fopen(entrada,"rb+");
	if(in!=NULL)
	{
		fscanf(in,"%d",&Vertices);
		printf("%d",Vertices);
	for(int i=0;i<Vertices;i++)
    {
    	printf("\n");
   		for(int j=0;j<2;j++)
   		{
   			fscanf(in,"%d",&arr[i][j]);
   			printf("%d ",arr[i][j]);
	    }
	} 	
	fclose(in);
	return 1;
	}
	else
	{
		printf("NO se encontr� el arhivo %s\n",entrada);
		return 0;
	}
}
int main()
{
  	FILE *out;
	int ban;
	ban=lee(archivo);
	if(ban)
	{
    }
    return 0;
}

