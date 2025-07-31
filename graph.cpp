
// #include<bits/stdc++.h>
// #include <GL/glut.h>
// using namespace std;
// const int n = 40;

// int INF = 9999;
// #define SOURCE 1024
// #define DEST 2024
// #define WALL 3024
// #define EMPTY 4024
// #define VISITED 5024
// #define CHECKED 6024
// #define FOUND 7024
// #define NOTFOUND 8024
// #define PATH 9024

// // Color constants
// const float sourceColor = 0.7;
// const float destColor = 0.9; 
// const float wallColor = 1.0;
// const float pathColor = 1.0;
// const float visitedColor = 0.5;
// const float checkedColor = 0.3;
// const float blockColor = 0.8;
// const float DULL = 0.2;

// float screenWidth = 750;
// float screenHeight = 750;
// int clickCount = 0;
// int isMouseLeftDown = 0;
// int isMouseRightDown = 0;
// int startEndNodes = 0;
// double hVDistance = 1.0;
// double dDistance = 1.4;
// const int TIME_SECS = 1000;
// const int SCREEN_FPS = 60;
// bool canAcceptInput = true;
// int flag = 0;
// bool isOnStartPage = true;
// bool isDestinationBlocked = false;
// bool flashColor = false;
// bool isSearchDone = false;

// class SPoint {
// public:
//     int x = -1;
//     int y = -1;
//     SPoint(void) {}
//     SPoint(int x, int y) {
//         this->x = x;
//         this->y = y;
//     }
// };

// class Node {
// public:
//     int gridx = -1;
//     int gridy = -1;
//     double distance = INF;
//     int type = -1;
//     bool visited = false;
//     SPoint parent = SPoint(-1, -1);
    
//     Node(void) {}
//     Node(int x, int y) {
//         this->gridx = x;
//         this->gridy = y;
//     }
//     Node(int x, int y, int type, double distance = INF) {
//         this->gridx = x;
//         this->gridy = y;
//         this->type = type;
//         this->distance = distance;
//     }
//     int getType() const { return this->type; }
//     int getX() const { return this->gridx; }
//     int getY() const { return this->gridy; }
//     int getGridPositionX() { return this->gridx; }
//     int getGridPositionY() { return this->gridy; }
// };

// bool operator<(const Node& n1, const Node& n2) {
//     return n1.distance > n2.distance;
// }

// vector<Node> nodes;
// priority_queue<Node> nQueue;
// Node mapn[n][n];
// Node *start = nullptr;
// Node *endn = nullptr;
// vector<SPoint> path;
// bool pathFound = false;

// void reset();

// void flashMessage(int value) {
//     if (isDestinationBlocked) {
//         flashColor = !flashColor;
//         glutPostRedisplay();
//         glutTimerFunc(300, flashMessage, 0);
//     }
// }

// void promptRestart() {
//     glColor3f(1.0, 0.0, 0.0);
//     char message1[] = "DESTINATION UNREACHABLE!";
//     char message2[] = "Press 'R' to Restart";
    
//     // Calculate center position for messages
//     float centerX = n / 2.0 - 6.0;
//     float centerY = n / 2.0;
    
//     glRasterPos2f(centerX, centerY);
//     for (int i = 0; message1[i] != '\0'; i++) {
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message1[i]);
//     }
    
//     glRasterPos2f(centerX + 2.0, centerY + 2.0);
//     for (int i = 0; message2[i] != '\0'; i++) {
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message2[i]);
//     }
// }

// void drawCharacterAtGrid(int gridX, int gridY, char character, float r, float g, float b) {
//     glColor3f(r, g, b);
//     glRasterPos2f(gridX + 0.25, gridY + 0.75);
//     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, character);
// }


// void drawCell(int i, int j, float r, float g, float b) {
//     glColor3f(r, g, b);
//     glBegin(GL_POLYGON);
//     glVertex2f(i + 0.1, j + 0.1);
//     glVertex2f(i + 0.9, j + 0.1);
//     glVertex2f(i + 0.9, j + 0.9);
//     glVertex2f(i + 0.1, j + 0.9);
//     glEnd();
// }

// void clicked(int i, int j, int type) {
//     if (type != EMPTY) {
//         float dif = 0.1;
//         glBegin(GL_POLYGON);
//         if (type == SOURCE) {
//             glColor3f(0.258, 0.031, 0.388);
//             dif = -0.1;
//         } else if (type == DEST) {
//             glColor3f(0.772, 0.447, 1);
//             dif = -0.1;
//         } else if (type == WALL) {
//             glColor3f(1.0, 0.0, 0.0);
//             dif = 0.05;
//         } else if (type == VISITED) {
//             glColor3f(0.250, 0.807, 0.890);
//             dif = 0.08;
//         } else if (type == CHECKED) {
//             glColor3f(0.6, 0.4, 0.8);
//             dif = 0.08;
//         } else if (type == PATH) {
//             glColor3f(1, 0.996, 0.415);
//             dif = 0.0;
//         }
//         glVertex2f(i + dif, j + dif);
//         glVertex2f(i + dif, j - dif + 1);
//         glVertex2f(i - dif + 1, j - dif + 1);
//         glVertex2f(i - dif + 1, j + dif);
//         glEnd();

//         if (type == WALL) {
//             drawCharacterAtGrid(i, j, 'X', 0.0, 0.0, 0.0);
//         }
//     }
// }

// void reDrawPoints() {
//     for (size_t i = 0; i < nodes.size(); i++) {
//         int x = nodes[i].getGridPositionX();
//         int y = nodes[i].getGridPositionY();
//         clicked(x, y, nodes[i].getType());
//     }
// }

// void addPoints(int x, int y) {
//     int posx = x / (screenWidth / n);
//     int posy = y / (screenHeight / n);
//     for (size_t i = 0; i < nodes.size(); i++) {
//         int nodex = nodes.at(i).getGridPositionX();
//         int nodey = nodes.at(i).getGridPositionY();
//         if (nodex == posx && nodey == posy && nodes.at(i).getType() == EMPTY) {
//             if (startEndNodes == 0) {
//                 nodes.at(i) = Node(posx, posy, SOURCE, 0);
//                 startEndNodes = 1;
//             } else if (startEndNodes == 1) {
//                 nodes.at(i) = Node(posx, posy, DEST, INF);
//                 startEndNodes = 2;
//             } else {
//                 nodes.at(i) = Node(posx, posy, WALL, INF);
//                 startEndNodes++;
//             }
//             break;
//         }
//     }
// }

// void removePoints(int x, int y) {
//     int posx = x / (screenWidth / n);
//     int posy = y / (screenHeight / n);
//     for (size_t i = 0; i < nodes.size(); i++) {
//         int nodex = nodes.at(i).getGridPositionX();
//         int nodey = nodes.at(i).getGridPositionY();
//         if (nodex == posx && nodey == posy) {
//             int oldType = nodes.at(i).getType();
//             if (oldType == SOURCE) startEndNodes = 0;
//             else if (oldType == DEST) startEndNodes = 1;
//             else if (oldType == WALL) startEndNodes--;
//             nodes.at(i) = Node(posx, posy, EMPTY, INF);
//             break;
//         }
//     }
// }

// void handleMouse(int button, int state, int x, int y) {
//     if (canAcceptInput && !isDestinationBlocked) {
//         if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
//             isMouseLeftDown = 0;
//             addPoints(x, y);
//         } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//             isMouseLeftDown = 1;
//         } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
//             isMouseRightDown = 0;
//             removePoints(x, y);
//         } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
//             isMouseRightDown = 1;
//         }
//         glutPostRedisplay();
//     }
// }

// void makeReady() {
//     memset(mapn, 0, sizeof(mapn));
//     start = nullptr;
//     endn = nullptr;
//     while (!nQueue.empty()) nQueue.pop();
//     path.clear();
//     pathFound = false;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             int current_index = i * n + j;
//             mapn[i][j] = nodes.at(current_index);
//             if (nodes.at(current_index).getType() == SOURCE) {
//                 start = &mapn[i][j];
//                 mapn[i][j].distance = 0;
//             } else if (nodes.at(current_index).getType() == DEST) {
//                 endn = &mapn[i][j];
//             }
//         }
//     }

//     if (start != nullptr) nQueue.push(*start);
// }

// void reconstructPath() {
//     if (!pathFound || endn == nullptr) {
//         isDestinationBlocked = true;
//         canAcceptInput = false;
//         glutTimerFunc(300, flashMessage, 0);
//         glutPostRedisplay();
//         return;
//     }

//     // Reconstruct path from destination to source
//     Node current = *endn;
//     while (current.getGridPositionX() != start->getGridPositionX() || 
//            current.getGridPositionY() != start->getGridPositionY()) {
//         if (current.getType() != DEST && current.getType() != SOURCE) {
//             nodes.at(current.getGridPositionX() * n + current.getGridPositionY()).type = PATH;
//         }
//         path.push_back(SPoint(current.getGridPositionX(), current.getGridPositionY()));
//         current = mapn[current.parent.x][current.parent.y];
//     }
//     canAcceptInput = true;
//     glutPostRedisplay();
// }
// void drive(int value) {
//     if (isSearchDone) return;
    
//     if (nQueue.empty()) {
//         isSearchDone = true;
//         reconstructPath();
//         return;
//     }

//     Node current = nQueue.top();
//     nQueue.pop();

//     // Skip if we already found a better path to this node
//     if (current.distance > mapn[current.getGridPositionX()][current.getGridPositionY()].distance) {
//         glutTimerFunc(TIME_SECS / SCREEN_FPS, drive, 0);
//         return;
//     }

//     // Check if we reached the destination
//     if (current.getType() == DEST) {
//         pathFound = true;
//         isSearchDone = true;
//         reconstructPath();
//         return;
//     }

//     // Mark as visited
//     mapn[current.getGridPositionX()][current.getGridPositionY()].visited = true;
//     if (current.getType() != SOURCE && current.getType() != DEST) {
//         nodes.at(current.getGridPositionX() * n + current.getGridPositionY()).type = VISITED;
//     }

//     // Explore neighbors (8-directional movement)
//     int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
//     int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//     double dist[] = {dDistance, hVDistance, dDistance, hVDistance, hVDistance, dDistance, hVDistance, dDistance};

//     for (int i = 0; i < 8; ++i) {
//         int nx = current.getGridPositionX() + dx[i];
//         int ny = current.getGridPositionY() + dy[i];

//         if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
//             Node& neighbor = mapn[nx][ny];
//             if (!neighbor.visited && neighbor.getType() != WALL) {
//                 double newDist = current.distance + dist[i];
//                 if (newDist < neighbor.distance) {
//                     neighbor.distance = newDist;
//                     neighbor.parent = SPoint(current.getGridPositionX(), current.getGridPositionY());
//                     nQueue.push(neighbor);
//                 }
//             }
//         }
//     }
    
//     glutPostRedisplay();
//     glutTimerFunc(TIME_SECS / SCREEN_FPS, drive, 0);
// }

// void findPath() {
//     bool hasSource = false;
//     bool hasDest = false;
//     for (size_t i = 0; i < nodes.size(); i++) {
//         if (nodes.at(i).type == SOURCE) hasSource = true;
//         if (nodes.at(i).type == DEST) hasDest = true;
//     }
//     if (!hasSource || !hasDest) {
//         return;
//     }
    
//     canAcceptInput = false;
//     isDestinationBlocked = false;
//     isSearchDone = false;
//     pathFound = false;

//     // Clear previous search results
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             int index = i * n + j;
//             if (nodes.at(index).type == VISITED || nodes.at(index).type == CHECKED || nodes.at(index).type == PATH) {
//                 nodes.at(index).type = EMPTY;
//             }
//         }
//     }

//     makeReady();
//     drive(0);
// }

// void drawMinus(int x, int y) {
//     glColor3f(1.0, 1.0, 1.0);
//     glLineWidth(3.0);
//     glBegin(GL_LINES);
//     glVertex2f(x + 0.2, y + 0.2);
//     glVertex2f(x + 0.8, y + 0.8);
//     glVertex2f(x + 0.2, y + 0.8);
//     glVertex2f(x + 0.8, y + 0.2);
//     glEnd();
// }

// void renderString(float x, float y, const char* string) {
//     glRasterPos2f(x, y);
//     for (int i = 0; string[i] != '\0'; i++) {
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
//     }
// }

// void drawString(float x, float y, float z, const char* string) {
//     glRasterPos3f(x, y, z);
//     for (const char* c = string; *c != '\0'; c++) {
//         glColor3f(1, 1, 1);
//         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
//     }
// }

// float findBitmapMidPoint(const char* str) {
//     return ((n / 2) - (strlen(str) / 2) * 8.76 / 31);
// }

// void showStartPage() {
//     glClearColor(0.2, 0.1, 0.4, 1.0);
//     char collegeName[64] = "INDIAN INSTITUTE OF TECHNOLOGY GUWAHATI";
//     char dept[40] = "Department of Chemical Engineering";
//     char proj[21] = "OpenGL Mini Project";
//     char title[23] = "Pathfinding Visualizer";
//     char instrc[43] = "Instructions";
//     char text1[21] = "Press Enter To Start";
//     char text2[28] = "Press 'r' or 'R' to Restart";
//     char text3[38] = "Press 's' or 'S' to Start Visualizing";
//     char text4[64] = "Press Left Mouse to place Nodes and Right Mouse to remove Nodes";
//     char text5[35] = "Press <ESC KEY> to quit the window";
//     char text6[13] = "Created By:";
//     char text7[23] = "Anuj Tyagi";
    
//     drawString(findBitmapMidPoint(collegeName), 3, 0.0, collegeName);
//     drawString(findBitmapMidPoint(dept), 6, 0.0, dept);
//     drawString(findBitmapMidPoint(proj), 8, 0.0, proj);
//     drawString(findBitmapMidPoint(title), 13, 0.0, title);
//     drawString(findBitmapMidPoint(instrc), 16, 0.0, instrc);
//     drawString(findBitmapMidPoint(text1), 18, 0.0, text1);
//     drawString(findBitmapMidPoint(text2), 19, 0.0, text2);
//     drawString(findBitmapMidPoint(text3), 20, 0.0, text3);
//     drawString(findBitmapMidPoint(text4), 21, 0.0, text4);
//     drawString(findBitmapMidPoint(text5), 22, 0.0, text5);
//     drawString(n - 10, n - 5, 0.0, text6);
//     drawString(n - 10, n - 3, 0.0, text7);
// }

// void display(void) {
//     glClearColor(0.0, 0.0, 0.0, 1.0);
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//     glLoadIdentity();

//     if (isOnStartPage) {
//         showStartPage();
//     } else {
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 Node& curr = nodes[i * n + j];
//                 switch (curr.getType()) {
//                 case SOURCE:
//                     drawCell(i, j, 0.258, 0.031, 0.388);
//                     break;
//                 case DEST:
//                     drawCell(i, j, 0.772, 0.447, 1.0);
//                     break;
//                 case WALL:
//                     drawCell(i, j, 1.0, 0.0, 0.0);
//                     drawMinus(i, j);
//                     break;
//                 case VISITED:
//                     drawCell(i, j, 0.0, 1.0, 1.0); // Cyan for visited nodes
//                     break;
//                 case CHECKED:
//                     drawCell(i, j, 1.0, 0.0, 1.0); // Purple for checked nodes
//                     break;
//                 case PATH:
//                     drawCell(i, j, 1.0, 1.0, 0.0); // Yellow for path
//                     break;
//                 case EMPTY:
//                     drawCell(i, j, DULL, DULL, DULL);
//                     break;
//                 }
//             }
//         }

//         if (isDestinationBlocked) {
//             if (flashColor) {
//                 promptRestart();
//             }
//         }
//         if (pathFound) {
//             glColor3f(0.0, 1.0, 0.0);
//             renderString(10, 30, "PATH FOUND!");
//         }
//     }

//     glutSwapBuffers();
// }

// void onMouseMovement(int x, int y) {
//     if (canAcceptInput && !isDestinationBlocked) {
//         if (isMouseLeftDown == 1) {
//             addPoints(x, y);
//             glutPostRedisplay();
//         }
//         if (isMouseRightDown == 1) {
//             removePoints(x, y);
//             glutPostRedisplay();
//         }
//     }
// }

// void resize(int w, int h) {
//     screenWidth = w;
//     screenHeight = h;
//     glViewport(0, 0, w, h);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     glOrtho(0.0, n, n, 0.0, -1.0, 1.0);
// }

// void reset() {
//     flag = 0;
//     isDestinationBlocked = false;
//     isSearchDone = false;
//     canAcceptInput = true;
//     pathFound = false;
//     flashColor = false;
    
//     glutIdleFunc(NULL);
//     glutTimerFunc(0, flashMessage, 0);
//     glutPostRedisplay();

//     nodes.clear();
//     nodes.shrink_to_fit();
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             Node node = Node(i, j, EMPTY, INF);
//             nodes.push_back(node);
//         }
//     }
//     startEndNodes = 0;

//     while (!nQueue.empty()) nQueue.pop();
//     path.clear();
//     start = nullptr;
//     endn = nullptr;
//     memset(mapn, 0, sizeof(mapn));

//     glutPostRedisplay();
// }

// void onKeyPress(unsigned char key, int x, int y) {
//     switch (key) {
//     case 27:
//         exit(0);
//         break;
//     case 115:
//     case 'S':
//         if (canAcceptInput && !isDestinationBlocked) {
//             bool hasSource = false;
//             bool hasDest = false;
//             for (const auto& node : nodes) {
//                 if (node.getType() == SOURCE) hasSource = true;
//                 if (node.getType() == DEST) hasDest = true;
//             }
//             if (hasSource && hasDest) {
//                 findPath();
//             }
//         }
//         break;
//     case 114:
//     case 'R':
//         reset();
//         break;
//     case 13:
//         isOnStartPage = false;
//         glutPostRedisplay();
//         break;
//     }
// }

// int main(int argc, char** argv) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             Node node = Node(i, j, EMPTY, INF);
//             nodes.push_back(node);
//         }
//     }
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//     glutInitWindowPosition(50, 50);
//     glutInitWindowSize(750, 750);
//     glutCreateWindow("Pathfinding Visualizer");
//     // glutFullScreen(); // Comment out fullscreen for testing
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     glOrtho(0.0, n, n, 0.0, -1.0, 1.0);
//     glutDisplayFunc(display);
//     glutMouseFunc(handleMouse);
//     glutReshapeFunc(resize);
//     glutMotionFunc(onMouseMovement);
//     glutKeyboardFunc(onKeyPress);
//     glutMainLoop();
//     return 0;
// }

#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
const int n = 40;

int INF = 9999;
#define SOURCE 1024
#define DEST 2024
#define WALL 3024
#define EMPTY 4024
#define CHECKED 5024
#define FOUND 6024
#define NOTFOUND 7024
#define PATH 8024

float screenWidth = 750;
float screenHeight = 750;
int clickCount = 0;
int prevX, prevY;
int isMouseLeftDown = 0;
int isMouseRightDown = 0;
int startEndNodes = 0; // 0: no nodes, 1: source set, 2: source and dest set (then walls)
double hVDistance = 1.0;
double dDistance = 1.4;
const int TIME_SECS = 1000;
const int SCREEN_FPS = 60;
bool canAcceptInput = true;
int flag = 0; // Flag to indicate if destination is found (1) or not (0)
bool isOnStartPage = true;

// New globals for flashing message
bool isDestinationBlocked = false;
bool flashColor = false; // Toggles for flashing effect

class SPoint {
public:
    int x = -1;
    int y = -1;
    SPoint(void) {

    }

    SPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }

};

class Node {
public:
    int gridx = -1;
    int gridy = -1;
    double distance = INF;
    int type = -1;
    bool visited = false;
    SPoint parent = SPoint(-1, -1);
    Node(void) {

    }

    Node(int x, int y) {
        this->gridx = x;
        this->gridy = y;
    }

    Node(int x, int y, int type, bool visited, int distance = INF) {
        this->gridx = x;
        this->gridy = y;
        this->type = type;
        this->distance = distance;
        this->visited = visited;
    }

    int getType() {
        return this->type;
    }

    int getGridPositionX() {
        return this->gridx;
    }
    int getGridPositionY() {
        return this->gridy;
    }

    int getDistance() {
        return this->distance;
    }

    bool isEqual(Node s, Node d) {
        if (s.getGridPositionX() == d.getGridPositionX() && s.getGridPositionY() == d.getGridPositionY()) {
            return true;
        }
        return false;
    }
};

bool operator<(const Node& n1, const Node& n2) {
    return n1.distance > n2.distance;
}

vector<Node> nodes;
priority_queue<Node> nQueue;
Node mapn[n][n];
Node* start = nullptr;
Node* endn = nullptr;
vector<SPoint> path;

void reset();
void flashMessage(int value) {
    if (isDestinationBlocked) {
        flashColor = !flashColor;
        glutPostRedisplay();
        glutTimerFunc(300, flashMessage, 0);
    }
}

void drawCharacterAtGrid(int gridX, int gridY, char character, float r, float g, float b) {
    glColor3f(r, g, b);
    glRasterPos2f(gridX + 0.25, gridY + 0.75);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, character);
}

void clicked(int i, int j, int type) {
    if (type != EMPTY) {
        float dif = 0.1;
        glBegin(GL_POLYGON);
        if (type == SOURCE) {
            glColor3f(0.258, 0.031, 0.388);
            dif = -0.1;
        } else if (type == DEST) {
            glColor3f(0.772, 0.447, 1);
            dif = -0.1;
        } else if (type == WALL) {
            glColor3f(1.0, 0.0, 0.0);
            dif = 0.05;
        } else if (type == CHECKED) {
            glColor3f(0.250, 0.807, 0.890);
            dif = 0.08;
        } else if (type == PATH) {
            glColor3f(1, 0.996, 0.415);
            dif = 0.0;
        }
        glVertex2f(i + dif, j + dif);
        glVertex2f(i + dif, j - dif + 1);
        glVertex2f(i - dif + 1, j - dif + 1);
        glVertex2f(i - dif + 1, j + dif);
        glEnd();

        if (type == WALL) {
            drawCharacterAtGrid(i, j, 'X', 0.0, 0.0, 0.0);
        }
    }
}

void reDrawPoints() {
    for (size_t i = 0; i < nodes.size(); i++) {
        int x = nodes[i].getGridPositionX();
        int y = nodes[i].getGridPositionY();
        clicked(x, y, nodes[i].getType());
    }
}

bool hasNodePlaced(Node n) {
    int type = n.getType();
    return (type == PATH || type == SOURCE || type == DEST || type == WALL || type == CHECKED);
}

void addPoints(int x, int y) {
    int posx = x / (screenWidth / n);
    int posy = y / (screenHeight / n);

    for (size_t i = 0; i < nodes.size(); i++) {
        int nodex = nodes.at(i).getGridPositionX();
        int nodey = nodes.at(i).getGridPositionY();

        if (nodex == posx && nodey == posy && nodes.at(i).getType() == EMPTY) {
            if (startEndNodes == 0) {
                nodes.at(i) = Node(posx, posy, SOURCE, true, 0);
                startEndNodes = 1;
            } else if (startEndNodes == 1) {
                nodes.at(i) = Node(posx, posy, DEST, false, INF);
                startEndNodes = 2;
            } else {
                nodes.at(i) = Node(posx, posy, WALL, false, INF);
                startEndNodes++;
            }
            break;
        }
    }
}

void removePoints(int x, int y) {
    int posx = x / (screenWidth / n);
    int posy = y / (screenHeight / n);
    for (size_t i = 0; i < nodes.size(); i++) {
        int nodex = nodes.at(i).getGridPositionX();
        int nodey = nodes.at(i).getGridPositionY();
        if (nodex == posx && nodey == posy) {
            int oldType = nodes.at(i).getType();
            if (oldType == SOURCE) startEndNodes = 0;
            else if (oldType == DEST) startEndNodes = 1;
            else if (oldType == WALL) startEndNodes--;

            nodes.at(i) = Node(posx, posy, EMPTY, false, INF);
            break;
        }
    }
}

void handleMouse(int button, int state, int x, int y) {
    if (canAcceptInput && !isDestinationBlocked) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            isMouseLeftDown = 0;
            addPoints(x, y);
        } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            isMouseLeftDown = 1;
        } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
            isMouseRightDown = 0;
            removePoints(x, y);
        } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
            isMouseRightDown = 1;
        }
        glutPostRedisplay();
    }
}

void makeReady() {
    memset(mapn, 0, sizeof(mapn));
    start = nullptr;
    endn = nullptr;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int current_index = i * n + j;
            mapn[i][j] = nodes.at(current_index);
            if (nodes.at(current_index).getType() == SOURCE) {
                start = &mapn[i][j];
                mapn[i][j].distance = 0;
            } else if (nodes.at(current_index).getType() == DEST) {
                endn = &mapn[i][j];
            }
        }
    }

    // This part is crucial: we must re-populate the priority queue on every new run.
    while (!nQueue.empty()) nQueue.pop(); // Clear any old queue data
    if (start != nullptr) {
        nQueue.push(*start);
    }
}

void showPath(int value) {
    if (endn != nullptr && mapn[endn->getGridPositionX()][endn->getGridPositionY()].distance != INF) {
        Node current = mapn[endn->getGridPositionX()][endn->getGridPositionY()];
        while (current.type != SOURCE && current.parent.x != -1 && current.parent.y != -1) {
            current = mapn[current.parent.x][current.parent.y];
            if (current.type != start->type) {
                nodes.at(current.getGridPositionX() * n + current.getGridPositionY()).type = PATH;
            }
        }
        glutPostRedisplay();
    }
    canAcceptInput = true;
}

void drive(int value) {
    if (flag == 1) return;

    if (!nQueue.empty()) {
        Node current = nQueue.top();
        nQueue.pop();
        
        // This check is very important for Dijkstra with a priority queue
        if (current.distance > mapn[current.getGridPositionX()][current.getGridPositionY()].distance) {
            glutTimerFunc(TIME_SECS / SCREEN_FPS, drive, 0);
            return;
        }

        if (current.getType() == DEST) {
            flag = 1;
            mapn[current.getGridPositionX()][current.getGridPositionY()].distance = current.distance;
            // The showPath function will handle visualization
            showPath(1);
            return;
        }

        mapn[current.getGridPositionX()][current.getGridPositionY()].visited = true;
        if (current.getType() != SOURCE && current.getType() != DEST) {
            nodes.at(current.getGridPositionX() * n + current.getGridPositionY()).type = CHECKED;
        }

        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        double dist[] = {dDistance, hVDistance, dDistance, hVDistance, hVDistance, dDistance, hVDistance, dDistance};

        for (int i = 0; i < 8; ++i) {
            int nx = current.getGridPositionX() + dx[i];
            int ny = current.getGridPositionY() + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                Node& neighbor = mapn[nx][ny];

                if (!neighbor.visited && neighbor.getType() != WALL) {
                    double newDist = current.distance + dist[i];
                    if (newDist < neighbor.distance) {
                        neighbor.distance = newDist;
                        neighbor.parent.x = current.getGridPositionX();
                        neighbor.parent.y = current.getGridPositionY();
                        nQueue.push(neighbor);
                    }
                }
            }
        }

        glutPostRedisplay();
        glutTimerFunc(TIME_SECS / SCREEN_FPS, drive, 0);
    } else {
        // This is the core logic to check for unreachability
        canAcceptInput = true;
        if (endn != nullptr && mapn[endn->getGridPositionX()][endn->getGridPositionY()].distance == INF) {
            isDestinationBlocked = true;
            canAcceptInput = false;
            glutTimerFunc(300, flashMessage, 0);
            glutPostRedisplay();
        }
    }
}

void findPath() {
    bool hasSource = false;
    bool hasDest = false;
    for (size_t i = 0; i < nodes.size(); i++) {
        if (nodes.at(i).type == SOURCE) hasSource = true;
        if (nodes.at(i).type == DEST) hasDest = true;
    }
    if (!hasSource || !hasDest) {
        return;
    }
    canAcceptInput = false;
    isDestinationBlocked = false;
    flag = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int index = i * n + j;
            if (nodes.at(index).type == CHECKED || nodes.at(index).type == PATH) {
                nodes.at(index).type = EMPTY;
            }
            nodes.at(index).distance = INF;
            nodes.at(index).visited = false;
            nodes.at(index).parent.x = -1;
            nodes.at(index).parent.y = -1;
        }
    }
    
    // Set start node properties
    for(size_t i=0; i < nodes.size(); ++i){
        if(nodes.at(i).type == SOURCE){
            nodes.at(i).distance = 0;
            break;
        }
    }

    makeReady();
    drive(nQueue.size());
}

void drawString(float x, float y, float z, const char* string) {
    glRasterPos3f(x, y, z);
    for (const char* c = string; *c != '\0'; c++) {
        glColor3f(1, 1, 1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

float findBitmapMidPoint(const char* str) {
    return ((n / 2) - (strlen(str) / 2) * 8.76 / 31);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (isOnStartPage) {
        glClearColor(0.2, 0.1, 0.4, 1.0);
        // ... (rest of start page content) ...
        char collegeName[64] = "INDIAN INSTITUTE OF TECHNOLOGY GUWAHATI";
        char dept[40] = "Department of Chemical Engineering";
        char proj[21] = "OpenGL Mini Project";
        char title[23] = "Pathfinding Visualizer";
        char instrc[43] = "Instructions";
        char text1[21] = "Press Enter To Start";
        char text2[28] = "Press 'r' or 'R' to Restart";
        char text3[38] = "Press 's' or 'S' to Start Visualizing";
        char text4[64] = "Press Left Mouse to place Nodes and Right Mouse to remove Nodes";
        char text5[35] = "Press <ESC KEY> to quit the window";
        char text6[13] = "Created By:";
        char text7[23] = "Anuj Tyagi";
        char text8[23] = "";
        drawString(findBitmapMidPoint(collegeName), 3, 0.0, collegeName);
        drawString(findBitmapMidPoint(dept), 6, 0.0, dept);
        drawString(findBitmapMidPoint(proj), 8, 0.0, proj);
        drawString(findBitmapMidPoint(title), 13, 0.0, title);
        drawString(findBitmapMidPoint(instrc), 16, 0.0, instrc);
        drawString(findBitmapMidPoint(text1), 18, 0.0, text1);
        drawString(findBitmapMidPoint(text2), 19, 0.0, text2);
        drawString(findBitmapMidPoint(text3), 20, 0.0, text3);
        drawString(findBitmapMidPoint(text4), 21, 0.0, text4);
        drawString(findBitmapMidPoint(text5), 22, 0.0, text5);
        drawString(n - 10, n - 5, 0.0, text6);
        drawString(n - 10, n - 3, 0.0, text7);

    } else {
        glClearColor(0.964, 0.964, 0.964, 1.0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                glLineWidth(1);
                glColor3f(0.686, 0.847, 0.972);
                glBegin(GL_LINE_LOOP);
                glVertex2f(i, j);
                glVertex2f(i, j + 1);
                glVertex2f(i + 1, j + 1);
                glVertex2f(i + 1, j);
                glEnd();
            }
        }
        reDrawPoints();

        if (isDestinationBlocked) {
            if (flashColor) {
                glColor3f(1.0, 0.0, 0.0);
            } else {
                glColor3f(0.964, 0.964, 0.964);
            }
            char blockedMessage[] = "DESTINATION UNREACHABLE! Press 'R' to Restart.";
            drawString(findBitmapMidPoint(blockedMessage), n / 2.0 - 1, 0.0, blockedMessage);
        }
    }
    glutSwapBuffers();
}

void onMouseMovement(int x, int y) {
    if (canAcceptInput && !isDestinationBlocked) {
        if (isMouseLeftDown == 1 && nodes.size() > 1) {
            addPoints(x, y);
            glutPostRedisplay();
        }
        if (isMouseRightDown == 1 && nodes.size() > 1) {
            removePoints(x, y);
            glutPostRedisplay();
        }
    }
}

void resize(int w, int h) {
    screenWidth = w;
    screenHeight = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, n, n, 0.0, -1.0, 1.0);
}

void reset() {
    flag = 0;
    isDestinationBlocked = false;
    glutIdleFunc(NULL);
    glutTimerFunc(0, flashMessage, 0);
    glutPostRedisplay();

    nodes.clear();
    nodes.shrink_to_fit();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Node node = Node(i, j, EMPTY, false, INF);
            nodes.push_back(node);
        }
    }
    startEndNodes = 0;

    while (!nQueue.empty()) {
        nQueue.pop();
    }
    path.clear();
    start = nullptr;
    endn = nullptr;

    canAcceptInput = true;
    glutPostRedisplay();
}

void onKeyPress(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
        exit(0);
        break;
    case 115:
    case 'S':
        if (canAcceptInput && !isDestinationBlocked) {
            bool hasSource = false;
            bool hasDest = false;
            for (size_t i = 0; i < nodes.size(); i++) {
                if (nodes.at(i).type == SOURCE) hasSource = true;
                if (nodes.at(i).type == DEST) hasDest = true;
            }
            if (hasSource && hasDest) {
                findPath();
            }
        }
        break;
    case 114:
    case 'R':
        reset();
        break;
    case 13:
        isOnStartPage = false;
        glutPostRedisplay();
        break;
    }
}

int main(int argc, char** argv) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Node node = Node(i, j, EMPTY, false, INF);
            nodes.push_back(node);
        }
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Pathfinding Visualizer");
    glutFullScreen();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, n, n, 0.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMouseFunc(handleMouse);
    glutReshapeFunc(resize);
    glutMotionFunc(onMouseMovement);
    glutKeyboardFunc(onKeyPress);
    glutMainLoop();
    return 0;
}