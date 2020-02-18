#include <stdio.h>
#include <stdlib.h>

/* Autor:    David Betancourt Montellano
   Objetivo: Practicar con el IDE dev C
   Fecha:    01-septiembre-2016 */
  
int main(int argc, char *argv[])
{
  char name[20]; //como un arreglo, con 20 carácteres
  int age = 0;
  char gender;
      
  printf("Escribe tu nombre: ");
  scanf("%s",&name); //leer desde teclado, "%s" indicamos el tipo de dato, &nom indica la dirección física en la memoria...  
  printf("Dame tu edad: ");
  scanf("%i",&age);
  printf("Dame tu clave de genero, m = masculino, otro = femenino");
  scanf("%s",&gender);
  
  if(age<=17) {
    printf("%s",name);   
    printf(" eres menor de edad ");
        
  }
  else {
    printf("%s",name);   
    printf(" eres mayor de edad ");    
  }
  
   if(gender=='m') {   
    printf(" tu género es masculino ");
        
  }
  else {   
    printf(" tu género es femenino ");    
  }
  
  system("PAUSE");	
  return 0;
}
