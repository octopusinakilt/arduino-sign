#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS   96
#define LEDSPERROW 24
#define BRIGHTNESS 255
#define LOOPCOUNT  10
CRGB leds[NUM_LEDS];

// Holds the mapping of the address to the actual location;
int ledMap[96] = {0,  1,  2,  3,    16, 17, 18, 19,   32, 33, 34, 35,   48, 49, 50, 51,   64, 65, 66, 67,  80, 81, 82, 83,
                  7,  6,  5,  4,    23, 22, 21, 20,   39, 38, 37, 36,   55, 54, 53, 52,   71, 70, 69, 68,  87, 86, 85, 84,
                  8,  9,  10, 11,   24, 25, 26, 27,   40, 41, 42, 43,   56, 57, 58, 59,   72, 73, 74, 75,  88, 89, 90, 91,
                  15, 14, 13, 12,   31, 30, 29, 28,   47, 46, 45, 44,   63, 62, 61, 60,   79, 78, 77, 76,  95, 94, 93, 92}; 
//int ledState[96][3]; // the current actual LED values

int ringMap[16] = {0, 1, 2, 3, 4, 11, 12, 13, 14, 15, 8, 7, 6, 5, 10, 9};
int bigRingMap[48] = {0,  1,  2,  3,    16, 17, 18, 19,   32, 33, 34, 35,
                      36, 43, 
                      44, 45, 46, 47, 28, 29, 30, 31, 12, 13, 14, 15, 8,  
                      7,  6,  5,  23, 22, 21, 20, 39, 38, 37, 
                      42, 41, 40, 27, 26, 25, 24, 11, 10, 9};
            //{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
int direction = 1;
int var1 = 0;
int foo;
void setup() 
{
  FastLED.addLeds<WS2812, LED_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);

/*  for (int i=0; i < NUM_LEDS; i++)
  {
    ledState[i][0] = 0;
    ledState[i][1] = 0;
    ledState[i][2] = 0;
  }*/
  

  for (int i=0; i < NUM_LEDS; i++)
  {
    if ((i%LEDSPERROW)==0) 
    {
      Serial.println();
    }
    Serial.print(ledMap[i]);
    Serial.print("\t");
  }
  Serial.println();
  Serial.println("LED State:");
  for (int i=0; i < NUM_LEDS; i++)
  {
    if ((i%LEDSPERROW)==0) 
    {
      Serial.println();
    }
  }
}

void loop() {

/*  var1 = 0;
  for (int looper=0; looper < LOOPCOUNT; looper ++)
  {basicloop2();}
  */

  var1 = 0;
  {shimmer();}

  var1 = 0;
  {twinkle();}

  var1 = 0;
  for (int looper=0; looper < LOOPCOUNT; looper ++)
  {bigrings();}
  
  var1 = 0;
  for (int looper=0; looper < LOOPCOUNT; looper ++)
  {rings();}
  
  var1 = 0;
  for (int looper=0; looper < LOOPCOUNT; looper ++)
  {oppositeCylons2();}
  
  var1 = 0;
  for (int looper=0; looper < LOOPCOUNT; looper ++)
  {worm();}

  var1 = 0;
  for (int looper=0; looper < LOOPCOUNT; looper ++)
  {oppositeCylons();}

  //var1 = 0;
  for (int looper=0; looper < LOOPCOUNT; looper ++)
  {bouncebar();}

  var1 = 0;
  for (int looper=0; looper < LOOPCOUNT; looper ++)
  {basicloop();}
}

void shimmer()
{
  int stars[10][4]; //= //[led ID],[color],[brightness][direction/rate]
  //[led ID],[color],[brightness][direction/rate]
  for (int i=0; i<10; i++)
  {
    stars[i][0] = random(96);
    stars[i][1] = random(255);
    stars[i][2] = 0;
    stars[i][3] = random(10)+1;
  }
  for (int allLeds=0; allLeds <= 96; allLeds ++ )
  {
    leds[allLeds] = CRGB ( 0, 0, 0); 
  }
  for (int cycles=0; cycles<= 2000; cycles++)
  {
    for (int allstars=0; allstars < 10; allstars++ )
    {
      leds[stars[allstars][0]].setHSV(stars[allstars][1], 255, stars[allstars][2]);
      stars[allstars][2] = stars[allstars][2] + stars[allstars][3];
      if ((stars[allstars][2] <= 0) || (stars[allstars][2] >= 255))
      {
        stars[allstars][3] = stars[allstars][3] * -1;
        if (stars[allstars][2] <= 0)
        { //Move the star
          leds[stars[allstars][0]] =  CRGB ( 0, 0, 0); 
          stars[allstars][0] = random(96); 
        }
        stars[allstars][2] = stars[allstars][2] + (2*stars[allstars][3]);
        
      }
    }
    FastLED.show();
    delay(5);
  }
  for (int allLeds=0; allLeds <= 96; allLeds ++ )
  {
    leds[allLeds] = CRGB ( 0, 0, 0); 
  }
  //clearsign();
}


void twinkle()
{
  int stars[10][4]; //= //[led ID],[color],[brightness][direction/rate]
  //[led ID],[color],[brightness][direction/rate]
  for (int i=0; i<10; i++)
  {
    stars[i][0] = random(96);
    stars[i][1] = random(255);
    stars[i][2] = 0;
    stars[i][3] = random(10)+1;
  }
  for (int allLeds=0; allLeds <= 96; allLeds ++ )
  {
    leds[allLeds] = CRGB ( 0, 0, 0); 
  }
  for (int cycles=0; cycles<= 2000; cycles++)
  {
    for (int allstars=0; allstars < 10; allstars++ )
    {
      leds[stars[allstars][0]].setHSV(stars[allstars][1], 255, stars[allstars][2]);
      stars[allstars][2] = stars[allstars][2] + stars[allstars][3];
      stars[allstars][1] = random(255);
      if ((stars[allstars][2] <= 0) || (stars[allstars][2] >= 255))
      {
        stars[allstars][3] = stars[allstars][3] * -1;
        if (stars[allstars][2] <= 0)
        { //Move the star
          leds[stars[allstars][0]] =  CRGB ( 0, 0, 0); 
          stars[allstars][0] = random(96); 
        }
        stars[allstars][2] = stars[allstars][2] + (2*stars[allstars][3]);
        
      }
    }
    FastLED.show();
    delay(5);
  }
  for (int allLeds=0; allLeds <= 96; allLeds ++ )
  {
    leds[allLeds] = CRGB ( 0, 0, 0); 
  }
  //clearsign();
}

void bigrings()
{
  for (int counter=0; counter <= 2; counter ++)
  {
    for (int j=0; j<28; j++)
    {
      for (int k=0; k<2; k++)
      {
        for (int l=0; l<28; l++)
        {
          if (j==l) 
          { leds[bigRingMap[l]+(48*k)].setHSV((foo+(k*128))%255, 255, BRIGHTNESS); } else
          { leds[bigRingMap[l]+(48*k)] = CRGB ( 0, 0, 0);  }
        }
      foo = (foo + 1) % 255;
      }
    
      //Serial.println();
      
      FastLED.show();
      delay(20);
    }
  }
}

void rings()
{
  for (int counter=0; counter <= 10; counter ++)
  {
    for (int j=0; j<12; j++)
    {
      for (int k=0; k<6; k++)
      {
        for (int l=0; l<12; l++)
        {
          if (j==l) 
          { leds[ringMap[l]+(16*k)].setHSV((foo+(k*10))%255, 255, BRIGHTNESS); } else
          { leds[ringMap[l]+(16*k)] = CRGB ( 0, 0, 0);  }
        }
      foo = (foo + 1) % 255;
      }
    
      //Serial.println();
      
      FastLED.show();
      delay(30);
      /*var1 = var1 + direction;
      if ((var1 < 1) || var1 >= LEDSPERROW-1)
      { direction = direction * -1; }*/
    }
  }
}



void worm()
{
  for (int counter=0; counter <= LEDSPERROW*4; counter ++)
  {
    for (int i = 0; i < NUM_LEDS; i++) 
    {
      if (i==var1)
      {
        leds[i].setHSV(foo, 255, BRIGHTNESS);
      } else {
        leds[i] = CRGB ( 0, 0, 0);  
      }
      //Serial.println();
    }
    foo = (foo + 1) % 255;
    FastLED.show();
    delay(10);
    var1 = var1 + direction;
    if ((var1 < 1) || var1 > NUM_LEDS)
    { direction = direction * -1; }
  }
}

void oppositeCylons()
{
  for (int counter=0; counter <= LEDSPERROW*4; counter ++)
  {
    for (int i = 0; i < LEDSPERROW; i++) 
    {
      if (i==var1)
      {
        leds[ledMap[i]].setHSV(foo, 255, BRIGHTNESS);
        leds[ledMap[((LEDSPERROW*2) -1) -i]].setHSV((foo+128)%255, 255, BRIGHTNESS );
        leds[ledMap[((LEDSPERROW*3) -1) -i]].setHSV((foo+128)%255, 255, BRIGHTNESS );
        leds[ledMap[i+(LEDSPERROW*3)]].setHSV(foo, 255, BRIGHTNESS );
        //Serial.print("\tON");
      } else {
        leds[ledMap[i]] = CRGB ( 0, 0, 0);  
        leds[ledMap[((LEDSPERROW*2) -1)-i]] = CRGB ( 0, 0, 0);  
        leds[ledMap[((LEDSPERROW*3) -1)-i]] = CRGB ( 0, 0, 0);  
        leds[ledMap[i+((LEDSPERROW*3))]] = CRGB ( 0, 0, 0);  
        //Serial.print("\tOFF");
      }
    }
    //Serial.println();
    foo = (foo + 1) % 255;
    FastLED.show();
    delay(20);
    var1 = var1 + direction;
    if ((var1 < 1) || var1 >= LEDSPERROW-1)
    { direction = direction * -1; }
  }
}

void oppositeCylons2()
{
  for (int counter=0; counter <= LEDSPERROW*4; counter ++)
  {
    for (int i = 0; i < LEDSPERROW; i++) 
    {
      if (i==var1)
      {
        leds[ledMap[i]].setHSV(foo, 255, BRIGHTNESS);
        leds[ledMap[((LEDSPERROW*2) -1) -i]].setHSV((foo+64)%255, 255, BRIGHTNESS );
        leds[ledMap[((LEDSPERROW*3) -1) -i]].setHSV((foo+128)%255, 255, BRIGHTNESS );
        leds[ledMap[i+(LEDSPERROW*3)]].setHSV((foo+192)%255, 255, BRIGHTNESS );
        //Serial.print("\tON");
      } else {
        leds[ledMap[i]] = CRGB ( 0, 0, 0);  
        leds[ledMap[((LEDSPERROW*2) -1)-i]] = CRGB ( 0, 0, 0);  
        leds[ledMap[((LEDSPERROW*3) -1)-i]] = CRGB ( 0, 0, 0);  
        leds[ledMap[i+((LEDSPERROW*3))]] = CRGB ( 0, 0, 0);  
        //Serial.print("\tOFF");
      }
    }
    //Serial.println();
    foo = (foo + 1) % 255;
    FastLED.show();
    delay(20);
    var1 = var1 + direction;
    if ((var1 < 1) || var1 >= LEDSPERROW-1)
    { direction = direction * -1; }
  }
}

void bouncebar()
{
  for (int counter=0; counter <= LEDSPERROW*4; counter ++)
  {
    for (int i = 0; i < LEDSPERROW; i++) 
    {
      if (i==var1)
      {
        leds[ledMap[i]].setHSV(foo, 255, BRIGHTNESS);
        leds[ledMap[i+(LEDSPERROW)]].setHSV(foo, 255, BRIGHTNESS );
        leds[ledMap[i+(LEDSPERROW*2)]].setHSV(foo, 255, BRIGHTNESS );
        leds[ledMap[i+(LEDSPERROW*3)]].setHSV(foo, 255, BRIGHTNESS );
        //Serial.print("\tON");
      } else {
        leds[ledMap[i]] = CRGB ( 0, 0, 0);  
        leds[ledMap[i+(LEDSPERROW)]] = CRGB ( 0, 0, 0);  
        leds[ledMap[i+(LEDSPERROW*2)]] = CRGB ( 0, 0, 0);  
        leds[ledMap[i+(LEDSPERROW*3)]] = CRGB ( 0, 0, 0);  
        //Serial.print("\tOFF");
      }
      //Serial.println();
      
    }
    foo = (foo + 1) % 255;
    FastLED.show();
    delay(10);
    var1 = var1 + direction;
    if ((var1 < 1) || var1 >= LEDSPERROW)
    { direction = direction * -1; }
  }
}

void basicloop()
{
  for (int i = 0; i <= NUM_LEDS; i++) 
  {
    Serial.print(NUM_LEDS, DEC);
    for (int j = 0; j <= NUM_LEDS; j++)
    {
      if (j != i)
      { 
        leds[ledMap[j]].setHSV(foo, 128, 0 );
        Serial.print(j, DEC);
      }
      else
      { 
        leds[ledMap[j]].setHSV(foo, 128, BRIGHTNESS );
        Serial.print(" ");
        Serial.print(ledMap[j], DEC);
        Serial.print(" ");
      }
      
    }
    Serial.println();
    foo = (foo + 1) % 255;
    FastLED.show();
    delay(10);
  }
}

void basicloop2()
{
  for (int i = 0; i <= NUM_LEDS; i++) 
  {
    for (int j = 0; j <= NUM_LEDS; j++)
    {
      if (j != i)
      { 
        if (j < LEDSPERROW)
        { leds[ledMap[j]] = CRGB ( 0, 0, 0); }
        if (j >= LEDSPERROW && j < LEDSPERROW*2)
        { leds[ledMap[(LEDSPERROW*2) - j]] = CRGB ( 0, 0, 0); }
        if (j >= LEDSPERROW*2 && j < LEDSPERROW*3)
        { leds[ledMap[(LEDSPERROW*2) + j]] = CRGB ( 0, 0, 0); }
        if (j >= LEDSPERROW*3 && j < LEDSPERROW*4)
        { leds[ledMap[(LEDSPERROW*4) - j]] = CRGB ( 0, 0, 0); }
      }
      else
      { 
        if (j < LEDSPERROW)
        { leds[ledMap[j]].setHSV(foo, 128, BRIGHTNESS ); }
        if (j >= LEDSPERROW && j < LEDSPERROW*2)
        { leds[ledMap[j]].setHSV(foo, 128, BRIGHTNESS ); }
        if (j >= LEDSPERROW*2 && j < LEDSPERROW*3)
        { leds[ledMap[j]].setHSV(foo, 128, BRIGHTNESS ); }
        if (j >= LEDSPERROW*3 && j < LEDSPERROW*4)
        { leds[ledMap[j]].setHSV(foo, 128, BRIGHTNESS ); }
      }
      //Serial.print(ja, DEC);
    }
    //Serial.println();
    foo = (foo + 1) % 255;
    FastLED.show();
    delay(10);
  }
}
