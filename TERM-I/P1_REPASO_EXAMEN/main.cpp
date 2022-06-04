#include <iostream>
#include <cstring>

using namespace std;

#define FL_MAX_MONTHS (12) // Iteracion de los meses de 1 a 12.

void ShowWelcomeMessage() {
    cout << "Hola MYN! Bienvenidos al programa de reportes de incendios y siniestros de vehiculos." << endl;
    cout << "A continuacion, se te mostrara un reporte con los datos que hemos recolectado hasta el momento...\n"
            "" << endl;
}

char *GetMonthName(int fl_month)
{
    static char fl_monthname[3 + 1]; // Caracteres del mes + NULL byte (caracter de valor 0)
    switch (fl_month) { // Switcheamos el # del mes segun corresponda para obtener el nombre corto del mes
        case 1: {
            strcpy(fl_monthname, "Ene");
            return fl_monthname;
        }
        case 2: {
            strcpy(fl_monthname, "Feb");
            return fl_monthname;
        }
        case 3: {
            strcpy(fl_monthname, "Mar");
            return fl_monthname;
        }
        case 4: {
            strcpy(fl_monthname, "Abr");
            return fl_monthname;
        }
        case 5: {
            strcpy(fl_monthname, "May");
            return fl_monthname;
        }
        case 6: {
            strcpy(fl_monthname, "Jun");
            return fl_monthname;
        }
        case 7: {
            strcpy(fl_monthname, "Jul");
            return fl_monthname;
        }
        case 8: {
            strcpy(fl_monthname, "Ago");
            return fl_monthname;
        }
        case 9: {
            strcpy(fl_monthname, "Sep");
            return fl_monthname;
        }
        case 10: {
            strcpy(fl_monthname, "Oct");
            return fl_monthname;
        }
        case 11: {
            strcpy(fl_monthname, "Nov");
            return fl_monthname;
        }
        case 12: {
            strcpy(fl_monthname, "Dic");
            return fl_monthname;
        }
        default : {
            strcpy(fl_monthname, "???");
            return fl_monthname;
        }
    } // Fin del switch
}


int main()
{
    int fl_init_fire = 1500, fl_month = 1, fl_firepercentage;
    double fl_monthly_firebranch, fl_total = 0;
    ShowWelcomeMessage();

    cout << "Mes\t\t Incendio \t\t Vehiculos \t\t Diferencia \t\t Promedio" << endl;
    do {
        if (fl_month == 1) {
            fl_monthly_firebranch = fl_init_fire + (fl_init_fire * 0.3);
            fl_total += fl_monthly_firebranch;
            cout << GetMonthName(fl_month) << "\t\t " << fl_monthly_firebranch << endl;
        }
        else if (fl_month >= 2 and fl_month <= 3) {
            fl_monthly_firebranch = fl_monthly_firebranch + (fl_monthly_firebranch * 0.3);
            fl_total += fl_monthly_firebranch;
            cout << GetMonthName(fl_month) << "\t\t " << fl_monthly_firebranch << endl;
        }
        else if (fl_month >= 4 and fl_month <= 6) {
            fl_monthly_firebranch = fl_monthly_firebranch - (fl_monthly_firebranch * 0.2);
            fl_total += fl_monthly_firebranch;
            cout << GetMonthName(fl_month) << "\t\t " << fl_monthly_firebranch << endl;
        }
        else if (fl_month >= 7 and fl_month <= 9) {
            do {
                cout << "Porcentaje de incendios en el mes de " << GetMonthName(fl_month) << " (1 al 100): ";
                cin >> fl_firepercentage;
            } while (fl_firepercentage <= 1 or fl_firepercentage >= 100);
            cout << "[!] Porcentaje de crecimiento en incendios para el mes de " << GetMonthName(fl_month) << ": " << (fl_firepercentage) << "%" << endl;
            fl_monthly_firebranch = fl_monthly_firebranch + (fl_monthly_firebranch * fl_firepercentage)/100;
            fl_total += fl_monthly_firebranch;
            cout << GetMonthName(fl_month) << "\t\t " << fl_monthly_firebranch << endl;
        }
        else if (fl_month >= 10 and fl_month <= 12) {
            do {
                cout << "Porcentaje de incendios en el mes de " << GetMonthName(fl_month) << " (1 al 100): ";
                cin >> fl_firepercentage;
            } while (fl_firepercentage <= 1 or fl_firepercentage >= 100);
            cout << "[!] Porcentaje de decremento en incendios para el mes de " << GetMonthName(fl_month) << ": " << (fl_firepercentage) << "%" << endl;
            fl_monthly_firebranch = fl_monthly_firebranch - (fl_monthly_firebranch * fl_firepercentage)/100;
            fl_total += fl_monthly_firebranch;
            cout << GetMonthName(fl_month) << "\t\t " << fl_monthly_firebranch << endl;
        }
        fl_month++;
    } while (fl_month <= FL_MAX_MONTHS);
    cout << "La suma total de incendios es: " << fl_total << endl;
    return 0;
}