#include "qlearning.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

const int GRID_SIZE = 5;
const int ACTIONS = 4;
double ALPHA = 0.3, GAMMA = 0.9, EPSILON = 0.2;
std::vector<std::vector<std::vector<double>>> Q(GRID_SIZE, std::vector<std::vector<double>>(GRID_SIZE, std::vector<double>(ACTIONS, 0.0)));

Action chooseAction(int x, int y) {
    if ((rand() / (double)RAND_MAX) < EPSILON) {
        return static_cast<Action>(rand() % ACTIONS);
    } else {
        return static_cast<Action>(max_element(Q[x][y].begin(), Q[x][y].end()) - Q[x][y].begin());
    }
}

std::pair<int, int> getNextState(int x, int y, Action action) {
    if (action == LEFT)  y = max(0, y - 1);
    if (action == RIGHT) y = min(GRID_SIZE - 1, y + 1);
    if (action == UP)    x = max(0, x - 1);
    if (action == DOWN)  x = min(GRID_SIZE - 1, x + 1);
    return {x, y};
}

double getReward(int x, int y) {
    return (x == GRID_SIZE - 1 && y == GRID_SIZE - 1) ? 1.0 : -0.1;
}

void updateQ(int x, int y, Action action, int next_x, int next_y, double reward) {
    double max_future_q = *max_element(Q[next_x][next_y].begin(), Q[next_x][next_y].end());
    Q[x][y][action] += ALPHA * (reward + GAMMA * max_future_q - Q[x][y][action]);
}

void trainStep() {
    for (int episode = 0; episode < 500; episode++) {
        int agent_x = 0, agent_y = 0;
        while (!(agent_x == GRID_SIZE - 1 && agent_y == GRID_SIZE - 1)) {
            Action action = chooseAction(agent_x, agent_y);
            auto next = getNextState(agent_x, agent_y, action);
            updateQ(agent_x, agent_y, action, next.first, next.second, getReward(next.first, next.second));
            agent_x = next.first;
            agent_y = next.second;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
        EPSILON = max(0.01, EPSILON * 0.995);
    }
}
