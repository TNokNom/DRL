#ifndef QLEARNING_H
#define QLEARNING_H

#include <vector>

enum Action { LEFT, RIGHT, UP, DOWN };

extern std::vector<std::vector<std::vector<double>>> Q;
Action chooseAction(int x, int y);
std::pair<int, int> getNextState(int x, int y, Action action);
double getReward(int x, int y);
void updateQ(int x, int y, Action action, int next_x, int next_y, double reward);
void trainStep();

#endif
