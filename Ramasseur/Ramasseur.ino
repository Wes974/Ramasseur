#include <Arduino.h>

#include <SPI.h>
#include <Pixy.h>

Pixy pixy;

int pwm_a = 3;   //PWM control for motor outputs 1 and 2 is on digital pin 3
int pwm_b = 11;  //PWM control for motor outputs 3 and 4 is on digital pin 11
int dir_a = 12;  //direction control for motor outputs 1 and 2 is on digital pin 12
int dir_b = 13;  //direction control for motor outputs 3 and 4 is on digital pin 13

void setup()
{
  pinMode(pwm_a, OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);

  analogWrite(pwm_a, 0);  //set both motors to run at (100/255 = 39)% duty cycle (slow)
  analogWrite(pwm_b, 0);

  Serial.begin(9600);
  Serial.print("Starting…\n");

  pixy.init();
}

/* Let's take a moment to talk about these functions. The forw and back functions are simply designating the direction the motors will turn once they are fed a PWM signal.
If you only call the forw, or back functions, you will not see the motors turn. On a similar note the fade in and out functions will only change PWM, so you need to consider
the direction you were last set to. In the code above, you might have noticed that I called forw and fade in the same grouping. You will want to call a new direction, and then
declare your pwm fade. There is also a stop function.
*/

void forward() {              //forward
  digitalWrite(dir_a, HIGH);  //Reverse motor direction, 1 high, 2 low
  digitalWrite(dir_b, HIGH);  //Reverse motor direction, 3 low, 4 high
  analogWrite(pwm_a, 60);     //set both motors to run at (100/255 = 39)% duty cycle
  analogWrite(pwm_b, 60);
}

void backward() {            //backward
  digitalWrite(dir_a, LOW);  //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, LOW);  //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, 1);     //set both motors to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 1);
}

void stopped() {            //stop
  digitalWrite(dir_a, LOW); //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, LOW); //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, 0);    //set both motors to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 0);
}

void astop() {              //stop motor A
  analogWrite(pwm_a, 0);    //set both motors to run at 100% duty cycle (fast)
}

void bstop() {              //stop motor B
  analogWrite(pwm_b, 0);    //set both motors to run at 100% duty cycle (fast)
}

void gauche() {
  digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, LOW);
  analogWrite(pwm_a, 65);
  analogWrite(pwm_b, 65);
}

void droite() {
  digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, HIGH);
  analogWrite(pwm_a, 65);
  analogWrite(pwm_b, 65);
}

void loop() {

  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; // ??

  // grab blocks!
  blocks = pixy.getBlocks();

  // If there are detect blocks, print them!
  if (blocks) {

    i++;

    Serial.print(pixy.blocks[j].x);
    Serial.print(" \n");

    if (i%50==0) {

      if (pixy.blocks[j].x < 140) {

        Serial.print("Aller à gauche\n");
        gauche();

      } else if (pixy.blocks[j].x > 160) {

        Serial.print("Aller à droite\n");
        droite();

      }
    }
    delay(100);
  }

}
