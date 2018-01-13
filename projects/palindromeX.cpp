/**
 * palindromeX.cpp
 *
 * this program checks if a word is a palindrome or not
 *
 * @s_egahi
 *
 * this is palindromeX
 */

#include <iostream>

int strlength(char []);

using namespace std;

int main(void)
{
    char word[46];
    int check = 0;
    
    cout << "WORD: ";
    cin.getline(word, '\n');

    // length of word    
    int length = strlength(word);
    
    for (int i = 0; i < length; i++)
    {
        // if a single character doesnot match it's equivalent
        // with same index from the end, the word is not a palindrome
        if (word[i] != word[(length - i) - 1])
        {
            cout << word << " is not a palindrome\n";
            break;
        }
        
        else      
            check++;
    }
    
    // all characters match up
    if (check == length)
    {
        cout << word << " is a palindrome\n";
    }
    
    // success
    return 0;
}

/**
 * computes and returns the length of a string
 */
int strlength(char word[46])
{
    int length = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        length++;
    }
    
    return length;
}