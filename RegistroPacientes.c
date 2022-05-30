#include <stdio.h>
#include "VerificarEdad.c"

FILE *salida;
FILE *cPacientes;
int cantPacientes = 0;

typedef struct
{
    char nombres[50];
    char sexo[50];
    char apellidos[70];
    int edad;
} paciente;
paciente RegistroPaciente;

void VerificarEdad(int edad);

void leerCantPaci(){
    FILE *cPacientes = fopen("cantPacientes.bin", "rb");
    if (cPacientes == NULL)
    {
        cantPacientes = 0;
        fwrite(&cantPacientes, sizeof(int), 1, cPacientes);
    } else
    {
       fread(&cantPacientes, sizeof(int), 1, cPacientes);
    }
    fclose(cPacientes);
}

void RegistroPacientes()
{
    leerCantPaci();
    cPacientes = fopen("cantPacientes.bin", "wb");
    printf("Escriba su sexo (tiene que ser Masculino o Femenino): ");
    scanf(" %[^\n]", RegistroPaciente.sexo);
    printf("Escriba sus nombres: ");
    scanf(" %[^\n]", RegistroPaciente.nombres);
    printf("Escriba sus apellidos: ");
    scanf(" %[^\n]", RegistroPaciente.apellidos);
    printf("Digita tu edad: ");
    scanf("%d", &RegistroPaciente.edad);
    VerificarEdad(RegistroPaciente.edad);
   
    FILE *salida;
    salida = fopen("RegistroPaciente.bin", "ab");
    fwrite(&RegistroPaciente, sizeof(paciente), 1, salida);
    cantPacientes++;
    fwrite(&cantPacientes, sizeof(int), 1, cPacientes);
    fclose(salida);
    fclose(cPacientes);
    

}
