// Lab_10_1_A.cpp

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Spec { ME, FI, TN, INF, KN };

struct Student
{
    string prizv;
    unsigned kurs;
    Spec spec;
    int fiz;
    int mat;
    int inf;
};

void Create(Student* p, const int N){

    int spec;

    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << "Прізвище: ";
        getline(cin, p[i].prizv);

        cout << "Курс: ";
        cin >> p[i].kurs;

        cout << "Спеціальність (0-ME, 1-FI, 2-TN, 3-IN, 4-KN): ";
        cin >> spec;
        p[i].spec = (Spec)spec;

        cout << "Фізика: ";
        cin >> p[i].fiz;

        cout << "Математика: ";
        cin >> p[i].mat;

        cout << "Інформатика: ";
        cin >> p[i].inf;
    }
}

void Print(Student* p, const int N)
{
    string specStr[] = {
        "Математика та економіка",
        "Фізика та інформатика",
        "Трудове навчання",
        "Інформатика",
        "Комп'ютерні науки"
    };

    cout << string(98, '-') << endl;

    cout << "| " << setw(3) << left << "№"
        << " | " << setw(15) << "Прізвище"
        << " | " << setw(5) << "Курс"
        << " | " << setw(24) << "Спеціальність"
        << " | " << setw(7) << "Фізика"
        << " | " << setw(10) << "Математика"
        << " | " << setw(12) << "Інформатика"
        << " |" << endl;

    cout << string(98, '-') << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1
            << " | " << setw(15) << left << p[i].prizv
            << " | " << setw(5) << p[i].kurs
            << " | " << setw(24) << specStr[p[i].spec]
            << " | " << setw(7) << p[i].fiz
            << " | " << setw(10) << p[i].mat
            << " | " << setw(12) << p[i].inf
            << " |" << endl;
    }

    cout << string(98, '-') << endl;
}
double PercentExcellent(Student* p, const int N)
{
    int k = 0;
    double P;

    for (int i = 0; i < N;i++) {
        if (p[i].mat == 5 && p[i].fiz == 5 && p[i].inf == 5) {
            k++;
        }
    }
    P = (k * 100.0) / N;
    
    return P;
}

void PrintExcellentPhysics(Student* p, const int N)
{
    for (int i = 0; i < N;i++) {
        if (p[i].fiz == 5) {
            cout <<p[i].prizv << endl;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student* p = new Student[N];

    Create(p, N);
    Print(p, N);
    
    cout << "Відсоток відмінників: "
        << PercentExcellent(p, N) << "%" << endl;

    cout << "Студенти, які отримали з фізики оцінку “5”:" << endl;

    PrintExcellentPhysics(p, N);

    delete[] p;
    
    return 0;
}

