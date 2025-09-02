#include <iostream> // import libraries
#include <string>
#include <cstring>
#include <iterator>
#include <array>
#include <algorithm>

using std::cin; // namespace aliases
using std::cout;
using std::endl;
using std::string;

struct ComparisonInfo {
    string wordOne = "";
    string wordTwo = "";
    bool isAnagram = false;
};

class AnagramCheck {
    private:

    public:


};

void recordOccurrences(const string& word, int* wordOccurrences) {
    for (int i = 0; i < word.size(); i++) {
        int letterIndex = word[i] - 'A';

        wordOccurrences[letterIndex] += 1;
    };
}

void outputOccurrences(const string& word, int size, int* wordOccurrences) {
    cout << "For word: " << word << endl;
    for (int i = 0; i < size; i++) {
        if (wordOccurrences[i] != 0) {
            cout << "Letter " << static_cast<char>('A' + i) << " (Index " << i << ") appeared " << wordOccurrences[i] << " times" << endl; // TODO: make more self-documenting
        }
    }
    cout << endl;
}

bool checkForAnagram(const string &wordOne,
                     int *wordOneOccurrences,
                     const string &wordTwo,
                     int *wordTwoOccurrences)
{
    // NOTE: only call outputOccurrences at the beginning so it doesn't get spammed
    recordOccurrences(wordOne, wordOneOccurrences);
    // outputOccurrences(wordOne, 26, wordOneOccurrences);

    recordOccurrences(wordTwo, wordTwoOccurrences);
    // outputOccurrences(wordTwo, 26, wordTwoOccurrences);

    if (!std::equal(wordOneOccurrences, wordOneOccurrences + 26,
                    wordTwoOccurrences, wordTwoOccurrences + 26))
    {
        // cout << wordOne << " and " << wordTwo << " are NOT an anagram" << endl;
        return false;
    }

    // cout << wordOne << " and " << wordTwo << " are an anagram" << endl;
    return true;
}

string translateBoolValue(const bool boolean) {
    if (boolean) {
        return "True";
    }
    else {
        return "False";
    }
}

int main() {
    ComparisonInfo comparisonArray[5][5];

    string wordOne = "SILENT";

    string wordTwo = "LISTEN";


    int wordOneOccurrences[26] = {};

    int wordTwoOccurrences[26] = {};


    // checkForAnagram(wordOne, wordOneOccurrences, wordTwo, wordTwoOccurrences);

    // string wordList[5] = {"test1", "test2", "test3", "test4", "test5"};

    // cout << endl;
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         cout << wordList[i] << " vs " << wordList[j] << endl;
    //     }
    // }

    string wordList[5] = {"TESTONE", "TESTTWO", "TESTTHREE", "TESTFOUR", "TESTFIVE"};
    // comparisonArray[0][0].wordOne = wordList[0];
    // comparisonArray[0][0].wordTwo = wordList[1];
    // comparisonArray[0][0].isAnagram = checkForAnagram(wordList[0], wordOneOccurrences, wordList[1], wordTwoOccurrences);

    // cout << "Index (0, 0) First Word: " << comparisonArray[0][0].wordOne << endl;
    // cout << "Index (0, 0) Second Word: " << comparisonArray[0][0].wordTwo << endl;
    // cout << "Index (0, 0) Anagram Check Result: " << translateBoolValue(comparisonArray[0][0].isAnagram) << endl;

    cout << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::fill(std::begin(wordOneOccurrences), std::end(wordOneOccurrences), 0);
            std::fill(std::begin(wordTwoOccurrences), std::end(wordTwoOccurrences), 0);

            comparisonArray[i][j].wordOne = wordList[i];
            comparisonArray[i][j].wordTwo = wordList[j];
            comparisonArray[i][j].isAnagram = checkForAnagram(comparisonArray[i][j].wordOne, wordOneOccurrences, comparisonArray[i][j].wordTwo, wordTwoOccurrences);

            cout << "Index (" << i << ", " << j << ") First Word: " << comparisonArray[i][j].wordOne << endl;
            cout << "Index (" << i << ", " << j << ") Second Word: " << comparisonArray[i][j].wordTwo << endl;
            cout << "Index (" << i << ", " << j << ") Anagram Checker Result: " << translateBoolValue(comparisonArray[i][j].isAnagram) << endl;
        }
    }

    return 0;
}