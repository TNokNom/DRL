#include "rendering.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "qlearning.h"

// OpenGL - 3D Ground
void drawGround() {
    glColor3f(0.3f, 0.7f, 0.3f);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 0);
    glVertex3f(GRID_SIZE, 0, 0);
    glVertex3f(GRID_SIZE, 0, GRID_SIZE);
    glVertex3f(0, 0, GRID_SIZE);
    glEnd();
}

// OpenGL - 3D Cube Drawing (Replaces `glutSolidCube`)
void drawCube(float size) {
    float half = size / 2.0f;
    glBegin(GL_QUADS);

    // Front
    glVertex3f(-half, -half, half);
    glVertex3f(half, -half, half);
    glVertex3f(half, half, half);
    glVertex3f(-half, half, half);

    // Back
    glVertex3f(-half, -half, -half);
    glVertex3f(-half, half, -half);
    glVertex3f(half, half, -half);
    glVertex3f(half, -half, -half);

    glEnd();
}

// OpenGL - Draw agent as cube
void drawAgent() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(agent_y + 0.5, 0.5, agent_x + 0.5);
    drawCube(0.8);
    glPopMatrix();
}

// OpenGL - Camera Setup
void setupCamera() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.5, 5, 5, GRID_SIZE / 2, 0, GRID_SIZE / 2, 0, 1, 0);
}

