#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;


bool fl_FileIsEmpty(string fileName) // Funcion para comprobar si el archivo (base de datos) esta vacio
{
    ifstream file(fileName); // Se abre el archivo
    return file.peek() == ifstream::traits_type::eof(); // Si el archivo esta vacio, el peek devuelve el valor de ifstream::traits_type::eof
}

int main() {
    int fl_MaxEstudiantes = 25, fl_maxDatos = 7; // Maximo de estudiantes y datos por estudiante
    string fl_Datos[fl_maxDatos] = { // Datos de los estudiantes
            "Nombre del Estudiante",
            "Codigo estudiantil",
            "Correo institucional",
            "Ciudad de residencia",
            "Carrera",
            "Clases en curso",
            "Becario"
    };

    string fl_Estudiantes[fl_MaxEstudiantes][fl_maxDatos]; // Matriz de estudiantes

    fstream students; // Archivo de estudiantes
    students.open("Students.txt", ios::in | ios::out | ios::app); // Se abre el archivo de estudiantes

    if(!students) {
        cout << "No se pudo abrir el archivo de estudiantes" << endl;
    }
    else {
        if(fl_FileIsEmpty("Students.txt")) { // Si el archivo esta vacio
            cout << "El archivo de estudiantes está vacio." << endl;
        }
        else {
            string fl_Linea; // Linea del archivo
            while(getline(students, fl_Linea)) {
                stringstream ss(fl_Linea); // Se crea un stringstream con la linea del archivo

                string id, name, email, city, career, classes, becario; // Datos de cada estudiante
                int i = 0; // Contador de datos

                //getline(ss, id, ',');           //cout << "\"" << id << "\"" << endl; // Se obtiene el id del estudiante
                //getline(ss, name, ',');         //cout << "\"" << name << "\"" << endl; // Se obtiene el nombre del estudiante
                //getline(ss, email, ',');        //cout << "\"" << email << "\"" << endl; // Se obtiene el correo del estudiante

                vector<string> enrolled; // Vector de datos del estudiante
                string course;
                while(getline(ss, course, ',')) {
                    enrolled.push_back(course);
                    cout << "\"" << course << "\"" << endl;  // Se obtiene el curso del estudiante
                }
                cout << "\n";
            }
        }
    }

    if(students.is_open()) { // Si el archivo se abre correctamente
        for(int i = 0; i < 1; i++) {
            for(int j = 0; j < fl_maxDatos; j++) {
                if(j == 6) cout << "¿Eres becario? (s/n): ";
                else cout << fl_Datos[j] << ": ";
                getline(cin, fl_Estudiantes[i][j]);
            }
            students << fl_Estudiantes[i][0] << ",";
            students << fl_Estudiantes[i][1] << ",";
            students << fl_Estudiantes[i][2] << ",";
            students << fl_Estudiantes[i][3] << ",";
            students << fl_Estudiantes[i][4] << ",";
            students << fl_Estudiantes[i][5] << ",";
            students << fl_Estudiantes[i][6] << endl;
        }
        students.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl; // Si no se pudo abrir el archivo
    }
    /*
     * Se pretende que el programa lea un archivo de texto con los datos de los estudiantes.
     * El archivo debe tener el siguiente formato:
     *
     */

    return 0;
}

