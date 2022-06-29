#include <Keypad.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

int i=0,life=5;
int number;
int key,temp=1;
const int ROW = 4;
const int COLUMN = 4;
const int BUZZER_PIN = 11;

char keys[ROW][COLUMN] =
{
    {'1','2','3', 'A'},
    {'4','5','6', 'B'},
    {'7','8','9', 'C'},
    {'*','0','#', 'D'}
};

byte pin_rows[ROW] = {9, 8, 7, 6};
byte pin_column[COLUMN] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW, COLUMN);

void setup()
{
    lcd_1.begin(16, 2);
    randomSeed(analogRead(0));
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
    if(temp)
    {
        ranFun();
    }
    mainFun();
}

void ranFun()
{
    temp=0;
    number = random(10);
    lcd_1.print("Hint:0-9 Life:5");
}

void mainFun()
{
    if(life>0)
    {
        key = keypad.getKey();
        if(key)
        {
            tone(BUZZER_PIN, 1000, 500);
            delay(10);
            noTone(BUZZER_PIN);
            lcd_1.setCursor(0,1);

            if(key-48==number)
            {
                lcd_1.print("                ");
                lcd_1.setCursor(0,1);
                if(life>0)
                {
                    lcd_1.print("Win");
                }
                else
                {
                    lcd_1.print("Lose");
                }

            }
            else if(key-48>number)
            {
                lcd_1.print("                ");
                lcd_1.setCursor(0,1);
                lcd_1.print("Less than ");
                lcd_1.print(key-48);
                life--;
                lcd_1.setCursor(0,0);
                lcd_1.print("Hint:0-9 Life:");
                lcd_1.print(life);
            }
            else if(key-48<number)
            {
                lcd_1.print("                ");
                lcd_1.setCursor(0,1);
                lcd_1.print("Greater than ");
                lcd_1.print(key-48);
                life--;
                lcd_1.setCursor(0,0);
                lcd_1.print("Hint:0-9 Life:");
                lcd_1.print(life);
            }
        }
    }
    else
    {
        lcd_1.clear();
        lcd_1.setCursor(0,0);
        lcd_1.print("Game Over");
      	delay(500);
    }
}