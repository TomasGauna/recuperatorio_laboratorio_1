#ifndef SRC_SERVICIO_H_
#define SRC_SERVICIO_H_

#include "mecanico.h"
#include "utn.h"

#define OCUPADO 1
#define LIBRE 0

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	char nombreDelCliente[50];
	eFecha fecha;
	float cotizacion;
	int idMecanico;
	int idDiagnostico;
	int estado;
}eServicio;

/// @brief Busca la primer posicion libre dentro del array
///
/// @param listaServicios array de servicios
/// @param sizeServicios logintud del array de servicios
/// @return int posicion libre encontrada  (-1)si no encuentra posicion libre
int BuscarEspacioLibre(eServicio listaServicios[], int sizeServicios);


/// @brief Calcula el id automaticamente
///
/// @return el id anterior incrementado en 1
int CalcularIdServicio();


void PedirNombre(eServicio unServicio);
int PedirDia();
int PedirMes();
int PedirAnio();

/// @brief Pide los datos de un servicio
///
/// @param listaServicios array de servicios
/// @param sizeServicios logintud del array de servicios
/// @return el servicio completado
eServicio PedirUnServicio();


/// @brief Carga una lista de servicios
///
/// @param listaServicios array de servicios
/// @param sizeServicios longitud array de servicios
/// @return (-1) si no hay espacio   (1)si esta ok
int CargarListaDeServicios(eServicio listaServicios[], int sizeServicios);


/// @brief Busca un id ingresado por parametro
///
/// @param listaServicios array de servicios
/// @param sizeServicios longitud del array de servicios
/// @param id int a buscar en el array
/// @return (-1) si no se encontro   (i)posicion en donde se encuentra el id
int BuscarId(eServicio listaServicios[], int sizeServicios, int id);


/// @brief Muestra los datos de un servicio
///
/// @param unServicio servicio a mostrar
void MostrarUnServicio(eServicio unServicio);


/// @brief Muestra los datos de toda la lista de servicios
///
/// @param listaServicios array de lista de servicios cargada por el usuario o hardcodeada
/// @param sizeServicio largo de la lista de servicios(T)
void MostrarListaDeServicios(eServicio listaServicios[], int sizeServicios);


/// @brief Muestra los datos de la lista de servicios que no han sido diagnosticados
///
/// @param listaServicios array de lista de servicios cargada por el usuario o hardcodeada
/// @param sizeServicios largo de la lista de servicios(T)
void MostrarServiciosNoDiagnosticados(eServicio listaServicios[], int sizeServicios);


/// @brief Modifica el nombre, la fecha o el mecanico del servicio elegido por el usuario
///
/// @param listaServicios listaServicios array de lista de servicios cargada por el usuario o hardcodeada
/// @param sizeServicios largo de la lista de servicios(T)
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
/// @return (-1) si no pudo modificar y 1 si esta ok
int ModificarServicio(eServicio listaServicios[], int sizeServicios, eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad);


/// @brief Modifica el servicio segun la opcion elegida por el usuario
///
/// @param opcionElegida opcion que eligio el usuario para modificar
/// @param listaServicios array de lista de servicios cargada por el usuario o hardcodeada
/// @param index posicion del array en la que se va a modificar el dato
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
/// @return (-1) si hubo algun error y 1 si esta ok
int MostrarMenuModificacion(int opcionElegida, eServicio listaServicios[], int index, eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad);


/// @brief Da de baja un servicio de la lista de servicios
///
/// @param listaServicios array de lista de servicios cargada por el usuario o hardcodeada
/// @param sizeServicios largo de la lista de servicios(T)
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @return (-1) si hubo algun error y 1 si elimino
int DarDeBaja(eServicio listaServicios[], int sizeServicios, eMecanico listaMecanicos[], int sizeMecanicos);


/// @brief Diagnostica un servicio de la lista de servicios
///
/// @param listaServicios array de lista de servicios cargada por el usuario o hardcodeada
/// @param sizeServicios largo de la lista de servicios(T)
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @param listaDiagnosticos array de la lista de diagnosticos harcodeada
/// @param sizeDiagnostico largo de la lista de diagnosticos (D)
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
/// @return (-1) si hubo algun error y 1 si esta ok
int DiagnosticarServicio(eServicio listaServicios[], int sizeServicios, eMecanico listaMecanicos[], int sizeMecanico, eDiagnostico listaDiagnosticos[], int sizeDiagnostico, sEspecialidad listaEspecialidades[], int sizeEspecialidad);


/// @brief Ordena la lista por fecha y la muestra
///
/// @param listaServicios array de lista de servicios cargada por el usuario o hardcodeada
/// @param sizeServicios largo de la lista de servicios(T)
void MostrarListaOrdenadaFecha(eServicio listaServicios[], int sizeServicios);


/// @brief Muestra la lista de servicios diagnosticados por 'Cambio de aceite', segun determinada fecha
///
/// @param listaServicios array de lista de servicios cargada por el usuario o hardcodeada
/// @param sizeServicios largo de la lista de servicios(T)
/// @param listaDiagnosticos array de la lista de diagnosticos harcodeada
/// @param sizeDiagnostico largo de la lista de diagnosticos (D)
void MostrarCotizacionSegunFecha(eServicio listaServicios[], int sizeServicios, eDiagnostico listaDiagnosticos[], int sizeDiagnostico);


/// @brief Calcula y muestra la cotizacion promedio por mecanico
///
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @param listaServicios array de lista de servicios cargada por el usuario o hardcodeada
/// @param sizeServicios largo de la lista de servicios(T)
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
void MostrarCotizacionPromedioPorMecanico(eMecanico listaMecanicos[], int sizeMecanico, eServicio listaServicios[], int sizeServicio, sEspecialidad listaEspecialidades[], int sizeEspecialidad);


/// @brief Muestra el mecanico con mas servicios diagnosticados
///
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
void MostrarMecanicosMasServicios(eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad);


/// @brief Muestra una lista de servicios entre Marzo y Mayo, segun determinada especialidad
///
/// @param listaServicios array de lista de servicios cargada por el usuario o hardcodeada
/// @param sizeServicios largo de la lista de servicios(T)
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
void ListarServiciosMarzoMayoPorEspecialidad(eServicio listaServicios[], int sizeServicio, sEspecialidad listaEspecialidad[], int sizeEspecialidad, eMecanico listaMecanicos[], int sizeMecanico);


/// @brief Calcula y muestra el porcentaje de servicios diagnosticados por mecanico, en funcion
/// al total de servicios diagnosticados
///
/// @param listaServicios array de lista de servicios cargada por el usuario o hardcodeada
/// @param sizeServicios largo de la lista de servicios(T)
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
void ListarPromedioServiciosDiagnosticados(eServicio listaServicios[], int sizeServicio, eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidad[], int sizeEspecialidad);


/// @brief Enlista el top 3 de los desperfectos mas diagnosticados
///
/// @param listaServicios array de lista de servicios cargada por el usuario o hardcodeada
/// @param sizeServicios largo de la lista de servicios(T)
/// @param listaDiagnosticos array de la lista de diagnosticos harcodeada
/// @param sizeDiagnostico largo de la lista de diagnosticos (D)
/// @param listaAuxiliar lista que auxilia a la lista de diagnosticos
void ListarTopDesperfectos(eServicio listaServicios[], int sizeServicios, eDiagnostico listaDiagnosticos[], int sizeDiagnostico, eAuxiliar listaAuxiliar[]);


/// @brief  Muestra una lista de los servicios ordenados por la especialidad del mecanico
///
/// @param listaServicios array de lista de servicios cargada por el usuario o hardcodeada
/// @param sizeServicios largo de la lista de servicios(T)
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
void MostrarServiciosOrdenadosPorEspecialidad(eServicio listaServicios[], int sizeServicio, eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad);

#endif
