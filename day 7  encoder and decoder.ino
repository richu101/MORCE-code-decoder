int ledPin = 8;
//For letters
char *letters[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",   // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S-Z
};
char alphabet[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int morsbut1 = 6;
int morsbut2 = 7;
int morsbut3 = 8;

    String morse = "";
//For Numbers
char *numbers[] = {
    "-----", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----."};
int dotDelay = 200;

void setup()
{
    // put your setup code here, to run once:

    pinMode(morsbut1, INPUT);
    pinMode(morsbut2, INPUT);
    pinMode(morsbut3, INPUT);
    Serial.begin(9600);
}

void loop()
{

    //alphtomors();
    morstoalpha();
    Serial.println(morse);
    alphtomors();

}

    
    void alphtomors()
    {
        char ch;
        if (Serial.available())
        {
            ch = Serial.read(); // read a single letter if (ch >= 'a' && ch <= 'z')
            if (ch >= 'a' && ch <= 'z')
            {
                flashSequence(letters[ch - 'a']);
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                flashSequence(letters[ch - 'A']);
            }
            else if (ch >= '0' && ch <= '9')
            {
                flashSequence(numbers[ch - '0']);
            }
            else if (ch == ' ')
            {
                Serial.print(" ");
            }
        }
    }

    void flashSequence(char *sequence)
    {
        int i = 0;
        while (sequence[i] != NULL)
        {
            flashDotOrDash(sequence[i]);
            i++;
        }
        delay(dotDelay * 3);
    }

    void flashDotOrDash(char dotOrDash)
    {
        if (dotOrDash == '.')
        {
            Serial.print(".");
        }
        else // must be a -
        {
            Serial.print("-");
        }
    }
void morstoalpha()
{   
    //Serial.println("mors to alpha");
    while (digitalRead(morsbut3) == LOW)
    {
          //Serial.println("mors to alpha");
        if (digitalRead(morsbut1))
        {
            morse += ".";
            Serial.println(".");
        }
        else if (digitalRead(morsbut2))
        {
            morse += "-";
            Serial.println("-");
        }
    }
    Serial.println(morse);
    for (int i = 0; i < 26; i++)
    {
        if (morse == letters[i])
        {
            Serial.print(alphabet[i]); /* code */
        }
        else
        {
            Serial.println("invalid");
        }
        
    }
}