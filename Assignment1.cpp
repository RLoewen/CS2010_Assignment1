/* 

Assignment: CS2010 Assignment 1
Purpose: This program reads inputs from keyboard or a file. This input is organized into words and the number of occurences of each word is tracked. This program currently supports a maximum number 25 words with a length of 131 characters.
Author: Ruben Loewen
Student ID: 5010926





*/





#include <cstdio>
#include <cctype>
#include <iostream>

//#define DEBUG_BLOCK

using namespace std;

const int NUMWORDS = 25;	// how many words can be kept in the dictionary
const int WORDSIZE = 132;	// size of the words, max is 131 characters because the last is reserved for NULL Bytes


int ptr	= 0;			// keeps track what location in the dictionary the current word is being placed
int i = 0;			// global variable
int lettercount =0;


char dictionary [NUMWORDS][WORDSIZE] = {0};
int freq [NUMWORDS]={0};


bool strcmp(int, int);		// compares 
int strlngth(int);
bool DictionaryIsFull();
void addCHAR(char);
void addWORD();
int isHERE();
void clearPTR();
void PrintDictionary();

int main() {

char ch;
int newLine= 0;


while( cin.good() )
{
 if(!DictionaryIsFull())	// if Dictionary is not full keep getting characters
	{
 ch = tolower(cin.get());
 if ( isalpha(ch) )  /* function test is ch  is A-Z, a-z */
    		{
       //cout.put(ch);
	addCHAR(ch);
       newLine = 1;
    		}
 else
       if (newLine)
          	{
	
              //cout.put('\n');
		addWORD();
	
              newLine = 0;
          	}
	}
}
PrintDictionary();

#ifdef DEBUG_BLOCK
cout<<strcmp(0,1)<<"testing strncmp"<<endl;
#endif

 return 0;
}

/* If the ptr variable is = to the dictionary capacity (NUMWORD) then the ptr has passed the last dictionary position and the dictionary is full and 0 is returned	*/

bool DictionaryIsFull(){	
if (ptr == NUMWORDS )  {
cout << "Sorry the dictionary is full. Program will be terminated." << endl;
return 1;
}
else return 0;


}


/* as long as the length of a word is less than the WORDSIZE-1(need to account for null byte) we can keep adding chars */

void addCHAR(char x){
#ifdef DEBUG_BLOCK
//cout << "adding Char" << endl;
#endif
//int tmp=strlngth(ptr);
//if(tmp < (WORDSIZE-1)) dictionary[ptr][tmp]=x;	
if (lettercount<(WORDSIZE))dictionary[ptr][lettercount++]=x;

}



/*	if isHERE finds the word the frequency ctr is incremented and the characters in ptr are wiped, if it does not then the word is added	*/

void addWORD()
{						
//cout << "adding word"<<endl;	// entered addword() function, used in debug	
		lettercount = 0;
		int tmp= isHERE();
//cout<<tmp<<"writing tmp"<<freq[i]<<endl; 
		if(tmp!=(NUMWORDS+1))		
		{
		freq[tmp]++;
		clearPTR();
		}
			else 		
			{
				if(ptr<NUMWORDS)
				{
				freq[ptr]++;
				ptr++;
				
				}
				 
			}
	
}


/*	searches the dictionary to find the word, if it is found the index is returned, 
	if not then NUMWORDS +1 is returned to indicate that the word is not yet in the library	*/

int isHERE()
{	int i=0;					
	//cout<<"looking in dictionary"<<endl;		// looking in dictionary for word	
	for(i=0;i<ptr;i++)
	{
	//cout <<i<<" printing i in isHere"<<endl;
		if(strcmp(i,ptr)==1)
					{
				
				//cout <<ptr<<" printing ptr in ishere() "<<i<<" i after freq[i] check"<< endl;				
				return i;}
	}return NUMWORDS+1;

}


/*	function takes a int indicating a word in the dictionay and returns the length by comparing each character and if it is 0 the function returns the number of characters counted(i) 	*/

int strlngth(int x)
{		
	//cout<<"checking string length" << endl; 	//in stringlength
        	
	for (i=0;i<WORDSIZE;i++)
	{
		if(dictionary[x][i]== 0) return i;

	}
return 0;
}


/*	takes 2 char arrays and compares each value from 0 to WORDSIZE-1 and if any don't match the function returns a 0		*/

//
bool strcmp(int x,int y)
{	int i=0;
	if(strlngth(x)!= strlngth(y))return 0;

		for	(i = 0; i < WORDSIZE ; i++)
		{
	
			if((dictionary[x][i])!=	(dictionary[y][i]))return 0;	// word X at 'i' is compared to word Y at 'i', if they do not equal return 0
		}

return 1;
}





// clear your array at location ptr to accept a new string of characters

void clearPTR(){	
for (int i=0;i < WORDSIZE;i++)dictionary[ptr][i]=0;

}
/* prints the dictionary by traversing the dictionary word by word and printing  each character, after each word is printed the frequency of it's occurence is printed*/

void PrintDictionary(){

 for(int f=0; f<ptr; f++)
	{
	int len= strlngth(f);
 //                cout << len << endl;
		for(int j=0; j < len; j++)	
		{
			if(dictionary[f][j] != 0)cout << dictionary[f][j];
			else break;
		} 
                for ( int j=0; j< 45-len; j++) cout << ' ' ;
		cout << "Occurs: "<<freq[f]<<" times."<<endl;

		
	}



}


