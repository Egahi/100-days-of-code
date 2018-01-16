/**
 * vowelCount.cpp
 *
 * this program reports the number of occurrences of 
 * the english vowel letters in a string.
 *
 * @s_egahi
 *
 * this is vowel count!
 */

#include <iostream>

#define DIFF 32

int strlength(char input[46]);

using namespace std;

int main(void)
{
    char input[46];
    
    cout << "INPUT: ";
    cin.getline(input, 46,'\n');
    
    // counter
    int count[6] = {0};
    
    // string length
    int length = strlength(input);
    
    for (int i = 0; i < length; i++)
    {
        // identify upper case characters
        if (isupper(input[i]))
        {
            // convert to lower case
            input[i] += DIFF;
        }
        
        // increament correspondingn counter index value for each
        // vowel letter found
        switch (input[i])
        {
            case 'a':
                count[0]++; break;
            case 'e':
                count[1]++; break;
            case 'i':
                count[2]++; break;
            case 'o':
                count[3]++; break;
            case 'u':
                count[4]++; break;
        }
    }

    cout << "\'a\' occured " << count[0] << " time(s)\n";
    cout << "\'e\' occured " << count[1] << " time(s)\n";
    cout << "\'i\' occured " << count[2] << " time(s)\n";
    cout << "\'o\' occured " << count[3] << " time(s)\n";
    cout << "\'u\' occured " << count[4] << " time(s)\n";
    
    // success
    return 0;
}

/**
 * calculates the length of a string and returns the value
 */
int strlength(char input[46])
{
    int len = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        cout << len << " + 1 for " <<input[i] << endl;
        len++;
    }

    return len;
}
