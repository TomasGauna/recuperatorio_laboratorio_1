#ifndef TALLER_H_
#define TALLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "servicio.h"
#include "especialidad.h"

typedef struct
{
	int id;
	char direccion[50];
	int pisos;
}Taller;


/// @brief Muestra los datos de un taller
///
/// @param unTaller taller a mostrar
void MostrarUnTaller(Taller unTaller);


/// @brief Muestra los talleres de la lista de talleres
///
/// @param listaTaller array de la lista de talleres hardcodeada
/// @param sizeTaller largo de la lista de talleres (L)
void MostrarListaDeTalleres(Taller listaTalleres[], int sizeTalleres);


/// @brief Ordena los talleres alfabeticamente
///
/// @param listaTaller array de la lista de talleres hardcodeada
/// @param sizeTaller largo de la lista de talleres (L)
void OrdenarTalleresAlfabeticamente(Taller listaTaller[], int sizeTaller);


/// @brief Ordena los mecanicos alfabeticamente segun las especialidades
///
/// @param listaMecanicos array de lista de mecanicos hardcodeada
/// @param sizeMecanico largo de la lista de mecanicos (M)
/// @param listaTaller array de la lista de talleres hardcodeada
/// @param sizeTaller largo de la lista de talleres (L)
void OrdenarMecanicosPorTaller(eMecanico listaMecanicos[], int sizeMecanico, Taller listaTaller[], int sizeTaller);

/**
 * @brief Ordena la lista de servicios alfabeticamente por direccion de taller del mecanico
 *
 * @param listaServicios array de lista de servicios cargada por el usuario o hardcodeada
 * @param sizeServicio largo de la lista de servicios(T)
 * @param listaMecanicos array de lista de mecanicos hardcodeada
 * @param sizeMecanico largo de la lista de mecanicos (M)
 * @param listaTaller array de la lista de talleres hardcodeada
 * @param sizeTaller largo de la lista de talleres (L)
 * @param listaEspecialidad array de la lista de especialidades hardcodeada
 * @param sizeEspecialidad largo de la lista de especialidades (E)
 */
void OrdenarServiciosPorDireccionTaller(eServicio listaServicios[], int sizeServicio, eMecanico listaMecanicos[], int sizeMecanico, Taller listaTaller[], int sizeTaller, sEspecialidad listaEspecialidad[], int sizeEspecialidad);

#endif
