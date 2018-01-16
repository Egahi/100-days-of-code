/**
 * vowelCount.cpp
 *
 * this program counts the number of occurrences of 
 * vowel letters in a string.
 *
 * @s_egahi
 *
 * this is vowel count!
 */

#include <iostream>

using namespace std;

int main(void)
{
    char input[46];
    
    cout << "INPUT: ";
    cin.getline(input, '\n');
    
    int count[6] = {0};
    
    for (int i = 0, j = sizeof(input); i < j; i++)
    {
        if (isupper(input[i]))
        {
            tolower(input[i]);
        }
        
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
    
    return 0;
}