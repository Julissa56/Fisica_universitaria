#include<stdio.h>
#include <float.h>
#define MAX         20                              //Ancho del arreglo
#define VLUZ        300000                          //Velocidad de la luz en km/s

unsigned char Obtener_linea(char arreglo[], char rango);
void ImprimirDatosIniciales(char arreglo[], char rango);
float Rapidez_Luz_En_Material(float n);
float IRefraccion_Velocidades(float Vm);

//void OrdenarDatosIniciales();

void main(){

    unsigned char longitud;
    char linea[MAX];                                //Arreglo de datos iniciales
    char lordenada[MAX];                            //Arreglo de datos iniciales ordenados

    printf("\n\nINDICE DE REFRACCI%cN\n", 224);
    printf("De la siguiente lista, ingrese el codigo de los datos con los que cuenta:\n\n");
    printf("1 - %cngulo de reflexi%cn o incidencia (respecto interfaz)\n", 181, 162);
    printf("2 - %cngulo de reflexi%cn o incidencia (respecto normal)\n", 181, 162);
    printf("3 - Indice de refracci%cn (material A)\n", 162);
    printf("4 - Indice de refracci%cn (material B)\n", 162);
    printf("5 - R%cpidez de la luz (material A)\n", 160);
    printf("6 - R%cpidez de la luz (material B)\n\n", 160);

    //Leer una linea, separada por blancos (lee solo numeros)

    while((longitud=Obtener_linea(linea, MAX))==0){
        ;
    }

    ImprimirDatosIniciales(linea, MAX);

    printf("\nLa rapidez de la luz en el agua es: %.2f km/s", Rapidez_Luz_En_Material(1.33));
    printf("\nEl indice de refraccion de la luz en el agua es: %.2f", IRefraccion_Velocidades(225563.91));
    //OrdenarDatosIniciales();
}

unsigned char Obtener_linea(char arreglo[], char rango){
    unsigned char i, c;

    for(i=0; i<rango-1 && (c=getchar())!=EOF && c!='\n';++i){
        if(c>='1' && c<='9'){
            arreglo[i]=c;
        }
        else{
            --i;
        }    
    }
    if(c=='\n'){
        arreglo[i]='\0';
    }
    return i;                                       //Cuenta cuantos caracteres hay en el arreglo
}

void ImprimirDatosIniciales(char arreglo[], char rango){
    for(int i=0;arreglo[i]!='\0'&& i<rango;++i){
        printf("%c ", arreglo[i]);
    }
}

float Rapidez_Luz_En_Material(float n){             //En unidades de km/s
    float rm;
    rm=VLUZ/n;
    
    return rm;   
}

float IRefraccion_Velocidades(float rm){
    float n;
    n=VLUZ/rm;

    return n;
}