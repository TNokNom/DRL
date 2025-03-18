#include "qlearning.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    srand(time(0));
    trainStep(); // Run Q-learning
    return 0;
}

