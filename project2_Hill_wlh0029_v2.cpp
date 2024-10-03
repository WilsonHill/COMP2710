#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>

using namespace std;

// Constants
const int Num_Of_Duels = 10000;
const double A_Acc = 1.0 / 3.0;
const double B_Acc = 1.0 / 2.0;
const double C_Acc = 1.0;

// Function Prototypes
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive, bool is_unit_test = false);
void Bob_shoots(bool& A_alive, bool& C_alive, bool is_unit_test = false);
void Charlie_shoots(bool& A_alive, bool& B_alive, bool is_unit_test = false);
void Aaron_shoots2(bool& B_alive, bool& C_alive, bool is_unit_test = false);

void test_at_least_two_alive();
void test_Aaron_shoots1();
void test_Bob_shoots();
void test_Charlie_shoots();
void test_Aaron_shoots2();

void press_any_key_to_continue();

int main() {
    srand(time(0));

    // Unit Testing
    test_at_least_two_alive();
    press_any_key_to_continue();  // Pause
    test_Aaron_shoots1();
    press_any_key_to_continue();  // Pause
    test_Bob_shoots();
    press_any_key_to_continue();  // Pause
    test_Charlie_shoots();
    press_any_key_to_continue();  // Pause
    test_Aaron_shoots2();
    press_any_key_to_continue();  // Pause

    // Variables for keeping track of wins
    int aaron_wins_1 = 0, bob_wins_1 = 0, charlie_wins_1 = 0;
    int aaron_wins_2 = 0, bob_wins_2 = 0, charlie_wins_2 = 0;

    // Strategy 1 Simulation
    cout << "Ready to test strategy 1 (run 10000 times):\n";
    press_any_key_to_continue();  // Pause
    for (int i = 0; i < Num_Of_Duels; i++) {
        bool A_alive = true, B_alive = true, C_alive = true;
        while (at_least_two_alive(A_alive, B_alive, C_alive)) {
            if (A_alive) Aaron_shoots1(B_alive, C_alive);
            if (B_alive) Bob_shoots(A_alive, C_alive);
            if (C_alive) Charlie_shoots(A_alive, B_alive);
        }

        if (A_alive) aaron_wins_1++;
        else if (B_alive) bob_wins_1++;
        else if (C_alive) charlie_wins_1++;
    }

    // Output Strategy 1 Results
    cout << "Aaron won " << aaron_wins_1 << "/" << Num_Of_Duels << " truels or " << (aaron_wins_1 * 100.0 / Num_Of_Duels) << "%\n";
    cout << "Bob won " << bob_wins_1 << "/" << Num_Of_Duels << " truels or " << (bob_wins_1 * 100.0 / Num_Of_Duels) << "%\n";
    cout << "Charlie won " << charlie_wins_1 << "/" << Num_Of_Duels << " truels or " << (charlie_wins_1 * 100.0 / Num_Of_Duels) << "%\n";

    // Strategy 2 Simulation
    cout << "\nReady to test strategy 2 (run 10000 times):\n";
    press_any_key_to_continue();  // Pause
    for (int i = 0; i < Num_Of_Duels; i++) {
        bool A_alive = true, B_alive = true, C_alive = true;
        while (at_least_two_alive(A_alive, B_alive, C_alive)) {
            if (A_alive) Aaron_shoots2(B_alive, C_alive);
            if (B_alive) Bob_shoots(A_alive, C_alive);
            if (C_alive) Charlie_shoots(A_alive, B_alive);
        }

        if (A_alive) aaron_wins_2++;
        else if (B_alive) bob_wins_2++;
        else if (C_alive) charlie_wins_2++;
    }

    // Output Strategy 2 Results
    cout << "Aaron won " << aaron_wins_2 << "/" << Num_Of_Duels << " truels or " << (aaron_wins_2 * 100.0 / Num_Of_Duels) << "%\n";
    cout << "Bob won " << bob_wins_2 << "/" << Num_Of_Duels << " truels or " << (bob_wins_2 * 100.0 / Num_Of_Duels) << "%\n";
    cout << "Charlie won " << charlie_wins_2 << "/" << Num_Of_Duels << " truels or " << (charlie_wins_2 * 100.0 / Num_Of_Duels) << "%\n";

    // Compare Strategies
    if (aaron_wins_2 > aaron_wins_1) {
        cout << "Strategy 2 is better than strategy 1.\n";
    } else {
        cout << "Strategy 1 is better than strategy 2.\n";
    }

    return 0;
}

// Function Implementations
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    return (A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive);
}

void Aaron_shoots1(bool& B_alive, bool& C_alive, bool is_unit_test) {
    if (is_unit_test) {
        cout << "Aaron is shooting at " << (C_alive ? "Charlie" : "Bob") << endl;
    }
    int shot = rand() % 100;
    if (C_alive && shot < A_Acc * 100) {
        C_alive = false;
    } else if (B_alive && shot < A_Acc * 100) {
        B_alive = false;
    }
}

void Bob_shoots(bool& A_alive, bool& C_alive, bool is_unit_test) {
    if (is_unit_test) {
        cout << "Bob is shooting at " << (C_alive ? "Charlie" : "Aaron") << endl;
    }
    int shot = rand() % 100;
    if (C_alive && shot < B_Acc * 100) {
        C_alive = false;
    } else if (A_alive && shot < B_Acc * 100) {
        A_alive = false;
    }
}

void Charlie_shoots(bool& A_alive, bool& B_alive, bool is_unit_test) {
    if (is_unit_test) {
        cout << "Charlie is shooting at " << (B_alive ? "Bob" : "Aaron") << endl;
    }
    if (B_alive) {
        B_alive = false;
    } else if (A_alive) {
        A_alive = false;
    }
}

void Aaron_shoots2(bool& B_alive, bool& C_alive, bool is_unit_test) {
    if (B_alive && C_alive) {
        if (is_unit_test) {
            cout << "Aaron intentionally misses his first shot\n";
        }
    } else {
        if (is_unit_test) {
            cout << "Aaron is shooting at " << (C_alive ? "Charlie" : "Bob") << endl;
        }
        Aaron_shoots1(B_alive, C_alive, is_unit_test);
    }
}

// Test driver implementations
void test_at_least_two_alive() {
    cout << "Unit Testing 1: Function - at_least_two_alive()\n";
    assert(at_least_two_alive(true, true, true));
    assert(at_least_two_alive(false, true, true));
    assert(at_least_two_alive(true, false, true));
    assert(at_least_two_alive(true, true, false));
    assert(!at_least_two_alive(false, false, true));
    assert(!at_least_two_alive(false, true, false));
    assert(!at_least_two_alive(true, false, false));
    cout << "All tests passed.\n";
}

void test_Aaron_shoots1() {
    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
    bool B_alive = true, C_alive = true;
    cout << "Case 1: Bob alive, Charlie alive\n";
    Aaron_shoots1(B_alive, C_alive, true);

    B_alive = false, C_alive = true;
    cout << "Case 2: Bob dead, Charlie alive\n";
    Aaron_shoots1(B_alive, C_alive, true);

    B_alive = true, C_alive = false;
    cout << "Case 3: Bob alive, Charlie dead\n";
    Aaron_shoots1(B_alive, C_alive, true);
}

void test_Bob_shoots() {
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
    bool A_alive = true, C_alive = true;
    cout << "Case 1: Aaron alive, Charlie alive\n";
    Bob_shoots(A_alive, C_alive, true);

    A_alive = false, C_alive = true;
    cout << "Case 2: Aaron dead, Charlie alive\n";
    Bob_shoots(A_alive, C_alive, true);

    A_alive = true, C_alive = false;
    cout << "Case 3: Aaron alive, Charlie dead\n";
    Bob_shoots(A_alive, C_alive, true);
}

void test_Charlie_shoots() {
    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
    bool A_alive = true, B_alive = true;
    cout << "Case 1: Aaron alive, Bob alive\n";
    Charlie_shoots(A_alive, B_alive, true);

    A_alive = false, B_alive = true;
    cout << "Case 2: Aaron dead, Bob alive\n";
    Charlie_shoots(A_alive, B_alive, true);

    A_alive = true, B_alive = false;
    cout << "Case 3: Aaron alive, Bob dead\n";
    Charlie_shoots(A_alive, B_alive, true);
}

void test_Aaron_shoots2() {
    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    bool B_alive = true, C_alive = true;
    cout << "Case 1: Bob alive, Charlie alive\n";
    Aaron_shoots2(B_alive, C_alive, true);

    B_alive = false, C_alive = true;
    cout << "Case 2: Bob dead, Charlie alive\n";
    Aaron_shoots2(B_alive, C_alive, true);

    B_alive = true, C_alive = false;
    cout << "Case 3: Bob alive, Charlie dead\n";
    Aaron_shoots2(B_alive, C_alive, true);
}

// Utility function to pause the execution and wait for user input
void press_any_key_to_continue() {
    cout << "Press any key to continue...\n";
    cin.ignore().get();  // Pause and wait for user input
}
