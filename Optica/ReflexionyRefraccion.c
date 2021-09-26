#include<stdio.h>
#include <float.h>
#include<math.h>


#define MAX         20                              //Ancho del arreglo
#define VLUZ        300000                          //Velocidad de la luz en km/s

unsigned char Obtener_linea(unsigned char arreglo[], char rango);
void ImprimirArregloChar(unsigned char arreglo[], char rango);
//          -------------------------------------------
void intercambiar(unsigned char *a, unsigned char *b);
void quicksort(unsigned char arreglo[], unsigned char izquierda, unsigned char derecha);
int particion(unsigned char arreglo[], unsigned char izquierda, unsigned char derecha);
//------------------------------------------------------------------------------
float Rapidez_Luz_En_Material(float n);
float IRefraccion_Velocidades(float Vm);
float IRefraccion_Senoidales(float nb, double Ab, double Aa);
double Angulo_In(float nb, double Ab, float na);
//------------------------------------------------------------------------------
double Conversn_Grado_Radian(double Ang);
double Conversn_Radian_Grado(double ARad);

//void OrdenarDatosIniciales();

void main(){

    unsigned char longitud;
    unsigned char linea[MAX];                                //Arreglo de datos iniciales
    //char lordenada[MAX];                            //Arreglo de datos iniciales ordenados
    unsigned char prueba[]={40,2,33,21,5};

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

    ImprimirArregloChar(linea, MAX);

    printf("\nLa rapidez de la luz en el agua es: %.2f km/s", Rapidez_Luz_En_Material(1.33));
    printf("\nEl indice de refraccion de la luz en el agua es: %.2f", IRefraccion_Velocidades(225563.91));
    printf("\nEl indice de refraccioin dado los angulos y un indice de refraccion es: %.2f", IRefraccion_Senoidales(1.33, 45, 70));
    printf("\nEl angulo de incidencia a es: %.2f", Angulo_In(1.33, 45, 1));
    //OrdenarDatosIniciales();

    //int fin_aordenado = sizeof linea / sizeof linea[0];
    quicksort(prueba, 0, 5);
    printf("\n\nImprimiendo arreglo despues de ordenar...\n");
    ImprimirArregloChar(prueba, 5);
}

//LÓGICA DEL PROGRAMA------------------------------------------------------------------------------

unsigned char Obtener_linea(unsigned char arreglo[], char rango){
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

void ImprimirArregloChar(unsigned char arreglo[], char rango){
    for(int i=0;arreglo[i]!='\0'&& i<rango;++i){
        printf("%d ", arreglo[i]);
    }
}

//-----------Ordenar el arreglo--------------------------------------
void intercambiar(unsigned char *a, unsigned char *b) {
  unsigned char temporal = *a;
  *a = *b;
  *b = temporal;
}

void quicksort(unsigned char arreglo[], unsigned char izquierda, unsigned char derecha) {
  if (izquierda < derecha) {
    unsigned char indiceParticion = particion(arreglo, izquierda, derecha);
    quicksort(arreglo, izquierda, indiceParticion);
    quicksort(arreglo, indiceParticion + 1, derecha);
  }
}

int particion(unsigned char arreglo[], unsigned char izquierda, unsigned char derecha) {
    int pivote = arreglo[izquierda];
    while(1){
        while(arreglo[izquierda]<pivote){
            ++izquierda;
        }
        while(arreglo[derecha]>pivote){
            --derecha;
        }
        if(izquierda>=derecha){
            return derecha;
        }
        else{
            intercambiar(&arreglo[izquierda], &arreglo[derecha]);
            ++izquierda;
            --derecha;
        }
    }
}

//FORMULAS FÍSICAS-----------------------------------------------------------------------------------

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

float IRefraccion_Senoidales(float nb, double Ab, double Aa){
    float na;
   
    //Convertir las razones  senoidales a razones en funcion de grados
    Ab=Conversn_Grado_Radian(Ab);
    Aa=Conversn_Grado_Radian(Aa);
    na=nb*(sin(Ab)/sin(Aa));
    return na;
}

double Angulo_In(float nb, double Ab, float na){
    double Aa;
    
    Ab=Conversn_Grado_Radian(Ab);
    Aa=asin((nb/na)*sin(Ab));
    Aa=Conversn_Radian_Grado(Aa);
    return Aa;
}

//CONVERSIONES------------------------------------------------------------------------------------
double Conversn_Grado_Radian(double Ang){
    Ang=Ang*(M_PI/180);
    return Ang;
}

double Conversn_Radian_Grado(double ARad){
    ARad=ARad*(180/M_PI);
    return ARad;
}