#include <math.h>
int frequenties = 0;
int aantalFreq = 0;

void setup()
{
  for (int i = 4; i<14; i++)
  {
    pinMode(i, INPUT);
  }
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT); 
}

void loop()
{
  for(int i = 4; i<14; i++){
    if (digitalRead(i) == HIGH){
      frequenties = frequenties + Freqfunc(i);
      aantalFreq = aantalFreq + 1;
    }
  }
  if (digitalRead(1) == HIGH){
      frequenties = frequenties + Freqfunc(1);
      aantalFreq = aantalFreq + 1;
    }
  if (digitalRead(2) == HIGH){
      frequenties = frequenties + Freqfunc(2);
      aantalFreq = aantalFreq + 1;
    }
  tone(3, frequenties/aantalFreq);
  frequenties = 0;
  aantalFreq = 0;
}

int Freqfunc(double x){
  int result;
  result = 464*pow (1.112999, x);
  return result;
}
