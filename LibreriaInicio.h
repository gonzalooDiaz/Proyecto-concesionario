#ifndef LIBRERIAREGISTRO_H_INCLUDED
#define LIBRERIAREGISTRO_H_INCLUDED

///PARA DEFINIR PROTOTIPADO Y ESTRUCTURAS

typedef struct
{
    char gmail[40];
    char nombreApellido[40];
    char nombreDeUsuario[20];
    int dni;
    char contrasenia[30];
}stRegistro;
int menuInicio();
void menuRegistro(char usuarios[]);
int contarInt(int num);
int validarCorreo(char archivo[], stRegistro usuarioAValidar);
void mostrarUsuarios(char archivo[]);
int validarDni(char archivo[], stRegistro usuarioAValidar);
int validarUsuario(char archivo[], stRegistro usuarioAValidar);
int menuInicioSesion(char registro[]);


#endif // LIBRERIAREGISTRO_H_INCLUDED
