# Proyecto: Estación de subte

![](https://github.com/lucafamozo/Dojo_Dos_Subte/blob/master/img/Dojo_dos_subte.png)

## Integrantes:
* Antuñez, Juan Ignacio.
* Barrientos, Gonzalo.
* Cortés, Abril.
* Famozo, Luca.

## Descripción
Este proyecto consiste en la simulación de una pequeña red de subte. El circuito presenta cuatro estaciones: Constitución, San Juan, Independencia y Moreno. Se ejecuta al presionar el pulsador. Al iniciarse, se muestra por el **display** un "4", el cual indica que faltan cuatro estaciones para finalizar el recorrido. Al llegar a la primera estación, se encenderá un **LED** asignado a esa estación, a la vez que sonará un **buzzer** para indicar que se ha llegado a esa estación (cada estación presenta un tono de buzzer distinto). Al reanudarse el recorrido, el display muestra ahora un "3", y así continuará el circuito hasta llegar a la última estación para volver a empezar (hasta que se presione nuevamente el pulsador.)

## Funciones
La función principal se divide en cuatro funciones distintas, las cuales tienen estructuras similares una de la otra, pero realizan las tareas obteniendo distintos datos. También se determina que el pulsador esté pulsado para ejecutarse las funciones. 
```c
void loop()
{
   while (digitalRead(boton) == LOW){
   estacion_uno();
   estacion_dos();
   estacion_tres();
   estacion_cuatro();
   }
}
```
Como ejemplo se dará la función *'estación_uno()'*. Esta primeramente indica las estaciones que faltan para completar el viaje, y cuyo dato será utilizado para mostrarlo por el display a través de la función *'numero_en_pantalla()'*. Luego se llama a la función *'llegar()'* y se le pasa por parámetro una estación (como en este caso es la estación uno, se le pasará *Constitución*).
```c
void estacion_uno()
{
  estaciones_faltantes = 4;
   numero_en_pantalla();
   llegar(constitucion);
}
```
La función *'llegar()'* toma como parámetro un pin (asociado a una estación) de la forma previamente ejemplificada. Se encarga de encender el LED y hacer sonar el buzzer. 
```c
void llegar(const int pin)
{
    digitalWrite(pin, LOW);
    delay(tiempo);
    digitalWrite(pin, HIGH);
    sonar_buzzer();
    delay(tiempo);
    digitalWrite(pin, LOW);
}
```
*'sonar_buzzer()'* utiliza una función que nos indica cual es la estación actual, y de acuerdo a esta, emitirá un tono u otro dependiendo de la estación en la que se encuentre.
```c
void sonar_buzzer()
{
  conocer_estacion();
  switch (estacion_actual){
    case constitucion:
      tone(buzzer, 495, 1500);
      break;
    case san_juan:
      tone(buzzer, 400, 1500);
      break;
    case independencia:
      tone(buzzer, 385, 1500);
      break;
    case moreno:
      tone(buzzer, 370, 1500);
      break;
  }
}
```
# :heavy_dollar_sign:Link al proyecto
[Proyecto](https://www.tinkercad.com/things/aSdIPMVB60v)
