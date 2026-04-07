#include <vector>
#include <string>
using namespace std;

class Robot {
private:
    int w, h;
    int x, y;
    int dir; // 0=East, 1=North, 2=West, 3=South
    int cycle;

    vector<string> dirs = {"East", "North", "West", "South"};

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;
        cycle = 2 * (w + h) - 4;
    }

    void step(int num) {
        int move = num % cycle;

        if (move == 0 && num > 0) {
            move = cycle;
        }

        while (move--) {

            // 🔥 FIX: Check BEFORE moving
            if (dir == 0 && x + 1 >= w) dir = 1;
            else if (dir == 1 && y + 1 >= h) dir = 2;
            else if (dir == 2 && x - 1 < 0) dir = 3;
            else if (dir == 3 && y - 1 < 0) dir = 0;

            // move AFTER deciding direction
            if (dir == 0) x++;
            else if (dir == 1) y++;
            else if (dir == 2) x--;
            else y--;
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return dirs[dir];
    }
};