#include <stdio.h>
#include <stdlib.h>
#include "VerificarDosis.c"
#include "RegistroPacientes.c"
#include "Seguimiento.c"
#include "MostrarPacientes.c";
#include "Menu.c"

int verificarDosis();
void RegistroPacientes();
void seguimiento();
void imprimirMenu();

int main(int argc, char const *argv[])
{
    char efectos[500];
    int op;
    int primeraDosis;
    char numHosp[50] = "2289-6471";
    
    do
    {
        imprimirMenu();
        printf("Ingrese una opcion: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            system("cls");
            primeraDosis = verificarDosis();
            if (primeraDosis == 1)
            {
                printf("¿Cuales? \n");
                scanf("%s", &efectos);
                printf("Se evaluara su condicion, por favor solicite seguimiento. \n");
                printf("Por favor llame a este numero: %d \n", numHosp);
                printf("Vuelva dentro de una semana. \n");
            }
            else
            {
                RegistroPacientes();
                seguimiento();
            }
            break;
        case 2:
            abrirPacientes();
            mostrarPacientes();
            break;
        default:
            printf("Opcion no valida... \n");
            break;
        }
    } while (op != 2);

    return 0;
}
