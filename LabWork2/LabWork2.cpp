#include <iostream>
#include <iomanip>
#include "Combi.h"
#include "Boat.h"

#define N (sizeof(AA)/2)
#define M 3
#define NN 25   //количество контейнеров
#define MM 5    //количество мест на судне

using namespace std;

void MnojestvaPodmnojestv() {
    char  AA[][2] = { "A", "B", "C", "D" };

    std::cout << endl << " - Генератор множества всех подмножеств -" <<
        endl << "Исходное множество: " << "{ ";

    int sizeAA = sizeof(AA) / 2;
    for (int i = 0; i < sizeAA; i++)
        std::cout << AA[i] << ((i < sizeAA - 1) ? ", " : " ");

    std::cout << "}";
    std::cout << std::endl << "Генерация всех подмножеств  ";

    combi::subset s1(sizeAA);         // создание генератора   
    int  n = s1.getfirst();
    while (n >= 0)                          // пока есть подмножества 
    {
        std::cout << std::endl << "{ ";

        for (int i = 0; i < n; i++)
            std::cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");

        std::cout << "}";

        n = s1.getnext();                   // cледующее подмножество 
    };

    std::cout << std::endl << "всего: " << s1.count() << std::endl;
}
void GeneraciaSochetani() {
    char  AA[][2] = { "A", "B", "C", "D", "E" };

    std::cout << std::endl << " --- Генератор сочетаний ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";

    for (int i = 0; i < sizeof(AA) / 2; i++)
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");

    std::cout << "}";
    std::cout << std::endl << "Генерация сочетаний ";

    combi::xcombination xc(sizeof(AA) / 2, 3);

    std::cout << "из " << xc.n << " по " << xc.m;

    int  n = xc.getfirst();
    while (n >= 0)
    {
        std::cout << std::endl << xc.nc << ": { ";

        for (int i = 0; i < n; i++)
            std::cout << AA[xc.ntx(i)] << ((i < n - 1) ? ", " : " ");

        std::cout << "}";

        n = xc.getnext();
    };

    std::cout << std::endl << "всего: " << xc.count() << std::endl;
}
void GeneracicacPerestanovok(){
    char  AA[][2] = { "A", "B", "C", "D" };           

    std::cout << std::endl << " --- Генератор перестановок ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";

    for (int i = 0; i < sizeof(AA) / 2; i++)
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");

    std::cout << "}";
    std::cout << std::endl << "Генерация перестановок ";

    combi::permutation p(sizeof(AA) / 2);
    __int64  n = p.getfirst();
    while (n >= 0)
    {
        std::cout << std::endl << std::setw(4) << p.np << ": { ";

        for (int i = 0; i < p.n; i++)

            std::cout << AA[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");

        std::cout << "}";

        n = p.getnext();
    };

    std::cout << std::endl << "всего: " << p.count() << std::endl;

}
void GeneraciaRazmeesheni() {
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " --- Генератор размещений ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";

    for (int i = 0; i < N; i++)
        std::cout << AA[i] << ((i < N - 1) ? ", " : " ");

    std::cout << "}";
    std::cout << std::endl << "Генерация размещений  из  " << N << " по " << M;

    combi::accomodation s(N, M);
    int  n = s.getfirst();
    while (n >= 0)
    {
        std::cout << std::endl << std::setw(2) << s.na << ": { ";

        for (int i = 0; i < 3; i++)
            std::cout << AA[s.ntx(i)] << ((i < n - 1) ? ", " : " ");

        std::cout << "}";

        n = s.getnext();
    };

    std::cout << std::endl << "всего: " << s.count() << std::endl;
}
void BoatLoading() {
    int V = 1500,
        v[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 150, 230, 265, 960, 540, 230, 790, 450, 320, 120, 120, 250, 300, 230, 230, 880 },
        c[NN] = { 10, 15, 20, 25, 30, 25, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 110, 120, 130, 140, 150 };
    short  r[MM];
    int cc = boatfnc::boat(
        V,   // [in]  максимальный вес груза
        MM,  // [in]  количество мест для контейнеров
        NN,  // [in]  всего контейнеров  
        v,   // [in]  вес каждого контейнера  
        c,   // [in]  доход от перевозки каждого контейнера
        r    // [out] результат: индексы выбранных контейнеров
    );
    std::cout << std::endl << "- Задача о размещении контейнеров на судне";
    std::cout << std::endl << "- общее количество контейнеров    : " << NN;
    std::cout << std::endl << "- количество мест для контейнеров : " << MM;
    std::cout << std::endl << "- ограничение по суммарному весу  : " << V;

    std::cout << std::endl << "- вес контейнеров                 : ";
    for (int i = 0; i < NN; i++) std::cout << std::setw(3) << v[i] << " ";

    std::cout << std::endl << "- доход от перевозки              : ";
    for (int i = 0; i < NN; i++) std::cout << std::setw(3) << c[i] << " ";

    std::cout << std::endl << "- выбраны контейнеры (0,1,...,m-1): ";
    for (int i = 0; i < MM; i++) std::cout << r[i] << " ";

    std::cout << std::endl << "- доход от перевозки              : " << cc;

    std::cout << std::endl << "- общий вес выбранных контейнеров : ";
    int s = 0; for (int i = 0; i < MM; i++) s += v[r[i]]; std::cout << s;

    std::cout << std::endl << std::endl;
}
void Zavisemost() {
    // эксперименты
    int vnn;
    for (vnn = 5; vnn <= NN;  vnn++)
    {
        clock_t t1 = 0, t2 = 0;        
        t1 = clock();

        int V = 1500,
            v[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 150, 230, 265, 960, 540, 230, 790, 450, 320, 120, 120, 250, 300, 230, 230, 880 },
            c[NN] = { 10, 15, 20, 25, 30, 25, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 110, 120, 130, 140, 150 };
        short  r[MM];
        int cc = boatfnc::boat(
            V,   // [in]  максимальный вес груза
            MM,  // [in]  количество мест для контейнеров
            vnn,  // [in]  всего контейнеров  
            v,   // [in]  вес каждого контейнера  
            c,   // [in]  доход от перевозки каждого контейнера
            r    // [out] результат: индексы выбранных контейнеров
        );

        t2 = clock();

        cout << endl << "количесвто контейнеров:     " << vnn;        
        cout << endl << "продолжительность (y.e):     " << (t2 - t1);
        cout << endl << "       (сек):      " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC) << "\n\n\n";
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    
    /*MnojestvaPodmnojestv();*/
    /*GeneraciaSochetani();*/
    /*GeneracicacPerestanovok();*/
    /*GeneraciaRazmeesheni();*/
    /*BoatLoading();*/
    /*Zavisemost();*/

    system("pause");
    return 0;
}
