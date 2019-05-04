#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SerialPort.h"
#define MAX_DATA_LENGTH 255

// Funciones prototipo
void autoConnect(SerialPort *arduino,char*);
void escribir_fichero(int[]);
void mensaje(int[]);

int main(void)
{
    //Arduino SerialPort object
    SerialPort *arduino;
    // Puerto serie en el que está Arduino
    char* portName = "\\\\.\\COM3";
    // Buffer para datos procedentes de Arduino
    char incomingData[MAX_DATA_LENGTH];

    // Crear estructura de datos del puerto serie
    arduino = (SerialPort *)malloc(sizeof(SerialPort));
    // Apertura del puerto serie
    Crear_Conexion(arduino,portName);
    autoConnect(arduino,incomingData);
    return 0;
}

void autoConnect(SerialPort *arduino,char *incomingData)
{
    int leervector[3];
    int i;
   // Espera la conexión con Arduino
    while (!isConnected(arduino))
    {
        Sleep(100);
        Crear_Conexion(arduino,arduino->portName);
    }
    //Comprueba si arduino está connectado
    if (isConnected(arduino))
    {
        printf ("Conectado con Arduino en el puerto %s\n",arduino->portName);
    }
    // Bucle de la aplicación
    while (isConnected(arduino))
    {
    	for(i=0;i<3;i++)
    	{
    		leervector[i]=readSerialPort(arduino,incomingData,MAX_DATA_LENGTH);
    		Sleep(10);
		}
		escribir_fichero(leervector);
		mensaje(leervector);
	}
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
