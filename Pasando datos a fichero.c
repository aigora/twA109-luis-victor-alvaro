#include <stdio.h>
#include <stdlib.h>


void escribir_fichero(int[]);
int main(void) 
{
	int i;
	int vector[3];
    //RECIBIR DATOS
    for (i=0;i<3;i++)
    {
    	printf("Inroduzca un numero\n");
    	scanf("%d",&vector[i]);
	}
    escribir_fichero(vector);
	return 0;
}
void escribir_fichero(int vector[])
{
	int j;
	FILE *salida;
	salida=fopen("Caramelos.txt","wt");
	if (salida==NULL)
	    printf("No se han podido guardar los datos\n");
	else
	{
		for(j=0;j<3;j++)
		{
			switch (vector[j])
			{
				case 1: 
				    fprintf(salida,"ROJO\n");
				    break;
				case 2: 
				    fprintf(salida,"VERDE\n");
				    break;
				case 3: 
				    fprintf(salida,"AZUL\n");
				    break;
			}
		}
	}
}
