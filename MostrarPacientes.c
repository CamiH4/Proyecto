#include <stdio.h>
//
typedef struct
{
    char nombres[50];
    char sexo[50];
    char apellidos[70];
    int edad;
} contenedorPacientes;

contenedorPacientes arregloPacientes[1000];

FILE *numPacientes;
FILE *pacientes;
int cantidadPacientes = 0;

void abrirPacientes()
{
    numPacientes = fopen("cantPacientes.bin", "rb");
    pacientes = fopen("registroPaciente.bin", "rb");

    if(numPacientes == NULL || pacientes == NULL)
    {
        printf("Error\n");
    } else fread(&cantidadPacientes, sizeof(int), 1, numPacientes);

    fread(&arregloPacientes, sizeof(contenedorPacientes) * cantidadPacientes, 1, pacientes);
    fclose(pacientes);
}

void mostrarPacientes()
{
    for(int i = 0; i < cantidadPacientes; i++) 
    {
        printf("==================================\n");
        printf("Nombre: %s\n", arregloPacientes[i].nombres);
        printf("Apellidos: %s\n", arregloPacientes[i].apellidos);
        printf("Sexo: %s\n", arregloPacientes[i].sexo);
        printf("Edad: %d\n", arregloPacientes[i].edad);
        printf("==================================\n");
    }
}