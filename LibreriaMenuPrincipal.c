#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LibreriaMenuPrincipal.h"
#include "pila.h"

///PARA FUNCIONES DEL MENU PRINCIPAL

int menuPrincipal()
{
    int input ;
    int flag = 0;

    mostrarLogo();

    system("color F");
    printf("\t1  - Agregar / modificar un auto\n");
    printf("\t2  - Agregar / modificar una persona.\n");
    printf("\t3  - Ver listado de personas\n");
    printf("\t4  - Ver info de una persona\n");
    printf("\t5  - Ver listado de autos\n");
    printf("\t6  - Ver autos en venta\n");
    printf("\t7  - Ver info de un auto\n");
    printf("\t8  - Ver ventas\n");
    printf("\t9  - Ver venta\n");
    printf("\t10 - Registrar una venta\n");
    printf("\t11 - Calcular cuanto se recaudo en determinado mes, de determinado anio\n");
    printf("\t12 - Calcular cual fue la venta que genero mayor ganancia hasta el momento\n");
    printf("\t13 - Ver los autos que tengan menos de 10 anios, por orden de antiguedad\n");
    printf("\t14 - Salir\n\n");

    while(flag == 0 )
    {
        printf("\tIngrese que opcion desea realizar: ");
        scanf("%i", &input);

        system("cls");
        mostrarLogo();

        if(input > 13 && input < 1 && !isdigit(input) )
        {
            printf("dato incorrecto: \n");

        }
        else
        {
            flag = 1;
        }
    }
    return input;
}
///FUNCION PARA MOSTRAR LOGO
void mostrarLogo()
{
    printf(" \t\t    _     _   _  _______   ____      ______   _       _____   _____   ______\n");
    printf("\t\t   / \\   | | | ||__   __| / __ \\    |  ____| | |     |_   _| |_   _| |  ____|\n");
    printf("\t\t  / _ \\  | | | |   | |   | | | |    | |____  | |       | |     | |   | |____ \n");
    printf("\t\t / ___ \\ | |_| |   | |   | | | |    |  ____| | |___   _| |_    | |   |  ____|\n");
    printf("\t\t/_/   \\_\  \\___/    |_|    \\____/    | |____  |_____| |_____|   |_|   | |____ \n\n\n");
}
///FUNCION PARA AGREGAR/MODIFICAR UN AUTO
int validarPatente(char archivoAuto[], AutoArchivo vehiculo)
{
    int flag=0;
    AutoArchivo vehiculoAux;

    FILE * buff = fopen(archivoAuto, "rb");
    if(buff != NULL)
    {
        while(flag==0 && fread(&vehiculoAux,sizeof(AutoArchivo),1,buff)>0)
        {
            if(strcmp(vehiculo.patente.letras,vehiculoAux.patente.letras)==0 && strcmp(vehiculo.patente.numeros,vehiculoAux.patente.numeros)==0)
            {
                flag=1;
            }
        }
        fclose(buff);
    }

    return flag;
}

int validarPatente2(char archVentas[], char letras[], char numeros[])
{
    int flag=0;
    Venta vehiculoAux;

    FILE * buff = fopen(archVentas, "rb");
    if(buff != NULL)
    {
        while(flag==0 && fread(&vehiculoAux,sizeof(Venta),1,buff)>0)
        {
            if(strcmp(letras,vehiculoAux.autoAVender.letras)==0 && strcmp(numeros,vehiculoAux.autoAVender.numeros)==0)
            {
                flag=1;
            }
        }
        fclose(buff);
    }

    return flag;
}

int validarPatente3(char archivoAuto[], char letras[], char numeros[])
{
    int flag=0;
    AutoArchivo vehiculoAux;

    FILE * buff = fopen(archivoAuto, "rb");
    if(buff != NULL)
    {
        while(flag==0 && fread(&vehiculoAux,sizeof(AutoArchivo),1,buff)>0)
        {
            if(strcmp(letras,vehiculoAux.patente.letras)==0 && strcmp(numeros,vehiculoAux.patente.numeros)==0)
            {
                flag=1;
            }
        }
        fclose(buff);
    }

    return flag;
}

///3A
void agregarAuto (char archivoAuto[])
{
    AutoArchivo vehiculos;
    char seguir='s';
    int validacion=0, flag=0;
    char patenteAux[6];

    FILE * buff = fopen(archivoAuto,"ab");

    if(buff!=NULL)
    {
        while(seguir=='s')
        {
            printf("\tIngrese la marca: ");
            fflush(stdin);
            gets(vehiculos.marca);

            printf("\tIngrese el modelo: ");
            fflush(stdin);
            scanf("%s",&vehiculos.modelo);

            printf("\tIngrese las letras de la patente(Maximo 3): ");
            fflush(stdin);
            scanf("%s",&vehiculos.patente.letras);

            while(strlen(vehiculos.patente.letras)!=3)
            {
                printf("\tERROR!Ingrese las letras de la patente nuevamente: ");
                fflush(stdin);
                scanf("%s",&vehiculos.patente.letras);
            }

            printf("\tIngrese los numeros de la patente(Maximo 3): ");
            fflush(stdin);
            scanf("%s",&vehiculos.patente.numeros);

            while(strlen(vehiculos.patente.numeros)!=3)
            {
                printf("\tERROR!Ingrese los numeros de la patente nuevamente: ");
                fflush(stdin);
                scanf("%s",&vehiculos.patente.numeros);
            }

            flag=validarPatente(archivoAuto,vehiculos);

            while(flag==1)
            {
                printf("\tEsta patente ya existe\n");
                printf("\tIngrese las letras de la patente(Maximo 3): ");
                fflush(stdin);
                scanf("%s",&vehiculos.patente.letras);

                while(strlen(vehiculos.patente.letras)!=3)
                {
                    printf("\tERROR!Ingrese las letras de la patente nuevamente: ");
                    fflush(stdin);
                    scanf("%s",&vehiculos.patente.letras);
                }

                printf("\tIngrese los numeros de la patente(Maximo 3): ");
                fflush(stdin);
                scanf("%s",&vehiculos.patente.numeros);

                while(strlen(vehiculos.patente.numeros)!=3)
                {
                    printf("\tERROR!Ingrese los numeros de la patente nuevamente: ");
                    fflush(stdin);
                    scanf("%s",&vehiculos.patente.numeros);
                }

                flag=validarPatente(archivoAuto,vehiculos);
            }

            printf("\tIngrese el anio: ");
            scanf("%i",&vehiculos.anio);

            while(vehiculos.anio>2024)
            {
                printf("\tERROR!Ingrese el anio de nuevo: ");
                scanf("%i",&vehiculos.anio);
            }

            printf("\tIngrese los kms: ");
            scanf("%i",&vehiculos.kms);

            validacion=0;

            printf("\tIngrese DNI titular: ");
            scanf("%i",&vehiculos.dniTitular);
            validacion=contarInt(vehiculos.dniTitular);

            while(validacion!=8)
            {
                printf("\tEl DNI es incorrecto\n");
                printf("\tIngrese nuevamente el DNI a continuacion: ");
                scanf("%i", &vehiculos.dniTitular);
                validacion=contarInt(vehiculos.dniTitular);
            }

            printf("\tIngrese el precio: $ ");
            scanf("%f",&vehiculos.precioDeAdquisicion);

            printf("\tSi desea agregar otro auto, ingrese S.");
            fflush(stdin);
            scanf("%c",&seguir);

            fwrite(&vehiculos,sizeof(AutoArchivo),1,buff);
        }
        fclose(buff);
    }
}
void modificarAuto(char archivoAuto[])
{
    char dosOpciones;
    char datoAModificar;
    AutoArchivo patenteAutoModificar;
    int pos=0, cant=0, flag=0;

    while(flag==0)
    {
        printf("\tIngrese las letras de la patente del auto a modificar(Maximo 3): ");
        fflush(stdin);
        scanf("%s",&patenteAutoModificar.patente.letras);

        while(strlen(patenteAutoModificar.patente.letras)!=3)
        {
            printf("\tERROR!Ingrese las letras de la patente nuevamente: ");
            fflush(stdin);
            scanf("%s",&patenteAutoModificar.patente.letras);
        }

        printf("\tIngrese los numeros de la patente del auto a modificar(Maximo 3): ");
        fflush(stdin);
        scanf("%s",&patenteAutoModificar.patente.numeros);

        while(strlen(patenteAutoModificar.patente.numeros)!=3)
        {
            printf("\tERROR!Ingrese los numeros de la patente nuevamente: ");
            fflush(stdin);
            scanf("%s",&patenteAutoModificar.patente.numeros);
        }

        flag=validarPatente(archivoAuto,patenteAutoModificar);

        if(flag==0)
        {
            printf("\tLa patente que ingreso no existe, ingrese nuevamente...\n");
        }
    }

    printf("\tIngrese si desea modificar todo el auto(t) o solo un dato del auto(d): ");
    fflush(stdin);
    scanf("%c",&dosOpciones);

    while(dosOpciones != 'd' && dosOpciones != 't')
    {
        printf("\tEsa opcion es incorrecta\n");
        printf("\tIngrese si desea modificar todo el auto(t) o solo un dato del auto(d): ");
        fflush(stdin);
        scanf("%c",&dosOpciones);
    }

    if(dosOpciones=='t')
    {
        modificarTodoElRegistro (archivoAuto, patenteAutoModificar);

    }
    else if(dosOpciones=='d')
    {

        printf("\tA-Modificar Marca\n\tB-Modificar Modelo\n\tC-Modificar patente\n\tD-Modificar anio\n\tE-Modificar kms\n\tF-Modificar DNI del Titular\n\tG-Modificar Precio\n");
        printf("\n\tIngrese el dato que desea modificar:");
        fflush(stdin);
        scanf("%c", &datoAModificar);

        while(datoAModificar > 'g')
        {
            printf("\tA-Modificar Marca\n\tB-Modificar Modelo\n\tC-Modificar patente\n\tD-Modificar anio\n\tE-Modificar kms\n\tF-Modificar DNI del Titular\n\tG-Modificar Precio\n");
            printf("\n\tIngrese el dato que desea modificar:");
            fflush(stdin);
            scanf("%c", &datoAModificar);
        }

        if(datoAModificar=='a')
        {
            modificarMarca(archivoAuto, patenteAutoModificar);
        }
        else if(datoAModificar=='b')
        {
            modificarModelo(archivoAuto, patenteAutoModificar);
        }
        else if(datoAModificar=='c')
        {
            modificarPatente(archivoAuto, patenteAutoModificar);
        }
        else if(datoAModificar=='d')
        {
            modificarAnio(archivoAuto, patenteAutoModificar);
        }
        else if(datoAModificar=='e')
        {
            modificarKms(archivoAuto, patenteAutoModificar);
        }
        else if(datoAModificar=='f')
        {
            modificarDNI (archivoAuto, patenteAutoModificar);
        }
        else if(datoAModificar=='g')
        {
            modificarPrecio (archivoAuto, patenteAutoModificar);
        }
    }
}
void modificarMarca(char archivoAuto[], AutoArchivo patentee)
{
    FILE * buff=fopen(archivoAuto, "r+b");
    AutoArchivo vehiculoAux;
    int flag=0;
    char nuevaMarca[30];

    if(buff!=NULL)
    {
        while(flag==0 && fread(&vehiculoAux,sizeof(AutoArchivo),1,buff)>0)
        {
            if(strcmp(patentee.patente.letras, vehiculoAux.patente.letras)==0 && strcmp(patentee.patente.numeros, vehiculoAux.patente.numeros)==0)
            {
                flag=1;
            }
        }
            fseek(buff,sizeof(AutoArchivo) * (-1), SEEK_CUR);

            printf("\tIngrese la nueva marca: ");
            fflush(stdin);
            gets(nuevaMarca);

            strcpy(vehiculoAux.marca, nuevaMarca);

            fwrite(&vehiculoAux,sizeof(AutoArchivo),1,buff);

            fclose(buff);
    }

}
void modificarModelo(char archivoAuto[], AutoArchivo patentee)
{
    FILE * buff=fopen(archivoAuto, "r+b");
    AutoArchivo vehiculoAux;
    char nuevaModelo[30];
    int flag=0;

    if(buff!=NULL)
    {
        while(flag==0 && fread(&vehiculoAux,sizeof(AutoArchivo),1,buff)>0)
        {
            if(strcmp(patentee.patente.letras, vehiculoAux.patente.letras)==0 && strcmp(patentee.patente.numeros, vehiculoAux.patente.numeros)==0)
            {
                flag=1;
            }
        }

        fseek(buff,sizeof(AutoArchivo) * (-1), SEEK_CUR);

        printf("\tIngrese el nuevo modelo: ");
        fflush(stdin);
        gets(nuevaModelo);

        strcpy(vehiculoAux.modelo,nuevaModelo);

        fwrite(&vehiculoAux,sizeof(AutoArchivo),1,buff);

        fclose(buff);
    }
}
void modificarPatente(char archivoAuto[], AutoArchivo patentee)
{
    FILE * buff=fopen(archivoAuto, "r+b");
    AutoArchivo vehiculoAux;
    int flag=0;

    if(buff!=NULL)
    {
        while(flag==0 && fread(&vehiculoAux,sizeof(AutoArchivo),1,buff)>0)
        {
            if(strcmp(patentee.patente.letras, vehiculoAux.patente.letras)==0 && strcmp(patentee.patente.numeros, vehiculoAux.patente.numeros)==0)
            {
                flag=1;
            }
        }

        fseek(buff,sizeof(AutoArchivo) * (-1), SEEK_CUR);

        flag=0;

        do
        {
            if(flag==1)
            {
                printf("\tEsa patente ya existe, ingrese otra...\n");
            }

            printf("\tIngrese las letras de la patente nueva(Maximo 3): ");
            fflush(stdin);
            gets(vehiculoAux.patente.letras);

            while(strlen(vehiculoAux.patente.letras)!=3)
            {
                printf("\tERROR!Ingrese las letras de la patente nuevamente: ");
                fflush(stdin);
                gets(vehiculoAux.patente.letras);
            }

            printf("\tIngrese los numeros de la patente nueva(Maximo 3): ");
            fflush(stdin);
            gets(vehiculoAux.patente.numeros);

            while(strlen(vehiculoAux.patente.numeros)!=3)
            {
                printf("\tERROR!Ingrese los numeros de la patente nuevamente: ");
                fflush(stdin);
                gets(vehiculoAux.patente.numeros);
            }

            flag=validarPatente(archivoAuto,vehiculoAux);
        }
        while(flag==1);

        fwrite(&vehiculoAux,sizeof(AutoArchivo),1,buff);

        fclose(buff);
    }
}
void modificarAnio(char archivoAuto[], AutoArchivo patentee)
{
    FILE * buff=fopen(archivoAuto, "r+b");
    AutoArchivo vehiculoAux;
    int nuevoAnio, flag=0;

    if(buff!=NULL)
    {
        while(flag==0 && fread(&vehiculoAux,sizeof(AutoArchivo),1,buff)>0)
        {
            if(strcmp(patentee.patente.letras, vehiculoAux.patente.letras)==0 && strcmp(patentee.patente.numeros, vehiculoAux.patente.numeros)==0)
            {
                flag=1;
            }
        }

        fseek(buff,sizeof(AutoArchivo) * (-1), SEEK_CUR);

            do
            {
                printf("\tIngrese el nuevo anio: ");
                scanf("%i", &nuevoAnio);
            }
            while(nuevoAnio > 2024);

            vehiculoAux.anio=nuevoAnio;

            fwrite(&vehiculoAux,sizeof(AutoArchivo),1,buff);

            fclose(buff);
    }
}
void modificarKms(char archivoAuto[], AutoArchivo patentee)
{
    FILE * buff=fopen(archivoAuto, "r+b");
    AutoArchivo vehiculoAux;
    int nuevoKMS=0, flag=0;

    if(buff!=NULL)
    {
        while(flag==0 && fread(&vehiculoAux,sizeof(AutoArchivo),1,buff)>0)
        {
            if(strcmp(patentee.patente.letras, vehiculoAux.patente.letras)==0 && strcmp(patentee.patente.numeros, vehiculoAux.patente.numeros)==0)
            {
                flag=1;
            }
        }

        fseek(buff,sizeof(AutoArchivo) * (-1), SEEK_CUR);

            printf("\tIngrese el nuevo kilometraje: ");
            scanf("%i", &nuevoKMS);
            vehiculoAux.kms=nuevoKMS;

            fwrite(&vehiculoAux,sizeof(AutoArchivo),1,buff);

        fclose(buff);
    }
}
void modificarDNI (char archivoAuto[], AutoArchivo patentee)
{
    FILE * buff=fopen(archivoAuto, "r+b");
    AutoArchivo vehiculoAux;
    int nuevoDNI,validacion=0,flag=0;

    if(buff!=NULL)
    {
        while(flag==0 && fread(&vehiculoAux,sizeof(AutoArchivo),1,buff)>0)
        {
            if(strcmp(patentee.patente.letras, vehiculoAux.patente.letras)==0 && strcmp(patentee.patente.numeros, vehiculoAux.patente.numeros)==0)
            {
                flag=1;
            }
        }

        fseek(buff,sizeof(AutoArchivo) * (-1), SEEK_CUR);

            do
            {
                printf("\tIngrese el nuevo dni: ");
                scanf("%i", &nuevoDNI);
                validacion=contarInt(nuevoDNI);
            }
            while(validacion!=8);

            vehiculoAux.dniTitular=nuevoDNI;

            fwrite(&vehiculoAux,sizeof(AutoArchivo),1,buff);

            fclose(buff);
    }
}
void modificarPrecio (char archivoAuto[], AutoArchivo patentee)
{
    FILE * buff=fopen(archivoAuto, "r+b");
    AutoArchivo vehiculoAux;
    float nuevoPrecio;
    int flag=0;

    if(buff!=NULL)
    {
        while(flag==0 && fread(&vehiculoAux,sizeof(AutoArchivo),1,buff)>0)
        {
            if(strcmp(patentee.patente.letras, vehiculoAux.patente.letras)==0 && strcmp(patentee.patente.numeros, vehiculoAux.patente.numeros)==0)
            {
                flag=1;
            }
        }

        fseek(buff,sizeof(AutoArchivo) * (-1), SEEK_CUR);

            printf("\tIngrese el nuevo precio: ");
            scanf("%f", &nuevoPrecio);
            vehiculoAux.precioDeAdquisicion=nuevoPrecio;

            fwrite(&vehiculoAux,sizeof(AutoArchivo),1,buff);

            fclose(buff);
    }
}
void modificarTodoElRegistro (char archivoAuto[], AutoArchivo patentee)
{
    modificarMarca(archivoAuto, patentee);
    modificarModelo(archivoAuto, patentee);
    modificarAnio(archivoAuto, patentee);
    modificarKms(archivoAuto, patentee);
    modificarDNI(archivoAuto, patentee);
    modificarPrecio(archivoAuto, patentee);
    modificarPatente(archivoAuto, patentee);
}

///3B
int validarTelefono (char archPersonas[], Persona doc)
{
    FILE * buff = fopen(archPersonas, "rb");
    int flag=0;
    Persona aux;

    if(buff!=NULL)
    {
        while(flag==0 && fread(&aux,sizeof(Persona),1,buff)>0)
        {
            if(doc.telefono==aux.telefono)
            {
                flag=1;
            }
        }
        fclose(buff);
    }
    return flag;
}
int validarDni2(char archPersonas[],  Persona usuarioAvalidar)///es para personas
{
    FILE * buff=fopen(archPersonas, "rb");
    Persona usuario;
    int flag=0;

    if(buff!=NULL)
    {
        while(fread(&usuario,sizeof(Persona),1,buff)>0 && flag==0)
        {
            if(usuario.dni==usuarioAvalidar.dni)
            {
                flag=1;
            }
        }
        fclose(buff);
    }
    return flag;

}
void agregarPersona (char archPersonas[])
{
    Persona personas;
    char comprador[]="comprador";
    char vendedor[]="vendedor";
    char seguir='s';
    int flag=0;
    int validacion=0;

    FILE * buff = fopen(archPersonas,"ab");

    if(buff!=NULL)
    {
        while(seguir=='s')
        {
            printf("\tIngrese DNI: ");
            scanf("%i",&personas.dni);
            validacion=contarInt(personas.dni);
            flag=validarDni2(archPersonas, personas);

            while(validacion!=8 || flag==1)
            {
                printf("\tEl DNI es incorrecto o ya existe\n");
                printf("\tIngrese nuevamente el DNI a continuacion: ");
                scanf("%i", &personas.dni);
                validacion=contarInt(personas.dni);
                flag=validarDni2(archPersonas, personas);
            }

            printf("\tIngrese su nombre: ");
            fflush(stdin);
            gets(personas.nombre);

            printf("\tIngrese su nro de telefono: 223 ");
            scanf("%i", &personas.telefono);
            validacion=0;
            validacion=contarInt(personas.telefono);

            flag=0;
            flag = validarTelefono (archPersonas, personas);

            while(validacion!=7 || flag==1)
            {
                printf("\tEl nro de telefono es incorrecto o ya existe\n");
                printf("\tIngrese nuevamente el telefono a continuacion: 223 ");
                scanf("%i", &personas.telefono);
                validacion=contarInt(personas.telefono);
                flag = validarTelefono (archPersonas, personas);
            }

            printf("\tIngrese su domicilio: ");
            fflush(stdin);
            gets(personas.direccion);

            printf("\tIngrese si es comprador o vendedor: ");
            fflush(stdin);
            scanf("%s",&personas.rol);

            while(strcmp(personas.rol,comprador)!=0 && strcmp(personas.rol,vendedor)!=0)
            {
                printf("\tNo es un rol valido\n");
                printf("\tIngrese nuevamente su rol: ");
                fflush(stdin);
                scanf("%s",&personas.rol);
            }

            printf("\tSi desea agregar otra persona, ingrese S.");
            fflush(stdin);
            scanf("%c",&seguir);

            fwrite(&personas,sizeof(Persona),1,buff);
        }
        fclose(buff);
    }
}
void modificarPersona(char archPersonas[])
{
    char dosOpciones;
    char datoAModificar;
    int flag=0;
    Persona doc;

    printf("\tIngrese el dni de la persona que quiere modificar: ");
    scanf("%i", &doc.dni);

    flag = validarDni2(archPersonas, doc);

    while(flag==0)
    {
        printf("\tEste DNI no existe\n");
        printf("\tIngrese nuevamente el DNI a modificar: ");
        scanf("%i", &doc.dni);
        flag = validarDni2(archPersonas, doc);
    }

    printf("\tIngrese si desea modificar toda la persona(t) o solo un dato (d): ");
    fflush(stdin);
    scanf("%c",&dosOpciones);

    while(dosOpciones != 'd' && dosOpciones != 't')
    {
        printf("\tEsa opcion es incorrecta\n");
        printf("\tIngrese si desea modificar toda la persona (t) o solo un dato(d): ");
        fflush(stdin);
        scanf("%c",&dosOpciones);
    }

    if(dosOpciones=='t')
    {
        modificarPersCompleta(archPersonas, doc);
    }
    else if(dosOpciones=='d')
    {
        printf("\tA-Modificar DNI\n\tB-Modificar nombre\n\tC-Modificar telefono\n\tD-Modificar domicilio\n\tE-Modificar rol");
        printf("\n\tIngrese el dato que desea modificar:");
        fflush(stdin);
        scanf("%c", &datoAModificar);

        while(datoAModificar > 'e')
        {
            printf("\tA-Modificar DNI\n\tB-Modificar nombre\n\tC-Modificar telefono\n\tD-Modificar domicilio\n\tE-Modificar rol");
            printf("\n\tIngrese el dato que desea modificar:");
            fflush(stdin);
            scanf("%c", &datoAModificar);
        }

        if(datoAModificar=='a')
        {
            modificarPersonaDni(archPersonas, doc);
        }
        else if(datoAModificar=='b')
        {
            modificarPersonaNombre(archPersonas, doc);
        }
        else if(datoAModificar=='c')
        {
            modificarPersonaTelefono(archPersonas, doc);
        }
        else if(datoAModificar=='d')
        {
            modificarPersonaDomicilio(archPersonas, doc);
        }
        else if(datoAModificar=='e')
        {
            modificarPersonaRol(archPersonas, doc);
        }
    }
}
void modificarPersonaDni (char archPersonas[], Persona doc)
{
    FILE * buff=fopen(archPersonas, "r+b");
    Persona personaAux;
    int validacion=0, flag=0;

    if(buff!=NULL)
    {
        while(flag==0 && fread(&personaAux,sizeof(archPersonas),1,buff)>0)
        {
            if(personaAux.dni==doc.dni)
            {
                flag=1;
            }
        }

        fseek(buff,sizeof(archPersonas) * (-1), SEEK_CUR);

        printf("\tIngrese el nuevo DNI: ");
        scanf("%i",&doc.dni);

        validacion=contarInt(doc.dni);
        flag=validarDni2(archPersonas, doc);

        while(validacion!=8 || flag==1)
        {
            printf("\tEl DNI es incorrecto o ya existe\n");
            printf("\tIngrese nuevamente el DNI a continuacion: ");
            scanf("%i", &doc.dni);
            validacion=contarInt(doc.dni);
            flag=validarDni2(archPersonas, doc);
        }

        personaAux.dni=doc.dni;

        fwrite(&personaAux,sizeof(archPersonas),1,buff);

        fclose(buff);
    }
}
void modificarPersonaNombre( char archPersonas[], Persona doc)
{
    FILE * buff = fopen(archPersonas,"r+b");
    Persona personaAux;
    int flag=0;

    if(buff!=NULL)
    {
        while(flag==0 && fread(&personaAux,sizeof(Persona),1,buff)>0)
        {
            if(personaAux.dni==doc.dni)
            {
                flag=1;
            }
        }

        fseek(buff,sizeof(Persona) * (-1), SEEK_CUR);

        printf("\tIngrese el nuevo nombre: ");
        fflush(stdin);
        gets(doc.nombre);

        strcpy(personaAux.nombre,doc.nombre);
        fwrite(&personaAux,sizeof(Persona),1,buff);

        fclose(buff);
    }
}
void modificarPersonaTelefono (char archPersonas[], Persona doc)
{
    FILE * buff = fopen(archPersonas,"r+b");
    Persona personaAux;
    int validacion=0, flag=0;

    if(buff!=NULL)
    {
        while(flag==0 && fread(&personaAux,sizeof(Persona),1,buff)>0)
        {
            if(personaAux.dni==doc.dni)
            {
                flag=1;
            }
        }
        fseek(buff, sizeof(Persona) * (-1), SEEK_CUR);

        printf("\tIngrese el nuevo nro de telefono: 223 ");
        scanf("%i",&doc.telefono);

              validacion = contarInt(doc.telefono);
              flag=0;
              flag = validarTelefono(archPersonas, doc);

        while(validacion!=7 || flag==1)
        {
            printf("\tEl nro de telefono es incorrecto o ya existe\n");
            printf("\tIngrese el nuevo nro de telefono: 223 ");
            scanf("%i", &doc.telefono);
            validacion=contarInt(doc.telefono);
            flag = validarTelefono(archPersonas, doc);
        }

        personaAux.telefono = doc.telefono;
        fwrite(&personaAux, sizeof(Persona),1,buff);

        fclose(buff);
    }
}
void modificarPersonaDomicilio(char archPersonas[], Persona doc)
{
    FILE * buff = fopen(archPersonas,"r+b");
    Persona personaAux;
    int flag=0;

    if(buff!=NULL)
    {
        while(flag==0 && fread(&personaAux,sizeof(Persona),1,buff)>0)
        {
            if(personaAux.dni==doc.dni)
            {
                flag=1;
            }
        }
        fseek(buff, sizeof(Persona) * (-1), SEEK_CUR);

        printf("\tIngrese el nuevo domicilio: ");
        fflush(stdin);
        gets(doc.direccion);

        strcpy(personaAux.direccion,doc.direccion);
        fwrite(&personaAux,sizeof(Persona),1,buff);

        fclose(buff);
    }
}
void modificarPersonaRol(char archPersonas[], Persona doc)
{
    FILE * buff = fopen(archPersonas,"r+b");
    Persona personaAux;
    int flag=0;
    char comprador[]="comprador";
    char vendedor[]="vendedor";


    if(buff!=NULL)
    {

        while(flag==0 && fread(&personaAux,sizeof(Persona),1,buff)>0)
        {
            if(personaAux.dni==doc.dni)
            {
                flag=1;
            }
        }

        fseek(buff, sizeof(Persona) * (-1), SEEK_CUR);

        printf("\tIngrese el nuevo rol (comprador o vendedor): ");
        fflush(stdin);
        gets(doc.rol);

        while(strcmp(doc.rol,comprador)!=0 && strcmp(doc.rol,vendedor)!=0)
        {
            printf("\tNo es un rol valido\n");
            printf("\tIngrese nuevamente su rol: ");
            fflush(stdin);
            gets(doc.rol);
        }

        strcpy(personaAux.rol,doc.rol);
        fwrite(&personaAux,sizeof(Persona),1,buff);

        fclose(buff);
    }
}
void modificarPersCompleta(char archPersonas[], Persona doc)
{
    modificarPersonaNombre (archPersonas, doc);
    modificarPersonaTelefono (archPersonas, doc);
    modificarPersonaDomicilio (archPersonas, doc);
    modificarPersonaRol (archPersonas, doc);
    modificarPersonaDni (archPersonas, doc);
}
///3C
void mostrarPersonas(char archPersonas[])///muestra nombre, apellido y DNI
{
    FILE * buff = fopen(archPersonas, "rb");
    Persona personasAux;
    int i=0;

    if(buff != NULL)
    {
        while(fread(&personasAux, sizeof(Persona),1,buff)>0)
        {
            printf("\t------------PERSONA N~%i--------------------\n", i+1);
            printf("\tNombre y apellido: %s\n", personasAux.nombre);
            printf("\tDNI: %i\n", personasAux.dni);
            printf("\t-----------------------------------------\n");
            i++;
        }
        fclose(buff);
    }
}
///3D
void mostrarUNApersona(char archPersonas[], Persona doc)
{
    FILE * buff = fopen(archPersonas, "rb");
    Persona personaAux;
    int flag=0;


    if(buff != NULL)
    {
        do
        {
            while(flag==0 && fread(&personaAux,sizeof(Persona),1,buff)>0)
            {
                if(personaAux.dni==doc.dni)
                {
                    flag=1;
                }
            }

            if(flag==1)
            {
                printf("\t------------ PERSONA --------------------\n");
                printf("\tDNI: %i\n", personaAux.dni);
                printf("\tNombre: %s\n", personaAux.nombre);
                printf("\tTelefono: 223 %i\n", personaAux.telefono);
                printf("\tDomicilio: %s\n", personaAux.direccion);
                printf("\tRol: %s\n", personaAux.rol);
                printf("\t-----------------------------------------\n");

            }
            else
            {
                printf("ERROR! Ingrese nuevamente el DNI: ");
                scanf("%i",&doc.dni);

                fseek(buff,0, SEEK_SET);
            }

        }
        while(flag==0);


        fclose(buff);
    }
}
///3E
void mostrarAutos(char archivoAuto[])///muestra marca, modelo y patente 3E
{
    FILE * buff = fopen(archivoAuto, "rb");
    AutoArchivo vehiculoaux;
    int i=0;
    if(buff != NULL)
    {
        while(fread(&vehiculoaux, sizeof(AutoArchivo),1,buff)>0)
        {
            printf("\t------------AUTO N~%i--------------------\n", i+1);
            printf("\tMarca:%s\n", vehiculoaux.marca);
            printf("\tModelo:%s\n", vehiculoaux.modelo);
            printf("\tPatente:%s-%s\n", vehiculoaux.patente.letras,vehiculoaux.patente.numeros);
            printf("\t-----------------------------------------\n");
            i++;
        }
        fclose(buff);
    }
}
///3F
void mostrarAutosEnVenta (char archivoAuto[], char archPersonas[])
{
    FILE * buff = fopen(archivoAuto, "rb");
    FILE * buff1=fopen(archPersonas, "rb");
    AutoArchivo aux;
    Auto auxAuto[500];
    Persona auxP;
    int i=0, u=0;

    if (buff!=NULL)
    {
        while(fread(&aux,sizeof(AutoArchivo),1,buff)>0)
        {
            auxAuto[i].anio = aux.anio;
            auxAuto[i].kms = aux.kms;
            strcpy(auxAuto[i].marca,aux.marca);
            strcpy(auxAuto[i].modelo,aux.modelo);
            auxAuto[i].precioDeAdquisicion = aux.precioDeAdquisicion;
            strcpy(auxAuto[i].patente.letras,aux.patente.letras);
            strcpy(auxAuto[i].patente.numeros,aux.patente.numeros);
            i++;
        }

        fclose(buff);
    }

    i=0;

    if(buff1 != NULL)
    {
        while(fread(&auxP,sizeof(Persona),1,buff1)>0)
        {
            strcpy(auxAuto[i].Titular.direccion,auxP.direccion);
            auxAuto[i].Titular.dni = auxP.dni;
            strcpy(auxAuto[i].Titular.nombre,auxP.nombre);
            strcpy(auxAuto[i].Titular.rol,auxP.rol);
            auxAuto[i].Titular.telefono = auxP.telefono;
            i++;
        }
        fclose(buff1);
    }

    while(u<i)
    {
        printf("\t-----------------AUTO--------------------\n");
        printf("\tMarca: %s\n",auxAuto[u].marca);
        printf("\tModelo: %s\n",auxAuto[u].modelo);
        printf("\tPatente: %s-%s\n",auxAuto[u].patente.letras, auxAuto[u].patente.numeros);
        printf("\tAnio: %i\n",auxAuto[u].anio);
        printf("\t-----------------------------------------\n");
        u++;
    }
}
///3G
void mostrarUNauto(char archivoAuto[], AutoArchivo patentee)
{
    FILE * buff = fopen(archivoAuto, "rb");
    AutoArchivo vehiculoaux;
    int flag=0;

    if(buff != NULL)
    {
        do
        {

            while(flag==0 && fread(&vehiculoaux,sizeof(AutoArchivo),1,buff)>0)
            {
                if(strcmp(patentee.patente.letras, vehiculoaux.patente.letras)==0 && strcmp(patentee.patente.numeros, vehiculoaux.patente.numeros)==0)
                {
                    flag=1;
                }
            }

            if(flag==1)
            {
                printf("\t------------ AUTO --------------------\n");
                printf("\tMarca: %s\n", vehiculoaux.marca);
                printf("\tModelo: %s\n", vehiculoaux.modelo);
                printf("\tPatente: %s-%s\n", vehiculoaux.patente.letras, vehiculoaux.patente.numeros);
                printf("\tAnio: %i\n", vehiculoaux.anio);
                printf("\tKilometraje: %i\n", vehiculoaux.kms);
                printf("\tDNI del titular: %i\n", vehiculoaux.dniTitular);
                printf("\tPrecio: $%.2f\n", vehiculoaux.precioDeAdquisicion);
                printf("\t-----------------------------------------\n");

            }
            else
            {
                printf("\tERROR!!");
                printf("\tIngrese las letras de la patente nueva(Maximo 3): ");
                fflush(stdin);
                gets(patentee.patente.letras);

                while(strlen(vehiculoaux.patente.letras)!=3)
                {
                    printf("\tERROR!Ingrese las letras de la patente nuevamente: ");
                    fflush(stdin);
                    gets(patentee.patente.letras);
                }

                printf("\tIngrese los numeros de la patente nueva(Maximo 3): ");
                fflush(stdin);
                gets(patentee.patente.numeros);

                while(strlen(patentee.patente.numeros)!=3)
                {
                    printf("\tERROR!Ingrese los numeros de la patente nuevamente: ");
                    fflush(stdin);
                    gets(patentee.patente.numeros);
                }

                fseek(buff,0, SEEK_SET);
            }
        }while(flag==0);

        fclose(buff);
    }

}
///3H
void verVentas(char archVentas[])
{
    Venta autosVendidos;
    FILE * buff=fopen(archVentas, "rb");
    int i=0;

    if(buff!=NULL)
    {
        while(fread(&autosVendidos,sizeof(Venta),1,buff)>0)
        {
            printf("\t--------------AUTO VENDIDOS N~%i--------------\n", i+1);
            printf("\tFecha: %i/%i/%i\n",autosVendidos.fecha.dia,autosVendidos.fecha.mes,autosVendidos.fecha.anio);
            printf("\tPatente: %s-%s\n",autosVendidos.autoAVender.letras,autosVendidos.autoAVender.numeros);
            printf("\t---------------------------------------------\n");
            i++;

        }

        fclose(buff);
    }
}
///3I
float gananciaDeAuto(char archivoAuto[], float precioVenta, char letras[], char numeros[])
{
    FILE * buff = fopen(archivoAuto, "rb");
    float ganancia=0;
    int flag=0;
    AutoArchivo vehiculoAux;

    if(buff != NULL)
    {
        while(flag==0 && fread(&vehiculoAux,sizeof(AutoArchivo),1,buff)>0)
        {
            if(strcmp(letras,vehiculoAux.patente.letras)==0 && strcmp(numeros,vehiculoAux.patente.numeros)==0)
            {
                flag=1;
            }
        }

        ganancia = precioVenta - (float) vehiculoAux.precioDeAdquisicion;


        fclose(buff);
    }

    return ganancia;
}
void verUnaVenta(char archVentas[])
{
    FILE * buff = fopen(archVentas, "rb");
    int flag=0;
    Venta autito;
    char letras[5];
    char numeros[5];
    if(buff != NULL)
    {
        while(flag==0)
        {
            do
            {
                printf("\tIngrese la letras de la patente del auto que quiere ver: ");
                fflush(stdin);
                gets(letras);
            }
            while (strlen(letras) != 3);

            do
            {
                printf("\tIngrese los numeros de la patente del auto que quiere ver: ");
                fflush(stdin);
                gets(numeros);
            }
            while (strlen(numeros) != 3);

            fseek(buff,0,SEEK_SET);
            while(flag ==0 && fread(&autito, sizeof(Venta),1,buff)>0)
            {
                if(strcmp(autito.autoAVender.letras,letras) ==0 && strcmp(autito.autoAVender.numeros,numeros) ==0)
                {
                    printf("\t--------------AUTO VENDIDO-------------------\n");
                    printf("\tFecha: %i/%i/%i\n",autito.fecha.dia, autito.fecha.mes, autito.fecha.anio);
                    printf("\tPatente: %s-%s\n",autito.autoAVender.letras, autito.autoAVender.numeros);
                    printf("\tDNI comprador: %i\n",autito.dniComprador);
                    printf("\tDNI vendedor: %i\n",autito.dniVendedor);
                    printf("\tPrecio de venta:$%.2f\n", autito.precioVenta);
                    printf("\tGanancia del auto:$%.2f\n", autito.ganancia);
                    printf("\t---------------------------------------------\n");
                    flag=1;
                }
            }
        }

        fclose(buff);
    }
}
///3J
void registrarUnaVenta(char archivoAuto[], char archVentas[])
{
    Venta ventaDeAuto;
    FILE * buff2=fopen(archVentas, "ab");
    int flag=0;
    int flag2=0, validacion=0;

    if(buff2!=NULL)
    {
        do
        {
            printf("\tIngrese las letras de la patente(Maximo 3): ");
            fflush(stdin);
            scanf("%s",&ventaDeAuto.autoAVender.letras);
        }
        while(strlen(ventaDeAuto.autoAVender.letras)!=3);

        do
        {
            printf("\tIngrese los numeros de la patente(Maximo 3): ");
            fflush(stdin);
            scanf("%s",&ventaDeAuto.autoAVender.numeros);
        }
        while(strlen(ventaDeAuto.autoAVender.numeros)!=3);

        flag=validarPatente3(archivoAuto,ventaDeAuto.autoAVender.letras,ventaDeAuto.autoAVender.numeros);
        flag2=validarPatente2(archVentas, ventaDeAuto.autoAVender.letras,ventaDeAuto.autoAVender.numeros);

        while(flag==0 || flag2==1)
        {
            printf("\tEste vehiculo no esta a la venta/ya fue vendido\n");
            printf("\tIngrese las letras de la patente(Maximo 3): ");
            fflush(stdin);
            scanf("%s",&ventaDeAuto.autoAVender.letras);

            while(strlen(ventaDeAuto.autoAVender.letras)!=3)
            {
                printf("\tERROR!Ingrese las letras de la patente nuevamente: ");
                fflush(stdin);
                scanf("%s",&ventaDeAuto.autoAVender.letras);
            }

            printf("\tIngrese los numeros de la patente(Maximo 3): ");
            fflush(stdin);
            scanf("%s",&ventaDeAuto.autoAVender.numeros);

            while(strlen(ventaDeAuto.autoAVender.numeros)!=3)
            {
                printf("\tERROR!Ingrese los numeros de la patente nuevamente: ");
                fflush(stdin);
                scanf("%s",&ventaDeAuto.autoAVender.numeros);
            }

        flag=validarPatente3(archivoAuto,ventaDeAuto.autoAVender.letras,ventaDeAuto.autoAVender.numeros);
        flag2=validarPatente2(archVentas, ventaDeAuto.autoAVender.letras,ventaDeAuto.autoAVender.numeros);

        }
            do
            {
                printf("\tIngrese el dia: ");
                scanf("%i",&ventaDeAuto.fecha.dia);

                if(ventaDeAuto.fecha.dia > 31)
                {
                    printf("\tEsa fecha no existe, ingrese otra...\n");
                }
            }while(ventaDeAuto.fecha.dia > 31);

            do
            {
                printf("\tIngrese el mes: ");
                scanf("%i",&ventaDeAuto.fecha.mes);

                if(ventaDeAuto.fecha.mes>12)
                {
                    printf("\tEse mes no existe, ingrese otra...\n");
                }
            }while(ventaDeAuto.fecha.mes>12);

            do
            {
                printf("\tIngrese el anio: ");
                scanf("%i",&ventaDeAuto.fecha.anio);

                if(ventaDeAuto.fecha.anio>2024)
                {
                    printf("\tEse anio no existe, ingrese otro...\n");
                }
            }while(ventaDeAuto.fecha.anio>2024);


            printf("\tIngrese el precio al que se vendio: ");
            scanf("%f", &ventaDeAuto.precioVenta);

            do
            {
                printf("\tIngrese el DNI del comprador: ");
                scanf("%i", &ventaDeAuto.dniComprador);
                validacion=contarInt(ventaDeAuto.dniComprador);

            }while(validacion != 8);

            ventaDeAuto.dniVendedor = 11111111;

            ventaDeAuto.ganancia=gananciaDeAuto(archivoAuto, ventaDeAuto.precioVenta, ventaDeAuto.autoAVender.letras, ventaDeAuto.autoAVender.numeros);

            fwrite(&ventaDeAuto,sizeof(Venta),1,buff2);

        fclose(buff2);
    }
}
///3K
float verRecaudacion(char archVentas[])
{
    FILE * buff = fopen(archVentas,"rb");
    int anio=0;
    int mes=0;
    Venta aux;
    Pila pilita;
    Pila pilaAux;
    inicpila(&pilita);
    inicpila(&pilaAux);
    float total=0;
    do
    {
        printf("\tIngrese el mes: ");
        scanf("%i", &mes);

        if(mes>12)
        {
            printf("\tEse mes no existe, ingrese otra...\n");
        }
    }while(mes>12);

    do
    {
        printf("\tIngrese el anio: ");
        scanf("%i",&anio);

        if(anio>2024)
        {
            printf("\tEse anio no existe, ingrese otro...\n");
        }
    }while(anio>2024);

    if(buff != NULL)
    {
        while(fread(&aux,sizeof(Venta),1,buff)>0)
        {
            if(mes == aux.fecha.mes && anio == aux.fecha.anio)
            {
                apilar(&pilita, aux.ganancia);
            }
        }

        while(!pilavacia(&pilita))
        {
            total= (float)tope(&pilita) + total;
            apilar(&pilaAux, desapilar(&pilita));
        }

        fclose(buff);
    }

    return total;
}
///3L
void mostrarUnaVentaLibre(Venta autito)
{
    printf("\t--------------AUTO VENDIDO-------------------\n");
    printf("\tFecha: %i/%i/%i\n",autito.fecha.dia, autito.fecha.mes, autito.fecha.anio);
    printf("\tPatente: %s-%s\n",autito.autoAVender.letras, autito.autoAVender.numeros);
    printf("\tDNI comprador: %i\n",autito.dniComprador);
    printf("\tDNI vendedor: %i\n",autito.dniVendedor);
    printf("\tPrecio de venta:$%.2f\n", autito.precioVenta);
    printf("\tGanancia del auto:$%.2f\n", autito.ganancia);
    printf("\t---------------------------------------------\n");
}
Venta verMayorVenta(char archVentas[])
{
    FILE * buff = fopen(archVentas,"rb");
    Venta aux;
    Venta mayor;

    if(buff != NULL)
    {
        while(fread(&aux,sizeof(Venta),1,buff)>0)
        {
            if(aux.ganancia > mayor.ganancia)
            {
                mayor=aux;
            }
        }
        fclose(buff);
    }

    return mayor;
}
///3M
int contAutosMenoresDiezAnios(char archivoAuto[])
{
    int cont=0;
    AutoArchivo aux;
    FILE * buff = fopen(archivoAuto,"rb");

    if(buff!=NULL)
    {
        while(fread(&aux,sizeof(AutoArchivo),1,buff)>0)
        {
            if(aux.anio>=2014)
            {
                cont++;
            }
        }
        fclose(buff);
    }
    return cont;
}
void autosMenoresDiezAnios (char archivoAuto[], AutoArchivo ** autosMenor, int tamanio)
{
    AutoArchivo aux;
    int u=0;

    FILE * buff = fopen(archivoAuto,"rb");
    *autosMenor = (AutoArchivo *) malloc(sizeof(AutoArchivo) * tamanio);

    if(buff!=NULL)
    {
        while(fread(&aux,sizeof(AutoArchivo),1,buff)>0)
        {
            if(aux.anio>=2014)
            {
                (*autosMenor)[u] = aux;
                u++;
            }
        }
        fclose(buff);
    }

}
int encontrarMenor(AutoArchivo autosMenor[], int validos, int pos)
{
    int posMenor=pos;
    int menor=autosMenor[posMenor].anio;
    int i=pos+1;

    while(i<validos)
    {
        if(autosMenor[i].anio<menor)
        {
            posMenor=i;
            menor=autosMenor[i].anio;
        }
        i++;
    }

    return posMenor;
}
void ordenarPorSeleccion(AutoArchivo autosMenor[], int validos)
{
    int posMenor=0;
    int i=0;
    AutoArchivo aux;

    while(i<validos)
    {
        posMenor=encontrarMenor(autosMenor,validos,i);

        aux=autosMenor[posMenor];
        autosMenor[posMenor]=autosMenor[i];
        autosMenor[i]=aux;
        i++;
    }
}
void mostrarMenoresDiezAnios(AutoArchivo autosMenor[], int tamanio)
{
    printf("\tAutos con menos de 10 anios de antiguedad\n");
    for(int i=0; i<tamanio; i++)
    {
        printf("\t-------------------- AUTO --------------------\n");
        printf("\tMarca: %s\n", autosMenor[i].marca);
        printf("\tModelo: %s\n",autosMenor[i].modelo);
        printf("\tPatente: %s-%s\n", autosMenor[i].patente.letras, autosMenor[i].patente.numeros);
        printf("\tAnio: %i\n", autosMenor[i].anio);
        printf("\tKilometraje: %i\n", autosMenor[i].kms);
        printf("\tDNI del titular: %i\n", autosMenor[i].dniTitular);
        printf("\tPrecio: $%.2f\n", autosMenor[i].precioDeAdquisicion);
        printf("\t----------------------------------------------\n");
    }
}
