//**************************************************************
//*** Title: Design Project #3 -> Connect 4
//*** Course: Computational Problem Solving I
//*** Developer: Ethan Miller
//*** Date: 10/29/22
//*** Description: Connect 4 Game in the terminal
//***
//**************************************************************




#include <iostream>
#include <time.h>
#include <stdio.h>
#include <iomanip>      
#include <cstdlib>
#include <unistd.h>

using namespace std;


//Displays board 
void displayBoard(char checkers[6][7]){
cout << "  1  " << " 2  " << " 3  " << " 4  " << " 5  " << " 6  " << " 7  " << endl;
cout   << "|" << setw(2) << checkers[0][0] << setw(2) << "|" << setw(2) << checkers[0][1] << setw(2) << "|" << setw(2) << checkers[0][2]<< setw(2) << "|" << setw(2) << checkers[0][3] << setw(2) << "|" << setw(2) << checkers[0][4] << setw(2) << "|" << setw(2) << checkers[0][5] << setw(2) << "|" << setw(2) << checkers[0][6] << setw(2) << "|"  <<endl;
cout   << "+---+" << "---+" << "---+" << "---+" << "---+" << "---+" << "---+" << endl;
cout   << "|" << setw(2) << checkers[1][0] << setw(2) << "|" << setw(2) << checkers[1][1] << setw(2) << "|" << setw(2) << checkers[1][2]<< setw(2) << "|" << setw(2) << checkers[1][3] << setw(2) << "|" << setw(2) << checkers[1][4] << setw(2) << "|" << setw(2) << checkers[1][5] << setw(2) << "|" << setw(2) << checkers[1][6] << setw(2) << "|" << endl; 
cout   << "+---+" << "---+" << "---+" << "---+" << "---+" << "---+" << "---+" << endl;
cout   << "|" << setw(2) << checkers[2][0] << setw(2) << "|" << setw(2) << checkers[2][1] << setw(2) << "|" << setw(2) << checkers[2][2]<< setw(2) << "|" << setw(2) << checkers[2][3] << setw(2) << "|" << setw(2) << checkers[2][4] << setw(2) << "|" << setw(2) << checkers[2][5] << setw(2) << "|" << setw(2) << checkers[2][6] << setw(2) << "|" << endl;
cout   << "+---+" << "---+" << "---+" << "---+" << "---+" << "---+" << "---+" << endl;
cout   << "|" << setw(2) << checkers[3][0] << setw(2) << "|" << setw(2) << checkers[3][1] << setw(2) << "|" << setw(2) << checkers[3][2]<< setw(2) << "|" << setw(2) << checkers[3][3] << setw(2) << "|" << setw(2) << checkers[3][4] << setw(2) << "|" << setw(2) << checkers[3][5] << setw(2) << "|" << setw(2) << checkers[3][6] << setw(2) << "|" << endl;
cout   << "+---+" << "---+" << "---+" << "---+" << "---+" << "---+" << "---+" << endl;
cout   << "|" << setw(2) << checkers[4][0] << setw(2) << "|" << setw(2) << checkers[4][1] << setw(2) << "|" << setw(2) << checkers[4][2]<< setw(2) << "|" << setw(2) << checkers[4][3] << setw(2) << "|" << setw(2) << checkers[4][4] << setw(2) << "|" << setw(2) << checkers[4][5] << setw(2) << "|" << setw(2) << checkers[4][6] << setw(2) << "|" << endl;
cout   << "+---+" << "---+" << "---+" << "---+" << "---+" << "---+" << "---+" << endl;
cout   << "|" << setw(2) << checkers[5][0] << setw(2) << "|" << setw(2) << checkers[5][1] << setw(2) << "|" << setw(2) << checkers[5][2]<< setw(2) << "|" << setw(2) << checkers[5][3] << setw(2) << "|" << setw(2) << checkers[5][4] << setw(2) << "|" << setw(2) << checkers[5][5] << setw(2) << "|" << setw(2) << checkers[5][6] << setw(2) << "|"  << endl;
cout   << "+---+" << "---+" << "---+" << "---+" << "---+" << "---+" << "---+" << endl;
}
//Prompt User if he/she would like to play again
void playAgain(int& repeat, int playerOneWins, int playerTwoWins, int numTies){
//Ask User to play again
char again;
cout << "Would you like to play again [Y/N]:  ";
bruh:
cin >> again;
switch(again){

case 'Y':
break;
case 'y':
break;
case 'N':
repeat = 0;
//If User doesn't want to play again wins for each player are displayed
printf("Player One Wins: %d\n", playerOneWins);
printf("Player Two Wins: %d\n ", playerTwoWins);
printf("Number Ties: %d\n", numTies);
break;
case 'n':
repeat = 0;
printf("\nPlayer One Wins: %d\n", playerOneWins);
printf("Player Two Wins: %d\n", playerTwoWins);
printf("Number Ties: %d\n", numTies);

break;
default:
//If an invalid input is enter the user is prompted back to the beginning of the switch statement
cout << "Enter a valid output";
goto bruh;
}
}
//Creates Logic for each turn
void player_turn(int& turn, char checkers[6][7], int& numMoves){
int move;
char dispChar;

int i;
movez:
//Displays the proper output based on which players turn it is
if(turn == 1){
    dispChar = 'X';
}
else{
    dispChar = 'O';
}

printf("\nPlayer number %d's Turn (%c): Enter Your move:", turn, dispChar);

invalid:
cin >> move;
/*If a non integer is prompted the code enters an infinite loop
In order to avoid this if the code fails the input is cleared and the user
is forced to go back to entering an input until it is an integer */
if(cin.fail()){
    cin.clear();
    cin.ignore();
    cout << "\nEnter a digit numbnuts";
    goto invalid;
}
//Checks to see if user entered a valid integer
if(move >= 8 || move < 1){
    cout << "\nIllegal Position Please reenter:  ";
    goto movez;
}


//Lines up user input which starts at 1 with the array that starts at 0
move = move - 1;
/*Based on user turn, the algorithm checks to see if the user entered a valid output and enters
the output in the array if the output is valid */
if(turn == 1){
    for(i = 5; i >-1; i--){
         if(isalpha(checkers[0][move])){
            turn = 2;
            cout <<"\n\nInvalid Move, You lost your turn";
            goto movez;
        }
       
        if(isalpha(checkers[i][move])){
            continue;
        }
        else{

            checkers[i][move] = 'X';
            numMoves += 1;
            turn = 2;
            break;
        }
    }
}
else if(turn == 2){
    for(i = 5; i > -1; i--){
         if(isalpha(checkers[0][move])){
            turn = 1;
            cout <<"\n\nInvalid Move, You lost your turn";
            goto movez;
        }
        if(isalpha(checkers[i][move])){
            continue;

        }
        else{

            checkers[i][move] = 'O';
            numMoves += 1;
            turn = 1;
            break;
        
        }
    }

}


}
//checks if there is a tie
int tieCheck(char checkers[6][7]){
int i;
int j;
//If all of the array cells have an input of X or O then all spots are filled and it's a tie
for(i = 0; i < 6; i++){
    for(j = 0; j < 7; j++){
        if(checkers[i][j] != 'X' && checkers[i][j] != 'O'){
            return 0;

            
        }
    }
}


return 1;
}
//Checks if a player won
void wincheck(char checkers[6][7], int& wincon, int& playerOneWins, int& playerTwoWins){
wincon = 0;
//int row = 0;
int i;
int j;



//horizontal win
//if 4 elements spaced by 1 cell to the right are equal then the user wins
for(i = 0; i < 6; i++){
    for(j = 0; j < 4; j++){
        if(checkers[i][j] == 'X' && checkers[i][j+1] == 'X' && checkers[i][j+2] == 'X' && checkers[i][j+3] == 'X' ){
            wincon = 1;
            playerOneWins +=1;
            system("CLS");
            displayBoard(checkers);
            cout << "\n\nPlayer #1 Wins\n\n";
            break;
        }
        else if( checkers[i][j] == 'O' && checkers[i][j+1] == 'O' && checkers[i][j+2] == 'O' && checkers[i][j+3]  == 'O' ){
            wincon = 1;
            playerTwoWins += 1;
            system("CLS");
            displayBoard(checkers);
            cout << "\n\nPlayer #2 Wins\n\n";
            break;
        }
    }
    }
    

//vertical win
//if 4 elements spaced by 1 cell up are euqual the user wins as well
for(i = 0; i < 4; i++){
    for(j = 0; j < 7; j++){
        if(checkers[i][j] == 'X' && checkers[i+1][j] == 'X' && checkers[i+2][j] == 'X' && checkers[i+3][j]  == 'X'){
            wincon = 1;
            playerOneWins +=1;
            system("CLS");
            displayBoard(checkers);
            cout << "\n\nPlayer #1 Wins\n\n";
            break;
        }
        else if( checkers[i][j] == 'O' && checkers[i+1][j] == 'O' && checkers[i+2][j] == 'O' && checkers[i+3][j]  == 'O' ){
            wincon = 1;
            playerTwoWins += 1;
            system("CLS");
            displayBoard(checkers);
            cout << "\n\nPlayer #2 Wins\n\n";
            break;
        }
    }
}
//right diagonal
//logic for if 4 diagonal elements are equal from the top down
for(i = 5; i > 2; i--){
    for(j = 0; j < 4; j++){
        if(checkers[i][j] == 'X' && checkers[i-1][j+1] == 'X' && checkers[i-2][j+2] == 'X' && checkers[i-3][j+3] == 'X'){
            wincon = 1;
            playerOneWins += 1;
            system("CLS");
            displayBoard(checkers);
            cout << "\n\nPlayer #1 Wins\n\n";
            break;
        }
         else if( checkers[i][j] == 'O' && checkers[i-1][j+1] == 'O' && checkers[i-2][j+2] == 'O' && checkers[i-3][j+3]  == 'O' ){
            wincon = 1;
            playerTwoWins += 1;
            system("CLS");
            displayBoard(checkers);
            cout << "\n\nPlayer #2 Wins\n\n";
            break;
        }
    }
}

//left diagonal
//logic if 4 diagonal elements are equal from the bottom up
for(i = 0; i < 3; i++){
    for(j = 0; j < 4; j++){
          if(checkers[i][j] == 'X' && checkers[i+1][j+1] == 'X' && checkers[i+2][j+2] == 'X' && checkers[i+3][j+3] == 'X'){
            wincon = 1;
            playerOneWins += 1;
            system("CLS");
            displayBoard(checkers);
            cout << "\n\nPlayer #1 Wins\n\n";
            break;
        }
         else if( checkers[i][j] == 'O' && checkers[i+1][j+1] == 'O' && checkers[i+2][j+2] == 'O' && checkers[i+3][j+3]  == 'O' ){
            wincon = 1;
            playerTwoWins += 1;
            system("CLS");
            displayBoard(checkers);
            cout << "\n\nPlayer #2 Wins\n\n";
            break;
        }
    }
}




}





int main(){
int i;
int j;
int playerOneWins = 0;
int playerTwoWins = 0;
int numTies = 0;
int repeat = 1;
int numMoves = 0;
//welcome screen
cout << endl;
cout << "\tWelcome to Connect4" << endl;
cout << "  The goal of Connect4 is to be the first\t" << endl;
cout << "player to place 4 checkers in a row, either" << endl;
cout << "  horizontally, vertically or diagonally\t" << endl;
cout << endl << endl << endl;

//main loop that runs the game itself
do{
//makes sure that the array is empty at the start of each game
char checkers[6][7] = {{""}};
//by making each value ' ', when a user enters a valid character, the spacing of the output doesn't change.
for(i = 0; i < 6; i++){
    for(j = 0; j < 7; j++){
        checkers[i][j] = ' ';
    }
}



char dispChar;
int turn;
int turnCount = 0;
int win = 0;
int tie;
//By seeding to time which changes every second, it creates the illusion of a truely random seed.
srand(time(0));
//turn depends on the output of a modulus
int player = rand()%2;
//displays which player goes first
switch (player)
{
case 0:
printf("Player 1 Goes First\n");
turn = 1;

break;
case 1:
printf("Player 2 Goes First\n");
turn = 2;
break;
}
cout << endl;

//loop for game itself
do{
//all the main functons are implemented here to make the game operate correctly
displayBoard(checkers);
player_turn(turn, checkers, numMoves);
wincheck(checkers, win, playerOneWins, playerTwoWins);

//checks if there is a tie after it checks if the player wins, this allows for a win on the last possible move
if(tieCheck(checkers) == 1){
    numTies += 1;
    win = 1;
    cout << "\n\nGame Ended in a Tie\n";
}
//clears screen after each output in order to display board after each new move
if(win == 0){
    system("CLS");
}


}while(win == 0);
//logic asking if the user wants to play again
playAgain(repeat, playerOneWins, playerTwoWins, numTies);

}while(repeat == 1);

 return 0;


}