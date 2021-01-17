#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct FunkKwadrat* getFuncParams();
void printResult();
void findZeros();
void calcualateVertex();
void findDelta();

struct Punkt {
    float x, y;
};

struct FunkKwadrat {
    int a, b, c;
    float delta;
    float x1, x2;
    struct Punkt wierz;

};

int main() {
    struct FunkKwadrat* mojaFunkcja = getFuncParams();
    findDelta(mojaFunkcja);
    findZeros(mojaFunkcja);
    calcualateVertex(mojaFunkcja);
    printResult(mojaFunkcja);


    return 0;
}

struct FunkKwadrat* getFuncParams() {
    struct FunkKwadrat* mojaFunkcja = (struct FunkKwadrat*) malloc(sizeof(struct FunkKwadrat));
    printf("Podaj a:");
    do{
        scanf(" %d", &(mojaFunkcja->a));
        if(mojaFunkcja->a == 0){
            printf("a nie moze byc rowne 0. Podaj a jeszcze raz: \n");
        }
    } while(mojaFunkcja->a == 0);
    printf("Podaj b:");
    scanf(" %d", &(mojaFunkcja->b));
    printf("Podaj c:");
    scanf(" %d", &(mojaFunkcja->c));
    return mojaFunkcja;
}

void printResult(struct FunkKwadrat *f) {

    printf("Podana funkcja: f(x) = %dx^2 + %dx + %d\n", f->a, f->b, f->c);
    printf("Delta = %f\n", f->delta);
    if((f->delta)<0){
        printf("Brak miejsc zerowych\n");
    }
    else if((f->delta) == 0){
        printf("x0 = %f\n", f->x1);
    }
    else {
        printf("x1 = %f  |  x2 = %f\n", f->x1, f->x2);
    }
    printf("Wspolrzedne wierzcholka: x = %f  |  y = %f\n", f->wierz.x, f->wierz.y);

}

void findDelta(struct FunkKwadrat *f) {
    (f->delta) = pow(f->b,2) - 4*(f->a)*(f->c);
}

void findZeros(struct FunkKwadrat *f) {

    if(f->delta == 0) {
        f->x1 = (-f->b-sqrt(f->delta))/(2*f->a);
    }
    else {
        f->x1 = (-(f->b)-sqrt(f->delta))/(2*(f->a));
        f->x2 = (-(f->b)+sqrt(f->delta))/(2*(f->a));
    }
}

void calcualateVertex(struct FunkKwadrat *f) {
    f->wierz.x = (float) -(f->b)/(2*f->a);
    f->wierz.y = (float) -(f->delta)/(4*f->a);
}
