#ifndef LIBRERIAMENUPRINCIPAL_H_INCLUDED
#define LIBRERIAMENUPRINCIPAL_H_INCLUDED

///PARA DEFINIR PROTOTIPADOS Y ESTRUCTURA PARA EL MENU PRINCIPAL

typedef struct {
	char letras[4];
	char numeros[4];
} Patente;
typedef struct {
	int dni;
	char nombre[40];
	int telefono;
	char direccion[30];
	char rol[9]; //comprador o vendedor
} Persona;
typedef struct {
	Patente patente;
	char marca[20];
	char modelo[20];
	int anio;
	int kms;
	Persona Titular;
	float precioDeAdquisicion;
} Auto;
typedef struct {
	Patente patente;
	char marca[20];
	char modelo[20];
	int anio;
	int kms;
	int dniTitular;
	float precioDeAdquisicion;
} AutoArchivo;
typedef struct {
	int dia;
	int mes;
	int anio;
} Fecha;
typedef struct {
	Fecha fecha;
	Patente autoAVender;
	float precioVenta;
	float ganancia;
	int dniComprador;
	int dniVendedor;
} Venta;
                                            ///PROTOTIPADO\\\

void mostrarLogo();
///3A
int validarPatente(char archivoAuto[], AutoArchivo vehiculo);
int validarPatente2(char archVentas[], char letras[], char numeros[]);
int validarPatente3(char archivoAuto[], char letras[], char numeros[]);
void agregarAuto (char archivoAuto[]);
void modificarAuto(char archivoAuto[]);
void modificarMarca(char archivoAuto[], AutoArchivo patentee);
void modificarModelo(char archivoAuto[], AutoArchivo patentee);
void modificarPatente(char archivoAuto[], AutoArchivo patentee);
void modificarAnio(char archivoAuto[], AutoArchivo patentee);
void modificarKms(char archivoAuto[], AutoArchivo patentee);
void modificarDNI (char archivoAuto[], AutoArchivo patentee);
void modificarPrecio (char archivoAuto[], AutoArchivo patentee);
void modificarTodoElRegistro (char archivoAuto[], AutoArchivo patentee);
///3B
int validarTelefono (char archPersonas[], Persona doc);
int validarDni2(char archPersonas[],  Persona usuarioAvalidar);///es para personas
void agregarPersona (char archPersonas[]);
void modificarPersona(char archPersonas[]);
void modificarPersonaDni (char archPersonas[], Persona doc);
void modificarPersonaNombre( char archPersonas[], Persona doc);
void modificarPersonaTelefono (char archPersonas[], Persona doc);
void modificarPersonaDomicilio(char archPersonas[], Persona doc);
void modificarPersonaRol(char archPersonas[], Persona doc);
void modificarPersCompleta(char archPersonas[], Persona doc);
///3C
void mostrarPersonas(char archPersonas[]);///muestra nombre, apellido y DNI
///3D
void mostrarUNApersona(char archPersonas[], Persona doc);
///3E
void mostrarAutos(char archivoAuto[]);///muestra marca, modelo y patente
///3F
void mostrarAutosEnVenta (char archivoAuto[], char archPersonas[]);
///3G
void mostrarUNauto(char archivoAuto[], AutoArchivo patentee);
///3H
void verVentas(char archVentas[]);
///3I
void verUnaVenta(char archVentas[]);
///3J
void registrarUnaVenta(char archivoAuto[], char archVentas[]);
///3K
float gananciaDeAuto(char autosEnVenta[], float precioVenta, char letras[], char numeros[]);
float verRecaudacion(char archVentas[]);
///3L
void mostrarUnaVentaLibre(Venta autito);
Venta verMayorVenta(char archVentas[]);
///3M
int contAutosMenoresDiezAnios(char archivoAuto[]);
void autosMenoresDiezAnios (char archivoAuto[], AutoArchivo ** autosMenor, int tamanio);
int encontrarMenor(AutoArchivo autosMenor[], int validos, int pos);
void ordenarPorSeleccion(AutoArchivo autosMenor[], int validos);
void mostrarMenoresDiezAnios(AutoArchivo autosMenor[], int tamanio);

#endif // LIBRERIAMENUPRINCIPAL_H_INCLUDED
