#include <iostream>
#include <vector>

using namespace std;

void printPossibilities(int score, int touchdowns, int fieldGoals, int safeties) {
    cout << "Possible combinations of scoring plays for " << score << " points:" << endl;
    for (int td = 0; td <= touchdowns; td++) {
        for (int fg = 0; fg <= fieldGoals; fg++) {
            for (int safety = 0; safety <= safeties; safety++) {
                if (td * 6 + fg * 3 + safety * 2 == score) {
                    cout << td << " TD + " << fg << " FG + " << safety << " Safety" << endl;
                }
            }
        }
    }
}

int main() {
    while (true) {
        int score;
        cout << "Enter an NFL score (2 or more, or less than 2 to exit): ";
        cin >> score;

        if (score < 2) {
            cout << "Program exits!" << endl;
            break;
        }

        int touchdowns = score / 6;
        int fieldGoals = (score % 6) / 3;
        int safeties = (score % 6) % 3;

        printPossibilities(score, touchdowns, fieldGoals, safeties);
    }

    return 0;
}
