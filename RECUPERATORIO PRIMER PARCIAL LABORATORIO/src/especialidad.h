#ifndef ESPECIALIDAD_H_
#define ESPECIALIDAD_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utn.h"

typedef struct
{
	int id;
	char descripcion[50];
}sEspecialidad;


/// @brief muestra los datos de una especialidad
///
/// @param unaEspecialidad especialidad a mostrar
void MostrarUnaEspecialidad(sEspecialidad unaEspecialidad);


/// @brief Muestra las especialidades de la lista de especialidades
///
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
void MostrarListaEspecialidades(sEspecialidad listaEspecialidades[], int sizeEspecialidad);


/// @brief Solicita al usuario un id de especialidades
///
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
/// @return el id pedido
int PedirIdEspecialidad(sEspecialidad listaEspecialidades[], int sizeEspecialidad);


/// @brief comprueba que el id este en la lista de especialidades
///
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
/// @param id id a comprobar
/// @return (-1) si no lo encontro y si lo encuentra, la posicion del array(index)
int BuscarIdEspecialidad(sEspecialidad listaEspecialidades[], int sizeEspecialidad, int id);


/// @brief Ordena la especialidades alfabeticamente
///
/// @param listaEspecialidades array de la lista de especialidades hardcodeada
/// @param sizeEspecialidad largo de la lista de especialidades (E)
void OrdenarEspecialidadesAlfabeticamente(sEspecialidad listaEspecialidades[], int sizeEspecialidad);

#endif
