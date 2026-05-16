#pragma once
#include <iostream>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsUtil
{

private:


    static char MixCharacter()
    {
        int Choice = RandomNumber(1, 3);

        if (Choice == 1)
        {
            return (char)RandomNumber(97, 122); 
        }
        else if (Choice == 2)
        {
            return (char)RandomNumber(65, 90); 
        }
        else
        {
            return (char)RandomNumber(48, 57);   
        }
    }

public:

    static string Tabs(unsigned short Number)
    {
        string Tab = "    ";
        string Tabs="";

        for (int i = 0; i < Number; i++)
        {
            Tabs =Tabs+Tab;
        }

        return Tabs;

    }


    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

   static int RandomNumber(int from, int to) {

        int RandomNumber;

        RandomNumber = rand() % (to - from + 1) + from;

        return RandomNumber;

    }

   enum enMixChar { SmallLetter = 1 , CapitalLetter , Digit , MixChar  };

   static char GetRandomCharacter(enMixChar CharType)
   {
       switch (CharType)
       {
       case enMixChar::SmallLetter:
           return (char)RandomNumber(97, 122);

       case enMixChar::CapitalLetter:
           return (char)RandomNumber(65, 90);

       case enMixChar::Digit:
           return (char)RandomNumber(48, 57);

       case enMixChar::MixChar:

           return MixCharacter();

       default:
           return '\0';
       }
   }

   static string GenerateWord(enMixChar CharType  , short Length) {

       string Word = "";

       for (int i = 0; i < Length; i++) {
           Word = Word + GetRandomCharacter(CharType);
       }

       return Word;
   }

   static string GenerateKey(enMixChar CharType  , short WordLength) {

       string Key = "";

       Key = Key + GenerateWord(CharType , WordLength) + "-";
       Key = Key + GenerateWord(CharType, WordLength) + "-";
       Key = Key + GenerateWord(CharType, WordLength) + "-";
       Key = Key + GenerateWord(CharType, WordLength);

       return Key;

   }

   static void GenerateKeys(enMixChar CharType,unsigned short NumberOfKeys ,  unsigned short WordLength)
   {
       for (int i = 0; i < NumberOfKeys; i++)
       {
           GenerateKey(CharType, WordLength);
       }
   }

   //Swap Functions Overloeaded (int-double-string-dates)

   static void Swap(int& a, int& b)
   {
       short Temp;

       Temp = a;
       a = b;
       b = Temp;
       
   }

   static void Swap(double& a, double& b)
   {
       double Temp;

       Temp = a;
       a = b;
       b = Temp;

   }

   static void Swap(string& a, string& b)
   {
       string Temp;

       Temp = a;
       a = b;
       b = Temp;

   }

   static  void Swap(clsDate& A, clsDate& B)
   {
       clsDate::SwapDates(A, B);

   }

   static void ShuffleArray(int Array[100], unsigned short size)
   {
       for (int i = 0; i < size; i++)
       {
           Array[i] = RandomNumber(Array[0], Array[size-1]);
       }

   }

   static void ShuffleArray(string sArray[100], unsigned short size)
   {
       for (int i = 0; i < size; i++)
       {
           int RandomIndex = RandomNumber(0, size - 1);

           swap(sArray[i], sArray[RandomIndex]);
       }
   }


   static void FillArrayWithRandomNumbers(int Arr[100], unsigned short size, int From, int To)
   {
       for (int i = 0; i < size; i++)
       {
           Arr[i] = RandomNumber(From, To);

       }

   }

   static void FillArrayWithRandomWords(string Arr[100], unsigned short size, enMixChar CharType , short Length)
   {
       for (int i = 0; i < size; i++)
       {
           Arr[i] = GenerateWord(CharType, Length);
       }

   }

   static void FillArrayWithRandomKeys(string Arr[100], unsigned short size, enMixChar CharType, short Length)
   {
       for (int i = 0; i < size; i++)
       {
           Arr[i] = GenerateKey(CharType, Length);
       }

   }

   static string  EncryptText(string Text, short EncryptionKey)
   {

       for (int i = 0; i <= Text.length(); i++)
       {

           Text[i] = char((int)Text[i] + EncryptionKey);

       }

       return Text;

   }

   static string  DecryptText(string Text, short EncryptionKey)
   {

       for (int i = 0; i <= Text.length(); i++)
       {

           Text[i] = char((int)Text[i] - EncryptionKey);

       }
       return Text;

   }

   static string NumberToText(int Number)
   {

       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
       "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
         "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

           return  arr[Number] + " ";

       }

       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
           return  arr[Number / 10] + " " + NumberToText(Number % 10);
       }

       if (Number >= 100 && Number <= 199)
       {
           return  "One Hundred " + NumberToText(Number % 100);
       }

       if (Number >= 200 && Number <= 999)
       {
           return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
       }

       if (Number >= 1000 && Number <= 1999)
       {
           return  "One Thousand " + NumberToText(Number % 1000);
       }

       if (Number >= 2000 && Number <= 999999)
       {
           return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
       }

       if (Number >= 1000000 && Number <= 1999999)
       {
           return  "One Million " + NumberToText(Number % 1000000);
       }

       if (Number >= 2000000 && Number <= 999999999)
       {
           return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
       }

       if (Number >= 1000000000 && Number <= 1999999999)
       {
           return  "One Billion " + NumberToText(Number % 1000000000);
       }
       else
       {
           return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
       }

   }

};

