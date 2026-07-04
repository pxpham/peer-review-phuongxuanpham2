#include "scoreboard.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

bool nearlyEqual(double actual, double expected, double tolerance = 0.0001) {
    return fabs(actual - expected) <= tolerance;
}

void assertArrayEquals(const int actual[], const int expected[], int size) {
    for (int i = 0; i < size; i++) {
        assert(actual[i] == expected[i]);
    }
}

void testIsValidSize() {
    assert(isValidSize(1));
    assert(isValidSize(5));
    assert(!isValidSize(0));
    assert(!isValidSize(-1));
}

void testCalculateTotal() {
    int scores[] = {25, 10, 30, 15, 40};
    assert(calculateTotal(scores, 5) == 120);

    int single[] = {99};
    assert(calculateTotal(single, 1) == 99);

    assert(calculateTotal(nullptr, 5) == 0);
    assert(calculateTotal(scores, 0) == 0);
}

void testCalculateAverage() {
    int scores[] = {25, 10, 30, 15, 40};
    assert(nearlyEqual(calculateAverage(scores, 5), 24.0));

    int scores2[] = {80, 90, 100};
    assert(nearlyEqual(calculateAverage(scores2, 3), 90.0));

    assert(nearlyEqual(calculateAverage(nullptr, 5), 0.0));
    assert(nearlyEqual(calculateAverage(scores, 0), 0.0));
}

void testFindLowest() {
    int scores[] = {25, 10, 30, 15, 40};
    assert(findLowest(scores, 5) == 10);

    int allNegative[] = {-3, -10, -1};
    assert(findLowest(allNegative, 3) == -10);

    assert(findLowest(nullptr, 5) == 0);
    assert(findLowest(scores, 0) == 0);
}

void testFindHighest() {
    int scores[] = {25, 10, 30, 15, 40};
    assert(findHighest(scores, 5) == 40);

    int allNegative[] = {-3, -10, -1};
    assert(findHighest(allNegative, 3) == -1);

    assert(findHighest(nullptr, 5) == 0);
    assert(findHighest(scores, 0) == 0);
}

void testFindScore() {
    int scores[] = {25, 10, 30, 15, 40};

    assert(findScore(scores, 5, 25) == 0);
    assert(findScore(scores, 5, 30) == 2);
    assert(findScore(scores, 5, 40) == 4);
    assert(findScore(scores, 5, 99) == -1);

    assert(findScore(nullptr, 5, 30) == -1);
    assert(findScore(scores, 0, 30) == -1);
}

void testSortScores() {
    int scores[] = {25, 10, 30, 15, 40};
    int expected[] = {10, 15, 25, 30, 40};

    sortScores(scores, 5);
    assertArrayEquals(scores, expected, 5);
}

void testSortAlreadySortedScores() {
    int scores[] = {1, 2, 3, 4};
    int expected[] = {1, 2, 3, 4};

    sortScores(scores, 4);
    assertArrayEquals(scores, expected, 4);
}

void testSortScoresWithDuplicates() {
    int scores[] = {20, 10, 20, 5};
    int expected[] = {5, 10, 20, 20};

    sortScores(scores, 4);
    assertArrayEquals(scores, expected, 4);
}

int main() {
    testIsValidSize();
    testCalculateTotal();
    testCalculateAverage();
    testFindLowest();
    testFindHighest();
    testFindScore();
    testSortScores();
    testSortAlreadySortedScores();
    testSortScoresWithDuplicates();

    cout << "All Lab 4.2 scoreboard array tests passed!" << endl;
    return 0;
}
