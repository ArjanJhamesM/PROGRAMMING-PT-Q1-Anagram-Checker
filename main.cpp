#include <iostream> // import libraries
#include <string>
#include <cstring>
#include <iterator>
#include <array>
#include <algorithm>
#include <conio.h>

using std::cin; // namespace aliases
using std::cout;
using std::endl;
using std::string;

string wordList[5] = {}; // reference list of input words

struct ComparisonInfo {
    string wordOne = ""; // word assigned at a particular column
    string wordTwo = ""; // word assigned at a particular row
    bool isAnagram = false; // result of anagram checker function
};

ComparisonInfo comparisonArray[5][5]; // 5 each for all rows and columns due to 5 words
// each two-dimensional index holds ComparisonInfo struct to store information for anagram checking

// stores letter occurrences as basis for anagram checking
int wordOneOccurrences[26] = {};
int wordTwoOccurrences[26] = {};

void recordOccurrences(const string& word, int* wordOccurrences) {
    for (int i = 0; i < static_cast<int>(word.size()); i++) { // iterates each letter of the string array
        int letterIndex = word[i] - 'A'; // 'A' as the reference point for alphabet position of iterated letter
        // letterIndex locates where to record the number of times the iterated letter occurred in the specified word
        wordOccurrences[letterIndex] += 1;
    };
}

bool checkForAnagram(const string &wordOne,
                     int *wordOneOccurrences,
                     const string &wordTwo,
                     int *wordTwoOccurrences) // bool return function to show the result of anagram check
{
    recordOccurrences(wordOne, wordOneOccurrences);
    recordOccurrences(wordTwo, wordTwoOccurrences); // store occurrences record to word information variables

    if (!std::equal(wordOneOccurrences, wordOneOccurrences + 26,
                    wordTwoOccurrences, wordTwoOccurrences + 26)) 
    { // guard clause: records, or elements, between the two occurrences arrays did not exactly match each other
        return false;
    }

    return true;
}

// indicators for whether word input process is complete or not
int currentWordCount = 0;

bool hasMoreWordsToInput() {
    return currentWordCount < 5;
}

// repeats until word input process is complete
void askForWordInput(string *wordList, int currentWordCount) {
    cout << endl;
    cout << "For word " << currentWordCount << ": Enter a word for anagram checking" << endl;
    std::getline(cin, wordList[currentWordCount]);
}

int main() {
    while (hasMoreWordsToInput()) { // updates progress of word input process
        askForWordInput(wordList, currentWordCount);
        currentWordCount++;
    }

    cout << endl;

    for (int i = 0; i < 5; i++) { // variable i mainly iterates over the column position of 2D array
        cout << "***** WORD: " << wordList[i] << " ****" << endl;

        for (int j = 0; j < 5; j++) { // variable j mainly iterates over the row position of 2D array
            std::fill(std::begin(wordOneOccurrences), std::end(wordOneOccurrences), 0);
            std::fill(std::begin(wordTwoOccurrences), std::end(wordTwoOccurrences), 0); // reset occurrences arrays

            comparisonArray[i][j].wordOne = wordList[i]; // fill in word information for anagram checker results
            comparisonArray[i][j].wordTwo = wordList[j];
            comparisonArray[i][j].isAnagram = checkForAnagram(comparisonArray[i][j].wordOne, wordOneOccurrences,
                                                              comparisonArray[i][j].wordTwo, wordTwoOccurrences);

            cout << "Second Word: " << comparisonArray[i][j].wordTwo << // compared against word iterated by variable i
                    "\t\t(Index (" << i << ", " << j << "))" << endl;
            cout << "Anagram Checker Result: " << std::boolalpha << comparisonArray[i][j].isAnagram <<
                    "\t(Index (" << i << ", " << j << "))" << endl; // output result of anagram checker between 2 words
            cout << endl;
        }

        cout << endl;
    }

    _getch();

    return 0;
}