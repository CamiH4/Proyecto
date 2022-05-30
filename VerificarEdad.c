#include <stdio.h>
typedef struct 
{
    char numCedula [50];
    char nomTutor [50];
    char apTutor [50];
    char fechaNac [50];
    char lugarNac [50];
    char domicilio [150];
}datos;
datos Registrodatos;
void VerificarEdad(int edad){
    
  if(edad >= 16){
      printf("Digite el numero de tu cedula: ");
      scanf(" %[^\n]", Registrodatos.numCedula);
      printf("Digita tu fecha de nacimiento (Por ejemplo: 06-05-2001 ): ");
      scanf(" %[^\n]", Registrodatos.fechaNac);
      printf("Digita tu lugar de nacimiento: ");
      scanf(" %[^\n]", Registrodatos.lugarNac);
      printf("Escribe tu domicilio: ");
      scanf(" %[^\n]", Registrodatos.domicilio);
  } 
  else{
      printf("Escribe los nombres del tutor: ");
      scanf(" %[^\n]", Registrodatos.nomTutor);
      printf("Escribe los apellidos del tutor: ");
      scanf(" %[^\n]", Registrodatos.apTutor);
      printf("Digita tu lugar de nacimiento: ");
      scanf(" %[^\n]", Registrodatos.lugarNac);
      printf("Escribe tu domicilio: ");
      scanf(" %[^\n]", Registrodatos.domicilio);
  }
}
