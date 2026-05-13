#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int opcion;
    double num1, num2;
    
    // Lista predefinida de alumnos
    string alumnos[] = {
        "Acosta Hanna", "Andrade Hugo", "Atiencia Josue", "Balarrezo Diego", 
        "Barrionuevo Sol", "Bedoya Juan", "Bravo Samuel", "Cajiao Paulo", 
        "Calvopina Brandon", "Castelo Katherine", "Chacha Victor", "Chiluiza Steed", 
        "Dominguez Daniel", "Freire Alan", "Gualle Abisag", "Guaman Alexander", 
        "Guanga Sebastian", "Guanotoa Karla", "Landeta Edison", "Lara Karen", 
        "Loor Jhon", "Lopez Washington", "Miranda Imanol", "Monar Jhair", 
        "Muyulema Mateo", "Narvaez Antonella", "Nunez Bryan", "Pilco Mario", 
        "Pomaquero Katherine", "Quevedo Gina", "Rivadeneira Matias", "Rocha Carolina", 
        "Sanchez Isaac", "Segovia Joseph", "Supe Joan", "Toapanta Matias", 
        "Verdesoto Kevin", "Villacres Alejandro", "Viteri Shantal"
    };
    int totalAlumnos = 39;

    do {
        cout << "\n===== MENU INTERACTIVO SISTEMA ESCOLAR =====" << endl;
        cout << "1. Operaciones basicas" << endl;
        cout << "2. Registrar notas de alumnos (39 estudiantes)" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                int operacion;
                cout << "\n--- OPERACIONES BASICAS ---" << endl;
                cout << "1. Suma\n2. Resta\n3. Multiplicacion\n4. Division" << endl;
                cout << "Seleccione: ";
                cin >> operacion;
                cout << "Ingrese numero 1: "; cin >> num1;
                cout << "Ingrese numero 2: "; cin >> num2;

                if(operacion == 1) cout << "Resultado: " << num1 + num2 << endl;
                else if(operacion == 2) cout << "Resultado: " << num1 - num2 << endl;
                else if(operacion == 3) cout << "Resultado: " << num1 * num2 << endl;
                else if(operacion == 4) {
                    if(num2 != 0) cout << "Resultado: " << num1 / num2 << endl;
                    else cout << "Error: Division por cero." << endl;
                } else {
                    cout << "Operacion no valida." << endl;
                }
                break;
            }

            case 2: {
                ofstream archivo("resultados.txt");
                if (!archivo.is_open()) {
                    cout << "Error al abrir el archivo." << endl;
                    break;
                }

                int aprobados = 0;
                int reprobados = 0;

                cout << "\n--- INICIANDO REGISTRO DE 39 ALUMNOS ---" << endl;
                archivo << "REPORTE ACADEMICO DETALLADO" << endl;
                archivo << "====================================" << endl;

                for (int i = 0; i < totalAlumnos; i++) {
                    double sumaNotas = 0, notaTemp, promedio;
                    cout << "\nEstudiante [" << i + 1 << "/39]: " << alumnos[i] << endl;

                    for (int j = 1; j <= 4; j++) {
                        cout << "  Ingrese nota " << j << ": ";
                        cin >> notaTemp;
                        sumaNotas += notaTemp;
                    }

                    promedio = sumaNotas / 4;
                    string estado = (promedio >= 7) ? "APROBADO" : "REPROBADO";

                    if (promedio >= 7) aprobados++;
                    else reprobados++;

                    cout << "  > Promedio: " << promedio << " (" << estado << ")" << endl;

                    // Escritura en archivo
                    archivo << "Nombre: " << alumnos[i] << endl;
                    archivo << "Promedio: " << promedio << " | Estado: " << estado << endl;
                    archivo << "------------------------------------" << endl;
                }

                // Resumen final
                cout << "\nRegistro completado con exito." << endl;
                cout << "Aprobados: " << aprobados << " | Reprobados: " << reprobados << endl;

                archivo << "\nRESUMEN GENERAL DEL GRUPO" << endl;
                archivo << "Total Aprobados: " << aprobados << endl;
                archivo << "Total Reprobados: " << reprobados << endl;
                archivo << "====================================" << endl;

                archivo.close();
                cout << "Todos los datos se han guardado en 'resultados.txt'." << endl;
                break;
            }

            case 3:
                cout << "Saliendo del sistema..." << endl;
                break;

            default:
                cout << "Opcion no valida, intente de nuevo." << endl;
        }

    } while(opcion != 3);

    return 0;
}