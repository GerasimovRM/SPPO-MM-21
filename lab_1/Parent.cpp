#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

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

int main() {
    PROCESS_INFORMATION pi;
    emp* students = NULL;
    int answer = 0;
    unsigned count = 0;
    string filename = "data.bin";
    cout << "Create new bin file?\n1-yes\n2-no\n";
    cin >> answer;
    if (answer == 1) {
        // 1 создает бинарный файл - массив emp
        cout << "Count of students: ";
        cin >> count;
        students = new emp[count];
        for (int i = 0; i < count; ++i) {
            cout << "Enter the id of student " << i + 1 << ": ";
            cin >> students[i].num;
            cout << "Enter the name of student: " << i + 1 << ": ";
            cin >> students[i].name;
            cout << "Enter the grade of student: " << i + 1 << ": ";
            cin >> students[i].grade;
        }
        ofstream file_out(filename, ios::out | ios::binary);
        file_out.write((char*)&count, sizeof count);
        for (int i = 0; i < count; ++i) {
//            file_out.write((char*)students[i].num, sizeof students[i].num);
//            file_out.write(students[i].name, sizeof students[i].name);
//            const char* loc_var = to_string(students[i].grade).c_str();
//            file_out.write(loc_var, sizeof students[i].grade);
            file_out.write((char*)&students[i], sizeof(emp));
        }
        file_out.close();
    }
    else {
        // 2 вывод созданного файл на консоль
        ifstream file_in(filename, ios::in | ios::binary);
        file_in.read((char *) &count, sizeof count);
        students = new emp[count];
        for (int i = 0; i < count; ++i) {
            file_in.read((char *) &students[i], sizeof(emp));
            students[i].print_emp();
        }
        file_in.close();
    }
    // 3 запрашивает с консоли номер зачетки, имя студента, новый средний балл
    emp new_student;
    cout << "Enter id of student: ";
    cin >> new_student.num;
    cout << "Enter name of student: ";
    cin >> new_student.name;
    cout << "Enter new grade of student: ";
    cin >> new_student.grade;
    // 4 формирует cmd_line
    string process_of_child_path = "C://.../Child.exe ";
    string cmd_line = process_of_child_path + to_string(new_student.num) +
            " " + string(new_student.name) + " " + to_string(new_student.grade);
    // 5 запускает child
    if (CreateProcess(NULL,
                      cmd_line.c_str(),
                      NULL,
                      NULL,
                      false,
                      0,
                      NULL,
                      NULL,
                      NULL,
                      &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
    }
    else {
        cout << "Fatal error!";
    }
        // 6 ждет заврешения
    // 7 выводит откорректированный файл
    delete [] students;
    return 0;
}