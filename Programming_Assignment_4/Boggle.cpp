/*
* File: Boggle.cpp
* ----------------
* Name: [TODO: enter name here]
* Section: [TODO: enter section leader here]
* This file is the main starter file for Assignment #4, Boggle.
* [TODO: extend the documentation]
*/
 
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>
#include <fstream>
#include <cmath>
#include <sstream> // To convert chars to string
using namespace std;

/* Constants */

const string STANDARD_CUBES[16]  = {
   "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
   "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
   "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
   "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};
 
const string BIG_BOGGLE_CUBES[25]  = {
   "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
   "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
   "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
   "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
   "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};

/* Function prototypes */

void welcome();
void giveInstructions();
void makeTheBoard(vector<vector<char> > &board, int inUse);
vector<string> createWordLexicon();
void wordPermutations(vector<vector<char> > board, vector<string> lexicon, vector<string> &all_computer_words, int & computer_score, vector<string> alreadyTried);
bool checkIfOK(string word, vector<string> &alreadyTried, vector<string> lexicon, vector<vector<char> > board);
bool possibleToMakeWithBoard(string word, vector<vector<char> > board, vector<string> keepTrack, int row, int col);
bool IsMarked(int row, int col, vector<string> keepTrack);
bool matchPrefix(string current_word, vector<string> lexicon);
void RecSubsets(vector<vector<char> > board, vector<string> lexicon, string current_word, vector<string> &all_computer_words, int & computer_score, int row, int col, vector<string> keepTrack, vector<string> alreadyTried);


//Function to convert string to uppercase
string ConvertToUpperCase(string text)
{
   transform(text.begin(), text.end(), text.begin(), ::toupper); //::required as therwise get compiler error - see coursereader for further details
   return text;
}

/* Main program */

int main() {
   while(true){
      srand(static_cast<unsigned int>(time(NULL))); // This seeds the randomiser
      vector<vector<char> > board;
      vector<string> alreadyTried;
      welcome();
      giveInstructions();

      //Ask what board the player wants to choose
      string choice;
      while(true){
         cout << "Choose the size of the board you want. Either 16 or 25." << endl;
         getline(cin, choice);
         if(choice == "25" || choice == "16"){ break;}
         cout << "Invalid choice !" << endl;
      }
      int inUse = stoi(choice);

      vector<string> lexicon = createWordLexicon();
      // for(vector<string>::iterator itr = lexicon.begin(); itr != lexicon.end(); ++itr) cout << *itr << endl;
      cout << "OK, now hit return when you're ready..." << endl << endl;
      while(true){
         string return_key;
         getline(cin, return_key);
         if(return_key != ""){
            cout << "You must have mistyped something. Please only hit return when you're ready..." << endl;
         }
         else{ break;}
      }
      cout << "Let's start then. Here is the board: " << endl << endl;
      makeTheBoard(board, inUse);
      int score = 0; // Initialise the score
      for(int i = 0; i < board.size(); i++){
         cout << "          ";
         for(int j = 0; j < board.at(i).size(); j++){
            cout << board.at(i).at(j) << " ";
         }
         cout << endl;
      }
      cout << "Please enter a word. Note it must be 4 letters minimum. When you are done, press Enter." << endl;
      while(true){
         string word;
         getline(cin, word);
         if(word == ""){ break;}
         else{
            if(checkIfOK(ConvertToUpperCase(word), alreadyTried, lexicon, board)) {
               score += word.length() - 3;
               cout << "Great job! Your current score is: " << score << endl;
            }
            else{
               cout << "Try again!" << endl;
            }
         }
      }
      int computer_score = 0;
      vector<string> all_computer_words;
      wordPermutations(board, lexicon, all_computer_words, computer_score, alreadyTried);
      if (score < computer_score){
         cout << "Sorry you lose. Your score is: " << score << ". And the computer's score is: " << computer_score << endl << endl;
      }
      if (score == computer_score){
         cout << "You both lose !!" << endl;
      }
      if (score > computer_score){
         cout << "Hey you win !! You score is: " << score << ". And the computer's: " << computer_score << endl;
      }

      //At the end of the game, check if player wants to play another time
      cout << "Do you want to play again? Please enter yes or no " << endl;
      string checkIfPlayerAgain;
      while(true){
         string answer;
         getline(cin, answer);
         if(answer == "no" || answer == "yes"){
            checkIfPlayerAgain = answer;
            break;
         }
      }
      if(checkIfPlayerAgain == "no"){
         break;
      }
   }
   return 0;
}

/*
 * Function: welcome
 * Usage: welcome();
 * -----------------
 * Print out a cheery welcome message.
 */

void welcome() {
   cout << endl;
   cout << "Welcome!  You're about to play an intense game ";
   cout << "of mind-numbing Boggle.  The good news is that ";
   cout << "you might improve your vocabulary a bit.  The ";
   cout << "bad news is that you're probably going to lose ";
   cout << "miserably to this little dictionary-toting hunk ";
   cout << "of silicon.  If only YOU had a gig of RAM..." << endl << endl;
}

/*
 * Function: giveInstructions
 * Usage: giveInstructions();
 * --------------------------
 * Print out the instructions for the user.
 */

void giveInstructions() {
   cout << endl;
   cout << "The boggle board is a grid onto which ";
   cout << "I will randomly distribute cubes. These ";
   cout << "6-sided cubes have letters rather than ";
   cout << "numbers on the faces, creating a grid of ";
   cout << "letters on which you try to form words. ";
   cout << "You go first, entering all the words you can ";
   cout << "find that are formed by tracing adjoining ";
   cout << "letters. Two letters adjoin if they are next ";
   cout << "to each other horizontally, vertically, or ";
   cout << "diagonally. A letter can only be used once ";
   cout << "in each word. Words must be at least four ";
   cout << "letters long and can be counted only once. ";
   cout << "You score points based on word length: a ";
   cout << "4-letter word is worth 1 point, 5-letters ";
   cout << "earn 2 points, and so on. After your puny ";
   cout << "brain is exhausted, I, the supercomputer, ";
   cout << "will find all the remaining words and double ";
   cout << "or triple your paltry score." << endl << endl;
}

/*
 * Function: makeTheBoard
 * --------------------------
 * Prints out the current board for playing. The board is created through random letter selection.
 */

void makeTheBoard(vector<vector<char> > &board, int inUse){
   int numRows = sqrt(inUse);
   int numCols = numRows;
   for (int row = 0; row < numRows; row++){
      vector<char> inside;
      for (int col = 0; col < numCols; col++){
         int randomRow = int(inUse * (rand() / (RAND_MAX + 1.0)));
         int randomCol = int(6.0 * (rand() / (RAND_MAX + 1.0)));
         if (inUse == 16){
            inside.push_back(STANDARD_CUBES[randomRow][randomCol]);
         }
         else{
            inside.push_back(BIG_BOGGLE_CUBES[randomRow][randomCol]);
         }
      }
      board.push_back(inside);
   }
}

bool checkIfOK(string word, vector<string> & alreadyTried, vector<string> lexicon, vector<vector<char> > board){
   if (find(alreadyTried.begin(), alreadyTried.end(), word)!=alreadyTried.end()){
      cout << "Hey you already tried this word! Try something else." << endl;
      return false;
   }
   alreadyTried.push_back(word);
   if(word.length() < 4){
      cout << "That word is too short, try a longer one." << endl;
      return false;
   }
   if (find(lexicon.begin(), lexicon.end(), word)==lexicon.end()){
      cout << "That's not a valid word!" << endl;
      return false;
   }
   else{
      vector<string> keepTrack;
      int k = 0;
      int row;
      int col;
      bool result = false;
      while(k < (board.size() * board.size())){
         row = k / board.size();
         col = k%board.size();
         if(board.at(row).at(col) == word[0]){
            keepTrack.push_back(to_string(row) + to_string(col)); //Mark square
            if(possibleToMakeWithBoard(word, board, keepTrack, row, col)){ 
               result = true;
               break;
            }
            keepTrack.pop_back(); //Unmark the square
         }
         k++;
      }
      return result;
   }
}

vector<string> createWordLexicon(){
   ifstream myStream("EnglishWords.txt");
   vector<string> lexicon;
   while(true){
      string word;
      myStream >> word;
      if(myStream.fail()){ break;}
      lexicon.push_back(word);
   }
   return lexicon;
}

bool possibleToMakeWithBoard(string word, vector<vector<char> > board, vector<string> keepTrack, int row, int col){
   //Base case ! We were able to get to the end of the word by traversing the board correctly but didn't return true so no more choices
   if(word.length() == 1) {return true; }
   row = row - 1;
   col = col - 1;
   for(int i = 0; i < 3; i++){
      row += i;
      for(int j = 0; j < 3; j++){
         col += j;
         //Check that we are still within the bounds of the board
         if(row >= 0 && col >= 0 && row < board.size() && col < board.size() && !IsMarked(row, col, keepTrack)){
            if(board.at(row).at(col) == word.substr(1)[0]){
               keepTrack.push_back(to_string(row) + to_string(col)); //Mark square
               if(possibleToMakeWithBoard(word.substr(1), board, keepTrack, row, col)){ return true;}
               else{ 
               keepTrack.pop_back(); } //Unmark the square
            }
         }
         col -= j;
      }
      row -= i;
   }
   return false;
}

bool IsMarked(int row, int col, vector<string> keepTrack){
   if(find(keepTrack.begin(), keepTrack.end(), (to_string(row) + to_string(col)))==keepTrack.end()){return false; }
   else {return true;}
}


void wordPermutations(vector<vector<char> > board, vector<string> lexicon, vector<string> &all_computer_words, int & computer_score, vector<string> alreadyTried){
   for(int k = 0; k < (board.size() * board.size()); k++){
      int row = k / board.size();
      int col = k%board.size();
      vector<string> keepTrack;
      keepTrack.push_back(to_string(row) + to_string(col)); //Mark initial square

      //Using sstream to convert char to string in c++
      stringstream ss;
      ss << board.at(row).at(col);
      string s;
      ss >> s;

      RecSubsets(board, lexicon, s, all_computer_words, computer_score, row - 1, col - 1, keepTrack, alreadyTried);
   }
}

void RecSubsets(vector<vector<char> > board, vector<string> lexicon, string current_word, vector<string> &all_computer_words, int & computer_score, int row, int col, vector<string> keepTrack, vector<string> alreadyTried){
   //BASE CASE
   if(find(lexicon.begin(), lexicon.end(), current_word)!=lexicon.end()){
      if((find(all_computer_words.begin(), all_computer_words.end(), current_word)==all_computer_words.end()) && (find(alreadyTried.begin(), alreadyTried.end(), current_word)==alreadyTried.end())){
         computer_score += 1;
         all_computer_words.push_back(current_word);
         cout << current_word << endl;
      }
   }
   else{
      for(int i = 0; i < 3; i++){
         row += i;
         for(int j = 0; j < 3; j++){
            col += j;
            //Check that we are still within the bounds of the board and only continue to search if there exists a word with that prefix and if I haven't picked that letter yet
            if(row >= 0 && col >= 0 && row < board.size() && col < board.size() && !IsMarked(row, col, keepTrack) && matchPrefix(current_word, lexicon)){    
               keepTrack.push_back(to_string(row) + to_string(col)); //Mark square
               //Include the next letter
               RecSubsets(board, lexicon, current_word + board.at(row).at(col), all_computer_words, computer_score, row - 1, col - 1, keepTrack, alreadyTried);
               keepTrack.pop_back(); //Unmark the square
            }
            col -= j;
         }
         row -= i;
      }
   }
}

bool matchPrefix(string current_word, vector<string> lexicon){
   int sizeOfPrefix = current_word.length();
   for(int l = 0; l < lexicon.size(); l++){
      if(current_word == lexicon.at(l).substr(0, sizeOfPrefix)){
         return true;
      }
   }
   return false;
}


