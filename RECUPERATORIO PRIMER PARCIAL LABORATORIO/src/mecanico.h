#ifndef SRC_MECANICO_H_
#define SRC_MECANICO_H_

#define OCUPADO 1
#define LIBRE 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "especialidad.h"
#include "utn.h"

typedef struct
{
	int id;
	char nombre[50];
	int idEspecialidad;
	int numeroClientes;
	int idTaller;
	int estado;
}eMecanico;

typedef struct
{
	int id;
	char descripcion[50];
}eDiagnostico;

typedef struct
{
	int contador;
	int id;
}eAuxiliar;


/// @brief Le asigna el valor de la lista de diagnosticos a la lista auxiliar
///
/// @param listaDiagnosticos array de la lista de diagnosticos harcodeada
/// @param sizeDiagnostico largo de la lista de diagnosticos (D)
/// @param listaAuxiliar lista que auxilia a la lista de diagnosticos
void InicializarListaAuxiliar(eDiagnostico listaDiagnosticos[], int sizeDiagnostico, eAuxiliar listaAuxiliar[]);


/// @brief Muestra la lista del top 3 de los desperfectos mas diagnosticados
///
/// @param listaDiagnosticos array de la lista de diagnosticos harcodeada
/// @param sizeDiagnostico largo de la lista de diagnosticos (D)
/// @param listaAuxiliar lista que auxilia a la lista de diagnosticos
/// @param sizeAuxiliar largo de la lista auxiliar
void MostrarListaDesperfectos(eDiagnostico listaDiagnosticos[], int sizeDiagnostico, eAuxiliar listaAuxiliar[], int sizeAuxiliar);


/// @brief Pide al usuario un id de mecanico
///
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
/// @return el id pedido
int PedirIdMecanico(eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad);


/// @brief Comprueba que el id este en la lista de mecanicos
///
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @param idRecibido id a comprobar
/// @return (-1) si no lo encontro y si lo encontro, la posicion del array(index)
int BuscarIdMecanico(eMecanico listaMecanicos[], int sizeMecanicos, int idRecibido);


/// @brief Muestra los datos ed un mecanico
///
/// @param unMecanico mecanico a mostrar
/// @param unaEspecialidad especialidad del mecanico
void MostrarUnMecanico (eMecanico unMecanico, sEspecialidad unaEspecialidad);


/// @brief Muestra todos los mecanicos de la lista de mecanicos
///
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
void MostrarListaMecanico (eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad);


/// @brief Solicita al usuario un id de diagnostico
///
/// @param listaDiagnosticos array de la lista de diagnosticos harcodeada
/// @param sizeDiagnostico largo de la lista de diagnosticos (D)
/// @return el id pedido
int PedirIdDiagnostico(eDiagnostico listaDiagnosticos[], int sizeDiagnostico);


/// @brief comprueba que el id este en la lista de diagnosticos
///
/// @param listaDiagnosticos array de la lista de diagnosticos harcodeada
/// @param sizeDiagnostico largo de la lista de diagnosticos (D)
/// @param id  id a comprobar
/// @return (-1) si no lo encontro y (1) si lo encontro
int BuscarIdDiagnostico(eDiagnostico listaDiagnosticos[], int sizeDiagnostico, int id);


/// @brief Muestra los datos de un diagnostico
///
/// @param unDiagnostico diagnostico a mostrar
void MostrarUnDiagnostico(eDiagnostico unDiagnostico);


/// @brief Muestra todos los diagnosticos de la lista de diagnosticos
///
/// @param listaDiagnosticos array de la lista de diagnosticos harcodeada
/// @param sizeDiagnostico largo de la lista de diagnosticos (D)
void MostrarListaDiagnosticos(eDiagnostico listaDiagnosticos[], int sizeDiagnostico);


/// @brief Muestra una lista de los mecanicos sin servicios asignados
///
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
void MostrarMecanicosLibres(eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad);


/// @brief Ordena a los mecanicos alfabeticamente por especialidad
///
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
void OrdenarMecanicosPorEspecialidad(eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad);


/// @brief Muestra el top 3 de las especialidades mas estudiadadas por los mecanicos
///
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
/// @param listaAuxiliar lista que auxilia a especialidades
void MostrarListaEspecialidadesMasEstudiadas(sEspecialidad listaEspecialidades[], int sizeEspecialidad, eAuxiliar listaAuxiliar[]);


/// @brief Enlista el top 3 de las especialidades mas estudiadadas por los mecanicos
///
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
/// @param listaAuxiliar lista que auxilia a especialidades
void ListarTopEspecialidadesEstudiadas(eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad, eAuxiliar listaAuxiliar[]);

#endif
