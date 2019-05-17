## Título del trabajo

### Máquina expendedora tarot

Maquina expendedora de caramelos de colores. Primero la máquina pedirá una contraseña y, si esta es correcta, entregará 3 caramelos. Esta detectará el color de estos caramelos y asignará un mensaje a cada combinación de colores. Finalmente enviará los datos de caramelos gastados a C y creará un fichero con ellos.

## Integrantes del equipo

- Luis Perez Gonzalez- luispgonzalez 

- Victor Ramos Perez- victorramosperez 

- Alvaro Romero Rodriguez- alvaroromerorodriguez 

## Objetivo del trabajo

- Desarrollar un proyecto empleando conocimientos adquiridos aplicable a una situacion real.
- Aprender a programar hardware y software empleando Arduino y C.

## Sensores y materiales necesarios

- 1 placa Arduino Mega 2560.
- Protoboard.
- Estructura de carton pluma.
- 1 servomotor.
- Piezas hechas con impresora 3D para incorporar al servomotor.
- Sensor de colores TCS3200.
- Panel de teclas Keypad 4x4.
- Pantalla de texto LCD16x02.
- Led rojo y led verde.
- Resistencias.
- Cable conector.

## Presentación 

En este grupo hemos elegido este trabajo con la intención de crear algo vistoso que se separase (dentro de lo posible) de los miles de proyectos disponibles en internet. En nuestro trabajo utilizamos sensores relativamente sencillos de utilizar y de los que existe numerosa documentación online para tratar de crear algo nuevo. 
Otra razón por la cual elegimos este trabajo fue con la intención de producir algo que podría potencialmente generar beneficios en el mundo real. Las máquinas expendedoras siempre han sido un negocio rentable, y esta, con una premisa original, captaría la atención de todos los públicos. Si bien no ha sido posible comenzar el programa con una moneda (a causa de un sensor de peso defectuoso), esta era la intención inicial, y nos hemos visto obligados a cambiar este sensor por una contraseña.

## Hardware

### Sensor de color TCS3200

El TCS3200 tiene cuatro entradas digitales S0, S1, S2, y S3, y una salida digital Out. Para conectarlo a Arduino hemos necesitado emplear 5 pines digitales.
En primer lugar alimentamos el módulo conectando los pines Gnd y Vcc del TCS3200, respectivamente, a Gnd y Vcc de Arduino.
Los pines S0 y S1 controlan la frecuencia de la salida y la desactivación del módulo. Los conectamos a dos salidas digitales, o podemos conectarlas a 5V si no queremos poder apagar el módulo.

....| Power Down  | 2%  |  20%  |  100%  |
--- | ----------- | --- | ----- | ------ |
 S0 |     L       |  L  |   H   |    H   |
 S1 |     L       |  H  |   L   |    H   |
 
 Por otra parte, los pines S2 y S3 seleccionan el color a medir. Deberemos conectarlos a dos salidas digitales de Arduino.

....| Rojo  | Azul  |  Clear  |  Verde  |
--- | ----- | ----- | ------- | ------- |
 S2 |   L   |   L   |    H    |    H    |
 S3 |   L   |   H   |    L    |    H    |

**Ejemplo de codigo**
```
git status 
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;    
int rojo =0;  
int verde =0;  
int azul = 0;
int vector[3];
void setup() {
      Serial.begin(9600);
      pinMode(s0, OUTPUT);
      pinMode(s1, OUTPUT);
      pinMode(s2, OUTPUT);
      pinMode(s3, OUTPUT);
      pinMode(out, INPUT);
      digitalWrite(s0, HIGH);
      digitalWrite(s1, LOW);
void loop{
for(i=0;i<3;i++)
  sensorcolor(vector,i);
}
int sensorcolor(int vector[],int i){  
  clr = readColor();
      delay(10);  
      switch (clr) {
        case 1:
        Serial.print("ROJO");
        vector[i]=1; 
        break;
        case 3:
        Serial.print("verde");
        vector[i]=2; 
        break;
        default:
        Serial.print("AZUL");
        vector[i]=3;  
      }
  } 



    int readColor() {
      // Setting red filtered photodiodes to be read
      digitalWrite(s2, LOW);
      digitalWrite(s3, LOW);
      // Reading the output frequency
      frequency = pulseIn(out, LOW);
      int R = frequency;
      // Printing the value on the serial monitor
      Serial.print("R= ");//printing name
      Serial.print(frequency);//printing RED color frequency
      Serial.print("  ");
      delay(50);
      // Setting Green filtered photodiodes to be read
      digitalWrite(s2, HIGH);
      digitalWrite(s3, HIGH);
      // Reading the output frequency
      frequency = pulseIn(out, LOW);
      int G = frequency;
      // Printing the value on the serial monitor
      Serial.print("G= ");//printing name
      Serial.print(frequency);//printing RED color frequency
      Serial.print("  ");
      delay(50);
      // Setting Blue filtered photodiodes to be read
      digitalWrite(s2, LOW);
      digitalWrite(s3, HIGH);
      // Reading the output frequency
      frequency = pulseIn(out, LOW);
      int B = frequency;
      // Printing the value on the serial monitor
      Serial.print("B= ");//printing name
      Serial.print(frequency);//printing RED color frequency
      Serial.println("  ");
      delay(50);
      if(R==21 || R== 23){
        clr=1;
      }

      
      if(R==22){
        clr = 3; // Green

      }
      return clr;  
    }
    ´´´
