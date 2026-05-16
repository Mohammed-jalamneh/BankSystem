#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class clsString
{
private:
	string _Value;
	char _Letter;
public:

	//Two constructors , one default constructor and one parameterized constructor

	clsString()
	{
		_Value = "";
	}
	clsString(string Value)
	{
		_Value = Value;
	}
	clsString(string Value, char Letter)
	{
		_Value = Value;
		_Letter = Letter;
	}

	//Property

	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}

	_declspec(property(get = GetValue, put = SetValue)) string Value;

	//Problem Number 23:-

	static void PrintFirstLetter(string UserStatment) {


		for (int i = 0; i < UserStatment.length(); i++)
		{
			if (i == 0)
				cout << UserStatment[0] << " ";

			if (UserStatment[i] == ' ') {
				cout << UserStatment[i + 1] << " ";
			}
		}

	}
	void PrintFirstLetter()
	{
		PrintFirstLetter(_Value);
	}

	//Problem Number 24:-

	static void SwitchFirstLetterToUpper(string UserStatment) {

		bool FirstLetter = true;

		for (int i = 0; i < UserStatment.length(); i++)
		{
			if (UserStatment[i] != ' ' && FirstLetter) {

				UserStatment[i] = toupper(UserStatment[i]);

			}

			FirstLetter = (UserStatment[i] == ' ' ? true : false);
		}

		cout << UserStatment;

	}
	void SwitchFirstLetterToUpper()
	{
		SwitchFirstLetterToUpper(_Value);
	}

	//Problem Number 25:-

	static void SwitchFirstLetterToLower(string UserStatment) {

		bool FirstLetter = true;

		for (int i = 0; i < UserStatment.length(); i++)
		{
			if (UserStatment[i] != ' ' && FirstLetter) {

				UserStatment[i] = tolower(UserStatment[i]);

			}

			FirstLetter = (UserStatment[i] == ' ' ? true : false);
		}

		cout << UserStatment;


	}
	void SwitchFirstLetterToLower()
	{
		SwitchFirstLetterToLower(_Value);
	}

	//Problem Number 26:-

	static string SwitchStatmentToUpper(string UserStatment) {


		for (int i = 0; i < UserStatment.length(); i++)
		{
			UserStatment[i] = toupper(UserStatment[i]);

		}

		return UserStatment;

	}
	static string SwitchStatmentToLower(string UserStatment) {


		for (int i = 0; i < UserStatment.length(); i++)
		{
			UserStatment[i] = tolower(UserStatment[i]);

		}

		return UserStatment;

	}

	void SwitchStatmentToUpper()
	{
		SwitchStatmentToUpper(_Value);
	}
	void SwitchStatmentToLower()
	{
		SwitchStatmentToLower(_Value);
	}

	//Problem Number 27:-

	static char InvertingLetter(char Letter) {


		int IntLetter = (int)Letter;

		if (IntLetter >= 97 && IntLetter <= 122) {
			return toupper(Letter);
		}
		else if (IntLetter >= 65 && IntLetter <= 90) {
			return tolower(Letter);
		}
		else {
			cout << "Please enter just Letters." << endl;
		}

	}
	char InvertingLetter()
	{
		return InvertingLetter(_Letter);
	}

	//Problem Number 28:-

	static string InvertingAllStatment(string statment) {

		for (int i = 0; i < statment.length(); i++)
		{
			statment[i] = InvertingLetter(statment[i]);
		}

		return statment;
	}
	void InvertingAllStatment()
	{
		_Value = InvertingAllStatment(_Value);
	}

	//Problem Number 29:-

	static int GetLength(string statment) {

		int Length = 0;

		for (int i = 0; i < statment.length(); i++)
		{
			Length++;
		}

		return Length;

	}
	static int CapitalLettersCounter(string statment) {

		int CapiatalCounter = 0;

		for (int i = 0; i < statment.length(); i++)
		{
			int IntStat = (int)statment[i];

			if (isupper(IntStat)) {
				CapiatalCounter++;
			}
		}

		return CapiatalCounter;

	}
	static int SmallLettersCounter(string statment) {

		int SmallCounter = 0;

		for (int i = 0; i < statment.length(); i++)
		{
			int IntStat = (int)statment[i];

			if (islower(IntStat)) {
				SmallCounter++;
			}
		}

		return SmallCounter;

	}

	int GetLength()
	{
		return GetLength(_Value);
	}
	int CapitalLettersCounter()
	{
		return CapitalLettersCounter(_Value);
	}
	int SmallLettersCounter()
	{
		return SmallLettersCounter(_Value);
	}

	//Problem Number 30:-

	static int SpecificLetterCounter(string UserStatment, char UserCharacter) {

		int CharacterCounter = 0;

		for (int i = 0; i < UserStatment.length(); i++)
		{
			if (UserStatment[i] == UserCharacter) {
				CharacterCounter++;
			}
		}


		return CharacterCounter;

	}
	int SpecificLetterCounter()
	{
		return SpecificLetterCounter(_Value, _Letter);
	}

	//Problem Number 31:-

	static int CountLetterInTwoCases(string UserStatment, char UserCharacter, int CharacterCounter) {

		int OpisitCaseLetterCounter = 0;

		for (int i = 0; i < UserStatment.length(); i++)
		{

			int CharacterInt = (int)UserCharacter;
			int StatmentInt = (int)UserStatment[i];

			if (isupper(UserCharacter)) {

				if (StatmentInt == CharacterInt + 32)
				{
					OpisitCaseLetterCounter++;
				}
			}
			else if (islower(UserCharacter)) {

				if (StatmentInt == CharacterInt - 32) {
					OpisitCaseLetterCounter++;
				}
			}

		}


		return OpisitCaseLetterCounter + CharacterCounter;

	}
	int CountLetterInTwoCases()
	{
		return CountLetterInTwoCases(_Value, _Letter, SpecificLetterCounter());
	}

	//Problem Number 32:-

	static bool IsVowel(char Usercharacter) {

		Usercharacter = tolower(Usercharacter);

		return (Usercharacter == 'a' || Usercharacter == 'i' || Usercharacter == 'o' || Usercharacter == 'u' || Usercharacter == 'e');

	}
	bool IsVowel()
	{
		return IsVowel(_Letter);
	}

	//Problem Number 33:-

	static int CountVowel(string UserString)
	{

		int Counter = 0;

		for (int i = 0; i < UserString.length(); i++)
		{
			if (IsVowel(UserString[i]))
				Counter++;
		}


		return Counter;

	}
	int CountVowel()
	{
		return CountVowel(_Value);
	}

	//Problem Number 34:-

	static string VowelIntoString(string UserString) {

		string JustVowel;

		for (int i = 0; i < UserString.length(); i++)
		{
			if (IsVowel(UserString[i]))
				JustVowel += UserString[i];

		}


		return JustVowel;
	}
	string VowelIntoString()
	{
		return VowelIntoString(_Value);
	}

	//Problem Number 35:-

	static void PrintEachWordInString(string S1)
	{
		string delim = " ";
		cout << "\nYour string wrords are: \n\n";
		short pos = 0;
		string sWord;

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S1.erase(0, pos + delim.length());

		}
		if (S1 != "")
		{
			cout << S1 << endl;
		}
	}
	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	//Problem Number 36:-

	static int CountWords(string UserString) {


		string delimiter = " ", sWord;
		int Counter = 0;
		short position = 0;

		while ((position = UserString.find(delimiter)) != std::string::npos) {

			sWord = UserString.substr(0, position);

			if (sWord != "")
				Counter++;


			UserString.erase(0, position + delimiter.length());

		}

		if (UserString != "")
		{
			Counter++;

		}

		return Counter;


	}
	short CountWords()
	{
		return CountWords(_Value);
	}

	//Problem Number 37:-

	string VectorToString(vector<string> vString, string Delimiter = " ")
	{
		string FinalString = "";

		for (short i = 0; i < vString.size(); i++)
		{
			FinalString += vString[i]; 

			if (i != vString.size() - 1)
			{
				FinalString += Delimiter;
			}
		}

		return FinalString;
	}

	

	static vector <string> Split(string s , string deli = " ")
	{

		vector <string> vString;

		string Word;
		short pos;

		while ((pos = s.find(deli)) != std::string::npos)
		{

			Word = s.substr(0, pos);

			if (Word != " ")
			{
				vString.push_back(Word);
			}

			s.erase(0, pos + deli.length());

		}

		if (s != " ")
			vString.push_back(s);

		return vString;


	}

	vector <string> Split()
	{
		return Split(_Value);
	}

	//Problem Number 38:-

	static string TrimLeft(string s)
	{
		int pos = 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ')
			{
				pos = i;
				break;
			}
		}

		return s.substr(pos);
	}
	static string TrimRight(string s)
	{
		for (int i = s.length() - 1; i >= 0; i--)
		{
			if (s[i] != ' ')
			{
				return s.substr(0, i + 1);
			}
		}

		return "";
	}
	static string Trim(string s)
	{
		return TrimLeft(TrimRight(s));
	}

	string TrimLeft()
	{
		return TrimLeft(_Value);
	}
	string TrimRight()
	{
		return TrimRight(_Value);
	}
	string Trim()
	{
		return Trim(_Value);
	}

	//Problem Number 39:-

	static string JoinString(vector <string> vS, string Deli)
	{

		string S1 = "";

		for (string loop : vS)
		{
			S1 = S1 + loop + Deli;

		}


		return (S1.substr(0, S1.length() - Deli.length()));

	}
	string JoinString()
	{
		return JoinString(Split(), " ");
	}

	//Problem Number 40:-

	static string JoinString(string arrString[], short Length, string Delim)
	{
		string S1 = "";
		for (short i = 0;i < Length;i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}

	//Problem Number 41:-

	static void ReversedWords(string S1)
	{

		vector <string> vString;

		string deli = " ";
		string Word;
		short pos;

		while ((pos = S1.find(deli)) != std::string::npos)
		{

			Word = S1.substr(0, pos);

			if (Word != " ")
			{
				vString.push_back(Word);
			}

			S1.erase(0, pos + deli.length());

		}

		if (S1 != " ")
			vString.push_back(S1);

		for (int i = vString.size() - 1; i >= 0; i--)
		{
			cout << vString[i] << " ";
		}

	}
	void ReversedWords()
	{
		ReversedWords(_Value);
	}

	//Problem Number 42:-

	static void ReplacWord(string UserString, string WordWantToChange, string NewWord)
	{

		vector <string> vString = Split(UserString);

		for (string S1 : vString)
		{
			if (S1 == WordWantToChange)
			{
				S1 = NewWord;
			}

			cout << S1 << " ";
		}

	}

	//Problem Number 43:-


	static string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	static string ReplaceWordInStringUsingSplit(string S1, string
		StringToReplace, string sRepalceTo, bool MatchCase = true)
	{
		vector<string> vString = Split(S1);
		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}
			}
			else
			{
				if (LowerAllString(s) ==
					LowerAllString(StringToReplace))
				{
					s = sRepalceTo;
				}
			}
		}
		return JoinString(vString, " ");
	}


	//Problem Number 44:-

	static string RemovePancuations(string UserString)
	{

		string S2 = "";

		for (int i = 0; i < UserString.length(); i++)
		{
			if (!ispunct(UserString[i]))
			{
				S2 = S2 + UserString[i];
			}
		}

		return S2;
	}

	string RemovePancuations()
	{
		return RemovePancuations(_Value);
	}


};

