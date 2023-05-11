#define constitucion 13
#define san_juan 12
#define independencia 11
#define moreno 10
int boton = 9; 
#define buzzer A0
#define a 7
#define b 8
#define c A1
#define d A2
#define e A3
#define f 6
#define g 5
int tiempo(3000);
int estacion_actual = 0;
int estaciones_faltantes = 4;

void setup()
{
  pinMode(constitucion, OUTPUT);
  pinMode(san_juan, OUTPUT);
  pinMode(independencia, OUTPUT);
  pinMode(moreno, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  Serial.begin(9600);
}
void llegar(const int pin)
{
    digitalWrite(pin, LOW);
    delay(tiempo);
    digitalWrite(pin, HIGH);
    sonar_buzzer();
    delay(tiempo);
    digitalWrite(pin, LOW);
}
void conocer_estacion()
{
 int estado_led_constitucion = digitalRead(constitucion);
 int estado_led_sanjuan = digitalRead(san_juan);
 int estado_led_independencia = digitalRead(independencia);
 int estado_led_moreno = digitalRead(moreno);
  
  if (estado_led_constitucion == HIGH) {
    estacion_actual = constitucion;
  }
  else if (estado_led_sanjuan == HIGH) {
    estacion_actual = san_juan;
  }
  else if (estado_led_independencia == HIGH) {
    estacion_actual = independencia;
  }
  else if (estado_led_moreno == HIGH) {
    estacion_actual = moreno;
  }
}
void numero_en_pantalla()
{
  if (estaciones_faltantes == 4) {
       digitalWrite(a, LOW);
       digitalWrite(b,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,LOW);
       digitalWrite(e,LOW);
       digitalWrite(f,HIGH);
       digitalWrite(g,HIGH);
  }
  else if (estaciones_faltantes == 3) {
       digitalWrite(a, HIGH);
       digitalWrite(b,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,HIGH);
       digitalWrite(e,LOW);
       digitalWrite(f,LOW);
       digitalWrite(g,HIGH);
  }
  else if (estaciones_faltantes == 2) {
       digitalWrite(a, HIGH);
       digitalWrite(b,HIGH);
       digitalWrite(c,LOW);
       digitalWrite(d,HIGH);
       digitalWrite(e,HIGH);
       digitalWrite(f,LOW);
       digitalWrite(g,HIGH);
  }
  else if (estaciones_faltantes == 1) {
       digitalWrite(a, LOW);
       digitalWrite(b,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,LOW);
       digitalWrite(e,LOW);
       digitalWrite(f,LOW);
       digitalWrite(g,LOW);
  }
  else if (estaciones_faltantes == 0) {
       // No se indica ningún número
  }
}
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

void estacion_uno()
{
  estaciones_faltantes = 4;
   numero_en_pantalla();
   llegar(constitucion);
}

void estacion_dos()
{
  estaciones_faltantes = 3;
   numero_en_pantalla();
   llegar(san_juan);
}

void estacion_tres()
{
  estaciones_faltantes = 2;
   numero_en_pantalla();
   llegar(independencia);
}

void estacion_cuatro()
{
  estaciones_faltantes = 1;
   numero_en_pantalla();
   llegar(moreno);
   numero_en_pantalla();
   estaciones_faltantes = 0;
   numero_en_pantalla();
}

void loop()
{
   while (digitalRead(boton) == LOW){
   estacion_uno();
   estacion_dos();
   estacion_tres();
   estacion_cuatro();
   }
}