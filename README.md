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
En primer lugar alimentamos el módulo conectando los pines Gnd y Vcc del TCS3200, respectivamente, a Gnd, OE y Vcc de Arduino.
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
        //Serial.print("ROJO");
        vector[i]=1; 
        break;
        case 2:
        //Serial.print("verde");
        vector[i]=2; 
        break;
        case 3:
        //Serial.print("AZUL");
        vector[i]=3;  
      }
  } 



    int readColor() {
      // Diodo rojo
      digitalWrite(s2, LOW);
      digitalWrite(s3, LOW);
      frequency = pulseIn(out, LOW);
      int R = frequency;
      delay(50);
      // Diodo verde
      digitalWrite(s2, HIGH);
      digitalWrite(s3, HIGH);
      frequency = pulseIn(out, LOW);
      int G = frequency;
      delay(50);
      //Diodo azul
      digitalWrite(s2, LOW);
      digitalWrite(s3, HIGH);
      frequency = pulseIn(out, LOW);
      int B = frequency;
      delay(50);
  if(R<45 & R>32 & G<65 & G>55){
    color = 1; // Red
  }
  if(R<53 & R>40 & G<53 & G>40){
    color = 2; // Green
  }
  else
  {
    color = 3; // Blue
  }
      return color;  
 }
    
```

El funcionamiento del código sigue el paradigma modular, empleando varias funciones para simplificar el código. La primera función, "sensorcolor" asigna la acción a cada color detectado, sin embargo esta no detecta el color, si no que llama a otra función diferente para esto. Esta función tiene entradas "i" (la variable del bucle for principal) y un vector de tres enteros donde se guardará la combinación de colores.
La función que detecta el color es "readColor". El funcionamiento de esta función no tiene gran complicación, aunque el código resulta cofuso. Básicamente enciende los diodos de cada color de forma separada para anotar la frecuencia leída por cada uno. Más tarde compara estas frecuencias a unas de referencia (ajustadas por nosotros para que distingan los colores de nuestros caramelos) y devuelve un entero a la función "sensorcolor" (1=ROJO 2=VERDE 3=AZUL)

### Servomotor

Un servomotor es un accionador ampliamente empleado en electrónica. A diferencia de otros
tipos de motores en los que se controla la velocidad de giro, en un servo se indica el ángulo
deseado y el servo se encarga de posicionarse en este ángulo.
Típicamente los servos disponen de un rango de movimiento de entre 0 a 180°. Es decir, no
son capaces de dar la vuelta por completo (de hecho disponen de topes internos que limitan el
rango de movimiento). Internamente un servo está constituido por un motor de corriente
continua, acoplado a un reductor para reducir la velocidad de giro, junto con la electrónica
necesaria para controlar su posición. Frecuentemente se dispone de un potenciómetro unido
al eje del servo que permite al servo conocer la posición del eje. Esta información es tratada
por un controlador integrado que se encarga de actuar sobre el motor para alcanzar la
posición deseada.
La comunicación de la posición deseada se realiza mediante la transmisión de una señal
pulsada con periodo de 20ms. El ancho del pulso determina la posición del servo. La relación
entre el ancho del pulso y el ángulo depende del modelo del motor. Por ejemplo, algunos
modelos responden con 0° a un pulso de 500 ms, y otros a un pulso de 1000 ms. En general,
en todos los modelos un pulso entre 500-1000µs corresponde con 0°, un pulso de 1500µs
corresponde con 90° (punto neutro) y un pulso entre 2000-2500µs corresponde con 180°. Por
tanto, variando la señal en microsegundos podemos disponer de una precisión teórica de
0.18°-0.36°, siempre que la mecánica del servo acompañe.
Conectar un servo a Arduino es sencillo. El servo dispone de tres cables, dos de alimentación
(GND y Vcc) y uno de señal (Sig). En general, la alimentación a los servos se realiza desde una
fuente de tensión externa (una batería o una fuente de alimentación) a una tensión de 5V6.5V, siendo 6V la tensión idónea. Arduino puede llegar a proporcionar corriente suficiente.

```
//Avanza de 115 a 65, posición donde está el sensor de color. Ahí, se detiene con un delay de 500.
      for(int i = 140; i > 65; i--) {
        servoMotor.write(i);
        delay(2);
      }
      //Avanza de 65 a 29, posición donde está el agujero para que caiga el caramelo.
      for(int i = 65; i > 29; i--) {
        servoMotor.write(i);
        delay(2);
      }
      delay(500);
      
      //Vuelve a la posicion de 115, donde recoje otro caramelo.
      for(int i = 29; i < 14 0; i++) {
        servoMotor.write(i);
        delay(2);
      }
```
En nuestro caso solo hemos empleado el servomotor con bucles for para moverlo entre posiciones. La primera sitúa la plataforma debajo del tubo de caramelos y recoge uno. La segunda posición coloca el caramelo bajo el sensor de color. La tercera deja caer el caramelo hacia la bandeja de recogida. Para terminar regresa a la posicion inicial.


