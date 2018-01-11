/**
 * guessMyNumber.cpp
 *
 * this program generates a random number and
 * prompts the user for numbers until the two match,
 * upon every failed attempt, it tells how close 
 * to the answer an attempt was.
 *
 * @s_egahi
 *
 * this is guess my number
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
    // use system time as seed for rand()
    srand(time(NULL));
    
    long long randomNumber, guess;
    int steps = 0;
    
    // generate random number
    randomNumber = rand() % 999999999999;
    
    cout << "\nI picked a number, care to guess what it is?\n" << endl;
    
    do
    {
        cout << "\nGuess a number: ";
        cin >> guess;
        
        // track no of steps to answer
        steps++;
        
        // right answer!
        if (randomNumber == guess)
        {
            cout << "\nYou guessed right!\n"
                 << "it took you " << steps << " steps!\n" << endl;
            break; 
        }

        else if ((randomNumber - guess) > 0 && (randomNumber - guess) < 10)
        {
            cout << "\nWrong number. Try a higher number\n"
                 << "Hint: You  are close to the right answer\n";
        }
            
        else if ((randomNumber - guess) >= 10 && (randomNumber - guess) < 50)
        {
            cout << "\nWrong number. Try a higher number\n"
                 << "Hint: You  are outside -10 neighburhood of the number, but within -50\n";
        }
                
        else if ((randomNumber - guess) >= 50 && (randomNumber - guess) < 100)
        {
            cout << "\nWrong number. Try a higher number\n"
                 << "Hint: You  are outside -50 neighburhood of the number, but within -100\n";
        }
        
        else if ((randomNumber - guess) > 100 && (randomNumber - guess) < 500)
        {
            cout << "\nWrong number. Try a higher number\n"
                 << "Hint: You are ouside -100 range of the number, but withing -500\n";
        }
        
        else if ((randomNumber - guess) > 1000)
        {
            cout << "\nWrong number. Try a higher number\n"
                 << "Hint: You are ouside -1000 range of the number\n";
        }
        
        else if ((randomNumber - guess) < 0 && (randomNumber - guess) > -10)
        {
            cout << "\nWrong number. Try a lower number\n"
                 << "Hint: You  are close to the right answer\n";
        }
            
        else if ((randomNumber - guess) <= -10 && (randomNumber - guess) > -50)
        {
            cout << "\nWrong number. Try a lower number\n"
                 << "Hint: You  are outside +10 neighburhood of the number, but within +50\n";
        }
                
        else if ((randomNumber - guess) <= -50 && (randomNumber - guess) > -100)
        {
            cout << "\nWrong number. Try a lower number\n"
                 << "Hint: You  are outside +50 neighburhood of the number, but within +100\n";
        }
        
        else if ((randomNumber - guess) < -100 && (randomNumber - guess) > -500)
        {
            cout << "\nWrong number. Try a lower number\n"
                 << "Hint: You are ouside +100 neighbourhood of the number, but withing +500\n";
        }
        
        else 
        {
            cout << "\nWrong number. Try a lower number\n"
                 << "Hint: You are ouside +1000 neighbourhood of the number\n";
        }
        
      // run until guess is right
    } while (randomNumber != guess);
    
    // success
    return 0;
}