/*
 1/18/23 
 This program is a memory game. A grid of face down cards is created. 
 Every element of the grid has a matching pair. 
 The user inputs the x and y coordinates 
 and the cards will flip, displaying if the user found a match or not.
 The user's goal is to find the location of all pairs in as 
 few attempts as possible.
*/ 

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <time.h>
const int LENGTH = 4;

using namespace std;


//func prototypes

// This function:
// 1. Recieves the numerical values
// 2. It holds the numerical values. 
//Returns nothing after the function executes. 
// 3. The purpose is to hold the actual numerical values for the game.
void InitializeCards(int cards[][LENGTH]); 

// This function:
// 1. Recieves the boleans and matches.
// 2. It shows if the the pairs are matches or not.
//Returns nothing after the function executes. 
// 3. The purpose is to hold the booleans and represent 
//if the function has been matched or not. 
//It generates a display on the screen. 
//If faceup=false, an * is output, otherwise, the card in that slot is output.
void ShowCards(int cards[][LENGTH], bool faceup[][LENGTH]); 

// ====================== 
//     main function 
// ====================== 
int main() { 
string name;
int userAttempts = 0;

 
// 1) Welcome the user and ask him to enter his full name. 
cout << "Hello! Please enter your full name: " << endl;
   getline(cin, name);

cout << name << ", Welcome to the memory game!\n" 
     << "The goal of the game is to find all of the matching pairs!" 
     <<  endl;


// 2) Create a two 2D array that will hold the number for each card. 
//Pass it to  
//    InitializeCards function.  
// add your code here 


int cards[LENGTH][LENGTH];
InitializeCards(cards);


// 3) Create the 2D array of Booleans that represents
// whether or not the card is matched.  
//   This should be initialized to all FALSE at first.  
// add your code here 
bool faceup[LENGTH][LENGTH];

for (int i = 0; i < LENGTH; i++)
for (int j = 0; j < LENGTH; j++)
faceup[i][j] = false;

int numMatch = 0;
bool gameOver = false;
int posX1, posX2, posY1, posY2;
char quit;



// 4) while the game is not over : 
// Display the current state of the game board. 
//Remember that non-matched pairs should be "facedown" 
// and that matched pairs should be "faceup" 
// add your code here 
while(!gameOver) {
ShowCards(cards, faceup);


// Prompt the user to enter the coordinates of two cards 
// Note: user can choose to quit 
// add your code here 
cout << "Enter both the x and y position for the first card: ";
cin >> posX1 >> posY1;

cout << "Enter both the x and y position for the second card: ";
cin >> posX2 >> posY2;




 // If the values of the two coordinates match :
userAttempts++;
// say that a match has been found and flip the cards over forever
// add your code here

if(cards[posX1][posY1] == cards[posX2][posY2])
{
cout << "You found a match!" << endl;
faceup[posX1][posY1] = true;
faceup[posX2][posY2] = true;
numMatch++;
ShowCards(cards,faceup);
if(numMatch == 2*LENGTH)
gameOver = true;
}else
{
// else :
// temporarily flip over the cards to show the user the values,
// then flip them over again.
cout << "You didn't find a match! Try again." << endl;
// add your code here
faceup[posX1][posY1] = true;
faceup[posX2][posY2] = true;
ShowCards(cards,faceup);
faceup[posX1][posY1] = false;
faceup[posX2][posY2] = false;
cout << "I will flip the cards for you again." << endl;

}

cout<<"Enter 'q' to quit or press any key to continue the game.";
cin >> quit;

if(quit == 'q')
gameOver = true;
}


// 5) Save the userDon message in the file. 
// add your code here 
ofstream fout("userInfo.txt"); 

if (numMatch != 2 * LENGTH) {
   fout << "Don't give up!" << endl;;
}  
   else {
      fout<< name <<" took "<< userAttempts <<" to win the game" << endl;
   }

fout.close();


return 0;
}
 //end of main function


// InitializeCards 
// Places pairs of numbers in the 2D array and then 
// randomly shuffles them. 
// ====================== 
//Notice that when you pass a 2D-array to a function, you MUST 
//specify the number of columns 
void InitializeCards(int cards[][LENGTH]) { 
//seed rand() - remember to always do this before using 
rand();
// also make sure to include the <time.h> library. 
srand(time(NULL)); 

// declarations
int posX1, posY1, posX2, posY2; 
int i; 
int temp; 

// Place pairs in known locations -   this is how our array 
//looks like after 
cards[0][0] = 1; cards[0][1] = 1;//   1  1  2  2 
cards[0][2] = 2; cards[0][3] = 2; 
cards[1][0] = 3; cards[1][1] = 3;//   3  3  4  4 
cards[1][2] = 4; cards[1][3] = 4; 
cards[2][0] = 5; cards[2][1] = 5;//   5  5  6   6 
cards[2][2] = 6; cards[2][3] = 6; 
cards[3][0] = 7; cards[3][1] = 7;//   7  7  8   8 
cards[3][2] = 8; cards[3][3] = 8; 

// Now that 2D has been initialized with 8 pairs, we want to 
//shuffle the board so 
// that the pairs aren't right next to each other 
for (int i = 0; i < 30; i++) { 
   //Get set of random coordinates and swap 
   //First random coordinate on our 2d "grid" 
   posY1 = rand() % LENGTH; 
   posX1 = rand() % LENGTH; 

   //Second random coordinate of our 2d "grid" 
   posY2 = rand() % LENGTH; 
   posX2 = rand() % LENGTH; 

   //Now we swap value at (x1, y1) with value at(x2, y2) 
   temp = cards[posX1][posY1]; 
   cards[posX1][posY1] = cards[posX2][posY2]; 
   cards[posX2][posY2] = temp; 

//Note: just like with 1D arrays, modifying an n-
//dimensional array inside 
// a function will change the array itself 
   } 
}

 

// ====================== 
// ShowCards 
// Generates a display on the screen.  If faceup=false, 
// an * is output, otherwise the card in that slot is output. 
// ====================== 
void ShowCards (int cards[][LENGTH], bool faceup[][LENGTH]) { 
// add your code here 
cout << endl << left << setw(8) << "";

for (int i = 0; i < LENGTH; i++) {
cout << left << setw(8) << i;
}

cout << endl << left << string(50,'_') << endl;

for (int i = 0; i < LENGTH; i++) {
cout << endl << left << setw(5) << i << left << setw(4) << "|";
   for (int j = 0; j < LENGTH; j++) {
      if (faceup[i][j])
         cout << left << setw(7) << cards[i][j];
            else
               cout << left << setw(7) << "*";
}

cout << left << setw(7) << "|";
}

cout << endl << left << string(50,'_') << endl;
}




//RUN 1: One input with invalid value

   // Hello! Please enter your full name: 
   // Juhanah Mian
   // Juhanah Mian, Welcome to the memory game!
   // The goal of the game is to find all of the matching pairs!

   //         0       1       2       3
   // __________________________________________________

   // 0    |   *      *      *      *      |
   // 1    |   *      *      *      *      |
   // 2    |   *      *      *      *      |
   // 3    |   *      *      *      *      |
   // __________________________________________________
   // Enter both the x and y position for the first card: w w
   // Invalid input. Try again.


//RUN 2: Three inputs with valid values
   // Hello! Please enter your full name: 
   // Juhanah Mian
   // Juhanah Mian, Welcome to the memory game!
   // The goal of the game is to find all of the matching pairs!

   //         0       1       2       3
   // __________________________________________________

   // 0    |   *      *      *      *      |
   // 1    |   *      *      *      *      |
   // 2    |   *      *      *      *      |
   // 3    |   *      *      *      *      |
   // __________________________________________________
   // Enter both the x and y position for the first card: 0 1
   // Enter both the x and y position for the second card: 0 2
   // You didn't find a match! Try again.

   //         0       1       2       3
   // __________________________________________________

   // 0    |   *      4      6      *      |
   // 1    |   *      *      *      *      |
   // 2    |   *      *      *      *      |
   // 3    |   *      *      *      *      |
   // __________________________________________________
   // I will flip the cards for you again.
   // Enter 'q' to quit or press any key to continue the game.l

   //         0       1       2       3
   // __________________________________________________

   // 0    |   *      *      *      *      |
   // 1    |   *      *      *      *      |
   // 2    |   *      *      *      *      |
   // 3    |   *      *      *      *      |
   // __________________________________________________
   // Enter both the x and y position for the first card: 0 3 
   // Enter both the x and y position for the second card: 1 2
   // You didn't find a match! Try again.

   //         0       1       2       3
   // __________________________________________________

   // 0    |   *      *      *      3      |
   // 1    |   *      *      7      *      |
   // 2    |   *      *      *      *      |
   // 3    |   *      *      *      *      |
   // __________________________________________________
   // I will flip the cards for you again.
   // Enter 'q' to quit or press any key to continue the game.f

   //         0       1       2       3
   // __________________________________________________

   // 0    |   *      *      *      *      |
   // 1    |   *      *      *      *      |
   // 2    |   *      *      *      *      |
   // 3    |   *      *      *      *      |
   // __________________________________________________
   // Enter both the x and y position for the first card: 0 4
   // Enter both the x and y position for the second card: 0 1
   // You didn't find a match! Try again.

   //         0       1       2       3
   // __________________________________________________

   // 0    |   *      4      *      *      |
   // 1    |   2      *      *      *      |
   // 2    |   *      *      *      *      |
   // 3    |   *      *      *      *      |
   // __________________________________________________
   // I will flip the cards for you again.
   // Enter 'q' to quit or press any key to continue the game.


//RUN 3: One input with quit choice
   // Hello! Please enter your full name: 
   // Juhanah Mian
   // Juhanah Mian, Welcome to the memory game!
   // The goal of the game is to find all of the matching pairs!

   //         0       1       2       3
   // __________________________________________________

   // 0    |   *      *      *      *      |
   // 1    |   *      *      *      *      |
   // 2    |   *      *      *      *      |
   // 3    |   *      *      *      *      |
   // __________________________________________________
   // Enter both the x and y position for the first card: 0 1
   // Enter both the x and y position for the second card: 0 2
   // You didn't find a match! Try again.

   //         0       1       2       3
   // __________________________________________________

   // 0    |   *      3      7      *      |
   // 1    |   *      *      *      *      |
   // 2    |   *      *      *      *      |
   // 3    |   *      *      *      *      |
   // __________________________________________________
   // I will flip the cards for you again.
   // Enter 'q' to quit or press any key to continue the game.q
   // PS C:\Users\2djam\2022 c++> 