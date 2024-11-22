#include <GL/glut.h>
#include <windows.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void Reshape(int w, int h);
void drawGrid();
void display();
float shoelaceFormul(int n);
void drawArea(float x, float y, float value);

float* Coordinates[3];
int points[3];

void drawArea(float x, float y, float value)
{
    char text[10]; // Metin dizesi için bir tampon oluştur
    snprintf(text, sizeof(text), "%.2f", value);
    glRasterPos2f(x, y);

    for (int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
}

float shoelaceFormul(int n)
{
    int kose = points[n]/2;
    float x[kose], y[kose];

    for(int i = 0; i < kose; i++)
    {
        x[i] = Coordinates[n][2*i];
        y[i] = Coordinates[n][2*i+1];
    }
    float area = 0.0;
    int j = kose - 1;  // Son noktayı başlangıç noktası olarak almak için

    for (int i = 0; i < kose; i++) {
        area += (x[j] + x[i]) * (y[j] - y[i]);
        j = i;  // Gezilen noktayı bir sonraki nokta olarak ayarla
    }
    return fabs(area) / 2;
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 60, 60, 0);
    glMatrixMode(GL_MODELVIEW);
    //glClearColor(0, 0, 0, 1);
}

void drawGrid()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Sadece kenar çizgileri çizilsin
    glColor3f(0.6, 0.3, 0.4);

    for (int i = 0; i <= 60; i += 1) {
        for (int j = 60; j >= 0; j -= 1) {
            glBegin(GL_LINE_LOOP);
            glVertex2f(i, j);
            glVertex2f(i + 1, j);
            glVertex2f(i + 1, j + 1);
            glVertex2f(i, j + 1);
            glEnd();
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Çokgenlerin içini boya
    glColor3f(0.3, 0.3, 0.4);

    for(int i = 0; i < 3; i++)
    {
        glBegin(GL_POLYGON);
        int xort, yort;
        float alan;

        for(int j = 0; j < points[i]; j += 2)
        {

            float xmax = Coordinates[i][0];
            float xmin = Coordinates[i][0];
            float ymin = Coordinates[i][1];

            float x = Coordinates[i][j];
            float y = Coordinates[i][j + 1];

            glVertex2f(x, y);

            xmax = fmax(xmax, x);
            xmin = fmin(xmin, x);
            ymin = fmin(ymin, y);

            xort = (xmax + xmin) / 2.0 + 1;
            yort = ymin - 2;
            alan = shoelaceFormul(i);

        }
        glEnd();
        drawArea(xort, yort, alan);
    }
    drawGrid();
    glFlush();
}

int main(int argc, char **argv)
{
    system("curl -s -o C:\\Prolab\\lab.txt http://abilgisayar.kocaeli.edu.tr/prolab1/prolab1.txt");
    //http://zplusorg.com/prolab.txt

    FILE* dosya = fopen("C:\\Prolab\\lab.txt", "r");

    char satir_oku[100]; // Belirli bir boyutta karakter dizisi oluşturduk
    int satir_adedi;

    for (satir_adedi = 0; fgets(satir_oku, sizeof(satir_oku), dosya) != NULL; satir_adedi++)
    {
        // Satırda bulunan tek kelimeyi bulmak için strtok fonksiyonunu kullanabiliriz
        char *kelime = strtok(satir_oku, " \t\n"); // Boşluk, sekme ve yeni satır karakterlerine göre ayır
        if (kelime != NULL)
            printf("\n%d. Satir: %s\n", satir_adedi + 1, kelime);

    }
    unsigned int secim = 0;
    while(secim > satir_adedi || secim <= 0)
    {
        printf("\nCizim icin satir seciniz: ");
        scanf("%d", &secim);
    }
    fseek(dosya, 0, SEEK_SET);

    char *secilen_satir;
    for(int i = 0; i < secim; i++)
    {
        fgets(satir_oku, sizeof(satir_oku), dosya);
        secilen_satir = strtok(satir_oku, " \t\n");
    }
    fclose(dosya);

    int degisim = 0, index = 0;
    char* ptr = secilen_satir;

    while (*ptr) {
        if (*ptr == '(')
        {
            int flag =1;
            float x=0, y=0;

            if(sscanf(ptr, "(%f,%f)", &x, &y) == 2)
            {
                for(int i = 0; i < index; i += 2)
                {
                    if(Coordinates[degisim][i] == x && Coordinates[degisim][i+1] == y)
                    {
                        points[degisim] = index;
                        index = 0;
                        degisim++;
                        flag = 0;
                    }
                }
            }
            if(flag)
            {
                Coordinates[degisim] = (float *) realloc(Coordinates[degisim], sizeof(float) * index);
                Coordinates[degisim][index] = x;
                Coordinates[degisim][index + 1] = y;
                index += 2;
            }
            ptr = strchr(ptr, ')'); // Parantezi bul
            if (ptr == NULL)
                break;
        }
        ptr++; // Pointer'ı bir sonraki karaktere taşı
    }
    glutInit(&argc, argv);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1080);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("Coordinate System");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
