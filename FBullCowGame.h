#pragma once
//#include <iostream>
#include <string>
#include <map>
#define TMap std::map

// using namespace std;					// don't use in header files!!!!!!

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus					// without class: all enum statuses are global! cannot be reused in other enums.
{
	OK,
	Not_Isogram,
	Invalid_Length,
	Not_Lowercase,
	Invalid_Status
};

class FBullCowGame
{
public:
	FBullCowGame();					// constructor
	int32 GetMaxTries() const;		// this method cannot change any variables of the class!!!
	int32 GetCurrentTry() const;
	void SetHiddenWord();
	FString GetHiddenWord() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon(int32);


	void Reset();							// TODO return value
	EGuessStatus CheckGuessValidity(FString); 	// TODO return value
	
										// provide a method for counting bulls and cows and increasing try number
	// assumes valid guess
	FBullCowCount SubmitValidGuess(FString);  // method takes a string (Guess) as argument and returns the updated struct!

private:							// values at compile time; initialized in constructor
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bIsGameWon;
	bool IsIsogram(FString);
	bool IsLowercase(FString);
	TMap<int32, bool> UsedWords;
};