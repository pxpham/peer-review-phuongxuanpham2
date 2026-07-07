#include "scoreboard.hpp"
#include <iostream>

using namespace std;

int calculateTotal(const int scores[], int size) {
    // TODO:
    // If the array is null or the size is invalid, return 0.
    // Otherwise, return the sum of all scores.
    if(size <= 0 || scores == NULL) {
        return 0;
    }

    int total = 0;

    for(int i = 0; i < size; i++) {
        total += scores[i];
    }

    return total;
}

double calculateAverage(const int scores[], int size) {
    // TODO:
    // If the array is null or the size is invalid, return 0.0.
    // Otherwise, return the total divided by size.
    if(size <= 0 || scores == NULL) {
        return 0.0;
    }

    return calculateTotal(scores, size) / double(size);
}

int findLowest(const int scores[], int size) {
    // TODO:
    // If the array is null or the size is invalid, return 0.
    // Otherwise, return the smallest score.
    if(size <= 0 || scores == NULL) {
        return 0;
    }

    int lowest = scores[0];

    for(int i = 0; i < size; i++) {
        if(scores[i] < lowest) {
            lowest = scores[i];
        }
    }

    return lowest;
}

int findHighest(const int scores[], int size) {
    // TODO:
    // If the array is null or the size is invalid, return 0.
    // Otherwise, return the largest score.
    if(size <= 0 || scores == NULL) {
        return 0;
    }

    int highest = scores[0];

    for(int i = 0; i < size; i++) {
        if(scores[i] > highest) {
            highest = scores[i];
        }
    }

    return highest;
}

int findScore(const int scores[], int size, int target) {
    // TODO:
    // Search the array from left to right.
    // Return the index where target is found.
    // Return -1 when target is not found.
    if(size <= 0 || scores == NULL) {
        return -1;
    }

    for(int i = 0; i < size; i++) {
        if(scores[i] == target) return i;
    }

    return -1;
}

void sortScores(int scores[], int size) {
    // TODO:
    // Sort the array from lowest to highest.
    // A selection sort works well for this lab.

    for (int i = 0; i < size - 1; i++) {
        int lowestIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (scores[j] < scores[lowestIndex]) {
                lowestIndex = j;
            }
        }

        int temp = scores[i];
        scores[i] = scores[lowestIndex];
        scores[lowestIndex] = temp;
    }
}

void printScores(const int scores[], int size) {
    if (scores == nullptr || !isValidSize(size)) {
        cout << "No scores to print." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << scores[i];

        if (i < size - 1) {
            cout << " ";
        }
    }

    cout << endl;
}

bool isValidSize(int size) {
    // TODO: Return true when size is greater than 0.
    return (size > 0);
}
