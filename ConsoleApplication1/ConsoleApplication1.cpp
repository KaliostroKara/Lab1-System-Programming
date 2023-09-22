#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

string removeNonAlphabetChars(const string& word) {
    string result;
    for (char c : word) {
        if (isalpha(c)) {
            result += tolower(c); // Convert to lowercase to ignore letter case
        }
    }
    return result;
}

int countUniqueLetters(const string& word) {
    unordered_set<char> uniqueLetters;
    for (char c : word) {
        uniqueLetters.insert(c);
    }
    return uniqueLetters.size();
}

int main() {
    ifstream inputFile("C:\\Users\\KIRIL MSI\\source\\vsyakoe\\Document.txt"); 
    if (!inputFile) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    string word;
    int maxUniqueLetterCount = 0;
    unordered_set<string> wordsWithMaxUniqueLetters;

    while (inputFile >> word) {
        string cleanedWord = removeNonAlphabetChars(word);
        int uniqueLetterCount = countUniqueLetters(cleanedWord);
        if (uniqueLetterCount > maxUniqueLetterCount) {
            maxUniqueLetterCount = uniqueLetterCount;
            wordsWithMaxUniqueLetters.clear();
            wordsWithMaxUniqueLetters.insert(cleanedWord);
        }
        else if (uniqueLetterCount == maxUniqueLetterCount) {
            wordsWithMaxUniqueLetters.insert(cleanedWord);
        }
    }

    inputFile.close();

    cout << "Words with the largest number of different letters (" << maxUniqueLetterCount << " unique letters):" << endl;
    for (const string& uniqueWord : wordsWithMaxUniqueLetters) {
        cout << uniqueWord << endl;
    }

    return 0;
}