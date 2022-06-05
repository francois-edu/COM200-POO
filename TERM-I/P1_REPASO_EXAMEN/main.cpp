#include <iostream>
#include <cstring>

using namespace std;

#define FL_MAX_MONTHS (12) // Iteracion de los meses de 1 a 12.

void ShowWelcomeMessage() {
    cout << "Hola MYN! Bienvenidos al programa de reportes de incendios y siniestros de vehiculos." << endl;
    cout << "A continuacion, te pedimos que ingreses la informacion faltante para poder mostrarte la tabla.\n" << endl;
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

double GetMajorBranch(double fl_total_firebranch, double fl_total_accidentbranch)
{
    double fl_major_branch;
    if (fl_total_firebranch > fl_total_accidentbranch) {
        fl_major_branch = fl_total_firebranch;
    } else {
        fl_major_branch = fl_total_accidentbranch;
    }
    return fl_major_branch;
}
char *GetMajorBranchName(double fl_total_firebranch, double fl_total_accidentbranch)
{
    static char fl_major_branch_name[3 + 1]; // Caracteres del mes + NULL byte (caracter de valor 0)
    double fl_major_branch;
    if (fl_total_firebranch > fl_total_accidentbranch) {
        strcpy(fl_major_branch_name, "Incendio");
    } else {
        strcpy(fl_major_branch_name, "Vehiculos");
    }
    return fl_major_branch_name;
}

int main()
{
    int /* Ramo de incendios */
        fl_init_fire = 1500,
        fl_month = 1,
        fl_firepercentage_inc,
        fl_firepercentage_dec,
            /* Ramo de accidentes */
        fl_init_accident = 1200,
        fl_accidentpercentage_inc,
        fl_accidentpercentage_dec;

    double /* Ramo de incendios */
        fl_monthly_firebranch,
        fl_total_firebranch = 0,
            /* Ramo de accidentes */
        fl_monthly_accidentbranch,
        fl_total_accidentbranch = 0,
            /* Diferencia */
        fl_branchdifference,
        fl_totaldifference,
            /* Promedio */
        fl_branchaverage,
        fl_totalaverage;

    ShowWelcomeMessage();
    do {
        cout << "Ingresa el porcentaje de incremento de incendios para los meses de Julio a Septiembre:" << endl;
        cin >> fl_firepercentage_inc;
    } while (fl_firepercentage_inc < 0 or fl_firepercentage_inc > 100);

    do {
        cout << "Ingresa el porcentaje de decremento de incendios para los meses de Octubre a Diciembre:" << endl;
        cin >> fl_firepercentage_dec;
    } while (fl_firepercentage_dec < 0 or fl_firepercentage_dec > 100);

    do {
        cout << "Ingresa el porcentaje de incremento de accidentes para los meses de Julio a Septiembre:" << endl;
        cin >> fl_accidentpercentage_inc;
    } while (fl_accidentpercentage_inc < 0 or fl_accidentpercentage_inc > 100);

    do {
        cout << "Ingresa el porcentaje de decremento de accidentes para los meses de Octubre a Diciembre:" << endl;
        cin >> fl_accidentpercentage_dec;
    } while (fl_accidentpercentage_dec < 0 or fl_accidentpercentage_dec > 100);

    cout << "Mes\t\t Incendio \t\t Vehiculos \t\t Diferencia \t\t Promedio" << endl;
    do {
        if (fl_month == 1) {
            // Fire branch
            fl_monthly_firebranch = fl_init_fire + (fl_init_fire * 0.3);
            fl_total_firebranch += fl_monthly_firebranch;

            // Accidents branch
            fl_monthly_accidentbranch = fl_init_accident + (fl_init_accident * 0.2);
            fl_total_accidentbranch += fl_monthly_accidentbranch;

            // Difference
            fl_branchdifference = fl_monthly_firebranch - fl_monthly_accidentbranch;
            fl_totaldifference += fl_branchdifference;

            // Average
            fl_branchaverage = (fl_monthly_firebranch + fl_monthly_accidentbranch) / 2;
            fl_totalaverage += fl_branchaverage;

            cout << GetMonthName(fl_month) << "\t\t " << fl_monthly_firebranch << "\t\t\t " << fl_monthly_accidentbranch << "\t\t\t " << fl_branchdifference << "\t\t\t " << fl_branchaverage << endl;
        }
        else if (fl_month >= 2 and fl_month <= 3) {
            fl_monthly_firebranch = fl_monthly_firebranch + (fl_monthly_firebranch * 0.3);
            fl_total_firebranch += fl_monthly_firebranch;

            // Accidents branch
            fl_monthly_accidentbranch = fl_monthly_accidentbranch + (fl_monthly_accidentbranch * 0.2);
            fl_total_accidentbranch += fl_monthly_accidentbranch;

            // Difference
            fl_branchdifference = fl_monthly_firebranch - fl_monthly_accidentbranch;
            fl_totaldifference += fl_branchdifference;

            // Average
            fl_branchaverage = (fl_monthly_firebranch + fl_monthly_accidentbranch) / 2;
            fl_totalaverage += fl_branchaverage;

            cout << GetMonthName(fl_month) << "\t\t " << fl_monthly_firebranch << "\t\t\t " << fl_monthly_accidentbranch << "\t\t\t " << fl_branchdifference << "\t\t\t " << fl_branchaverage << endl;
        }
        else if (fl_month >= 4 and fl_month <= 6) {
            fl_monthly_firebranch = fl_monthly_firebranch - (fl_monthly_firebranch * 0.2);
            fl_total_firebranch += fl_monthly_firebranch;

            // Accidents branch
            fl_monthly_accidentbranch = fl_monthly_accidentbranch + (fl_monthly_accidentbranch * 0.2);
            fl_total_accidentbranch += fl_monthly_accidentbranch;

            // Difference
            fl_branchdifference = fl_monthly_firebranch - fl_monthly_accidentbranch;
            fl_totaldifference += fl_branchdifference;

            // Average
            fl_branchaverage = (fl_monthly_firebranch + fl_monthly_accidentbranch) / 2;
            fl_totalaverage += fl_branchaverage;

            /* Solo para formatear el output */
            if (fl_month == 5)
                cout << GetMonthName(fl_month) << "\t\t " << fl_monthly_firebranch << "\t\t " << fl_monthly_accidentbranch << "\t\t " << fl_branchdifference << "\t\t " << fl_branchaverage << endl;
            else if (fl_month == 6)
                cout << GetMonthName(fl_month) << "\t\t " << fl_monthly_firebranch << "\t\t\t " << fl_monthly_accidentbranch << "\t\t " << fl_branchdifference << "\t\t " << fl_branchaverage << endl;
            /* Fin de formateo */
        }
        else if (fl_month >= 7 and fl_month <= 9) {
            // Fire branch

            fl_monthly_firebranch = fl_monthly_firebranch + (fl_monthly_firebranch * fl_firepercentage_inc)/100;
            fl_total_firebranch += fl_monthly_firebranch;

            // Accidents branch
            fl_monthly_accidentbranch = fl_monthly_accidentbranch + (fl_monthly_accidentbranch * fl_accidentpercentage_inc)/100;
            fl_total_accidentbranch += fl_monthly_accidentbranch;

            // Difference
            fl_branchdifference = fl_monthly_firebranch - fl_monthly_accidentbranch;
            fl_totaldifference += fl_branchdifference;

            // Average
            fl_branchaverage = (fl_monthly_firebranch + fl_monthly_accidentbranch) / 2;
            fl_totalaverage += fl_branchaverage;

            cout << GetMonthName(fl_month) << "\t\t " << fl_monthly_firebranch << "\t\t " << fl_monthly_accidentbranch << "\t\t " << fl_branchdifference << "\t\t " << fl_branchaverage << endl;
        }
        else if (fl_month >= 10 and fl_month <= 12) {
            // Fire branch

            fl_monthly_firebranch = fl_monthly_firebranch - (fl_monthly_firebranch * fl_firepercentage_dec)/100;
            fl_total_firebranch += fl_monthly_firebranch;

            // Accidents branch
            fl_monthly_accidentbranch = fl_monthly_accidentbranch - (fl_monthly_accidentbranch * fl_accidentpercentage_dec)/100;
            fl_total_accidentbranch += fl_monthly_accidentbranch;

            // Difference
            fl_branchdifference = fl_monthly_firebranch - fl_monthly_accidentbranch;
            fl_totaldifference += fl_branchdifference;

            // Average
            fl_branchaverage = (fl_monthly_firebranch + fl_monthly_accidentbranch) / 2;
            fl_totalaverage += fl_branchaverage;

            cout << GetMonthName(fl_month) << "\t\t " << fl_monthly_firebranch << "\t\t " << fl_monthly_accidentbranch << "\t\t " << fl_branchdifference << "\t\t " << fl_branchaverage << endl;
        }
        fl_month++;
    } while (fl_month <= FL_MAX_MONTHS);
    cout << "Total: \t\t" << fl_total_firebranch << "\t\t\t " << fl_total_accidentbranch << "\t\t\t" << fl_totaldifference << "\t\t" << fl_totalaverage << endl;
    cout << "El branch (ramo) de mayor siniestralidad es " << GetMajorBranchName(fl_total_firebranch, fl_total_accidentbranch) << " con: " << GetMajorBranch(fl_total_firebranch, fl_total_accidentbranch) << endl;
    return 0;
}