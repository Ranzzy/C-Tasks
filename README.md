# Лабораторная работа №10 Объекты, классы, наследование и полиморфизм

**Цель работы:** закрепить на практике знания по написанию программного кода для задач на языке С++.

**Ход работы:**

**Задание 1:** Создать класс *circle* в котором будут определены параметры фигуры, функции вывода радиуса, площади, периметра и сравнения площадей двух окружностей.

Функция *main* файла main.cpp:

    int main (int argc, char* argv[]) {
    Circle *c = new Circle(10);
    shape *s;

      s = c;

    s->draw();
    Circle c2 = Circle(10,11,34);
    Circle c3 = Circle(10,11,34);
    if(c2.isEqual(c3)){
    cout << "Окружности равны!" << endl;
    }
    else {
    cout << "Окружности разные!" << endl;
    }
    return 0;
    }

**Задание 2:** Создать класс матрица, определить его параметры и функию печати.

Функция *main* файла matrix.cpp:

    #include <iostream>
    #include "matrix.h"  // Модуль работы с матрицами содержит шаблон класса Matrix<Type>

    using namespace std;

    int main (){

    // Матрица А
    const int A1[] = {2, 3};
    const int A2[] = {1, 0};
    const int A3[] = {-1, 3};
    const int *const mxA[] = {A1, A2, A3};

    // Матрица Б
    const int B1[] = {2,  0, 1};
    const int B2[] = {1, -2, 2};
    const int B3[] = {5,  0, 7};
    const int *const mxB[] = {B1, B2, B3};

    // Вычисляем
    Matrix<int> a(mxA, 3, 2);
    cout << "a = ";    a.print();
    Matrix<int> b(mxB, 3, 3);
    cout << "b =";
    b.print();

    // Умножение числа на матрицу, матрицы на матрицу и вычитание
    // Результат заносится в матрицу С
    Matrix<int> c = (2*a) - (b*a);
    cout << "c = 2a - ba =";    // Выводим результат
    c.print();

    return 0;
    }

**Задание 3:** Создать класс фигур, определить его параметры, возможные ходы фигур.

Класс *фигура* файла chess.cpp:

    class figure {                 //класс «фигура»
    protected:
    int hor;                      //позиция фигуры по горизонтали
    coord vert;                    //позиция фигуры по вертикали
    fig_color color;                     //цвет фигуры
    public:
    figure(coord x, int y, fig_color c); //конструктор
    virtual ~figure();
    //чистая функция «ход»
    virtual bool step (coord new_letter, int new_digit)=0;
    };

Функция *main* файла chess.cpp:

    int main()
    {
    setlocale(LC_ALL, "Russian");// Русский в консоли
    figure* f0=new castle(b,2,white);  // устанавливаем ладью на доску
    figure* f1=new queen(e,4,black);	// устанавливаем королеву
    figure* f2=new bishop(e,4,black);  // устанавливаем слона

    f0->step(b,3);  // Ход ладьей 
    f1->step(d,3);  // Ход королевой
    f2->step(e,5);  // Ход слоном
    return 0;
    }

**Вывод:** практиковался в создании объектов, объявлении классов и использования возможностей языка С++ для выполнения задач.