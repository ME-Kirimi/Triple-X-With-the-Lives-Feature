#include <iostream>//This is a preprocessor statement
#include <ctime>
#include <cstdlib>

using namespace std;

int Lives = 5;


void PrintIntroduction(int Difficulty)
{
	//These are expression statements
	cout << "\nHi...My name is Dr Con...Welcome to the level " << Difficulty;
	cout << " hacking world! Tonight, we break into the City Bank! Get your math ready and enter the right code because you have " << Lives << " lives!\n\n";
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);
	//These are declaration statements
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;


	const int CodeProduct = CodeA * CodeB * CodeC;
	const int CodeSum = CodeA + CodeB + CodeC;

	cout << "->The code contains three numbers " << endl;
	cout << "->The numbers add up to: " << CodeSum << endl;
	cout << "->The numbers multiply to give: " << CodeProduct << endl;

	//Stores the player's guesses
	int GuessA, GuessB, GuessC;

	cout << "Fellow conman...Do the honours of guessing the three numbers!\n";
	cin >> GuessA >> GuessB >> GuessC;


	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	//Checks if player's guesses are correct
	if (GuessProduct == CodeProduct && GuessSum == CodeSum)
	{
		cout << "***Yeehah mate! You entered the right combination! Proceed to the next security level***\n";
		return true;
	}
	else
	{
		--Lives;
		cout << "***Uh-oh...You entered the wrong combination! The bomb is ticking and you have " << Lives << " Lives!!!! Try again before the bomb is detonated!***\n";
		return false;
	}

}


int main()
{
	srand(time(NULL));//Creates a new random sequence based on time of the day

	int LevelDifficulty = 1;
	const int MaxDifficulty = 3;

	while (LevelDifficulty <= MaxDifficulty && Lives > 0) //Loops the game until the game is completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		cin.clear();
		cin.ignore();

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}

		if (Lives <= 0) {

			cout << "***You died! Game over sucker!***\n";

		}
		
	}
	//cout << "***We did it comrade! The cash is ours!!!!***\n";
	//This is a return statement
	return 0;
}
