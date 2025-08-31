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

// struct ComparisonInfo {
//     string wordOne = "";
//     string wordTwo = "";
//     bool isAnagram = false;
// };

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
    outputOccurrences(wordOne, 26, wordOneOccurrences);

    recordOccurrences(wordTwo, wordTwoOccurrences);
    outputOccurrences(wordTwo, 26, wordTwoOccurrences);

    if (!std::equal(wordOneOccurrences, wordOneOccurrences + 26,
                    wordTwoOccurrences, wordTwoOccurrences + 26))
    {
        cout << wordOne << " and " << wordTwo << " are NOT an anagram" << endl;
        return false;
    }

    cout << wordOne << " and " << wordTwo << " are an anagram" << endl;
    return true;
}

int main() {
    // ComparisonInfo comparisonArray[5][5];

    string wordOne = "SILENT";

    string wordTwo = "LISTEN";


    int wordOneOccurrences[26] = {};

    int wordTwoOccurrences[26] = {};


    checkForAnagram(wordOne, wordOneOccurrences, wordTwo, wordTwoOccurrences);

    return 0;
}