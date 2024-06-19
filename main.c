#include <stdio.h>
#include <stdlib.h>
#include "LibreriaInicio.h"
#include "LibreriaMenuPrincipal.h"

const char registro[]="registro.bin";
const char archivoAuto[]="autos.bin";
const char archPersonas[]="personas.bin";
const char archVentas[]="ventas.bin";


int main()
{
    AutoArchivo patentee;
    Persona doc;
    int opcion, opcionAuto=0, opcionPersona=0;
    int opcionMenPrin=0;
    int pos=0;
    int flag=0;
    int i=0;
    float total=0;
    Venta mayor;
    int validos=0;
    AutoArchivo * autosMenor;

    do
    {
        opcion=menuInicio();
        switch(opcion)
        {
        case 1:
            menuRegistro(registro);
            break;
        case 2:
            flag=menuInicioSesion(registro);
            system("cls");

            if(flag==1)
            {
                do
                {
                    opcionMenPrin=menuPrincipal();
                    switch(opcionMenPrin)
                    {
                    case 1:
                        printf("\tIngrese 1 si desea agregar autos o 2 si desea modificarlo: ");
                        scanf("%i", &opcionAuto);

                        if(opcionAuto==1)
                        {
                            agregarAuto (archivoAuto);
                        }
                        else if(opcionAuto==2)
                        {
                            modificarAuto(archivoAuto);
                        }
                        else
                        {
                            printf("\tEsa opcion no existe");
                            system("PAUSE");
                        }

                        break;

                    case 2:
                        printf("\tIngrese 1 si desea agregar una persona o 2 si desea modificarla: ");
                        scanf("%i",&opcionPersona);

                        if(opcionPersona==1)
                        {
                            agregarPersona(archPersonas);
                        }
                        else if(opcionPersona==2)
                        {
                            modificarPersona(archPersonas);
                        }
                        else
                        {
                            printf("\tEsa opcion no existe");
                            system("PAUSE");
                        }

                        break;

                    case 3:
                        mostrarPersonas(archPersonas);
                        system("PAUSE");

                        break;

                    case 4:
                        printf("\tIngrese el DNI de la persona que quiere ver: ");
                        scanf("%i",&doc.dni);
                        mostrarUNApersona(archPersonas, doc);
                        system("PAUSE");

                        break;

                    case 5:
                        mostrarAutos(archivoAuto);
                        system("PAUSE");

                        break;

                    case 6:
                        mostrarAutosEnVenta(archivoAuto, archPersonas);
                        system("PAUSE");

                        break;

                    case 7:
                        printf("\tIngrese la letras de la patente que quiere ver: ");
                        fflush(stdin);
                        scanf("%s", &patentee.patente.letras);
                        printf("\tIngrese los numeros de la patente que quiere ver: ");
                        fflush(stdin);
                        scanf("%s", &patentee.patente.numeros);

                        mostrarUNauto(archivoAuto, patentee);
                        system("PAUSE");

                        break;

                    case 8:
                        verVentas(archVentas);
                        system("PAUSE");
                        break;

                    case 9:
                        verUnaVenta(archVentas);
                        system("PAUSE");
                        break;

                    case 10:
                        registrarUnaVenta(archivoAuto,archVentas);
                        system("cls");
                        printf("\tAuto vendido con exito!!!\n");
                        system("PAUSE");
                        break;

                    case 11:
                        total=verRecaudacion(archVentas);
                        printf("\tLo recaudado fue: $%.2f\n", total);
                        system("PAUSE");
                        break;

                    case 12:
                        mayor=verMayorVenta(archVentas);
                        printf("\tEsta fue la mayor venta hasta el momento...\n");
                        mostrarUnaVentaLibre(mayor);
                        system("PAUSE");
                        break;

                    case 13:
                        validos=contAutosMenoresDiezAnios(archivoAuto);
                        autosMenoresDiezAnios(archivoAuto,&autosMenor,validos);
                        ordenarPorSeleccion(autosMenor,validos);
                        mostrarMenoresDiezAnios(autosMenor,validos);
                        system("PAUSE");
                        break;

                    default:
                        printf("\tOpcion incorrecta. Por favor, ingrese nuevamente\n");
                        break;
                    }
                    system("cls");
                }while(opcionMenPrin!=14);
            }
            else
            {
                printf("\tUsuario o contrasenia invalida\n");

            }

            break;
        case 3:
            system("cls");
            printf("\tAdios, nos vemos pronto!");
            break;

        default:
            printf("\tOpcion incorrecta. Por favor, ingrese nuevamente\n");
            break;
        }
        system("PAUSE");
        system("cls");
    }
    while(opcion!=3);

    return 0;
}
