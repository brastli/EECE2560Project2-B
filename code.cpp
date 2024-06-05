#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "dictionary.h"
using namespace std;

void dictionary::heapsort() {
    heap max_heap;
    
    // Insert all words into the heap
    for (const auto& word : words) {
        max_heap.insert(word);
    }
    
    // Build the max heap
    max_heap.buildMaxHeap();
    
    // Extract the maximum element from the heap and place it in the array
    for (int i = words.size() - 1; i >= 0; i--) {
        words[i] = max_heap.extractMax();
    }
}

// Function declaration for printing the words found
void printWordsFound(vector<string>& wordsFound);

// Function to search for words in a grid using the specified sorting algorithm
void search(int algorithm)
{
    string gridFileName;
    // Prompt the user to enter the name of the grid file
    cout << "Enter the name of the grid file: ";
    cin >> gridFileName;
    ifstream gridFile(gridFileName);
    // Check if the grid file opened successfully
    if (!gridFile)
    {
        cout << "Error: unable to open grid file." << endl;
        return;
    }

    int n;
    // Read the size of the grid
    gridFile >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    // Read the grid data from the file
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            gridFile >> grid[i][j];
        }
    }

    string wordListFileName;
    // Prompt the user to enter the name of the word list file
    cout << "Enter the name of the word list file: ";
    cin >> wordListFileName;

    ifstream wordListFile(wordListFileName);
    // Check if the word list file opened successfully
    if (!wordListFile)
    {
        cout << "Error: unable to open word list file." << endl;
        return;
    }

    vector<string> wordList;
    string word;
    // Read the word list from the file
    while (wordListFile >> word)
    {
        wordList.push_back(word);
    }

    dictionary dict;
    // Sort the word list using the specified algorithm
    if (algorithm == 1)
    {
        dict.quickSort(wordList); // Use quicksort
    }
    else if (algorithm == 2)
    {
        dict.heapSort(wordList); // Use heapsort
    }
    else
    {
        cout << "Error: invalid sorting algorithm." << endl;
        return;
    }

    vector<string> wordsFound;
    // Search for each word in the grid
    for (string word : wordList)
    {
        if (dict.binarySearch(word, grid))
        {
            wordsFound.push_back(word); // Add found words to the list
        }
    }

    // Print the found words
    printWordsFound(wordsFound);
}

// Function to print the words found
void printWordsFound(vector<string>& wordsFound)
{
    if (wordsFound.empty())
    {
        cout << "No words found." << endl;
    }
    else
    {
        cout << "Words found:" << endl;
        for (string word : wordsFound)
        {
            cout << word << endl;
        }
    }
}

int main()
{
    int algorithm;
    // Prompt the user to choose the sorting algorithm
    cout << "Enter 1 for quicksort, 2 for heapsort: ";
    cin >> algorithm;

    // Call the search function with the chosen algorithm
    search(algorithm);

    return 0;
}
