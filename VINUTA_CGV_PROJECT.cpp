#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define GRAPHSIZE 10
#define INFINITY GRAPHSIZE*GRAPHSIZE
#define MAX(a, b) ((a > b) ? (a) : (b))

int n = 5;
long dist[GRAPHSIZE][GRAPHSIZE];
int prev[GRAPHSIZE];

long d[GRAPHSIZE];
int dummypath[GRAPHSIZE];
int path[GRAPHSIZE];
int getPath[GRAPHSIZE];
long getDistance[GRAPHSIZE][GRAPHSIZE];
float x = 0, y = 0;
float m[GRAPHSIZE][GRAPHSIZE] = {
    {
        0,
        1.33,
        0.56,
        -1.33,
        -0.55
    },
    {
        1.33,
        0,
        0,
        -10.6,
        -1.76
    },
    {
        0.56,
        -0.25,
        0,
        1.76,
        -10.6
    },
    {-1.33,
        -10.6,
        1.76,
        0,
        0
    },
    {-0.55,
        -1.76,
        -10.6,
        0.15,
        0
    }
};

int i = 0, j = 0, k = 0;
int a, b, flag = 0;

void destpath(int g) {
    int i, j, w;
    i = 0;
    j = n;
    w = g;
    while (j != 0) {

        if (prev[w] != -1) {
            dummypath[i] = prev[w];
            w = dummypath[i];
            i++;
        }
        j--;
    }
    j = 0;
    i--;
    while (i != -1) {
        path[j] = dummypath[i];
        i--;
        j++;
    }
    path[j] = g;
}

void dijkstra(int s) {
    int i, k, mini;
    int visited[GRAPHSIZE];

    for (i = 1; i <= n; ++i) {
        d[i] = INFINITY;
        prev[i] = -1;
        visited[i] = 0;
        dummypath[i] = -1;
    }

    d[s] = 0;

    for (k = 1; k <= n; ++k) {
        mini = -1;
        for (i = 1; i <= n; ++i)
            if (!visited[i] && ((mini == -1) || (d[i] < d[mini])))
                mini = i;

        visited[mini] = 1;

        for (i = 1; i <= n; ++i)
            if (dist[mini][i]) {
                if (d[mini] + dist[mini][i] < d[i]) {
                    d[i] = d[mini] + dist[mini][i];
                    prev[i] = mini;
                }
            }
    }
}
void callPath(int a, int b) {
    int i, j, k;
    int u, v, w, dest, src;

    src = a;
    dest = b;

    dijkstra(src);

    destpath(dest);

    k = 0;
    while (path[k] != '\0') {
        getPath[k] = path[k];
        k++;
    }

}
void distanceMatrix() {
    int i, j;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            dist[i][j] = 0;

    n = 5;
    dist[1][2] = 10;
    dist[1][4] = 5;
    dist[2][3] = 1;
    dist[2][4] = 3;
    dist[3][5] = 6;
    dist[4][2] = 2;
    dist[4][3] = 9;
    dist[4][5] = 2;
    dist[5][1] = 7;
    dist[5][3] = 4;

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            getDistance[i][j] = dist[i][j];
}
void rev(char s[]) {
    int i, j;
    char c;

    for (i = 0; j = strlen(s) - 1, i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
void my_itoa(int n, char s[]) {
    int i, sign;

    if ((sign == n) < 0)
        n = -n;

    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    rev(s);
}

void drawString(float x, float y, float z, char * string) {
    char * c;
    glRasterPos3f(x, y, z);
    for (c = string; * c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, * c);
    }
}
void drawString1(float x, float y, float z, char * string) {
    char * c;
    glRasterPos3f(x, y, z);
    for (c = string; * c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, * c);
    }
}
void drawString2(float x, float y, float z, char * string) {
    char * c;
    glRasterPos3f(x, y, z);
    for (c = string; * c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, * c);
    }
}
void delay() {
    int bx, ax;
    bx = 100;
    label1: ax = 2000;
    label2: ax--;
    if (ax != 0) {
        goto label2;
    }
    bx--;
    if (bx != 0) {
        goto label1;
    }
}
void getCube1() {
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(25, 225, 0);
    glVertex3f(25, 265, 0);
    glVertex3f(75, 265, 0);
    glVertex3f(75, 225, 0);
    glVertex3f(25, 225, 0);
    glVertex3f(75, 225, 0);
    glVertex3f(100, 250, 0);
    glVertex3f(100, 290, 0);
    glVertex3f(50, 290, 0);
    glVertex3f(25, 265, 0);
    glEnd();
    glFlush();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(75, 225, 0);
    glVertex3f(25, 225, 0);
    glVertex3f(25, 265, 0);
    glVertex3f(75, 265, 0);
    glVertex3f(75, 225, 0);
    glVertex3f(100, 250, 0);
    glVertex3f(100, 290, 0);
    glVertex3f(50, 290, 0);
    glVertex3f(25, 265, 0);
    glVertex3f(75, 265, 0);
    glVertex3f(100, 290, 0);
    glEnd();
    glFlush();
    glColor3f(0.0, 0.0, 0.0);
    drawString(35, 245, 0, "Node 1");
    glFlush();
}
void getCube2() {
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(125, 430, 0);
    glVertex3f(125, 390, 0);
    glVertex3f(175, 390, 0);
    glVertex3f(175, 430, 0);
    glVertex3f(175, 390, 0);
    glVertex3f(200, 415, 0);
    glVertex3f(200, 455, 0);
    glVertex3f(150, 455, 0);
    glVertex3f(125, 430, 0);
    glEnd();
    glFlush();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(175, 390, 0);
    glVertex3f(125, 390, 0);
    glVertex3f(125, 430, 0);
    glVertex3f(175, 430, 0);
    glVertex3f(175, 390, 0);
    glVertex3f(200, 415, 0);
    glVertex3f(200, 455, 0);
    glVertex3f(150, 455, 0);
    glVertex3f(125, 430, 0);
    glVertex3f(175, 430, 0);
    glVertex3f(200, 455, 0);
    glEnd();
    glFlush();
    glColor3f(0.0, 0.0, 0.0);
    drawString(135, 410, 0, "Node 2");
    glFlush();
}
void getCube3() {
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(300, 430, 0);
    glVertex3f(300, 390, 0);
    glVertex3f(350, 390, 0);
    glVertex3f(350, 430, 0);
    glVertex3f(350, 390, 0);
    glVertex3f(375, 415, 0);
    glVertex3f(375, 455, 0);
    glVertex3f(325, 455, 0);
    glVertex3f(300, 430, 0);
    glEnd();
    glFlush();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(350, 390, 0);
    glVertex3f(300, 390, 0);
    glVertex3f(300, 430, 0);
    glVertex3f(350, 430, 0);
    glVertex3f(350, 390, 0);
    glVertex3f(375, 415, 0);
    glVertex3f(375, 455, 0);
    glVertex3f(325, 455, 0);
    glVertex3f(300, 430, 0);
    glVertex3f(350, 430, 0);
    glVertex3f(375, 455, 0);
    glEnd();
    glFlush();
    glColor3f(0.0, 0.0, 0.0);
    drawString(310, 410, 0, "Node 3");
    glFlush();
}
void getCube4() {

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(125, 100, 0);
    glVertex3f(125, 60, 0);
    glVertex3f(175, 60, 0);
    glVertex3f(175, 100, 0);
    glVertex3f(175, 60, 0);
    glVertex3f(200, 85, 0);
    glVertex3f(200, 125, 0);
    glVertex3f(150, 125, 0);
    glVertex3f(125, 100, 0);
    glEnd();
    glFlush();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(175, 60, 0);
    glVertex3f(125, 60, 0);
    glVertex3f(125, 100, 0);
    glVertex3f(175, 100, 0);
    glVertex3f(175, 60, 0);
    glVertex3f(200, 85, 0);
    glVertex3f(200, 125, 0);
    glVertex3f(150, 125, 0);
    glVertex3f(125, 100, 0);
    glVertex3f(175, 100, 0);
    glVertex3f(200, 125, 0);
    glEnd();
    glFlush();
    glColor3f(0.0, 0.0, 0.0);
    drawString(135, 80, 0, "Node 4");
    glFlush();
}
void getCube5() {
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(300, 100, 0);
    glVertex3f(300, 60, 0);
    glVertex3f(350, 60, 0);
    glVertex3f(350, 100, 0);
    glVertex3f(350, 60, 0);
    glVertex3f(375, 85, 0);
    glVertex3f(375, 125, 0);
    glVertex3f(325, 125, 0);
    glVertex3f(300, 100, 0);
    glEnd();
    glFlush();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(350, 60, 0);
    glVertex3f(300, 60, 0);
    glVertex3f(300, 100, 0);
    glVertex3f(350, 100, 0);
    glVertex3f(350, 60, 0);
    glVertex3f(375, 85, 0);
    glVertex3f(375, 125, 0);
    glVertex3f(325, 125, 0);
    glVertex3f(300, 100, 0);
    glVertex3f(350, 100, 0);
    glVertex3f(375, 125, 0);
    glEnd();
    glFlush();
    glColor3f(0.0, 0.0, 0.0);
    drawString(310, 80, 0, "Node 5");
    glFlush();
}
void drawLine(int x, int y, int w) {
    char z[5];

    my_itoa(w, z);
    switch (x) {
    case 1:
        if (y == 2) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(100, 290);
            glVertex2f(137, 340);
            glVertex2f(132, 340);
            glVertex2f(137, 340);
            glVertex2f(137, 333);
            glVertex2f(137, 340);
            glVertex2f(137, 340);
            glVertex2f(175, 390);
            glEnd();
            glFlush();
            drawString(135, 345, 0, z);
            glFlush();
        } else if (y == 3) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(100, 250);
            glVertex2f(225, 320);
            glVertex2f(220, 322);
            glVertex2f(225, 320);
            glVertex2f(225, 313);
            glVertex2f(225, 320);
            glVertex2f(225, 320);
            glVertex2f(350, 390);
            glEnd();
            glFlush();
            drawString(223, 325, 0, z);
            glFlush();
        } else if (y == 4) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(75, 225);
            glVertex2f(112, 175);
            glVertex2f(107, 175);
            glVertex2f(112, 175);
            glVertex2f(112, 182);
            glVertex2f(112, 175);
            glVertex2f(112, 175);
            glVertex2f(150, 125);
            glEnd();
            glFlush();
            drawString(108, 182, 0, z);
            glFlush();
        } else {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(75, 225);
            glVertex2f(187, 162);
            glVertex2f(187, 169);
            glVertex2f(187, 162);
            glVertex2f(182, 162);
            glVertex2f(187, 162);
            glVertex2f(187, 162);
            glVertex2f(300, 100);
            glEnd();
            glFlush();
            drawString(185, 167, 0, z);
            glFlush();
        }
        break;

    case 2:
        if (y == 1) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(125, 390);
            glVertex2f(87, 340);
            glVertex2f(92, 340);
            glVertex2f(87, 340);
            glVertex2f(87, 347);
            glVertex2f(87, 340);
            glVertex2f(87, 340);
            glVertex2f(50, 290);
            glEnd();
            glFlush();
            drawString(83, 345, 0, z);
            glFlush();
        } else if (y == 3) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(200, 455);
            glVertex2f(262, 455);
            glVertex2f(258, 460);
            glVertex2f(262, 455);
            glVertex2f(258, 450);
            glVertex2f(262, 455);
            glVertex2f(262, 455);
            glVertex2f(325, 455);
            glEnd();
            glFlush();
            drawString(260, 460, 0, z);
            glFlush();
        } else if (y == 4) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(125, 390);
            glVertex2f(137, 257);
            glVertex2f(133, 262);
            glVertex2f(137, 257);
            glVertex2f(141, 262);
            glVertex2f(137, 257);
            glVertex2f(137, 257);
            glVertex2f(150, 125);
            glEnd();
            glFlush();
            drawString(130, 262, 0, z);
            glFlush();
        } else {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(175, 390);
            glVertex2f(250, 257);
            glVertex2f(245, 257);
            glVertex2f(250, 257);
            glVertex2f(250, 263);
            glVertex2f(250, 257);
            glVertex2f(250, 257);
            glVertex2f(325, 125);
            glEnd();
            glFlush();
            drawString(248, 246, 0, z);
            glFlush();
        }
        break;

    case 3:
        if (y == 1) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(300, 390);
            glVertex2f(200, 340);
            glVertex2f(202, 348);
            glVertex2f(200, 340);
            glVertex2f(205, 336);
            glVertex2f(200, 340);
            glVertex2f(200, 340);
            glVertex2f(100, 290);
            glEnd();
            glFlush();
            drawString(204, 345, 0, z);
            glFlush();
        } else if (y == 2) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(300, 390);
            glVertex2f(250, 402);
            glVertex2f(255, 408);
            glVertex2f(250, 402);
            glVertex2f(252, 394);
            glVertex2f(250, 402);
            glVertex2f(250, 402);
            glVertex2f(200, 415);
            glEnd();
            glFlush();
            drawString(248, 407, 0, z);
            glFlush();
        } else if (y == 4) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(300, 390);
            glVertex2f(225, 257);
            glVertex2f(225, 265);
            glVertex2f(225, 257);
            glVertex2f(230, 257);
            glVertex2f(225, 257);
            glVertex2f(225, 257);
            glVertex2f(150, 125);
            glEnd();
            glFlush();
            drawString(232, 260, 0, z);
            glFlush();
        } else {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(300, 390);
            glVertex2f(312, 257);
            glVertex2f(316, 262);
            glVertex2f(312, 257);
            glVertex2f(308, 262);
            glVertex2f(312, 257);
            glVertex2f(312, 257);
            glVertex2f(325, 125);
            glEnd();
            glFlush();
            drawString(315, 262, 0, z);
            glFlush();
        }
        break;

    case 4:
        if (y == 1) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(125, 100);
            glVertex2f(75, 162);
            glVertex2f(80, 162);
            glVertex2f(75, 162);
            glVertex2f(75, 155);
            glVertex2f(75, 162);
            glVertex2f(75, 162);
            glVertex2f(25, 225);
            glEnd();
            glFlush();
            drawString(73, 167, 0, z);
            glFlush();
        } else if (y == 2) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(200, 125);
            glVertex2f(187, 257);
            glVertex2f(191, 253);
            glVertex2f(187, 257);
            glVertex2f(183, 252);
            glVertex2f(187, 257);
            glVertex2f(187, 257);
            glVertex2f(175, 390);
            glEnd();
            glFlush();
            drawString(180, 262, 0, z);
            glFlush();
        } else if (y == 3) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(200, 125);
            glVertex2f(275, 257);
            glVertex2f(270, 257);
            glVertex2f(275, 257);
            glVertex2f(275, 250);
            glVertex2f(275, 257);
            glVertex2f(275, 257);
            glVertex2f(350, 390);
            glEnd();
            glFlush();
            drawString(273, 262, 0, z);
            glFlush();
        } else {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(175, 60);
            glVertex2f(237, 60);
            glVertex2f(233, 65);
            glVertex2f(237, 60);
            glVertex2f(233, 55);
            glVertex2f(237, 60);
            glVertex2f(237, 60);
            glVertex2f(300, 60);
            glEnd();
            glFlush();
            drawString(235, 65, 0, z);
            glFlush();
        }
        break;

    case 5:
        if (y == 1) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(325, 125);
            glVertex2f(212, 187);
            glVertex2f(217, 189);
            glVertex2f(212, 187);
            glVertex2f(212, 180);
            glVertex2f(212, 187);
            glVertex2f(212, 187);
            glVertex2f(100, 250);
            glEnd();
            glFlush();
            drawString(210, 192, 0, z);
            glFlush();
        } else if (y == 2) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(375, 125);
            glVertex2f(287, 270);
            glVertex2f(292, 270);
            glVertex2f(287, 270);
            glVertex2f(287, 263);
            glVertex2f(287, 270);
            glVertex2f(287, 270);
            glVertex2f(200, 415);
            glEnd();
            glFlush();
            drawString(289, 246, 0, z);
            glFlush();
        } else if (y == 3) {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(375, 125);
            glVertex2f(362, 257);
            glVertex2f(366, 252);
            glVertex2f(362, 257);
            glVertex2f(358, 252);
            glVertex2f(362, 257);
            glVertex2f(362, 257);
            glVertex2f(350, 390);
            glEnd();
            glFlush();
            drawString(365, 262, 0, z);
            glFlush();
        } else {
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(300, 100);
            glVertex2f(250, 92);
            glVertex2f(254, 99);
            glVertex2f(250, 92);
            glVertex2f(254, 88);
            glVertex2f(250, 92);
            glVertex2f(250, 92);
            glVertex2f(200, 85);
            glEnd();
            glFlush();
            drawString(247, 94, 0, z);
            glFlush();
        }
        break;
    default:
        break;
    }
    glFlush();
}
void getLines() {
    int i, j, w;

    glLineWidth(1);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (dist[i][j] != 0) {
                w = dist[i][j];

                drawLine(i, j, w);
            }
        }
    }
}
void display2() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    getCube1();
    getCube2();
    getCube3();
    getCube4();
    getCube5();
    getLines();

    glColor3f(0.0, 0.0, 1.0);
    drawString2(385, 235, 0, "Press the E or e to RUN");

    glFlush();
}
void display1() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    drawString1(125, 400, 0, " SIMULATION OF BEST PATH FOR PACKET TRANSFER");
    glLineWidth(5);

    for (i = 0; i < 250; i = i + 25) {
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(125 + i, 390, 0);
        glVertex3f(150 + i, 390, 0);
        glEnd();
        for (j = 0; j <= 100; j++) {
            delay();
        }
        glFlush();
    }
    glFlush();
    for (i = 0; i <= 100; i++) {
        delay();
    }
    for (i = 0; i <= 100; i++) {
        delay();
    }
    for (i = 0; i <= 100; i++) {
        delay();
    }

    glLineWidth(2);
    display2();
}
void getFinalCube1() {
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(25, 225, 0);
    glVertex3f(25, 265, 0);
    glVertex3f(75, 265, 0);
    glVertex3f(75, 225, 0);
    glVertex3f(25, 225, 0);
    glVertex3f(75, 225, 0);
    glVertex3f(100, 250, 0);
    glVertex3f(100, 290, 0);
    glVertex3f(50, 290, 0);
    glVertex3f(25, 265, 0);
    glEnd();
    glFlush();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(75, 225, 0);
    glVertex3f(25, 225, 0);
    glVertex3f(25, 265, 0);
    glVertex3f(75, 265, 0);
    glVertex3f(75, 225, 0);
    glVertex3f(100, 250, 0);
    glVertex3f(100, 290, 0);
    glVertex3f(50, 290, 0);
    glVertex3f(25, 265, 0);
    glVertex3f(75, 265, 0);
    glVertex3f(100, 290, 0);
    glEnd();
    glFlush();
    glColor3f(0.0, 0.0, 0.0);
    drawString(35, 245, 0, "Node 1");
    glFlush();
}
void getFinalCube2() {
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(125, 430, 0);
    glVertex3f(125, 390, 0);
    glVertex3f(175, 390, 0);
    glVertex3f(175, 430, 0);
    glVertex3f(175, 390, 0);
    glVertex3f(200, 415, 0);
    glVertex3f(200, 455, 0);
    glVertex3f(150, 455, 0);
    glVertex3f(125, 430, 0);
    glEnd();
    glFlush();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(175, 390, 0);
    glVertex3f(125, 390, 0);
    glVertex3f(125, 430, 0);
    glVertex3f(175, 430, 0);
    glVertex3f(175, 390, 0);
    glVertex3f(200, 415, 0);
    glVertex3f(200, 455, 0);
    glVertex3f(150, 455, 0);
    glVertex3f(125, 430, 0);
    glVertex3f(175, 430, 0);
    glVertex3f(200, 455, 0);
    glEnd();
    glFlush();
    glColor3f(0.0, 0.0, 0.0);
    drawString(135, 410, 0, "Node 2");
    glFlush();
}
void getFinalCube3() {
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(300, 430, 0);
    glVertex3f(300, 390, 0);
    glVertex3f(350, 390, 0);
    glVertex3f(350, 430, 0);
    glVertex3f(350, 390, 0);
    glVertex3f(375, 415, 0);
    glVertex3f(375, 455, 0);
    glVertex3f(325, 455, 0);
    glVertex3f(300, 430, 0);
    glEnd();
    glFlush();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(350, 390, 0);
    glVertex3f(300, 390, 0);
    glVertex3f(300, 430, 0);
    glVertex3f(350, 430, 0);
    glVertex3f(350, 390, 0);
    glVertex3f(375, 415, 0);
    glVertex3f(375, 455, 0);
    glVertex3f(325, 455, 0);
    glVertex3f(300, 430, 0);
    glVertex3f(350, 430, 0);
    glVertex3f(375, 455, 0);
    glEnd();
    glFlush();
    glColor3f(0.0, 0.0, 0.0);
    drawString(310, 410, 0, "Node 3");
    glFlush();
}
void getFinalCube4() {

    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(125, 100, 0);
    glVertex3f(125, 60, 0);
    glVertex3f(175, 60, 0);
    glVertex3f(175, 100, 0);
    glVertex3f(175, 60, 0);
    glVertex3f(200, 85, 0);
    glVertex3f(200, 125, 0);
    glVertex3f(150, 125, 0);
    glVertex3f(125, 100, 0);
    glEnd();
    glFlush();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(175, 60, 0);
    glVertex3f(125, 60, 0);
    glVertex3f(125, 100, 0);
    glVertex3f(175, 100, 0);
    glVertex3f(175, 60, 0);
    glVertex3f(200, 85, 0);
    glVertex3f(200, 125, 0);
    glVertex3f(150, 125, 0);
    glVertex3f(125, 100, 0);
    glVertex3f(175, 100, 0);
    glVertex3f(200, 125, 0);
    glEnd();
    glFlush();
    glColor3f(0.0, 0.0, 0.0);
    drawString(135, 80, 0, "Node 4");
    glFlush();
}
void getFinalCube5() {
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(300, 100, 0);
    glVertex3f(300, 60, 0);
    glVertex3f(350, 60, 0);
    glVertex3f(350, 100, 0);
    glVertex3f(350, 60, 0);
    glVertex3f(375, 85, 0);
    glVertex3f(375, 125, 0);
    glVertex3f(325, 125, 0);
    glVertex3f(300, 100, 0);
    glEnd();
    glFlush();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(350, 60, 0);
    glVertex3f(300, 60, 0);
    glVertex3f(300, 100, 0);
    glVertex3f(350, 100, 0);
    glVertex3f(350, 60, 0);
    glVertex3f(375, 85, 0);
    glVertex3f(375, 125, 0);
    glVertex3f(325, 125, 0);
    glVertex3f(300, 100, 0);
    glVertex3f(350, 100, 0);
    glVertex3f(375, 125, 0);
    glEnd();
    glFlush();
    glColor3f(0.0, 0.0, 0.0);
    drawString(310, 80, 0, "Node 5");
    glFlush();
}
void display4() {

    if (a == b) {
        if (a == 1) {
            getFinalCube1();
            glColor3f(0.0, 0.0, 1.0);
            drawString(10, 295, 0, "Source");
            drawString(10, 210, 0, "Destination");
            glFlush();
        } else if (a == 2) {
            getFinalCube2();
            glColor3f(0.0, 0.0, 1.0);
            drawString(110, 460, 0, "Source");
            drawString(110, 375, 0, "Destination");
            glFlush();
        } else if (a == 3) {
            getFinalCube3();
            glColor3f(0.0, 0.0, 1.0);
            drawString(285, 460, 0, "Source");
            drawString(285, 375, 0, "Destination");
            glFlush();
        } else if (a == 4) {
            getFinalCube4();
            glColor3f(0.0, 0.0, 1.0);
            drawString(110, 130, 0, "Source");
            drawString(110, 45, 0, "Destination");
            glFlush();
        } else {
            getFinalCube5();
            glColor3f(0.0, 0.0, 1.0);
            drawString(285, 130, 0, "Source");
            drawString(285, 45, 0, "Destination");
            glFlush();
        }
        glFlush();
    } else {
        glColor3f(0.0, 0.0, 1.0);
        if (a == 1)
            drawString(10, 295, 0, "Source");
        else if (a == 2)
            drawString(110, 460, 0, "Source");
        else if (a == 3)
            drawString(285, 460, 0, "Source");
        else if (a == 4)
            drawString(110, 130, 0, "Source");
        else if (a == 5)
            drawString(285, 130, 0, "Source");

        if (b == 1)
            drawString(10, 210, 0, "Destination");
        else if (b == 2)
            drawString(110, 375, 0, "Destination");
        else if (b == 3)
            drawString(285, 375, 0, "Destination");
        else if (b == 4)
            drawString(110, 45, 0, "Destination");
        else if (b == 5)
            drawString(285, 45, 0, "Destination");

        i = 0;
        while (getPath[i + 1] != '\0') {
            if (getPath[i] == 1) {
                getFinalCube1();
                glFlush();
                if (getPath[i + 1] == 2) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 60) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(110 + x, 290 + y, 0);
                        glVertex3f(125 + x, 307.5 + y, 0);
                        glVertex3f(130 + x, 302.5 + y, 0);
                        glVertex3f(115 + x, 285 + y, 0);
                        glVertex3f(110 + x, 290 + y, 0);
                        y = y + 33;
                        x = x + 25;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 100; k++) {
                            delay();
                        }
                        glFlush();
                    }
                    getFinalCube2();
                    glFlush();
                } else if (getPath[i + 1] == 3) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 31) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(112.5 + x, 250 + y, 0);
                        glVertex3f(135 + x, 265 + y, 0);
                        glVertex3f(137.5 + x, 260 + y, 0);
                        glVertex3f(115 + x, 245 + y, 0);
                        glVertex3f(112.5 + x, 250 + y, 0);
                        y = y + 25;
                        x = x + 48;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 100; k++) {
                            delay();
                        }
                        glFlush();
                    }

                    getFinalCube3();
                    glFlush();
                } else if (getPath[i + 1] == 4) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 60) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(65 + x, 220 + y, 0);
                        glVertex3f(80 + x, 200 + y, 0);
                        glVertex3f(75 + x, 195 + y, 0);
                        glVertex3f(60 + x, 215 + y, 0);
                        glVertex3f(65 + x, 220 + y, 0);
                        y = y - 33;
                        x = x + 25;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 300; k++) {
                            delay();
                        }
                        glFlush();
                    }
                    getFinalCube4();
                    glFlush();
                } else {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 40) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(95 + x, 210 + y, 0);
                        glVertex3f(117.5 + x, 197.5 + y, 0);
                        glVertex3f(115 + x, 192.5 + y, 0);
                        glVertex3f(92.5 + x, 205 + y, 0);
                        glVertex3f(95 + x, 210 + y, 0);
                        y = y - 32;
                        x = x + 56;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 300; k++) {
                            delay();
                        }
                        glFlush();
                    }

                    getFinalCube5();
                    glFlush();
                }
                glFlush();
            } else if (getPath[i] == 2) {
                getFinalCube2();
                glFlush();
                if (getPath[i + 1] == 1) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 60) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(120 + x, 375 + y, 0);
                        glVertex3f(125 + x, 370 + y, 0);
                        glVertex3f(110 + x, 350 + y, 0);
                        glVertex3f(105 + x, 355 + y, 0);
                        glVertex3f(120 + x, 375 + y, 0);
                        y = y - 25;
                        x = x - 18;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 100; k++) {
                            delay();
                        }
                        glFlush();
                    }
                    getFinalCube1();
                    glFlush();
                } else if (getPath[i + 1] == 3) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 50) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(212.5 + x, 445 + y, 0);
                        glVertex3f(237.5 + x, 445 + y, 0);
                        glVertex3f(237.5 + x, 438 + y, 0);
                        glVertex3f(212.5 + x, 438 + y, 0);
                        glVertex3f(212.5 + x, 445 + y, 0);
                        y = y;
                        x = x + 30;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 300; k++) {
                            delay();
                        }
                        glFlush();
                    }
                    getFinalCube3();
                    glFlush();
                } else if (getPath[i + 1] == 4) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 35) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(135 + x, 380 + y, 0);
                        glVertex3f(137.5 + x, 355 + y, 0);
                        glVertex3f(142.5 + x, 359 + y, 0);
                        glVertex3f(140 + x, 383.5 + y, 0);
                        glVertex3f(135 + x, 380 + y, 0);
                        y = y - 70;
                        x = x + 5;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 300; k++) {
                            delay();
                        }
                        glFlush();
                    }
                    getFinalCube4();

                    glFlush();
                } else {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 31) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(182.5 + x, 367.5 + y, 0);
                        glVertex3f(195 + x, 345 + y, 0);
                        glVertex3f(190 + x, 342.5 + y, 0);
                        glVertex3f(177.5 + x, 365 + y, 0);
                        glVertex3f(182.5 + x, 367.5 + y, 0);
                        y = y - 66;
                        x = x + 37;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 100; k++) {
                            delay();
                        }
                        glFlush();
                    }
                    getFinalCube5();
                    glFlush();
                }
                glFlush();
            } else if (getPath[i] == 3) {
                getFinalCube3();
                glFlush();
                if (getPath[i + 1] == 1) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 31) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(297.5 + x, 382.5 + y, 0);
                        glVertex3f(275 + x, 372.5 + y, 0);
                        glVertex3f(277.5 + x, 367.5 + y, 0);
                        glVertex3f(300 + x, 377.5 + y, 0);
                        glVertex3f(297.5 + x, 382.5 + y, 0);
                        y = y - 25;
                        x = x - 50;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 100; k++) {
                            delay();
                        }
                        glFlush();
                    }
                    getFinalCube1();
                    glFlush();
                } else if (getPath[i + 1] == 2) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 60) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(290 + x, 385 + y, 0);
                        glVertex3f(287.5 + x, 380 + y, 0);
                        glVertex3f(265 + x, 387.5 + y, 0);
                        glVertex3f(267.5 + x, 392.5 + y, 0);
                        glVertex3f(290 + x, 385 + y, 0);
                        y = y + 6.25;
                        x = x - 30;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 100; k++) {
                            delay();
                        }
                        glFlush();
                    }
                    getFinalCube2();
                    glFlush();
                } else if (getPath[i + 1] == 4) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 31) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(295 + x, 372.5 + y, 0);
                        glVertex3f(282.5 + x, 350 + y, 0);
                        glVertex3f(287.5 + x, 347.5 + y, 0);
                        glVertex3f(300 + x, 370 + y, 0);
                        glVertex3f(295 + x, 372.5 + y, 0);
                        y = y - 66.25;
                        x = x - 37.5;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 100; k++) {
                            delay();
                        }
                        glFlush();
                    }
                    getFinalCube4();
                    glFlush();
                } else {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 35) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(310 + x, 385 + y, 0);
                        glVertex3f(313 + x, 360 + y, 0);
                        glVertex3f(317.5 + x, 362.5 + y, 0);
                        glVertex3f(315 + x, 387.5 + y, 0);
                        glVertex3f(310 + x, 385 + y, 0);
                        y = y - 70;
                        x = x + 5;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 300; k++) {
                            delay();
                        }
                        glFlush();
                    }
                    getFinalCube5();

                    glFlush();
                }
                glFlush();
            } else if (getPath[i] == 4) {
                getFinalCube4();
                glFlush();
                if (getPath[i + 1] == 1) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 45) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(127.5 + x, 115 + y, 0);
                        glVertex3f(112.5 + x, 135 + y, 0);
                        glVertex3f(107.5 + x, 132.5 + y, 0);
                        glVertex3f(122.5 + x, 112.5 + y, 0);
                        glVertex3f(127.5 + x, 115 + y, 0);
                        y = y + 31.25;
                        x = x - 25;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 300; k++) {
                            delay();
                        }
                        glFlush();
                    }
                    getFinalCube1();
                    glFlush();
                } else if (getPath[i + 1] == 2) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 35) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(210 + x, 125 + y, 0);
                        glVertex3f(207.5 + x, 155 + y, 0);
                        glVertex3f(212.5 + x, 157.5 + y, 0);
                        glVertex3f(215 + x, 127.5 + y, 0);
                        glVertex3f(210 + x, 125 + y, 0);
                        y = y + 70;
                        x = x - 5;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 300; k++) {
                            delay();
                        }
                        glFlush();
                    }
                    getFinalCube2();
                    glFlush();
                } else if (getPath[i + 1] == 3) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 22) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(210 + x, 125 + y, 0);
                        glVertex3f(222.5 + x, 145 + y, 0);
                        glVertex3f(226 + x, 138 + y, 0);
                        glVertex3f(215 + x, 120 + y, 0);
                        glVertex3f(210 + x, 125 + y, 0);
                        y = y + 45;
                        x = x + 25;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 300; k++) {
                            delay();
                        }
                        glFlush();
                    }

                    getFinalCube3();
                    glFlush();
                } else {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 50) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(180 + x, 50 + y, 0);
                        glVertex3f(205 + x, 50 + y, 0);
                        glVertex3f(205 + x, 42.5 + y, 0);
                        glVertex3f(180 + x, 42.5 + y, 0);
                        glVertex3f(180 + x, 50 + y, 0);
                        y = y;
                        x = x + 40;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 300; k++) {
                            delay();
                        }
                        glFlush();
                    }
                    getFinalCube5();
                    glFlush();
                }
                glFlush();
            } else {
                getFinalCube5();
                glFlush();
                if (getPath[i + 1] == 1) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 30) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(315 + x, 120 + y, 0);
                        glVertex3f(287.5 + x, 132.5 + y, 0);
                        glVertex3f(282.5 + x, 127.5 + y, 0);
                        glVertex3f(310 + x, 115 + y, 0);
                        glVertex3f(315 + x, 120 + y, 0);
                        y = y + 25;
                        x = x - 45;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 300; k++) {
                            delay();
                        }
                        glFlush();
                    }

                    getFinalCube1();
                    glFlush();
                } else if (getPath[i + 1] == 2) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 30) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(362.5 + x, 130 + y, 0);
                        glVertex3f(350 + x, 150 + y, 0);
                        glVertex3f(345 + x, 147.5 + y, 0);
                        glVertex3f(357.5 + x, 127.5 + y, 0);
                        glVertex3f(362.5 + x, 130 + y, 0);
                        y = y + 60;
                        x = x - 35;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 300; k++) {
                            delay();
                        }
                        glFlush();
                    }

                    getFinalCube2();
                    glFlush();
                } else if (getPath[i + 1] == 3) {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 35) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(385 + x, 125 + y, 0);
                        glVertex3f(382.5 + x, 155 + y, 0);
                        glVertex3f(387.5 + x, 157.5 + y, 0);
                        glVertex3f(390 + x, 127.5 + y, 0);
                        glVertex3f(385 + x, 125 + y, 0);
                        y = y + 70;
                        x = x - 5;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 300; k++) {
                            delay();
                        }
                        glFlush();
                    }
                    getFinalCube3();
                    glFlush();
                } else {
                    x = 0;
                    y = 0;
                    x = m[i][i + 1] * y;
                    for (j = 0; j < 125; j = j + 60) {
                        glBegin(GL_POLYGON);
                        glColor3f(1.0, 0.0, 0.0);
                        glVertex3f(295 + x, 95 + y, 0);
                        glVertex3f(270 + x, 90 + y, 0);
                        glVertex3f(272.5 + x, 85 + y, 0);
                        glVertex3f(297.5 + x, 90 + y, 0);
                        glVertex3f(295 + x, 95 + y, 0);
                        y = y - 5;
                        x = x - 35;

                        glFlush();
                        glEnd();
                        for (k = 0; k <= 300; k++) {
                            delay();
                        }
                        glFlush();
                    }

                    getFinalCube4();
                    glFlush();
                }
                glFlush();
            }
            i++;
            glFlush();
        }
    }
    glFlush();
}
void display3() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glColor3f(0.0, 0.0, 1.0);
    drawString1(135, 200, 0, " CALCULATING BEST PATH ");
    glLineWidth(3);

    for (i = 0; i < 300; i = i + 25) {
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(125 + i, 190, 0);
        glVertex3f(150 + i, 190, 0);
        glEnd();
        for (j = 0; j <= 100; j++) {
            delay();
        }
        glFlush();
    }
    glFlush();
    for (i = 0; i <= 100; i++) {
        delay();
    }
    for (i = 0; i <= 100; i++) {
        delay();
    }
    for (i = 0; i <= 100; i++) {
        delay();
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);

    callPath(a, b);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);

    getCube1();
    getCube2();
    getCube3();
    getCube4();
    getCube5();
    getLines();

    display4();

}
void mykey(unsigned char key, int x, int y) {

    if ((key == 'E' || key == 'e') && flag == 0) {
        flag = 1;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        getCube1();
        getCube2();
        getCube3();
        getCube4();
        getCube5();
        getLines();
        glColor3f(0.0, 0.0, 1.0);
        drawString2(385, 235, 0, " Enter the number for Source Node");
        drawString2(385, 225, 0, " 1, 2, 3, 4, 5");

        glFlush();
    } else if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5') {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        getCube1();
        getCube2();
        getCube3();
        getCube4();
        getCube5();
        getLines();
        glColor3f(0.0, 0.0, 1.0);

        if (flag == 1) {
            flag = 2;
            drawString2(385, 235, 0, " Enter the number for Destination Node");
            drawString2(385, 225, 0, " 1, 2, 3, 4, 5");

            if (key == '1') {
                a = 1;
            } else if (key == '2') {
                a = 2;
            } else if (key == '3') {
                a = 3;
            } else if (key == '4') {
                a = 4;
            } else {
                a = 5;
            }

        } else if (flag == 2) {
            if (key == '1') {
                b = 1;
            } else if (key == '2') {
                b = 2;
            } else if (key == '3') {
                b = 3;
            } else if (key == '4') {
                b = 4;
            } else {
                b = 5;
            }

            display3();
        } else {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glFlush();
            glClearColor(1.0, 1.0, 1.0, 1.0);
            glFlush();
            glColor3f(0.0, 0.0, 1.0);
            drawString1(100, 400, 0, " Invalid Key Pressed ");
            glFlush();
            for (i = 0; i <= 500; i++) {
                delay();
            }
            for (i = 0; i <= 500; i++) {
                delay();
            }
            exit(0);
        }
        glFlush();
    } else {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glFlush();
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glFlush();
        glColor3f(0.0, 0.0, 1.0);
        drawString1(100, 400, 0, " Invalid Key Pressed ");
        glFlush();
        for (i = 0; i <= 500; i++) {
            delay();
        }
        for (i = 0; i <= 500; i++) {
            delay();
        }
        exit(0);
    }
}
void display() {
    distanceMatrix();
    display1();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 499, 0, 499);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}
void init() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char * * argv) {
    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Project");
    void init();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //glutFullScreen();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(mykey);
    glutMainLoop();
}
