#include "scoreboard.hpp"
#include <iostream>

using namespace std;

int main() {
    int scores[DEFAULT_SCORE_COUNT] = {25, 10, 30, 15, 40};
    int target = 0;

    cout << "Scoreboard Analyzer" << endl;
    cout << endl;

    cout << "Original scores:" << endl;
    printScores(scores, DEFAULT_SCORE_COUNT);
    cout << endl;

    cout << "Total: " << calculateTotal(scores, DEFAULT_SCORE_COUNT) << endl;
    cout << "Average: " << calculateAverage(scores, DEFAULT_SCORE_COUNT) << endl;
    cout << "Lowest: " << findLowest(scores, DEFAULT_SCORE_COUNT) << endl;
    cout << "Highest: " << findHighest(scores, DEFAULT_SCORE_COUNT) << endl;
    cout << endl;

    cout << "Enter score to search for: ";
    cin >> target;

    int index = findScore(scores, DEFAULT_SCORE_COUNT, target);

    if (index == -1) {
        cout << "Score not found." << endl;
    } else {
        cout << "Score found at index " << index << endl;
    }

    cout << endl;
    sortScores(scores, DEFAULT_SCORE_COUNT);

    cout << "Sorted scores:" << endl;
    printScores(scores, DEFAULT_SCORE_COUNT);

    return 0;
}
