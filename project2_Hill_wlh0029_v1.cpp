// Wilson Hill
// wlh0029
//project2_Hill_wlh0029_v1.cpp
// ----Compilation Instructions----
// To compile this file use the following commands: g++ project2_Hill_wlh0029_v1.cpp then ./a.out
//=============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constants
const int Nums_Of_Duels = 10000;
const double A_Acc = 1.0 / 3.0;
const double B_Acc = 1.0 / 2.0;
const double C_Acc = 1.0;

// Function Prototypes
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);

void press_any_key_to_continue();

int main() {
    srand(time(0));

    // Variables for keeping track of wins
    int aaron_wins_1 = 0, bob_wins_1 = 0, charlie_wins_1 = 0;
    int aaron_wins_2 = 0, bob_wins_2 = 0, charlie_wins_2 = 0;

    // Strategy 1 Simulation
    cout << "Ready to test strategy 1 (run 10000 times):\n";
    press_any_key_to_continue();  // Pause
    for (int i = 0; i < Nums_Of_Duels; i++) {
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
    cout << "Aaron won " << aaron_wins_1 << "/" << Nums_Of_Duels << " truels or " << (aaron_wins_1 * 100.0 / Nums_Of_Duels) << "%\n";
    cout << "Bob won " << bob_wins_1 << "/" << Nums_Of_Duels << " truels or " << (bob_wins_1 * 100.0 / Nums_Of_Duels) << "%\n";
    cout << "Charlie won " << charlie_wins_1 << "/" << Nums_Of_Duels << " truels or " << (charlie_wins_1 * 100.0 / Nums_Of_Duels) << "%\n";

    // Strategy 2 Simulation
    cout << "\nReady to test strategy 2 (run 10000 times):\n";
    press_any_key_to_continue();  // Pause
    for (int i = 0; i < Nums_Of_Duels; i++) {
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
    cout << "Aaron won " << aaron_wins_2 << "/" << Nums_Of_Duels << " truels or " << (aaron_wins_2 * 100.0 / Nums_Of_Duels) << "%\n";
    cout << "Bob won " << bob_wins_2 << "/" << Nums_Of_Duels << " truels or " << (bob_wins_2 * 100.0 / Nums_Of_Duels) << "%\n";
    cout << "Charlie won " << charlie_wins_2 << "/" << Nums_Of_Duels << " truels or " << (charlie_wins_2 * 100.0 / Nums_Of_Duels) << "%\n";

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

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
    int shot = rand() % 100;
    if (C_alive && shot < A_Acc * 100) {
        C_alive = false;
    } else if (B_alive && shot < A_Acc * 100) {
        B_alive = false;
    }
}

void Bob_shoots(bool& A_alive, bool& C_alive) {
    int shot = rand() % 100;
    if (C_alive && shot < B_Acc * 100) {
        C_alive = false;
    } else if (A_alive && shot < B_Acc * 100) {
        A_alive = false;
    }
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
    if (B_alive) {
        B_alive = false;
    } else if (A_alive) {
        A_alive = false;
    }
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
    if (B_alive && C_alive) {
        return;  // Aaron intentionally misses his first shot
    } else {
        Aaron_shoots1(B_alive, C_alive);
    }
}

void press_any_key_to_continue() {
    cout << "Press any key to continue...\n";
    cin.ignore().get();  // Pause and wait for user input
}
