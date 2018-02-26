/**
 * gms.cpp
 */

#include <iostream>
#include <cstring>
#include <fstream>

#define MAXTWEET_XTERS 240
using namespace std;

// malicious tweet
struct alert
{
    char symbol[4];
    int length;
};

/**
 * calculates the number of characters
 * in all occuring palindrome in a tweet
 */
void palindromeCheck(char tweets[], int subSize, int index, int &count);

/**
 * returns the length of a string
 */
int length(char tweets[]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: ./gms infile.in\n";
        return 1;
    }

    ifstream infile (argv[1], ios::in);
    if (infile == NULL)
    {
        cout << "Could not open " << argv[1] << endl;
        return 2;
    }

    int  size;
    infile >> size;

    alert verdict[size];
    char tweets[size][MAXTWEET_XTERS];

    for (int i = 0; i < size; i++)
    {
        // load tweets
        infile >> tweets[i];
    }

    for (int i = 0; i < size; i++)
    {
        // palindron characters
        int count = 0;

        int subSize = length(tweets[i]);

        for (int j = 0; j < subSize; j++)
        {
            palindromeCheck(tweets[i], subSize, j, count);
        }

        // palindron found
        if (count)
        {
            strncpy(verdict[i].symbol, &tweets[i][subSize - 3], 3);
            verdict[i].symbol[3] = '\0';

            verdict[i].length = count;
        }

        else
        {
            strcpy(verdict[i].symbol, "n/a");
            verdict[i].length = count;
        }
    }

    ofstream outfile ("output.in", ios::app);
    if (outfile == NULL)
    {
        cout << "Could not open outfile" << endl;
        return 3;
    }


    for (int i = 0; i < size; i++)
    {
        outfile << verdict[i].symbol;

        if (verdict[i].length >= 1 && verdict[i].length <= 10)
        {
            outfile << " Possible\n";
        }

        else if (verdict[i].length >= 11 && verdict[i].length <= 40)
        {
            outfile << " Probable\n";
        }

        else if (verdict[i].length >= 41 && verdict[i].length <= 150)
        {
            outfile << " Escalate\n";
        }

        // ignore
        else
        {
            outfile << endl;
        }
    }

    return 0;
}

/**
 * calculates the number of characters
 * in all occuring palindrome in a tweet
 */
void palindromeCheck(char tweets[], int subSize, int index, int &count)
{
    int iter = index + 2;

    bool valid;

    while (iter < subSize - 3)
    {
        int j = 0;

        for (int i = index; i < iter; i++)
        {
            valid = true;

            // string is not a palindron
            if (tweets[i] != tweets[iter - j])
            {
                valid = false;
                break;
            }

            j++;
        }

        // palindron found
        if (valid)
        {
            char temp[iter + 2];
            strncpy(temp, &tweets[index], iter + 1);
            temp[j + 1] = '\0';

            count += length(temp);
        }

        iter++;
    }
}

/**
 * returns the length of a string
 */
int length(char tweets[])
{
    int len = 0;

    while (tweets[len] != '\0')
    {
        char temp = tweets[len];
        len++;
    }

    return len;
}