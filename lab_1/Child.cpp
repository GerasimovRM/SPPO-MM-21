#include <iostream>
#include <string>
using namespace std;
struct emp {
    int num; // номер зачетки
    char name[10]; // имя студент
    double grade; // средний балл

public:
    void print_emp() {
        cout << this->num << " " << this->name << " " << this->grade << endl;
    }
};

int main(int argc, char* argv[]) {
    // string filename = "C://.../data.bin"
    // 1 выводит на консоль полученную информацию
    string filename = "data.bin";
    emp student;
    student.num = atoi(argv[1]);
    strcpy(student.name, argv[2]);
    student.grade = atof(argv[3]);
    student.print_emp();
    // 2 корректирует в файле нужную запись

    return 0;
}