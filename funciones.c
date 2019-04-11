#include <stdio.h>
#include <stdlib.h>
void peso(float);
void servo_peso(void);
void mensaje(int[]);
int main (void)
{
}

void servo_peso (void)
{
	gira180grados;
	gira180grados;
}

void peso(float peso)
{
	const float euro=7.50;
    servo_peso;
    if (peso>=(euro-0.1) && peso<=(euro+0.1))
        printf("Espere... \n");
		servo_rueda;
    else 
	    printf("Introduzca la cantidad adecuada\n");
}

void mensaje(int combinacion[])
{
	//rojo==1,verde==2,azul==3//
	int i;
	switch (combinacion[1])
	{
		case 1:
		{
			switch (combinacion[2])
			{
				case 1: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" \n"); //ROJO ROJO ROJO
						    break;
						case 2: 
						    printf(" \n"); //ROJO ROJO VERDE
						    break;
						case 3: 
						    printf(" \n"); //ROJO ROJO AZUL
						    break;
					}
			    }
				case 2: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" \n"); //ROJO VERDE ROJO
						    break;
						case 2: 
						    printf(" \n"); //ROJO VERDE VERDE
						    break;
						case 3: 
						    printf(" \n"); //ROJO VERDE AZUL
						    break;
					}
		    	}
				case 3: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" \n"); //ROJO AZUL ROJO
						    break;
						case 2: 
						    printf(" \n"); //ROJO AZUL VERDE
						    break;
						case 3: 
						    printf(" \n"); //ROJO AZUL AZUL
						    break;
					}		
				}
			}
		}
	    case 2:
		{
			switch (combinacion[2])
			{
				case 1: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" \n"); //VERDE ROJO ROJO
						    break;
						case 2: 
						    printf(" \n"); //VERDE ROJO VERDE
						    break;
						case 3: 
						    printf(" \n"); //VERDE ROJO AZUL
						    break;
					}
			    }
				case 2: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" \n"); //VERDE VERDE ROJO
						    break;
						case 2: 
						    printf(" \n"); //VERDE VERDE VERDE
						    break;
						case 3: 
						    printf(" \n"); //VERDE VERDE AZUL
						    break;
					}
		    	}
				case 3: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" \n"); //VERDE AZUL ROJO
						    break;
						case 2: 
						    printf(" \n"); //VERDE AZUL VERDE
						    break;
						case 3: 
						    printf(" \n"); //VERDE AZUL AZUL
						    break;
					}		
				}
			}
		}
		case 3:
		{
			switch (combinacion[2])
			{
				case 1: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" \n"); //AZUL ROJO ROJO
						    break;
						case 2: 
						    printf(" \n"); //AZUL ROJO VERDE
						    break;
						case 3: 
						    printf(" \n"); //AZUL ROJO AZUL
						    break;
					}
			    }
				case 2: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" \n"); //AZUL VERDE ROJO
						    break;
						case 2: 
						    printf(" \n"); //AZUL VERDE VERDE
						    break;
						case 3: 
						    printf(" \n"); //AZUL VERDE AZUL
						    break;
					}
		    	}
				case 3: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" \n"); //AZUL AZUL ROJO
						    break;
						case 2: 
						    printf(" \n"); //AZUL AZUL VERDE
						    break;
						case 3: 
						    printf(" \n"); //AZUL AZUL AZUL
						    break;
					}		
				}
			}
		}
	}
}
