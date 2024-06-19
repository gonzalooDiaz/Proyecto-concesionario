#include <stdio.h>
#include <stdlib.h>
#include "LibreriaInicio.h"
#include <string.h>
#include<ctype.h>
///PARA FUNCIONES
///1
int menuInicio()
{
    int input;
    int flag = 0;

    mostrarLogo();

    system("color F");
    printf("\t1 - Crear usuario\n");
    printf("\t2 - Iniciar sesion\n");
    printf("\t3 - Salir\n\n");
    while(flag == 0 )
    {
        printf("\tIngrese que opcion desea realizar: ");
        scanf("%i", &input);

        system("cls");
        mostrarLogo();

        if(input > 3 && input < 1 && !isdigit(input) )
        {
            printf("Dato incorrecto: \n");

        }
        else
        {
            flag = 1;
        }
    }
    return input;
}

int contarInt(int num)
{
    int aux=0;
    int contador=0;

    while(num>0)
    {
        num=num/10;
        contador++;
    }

    return contador;
}

void menuRegistro(char registro[])
{
    FILE * buff=fopen(registro, "ab");
    stRegistro usuarios;
    int validacion=0;
    int flag=0;

    if(buff!=NULL)
    {
        printf("\tCorreo electronico: ");
        fflush(stdin);
        gets(usuarios.gmail);

        validacion=strlen(usuarios.gmail);
        flag=validarCorreo(registro,usuarios);

        char arroba[40] = {'@'};
        if(validacion>40 || strstr(usuarios.gmail, arroba) == NULL || flag==1)
        {
            while(validacion>40 || strstr(usuarios.gmail, arroba) == NULL || flag==1)
            {

            system("cls");
            printf("\tEl email ya existe / No contiene arroba\n");
            printf("\tIngrese nuevamente el correo a continuacion\n\n");
            printf("\t");
            system("PAUSE");
            system("cls");
            printf("\tCorreo electronico: ");
            fflush(stdin);
            gets(usuarios.gmail);
            validacion=strlen(usuarios.gmail);
            flag=validarCorreo(registro,usuarios);
            }
        }
        validacion=0;
        flag=0;

        printf("\tNombre de usuario: ");
        fflush(stdin);
        gets(usuarios.nombreDeUsuario);

        validacion=strlen(usuarios.nombreDeUsuario);
        flag=validarUsuario(registro,usuarios);

        if(validacion>20 || flag==1)
        {
            while(validacion>20 || flag==1)
            {
            system("cls");
            printf("\tEl nombre de usuario supera los caracteres permitidos\n");
            printf("\tIngrese nuevamente el nombre de usuario a continuacion\n\n");
            printf("\t");
            system("PAUSE");
            system("cls");
            printf("\tNombre de usuario: ");
            fflush(stdin);
            gets(usuarios.nombreDeUsuario);
            validacion=strlen(usuarios.nombreDeUsuario);
            flag=validarUsuario(registro,usuarios);
            }
        }

        validacion=0;

        printf("\tContrasenia: ");
        fflush(stdin);
        gets(usuarios.contrasenia);
        validacion=strlen(usuarios.contrasenia);

         if(validacion>30)
        {
            while(validacion>30)
            {
            system("cls");
            printf("\tLa contrasenia supera los caracteres permitidos\n");
            printf("\tIngrese nuevamente la contrasenia a continuacion\n\n");
            printf("\t");
            system("PAUSE");
            system("cls");
            printf("\tContrasenia: ");
            fflush(stdin);
            gets(usuarios.contrasenia);
            validacion=strlen(usuarios.contrasenia);
            }
        }

        validacion=0;
        flag=0;

        printf("\tDNI: ");
        scanf("%i",&usuarios.dni);

        validacion=contarInt(usuarios.dni);
        flag=validarDni(registro,usuarios);

         if(validacion!=8 || flag==1)
        {
            while(validacion!=8 || flag==1)
            {
            system("cls");
            if(flag==1)
            {
                printf("\tEl DNI ya existe\n");
            }
            else if(validacion!=8)
            {
                printf("\tEl DNI es incorrecto\n");
            }
            printf("\tIngrese nuevamente el DNI a continuacion\n\n");
            printf("\t");
            system("PAUSE");
            system("cls");
            printf("\tDNI: ");
            scanf("%i", &usuarios.dni);
            validacion=contarInt(usuarios.dni);
            flag=validarDni(registro,usuarios);

            }
        }
        fflush(stdin);
        fwrite(&usuarios,sizeof(stRegistro),1,buff);

        system("cls");
        printf("Usuario creado con exito!\n");
        system("PAUSE");
        system("cls");

        fclose(buff);
    }
}

///FUNCION PARA VALIDAR USUARIOS

//PARA VALIDAR SI YA EXISTE EL GMAIL
int validarCorreo(char registro[], stRegistro usuarioAValidar)
{
    FILE * buff=fopen(registro, "rb");
    stRegistro usuario;
    int flag=0;

    if(buff!=NULL)
    {
        while(fread(&usuario,sizeof(stRegistro),1,buff)>0 && flag==0)
        {
            if(strcmp(usuario.gmail,usuarioAValidar.gmail)==0)
            {
                flag=1;
            }
        }
        fclose(buff);
    }
    return flag;
}
int validarUsuario(char registro[], stRegistro usuarioAValidar)
{
    FILE * buff=fopen(registro, "rb");
    stRegistro usuario;
    int flag=0;

    if(buff!=NULL)
    {
        while(fread(&usuario,sizeof(stRegistro),1,buff)>0 && flag==0)
        {
            if(strcmp(usuario.nombreDeUsuario,usuarioAValidar.nombreDeUsuario)==0)
            {
                flag=1;
            }
        }
        fclose(buff);
    }
    return flag;
}
int validarDni(char registro[], stRegistro usuarioAValidar)
{
    FILE * buff=fopen(registro, "rb");
    stRegistro usuario;
    int flag=0;

    if(buff!=NULL)
    {
        while(fread(&usuario,sizeof(stRegistro),1,buff)>0 && flag==0)
        {
            if(usuario.dni==usuarioAValidar.dni)
            {
                flag=1;
            }
        }
        fclose(buff);
    }
    return flag;
}

///FUNCION PARA QUE EL USUARIO INICIE SESIÒN

int menuInicioSesion(char registro[])
{
    FILE * buff=fopen(registro, "rb");
    stRegistro usuarios;
    stRegistro aux;
    int flag=0;

    if(buff!=NULL)
    {
        printf("\tNombre de usuario: ");
        fflush(stdin);
        gets(usuarios.nombreDeUsuario);

        printf("\tContrasenia: ");
        fflush(stdin);
        scanf("%s",usuarios.contrasenia);

        while(fread(&aux,sizeof(stRegistro),1,buff)>0 && flag==0)
        {
            if(strcmp(usuarios.nombreDeUsuario,aux.nombreDeUsuario)==0 && strcmp(usuarios.contrasenia,aux.contrasenia)==0)
            {
                printf("\tSesion iniciada correctamente\n");
                flag=1;
            }
        }

        fclose(buff);
    }

    return flag;
}
