#include <stdio.h>
#include <stdlib.h>
void peso(float);
void servo_peso(void);
void mensaje(int[]);
void color(int[]);
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
						    printf(" MENSAJE \n"); //ROJO ROJO ROJO
						    break;
						case 2: 
						    printf(" MENSAJE \n"); //ROJO ROJO VERDE
						    break;
						case 3: 
						    printf(" MENSAJE \n"); //ROJO ROJO AZUL
						    break;
					}
			    }
				case 2: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" MENSAJE \n"); //ROJO VERDE ROJO
						    break;
						case 2: 
						    printf(" MENSAJE \n"); //ROJO VERDE VERDE
						    break;
						case 3: 
						    printf(" MENSAJE \n"); //ROJO VERDE AZUL
						    break;
					}
		    	}
				case 3: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" MENSAJE \n"); //ROJO AZUL ROJO
						    break;
						case 2: 
						    printf(" MENSAJE \n"); //ROJO AZUL VERDE
						    break;
						case 3: 
						    printf(" MENSAJE \n"); //ROJO AZUL AZUL
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
						    printf(" MENSAJE \n"); //VERDE ROJO ROJO
						    break;
						case 2: 
						    printf(" MENSAJE \n"); //VERDE ROJO VERDE
						    break;
						case 3: 
						    printf(" MENSAJE \n"); //VERDE ROJO AZUL
						    break;
					}
			    }
				case 2: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" MENSAJE \n"); //VERDE VERDE ROJO
						    break;
						case 2: 
						    printf(" MENSAJE \n"); //VERDE VERDE VERDE
						    break;
						case 3: 
						    printf(" MENSAJE \n"); //VERDE VERDE AZUL
						    break;
					}
		    	}
				case 3: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" MENSAJE \n"); //VERDE AZUL ROJO
						    break;
						case 2: 
						    printf(" MENSAJE \n"); //VERDE AZUL VERDE
						    break;
						case 3: 
						    printf(" MENSAJE \n"); //VERDE AZUL AZUL
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
						    printf(" MENSAJE \n"); //AZUL ROJO ROJO
						    break;
						case 2: 
						    printf(" MENSAJE \n"); //AZUL ROJO VERDE
						    break;
						case 3: 
						    printf(" MENSAJE \n"); //AZUL ROJO AZUL
						    break;
					}
			    }
				case 2: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" MENSAJE \n"); //AZUL VERDE ROJO
						    break;
						case 2: 
						    printf(" MENSAJE \n"); //AZUL VERDE VERDE
						    break;
						case 3: 
						    printf(" MENSAJE \n"); //AZUL VERDE AZUL
						    break;
					}
		    	}
				case 3: 
				{
					switch (combinacion[3])
					{
						case 1: 
						    printf(" MENSAJE \n"); //AZUL AZUL ROJO
						    break;
						case 2: 
						    printf(" MENSAJE \n"); //AZUL AZUL VERDE
						    break;
						case 3: 
						    printf(" MENSAJE \n"); //AZUL AZUL AZUL
						    break;
					}		
				}
			}
		}
	}
}

void color(int color[3]){
	int i;
 sensor_color;
	
	rojo=1;
	azul=2;
	verde=3;
	
	for(i=0; i<3; i++){
	
	   switch(c){
		   case 1: color[i]=1;
		   case 2: color[i]=2;
		   case 3: color[i]=3;
	   }
    }
    
}

