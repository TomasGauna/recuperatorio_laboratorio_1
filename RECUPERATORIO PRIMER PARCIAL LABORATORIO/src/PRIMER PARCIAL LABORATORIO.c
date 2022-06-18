#include <stdio.h>
#include <stdlib.h>
#include "servicio.h"
#include "especialidad.h"
#include "utn.h"
#include "taller.h"
#define T 20
#define E 6
#define M 9
#define D 6
#define L 7

int main(void)
{
	setbuf(stdout, NULL);

	char opcion[10];
	int transformoOpcion;
	int transformoOtraOpcion;
	int altasHechas = 0;
	int retorno;

	eDiagnostico listaDiagnosticos[D] = {{200,"Cambio de aceite"},{201,"Suspension"},{202,"Reparacion de motor"},{203,"Aleron"},{204,"Escape"},{205,"Frenos"}};

	eServicio listaServicios[T];/* = {{1,"Tomas",{05,05,2022},4023.41, 102, 201,OCUPADO},{2,"Juan",{15,12,2022},605.12,106,200,OCUPADO},
								   {3,"Esteban",{05,05,2022},10000.00, 105, 201,OCUPADO}};*/

	eMecanico listaMecanicos[M] = {{101,"German",10, 0,50,LIBRE},{103,"Ezequiel",11,0, 51,LIBRE},{104,"Giovanni",10,0, 53,LIBRE},
								   {105,"Leonel",12,0,52,LIBRE},{106,"Gabriel",14,0,53,LIBRE},{107,"Natalia",15,0,52,LIBRE},
								   {108,"Florencia",14,0,55,LIBRE},{109,"Luciano",13,0,51,LIBRE},{110,"Cesar",11,0,54,LIBRE}};

	sEspecialidad listaEspecialidades[E] = {{10,"Cambio de aceite"},{11,"Suspension"},{12,"Reparacion de motor"},{13,"Aleron"},{14,"Escape"},{15,"Frenos"}};

	Taller listaTalleres[L] = {{50, "CYII9M00",0},{51, "CYIT2M90",2},{52, "CYQL1M07",3},{52, "CYVO9M77",2},{53, "CYII9M12",3},{54, "CZBO9M81",1},{55, "CYCA9X56",3}};

    eAuxiliar listaAuxiliar[D];

	do
	{
		getString("\n¡Bienvenido al menu!\n1-Nuevo servicio\n2-Modificar un servicio\n3-Dar de baja un servicio\n4-Diagnosticar un servicio"
							   "\n5-Listado de informes\n6-Listado de TOPS\n7-Informe TALLER\n8-Salir\nIngrese una opcion: ", opcion);
		while(esNumerico(opcion) == 0 || (atoi(opcion) != 1 && atoi(opcion) != 2 && atoi(opcion) != 3 &&
			  atoi(opcion) != 4 && atoi(opcion) != 5 && atoi(opcion) != 6 && atoi(opcion) != 7 && atoi(opcion) != 8))
		{
			getString("\n|ERROR|\n¡Bienvenido al menu!\n1-Nuevo servicio\n2-Modificar un servicio\n3-Dar de baja un servicio\n4-Diagnosticar un servicio"
					   "\n5-Listado de informes\n6-Listado de TOPS\n7-Informe TALLER\n8-Salir\nIngrese una opcion correcta: ", opcion);
		}

		transformoOpcion = atoi(opcion);


		switch(transformoOpcion)
		{
			case 1:
				retorno = CargarListaDeServicios(listaServicios, T);
				switch(retorno)
				{
					case -1:
						printf("\n|ERROR| No se pudo cargar el servicio. No hay mas espacio.");
					break;

					case 1:
						printf("\nEl servicio se ha cargado correctamente.\n");
						altasHechas ++;
					break;
				}
			break;

			case 2:
				if(altasHechas == 0)
				{
					printf("\n|ERROR|\nSe debe ingresar al menos un alta para poder acceder a esta opcion.");
				}
				else
				{
					retorno = ModificarServicio(listaServicios, T, listaMecanicos, M, listaEspecialidades, E);
					switch(retorno)
					{
						case -1:
							printf("\n|No se han modificado los datos|\n");
						break;

						default:
							printf("\n<EL servicio se ha modificado correctamente>\n");
						break;
					}
				}
			break;

			case 3:
				if(altasHechas == 0)
				{
					printf("\n|ERROR|\nSe debe ingresar al menos un alta para poder acceder a esta opcion.");
				}
				else
				{
					retorno = DarDeBaja(listaServicios, T, listaMecanicos, M);
					switch(retorno)
					{
						case -1:
							printf("\n|Volviendo al menu|\n");
						break;

						case 1:
							printf("\n<El servicio ha sido dado de baja con exito>");
						break;
					}
				}
			break;

			case 4:
				if(altasHechas == 0)
				{
					printf("\n|ERROR|\nSe debe ingresar al menos un alta para poder acceder a esta opcion.");
				}
				else
				{
					retorno = DiagnosticarServicio(listaServicios, T, listaMecanicos, M, listaDiagnosticos, D, listaEspecialidades, E);
					switch(retorno)
					{
						case -1:
							printf("\n|El servicio no ha sido diagnosticado|\n");
						break;

						case 1:
							printf("\n<El servicio ha sido diagnosticado con exito>\n");
						break;
					}
				}
			break;

			case 5:
				if(altasHechas == 0)
				{
					printf("\n|ERROR|\nSe debe ingresar al menos un alta para poder acceder a esta opcion.");
				}
				else
				{
					getString("\n|Listado de informes|\n1-Todos los mecanicos\n2-Todos los servicios\n3-Mecanicos libres\n4-Listado de servicios ordenados por fecha\n"
				   "5-Suma de cotizaciones por 'Cambio de aceite', segun cierta fecha\n6-Cotizacion promedio por mecanico\n7-Mecanico con mas servicios\n"
				   "8-Servicios ordenados alfabeticamente por especialidad del mecanico\n9-Servicios entre marzo y mayo del 2022, para cierta especialidad\n"
				   "10-Porcentaje de servicio diagnosticados que atiende cada mecánico en función del total de diagnósticos\n11-Volver al menu\nElija una opcion: ", opcion);

					while(esNumerico(opcion) == 0 || (atoi(opcion) != 1 && atoi(opcion) != 2 && atoi(opcion) != 3 &&
						  atoi(opcion) != 4 && atoi(opcion) != 5 && atoi(opcion) != 6 && atoi(opcion) != 7 &&
						  atoi(opcion) != 8 && atoi(opcion) != 9 && atoi(opcion) != 10 && atoi(opcion) != 11))
		            {
						getString("\n|Listado de informes|\n1-Todos los mecanicos\n2-Todos los servicios\n3-Mecanicos libres\n4-Listado de servicios ordenados por fecha\n"
								  "5-Suma de cotizaciones por 'Cambio de aceite', segun cierta fecha\n6-Cotizacion promedio por mecanico\n7-Mecanico con mas servicios\n"
								  "8-Servicios ordenados alfabeticamente por especialidad del mecanico\n9-Servicios entre marzo y mayo del 2022, para cierta especialidad\n"
								  "10-Porcentaje de servicio diagnosticados que atiende cada mecánico en función del total de diagnósticos\n11-Volver al menu\nElija una opcion posible: ", opcion);
		            }

		            transformoOtraOpcion = atoi(opcion);

					switch(transformoOtraOpcion)
					{
						case 1:
							MostrarListaMecanico(listaMecanicos, M, listaEspecialidades, E);
						break;

						case 2:
							MostrarListaDeServicios(listaServicios, T);
						break;

						case 3:
							MostrarMecanicosLibres(listaMecanicos, M, listaEspecialidades, E);
						break;

						case 4:
							MostrarListaOrdenadaFecha(listaServicios, T);
						break;

						case 5:
							MostrarCotizacionSegunFecha(listaServicios, T, listaDiagnosticos, D);
						break;

						case 6:
							MostrarCotizacionPromedioPorMecanico(listaMecanicos, M, listaServicios, T, listaEspecialidades, E);
						break;

						case 7:
							MostrarMecanicosMasServicios(listaMecanicos, M, listaEspecialidades, E);
						break;

						case 8:
							MostrarServiciosOrdenadosPorEspecialidad(listaServicios, T, listaMecanicos, M, listaEspecialidades, E);
						break;

						case 9:
							ListarServiciosMarzoMayoPorEspecialidad(listaServicios, T, listaEspecialidades, E, listaMecanicos, M);
						break;

						case 10:
							ListarPromedioServiciosDiagnosticados(listaServicios, T, listaMecanicos, M, listaEspecialidades, E);//me falta esta
						break;
					}
				}
			break;

			case 6:
				getString("\n|Listado de TOPS|\n1-Top 3 de desperfectos más diagnosticados\n2-Top 3 de especialidades más estudiadas por los mecánicos\n3-Volver al menu\nElija una opcion: ", opcion);

				while(esNumerico(opcion) == 0 || (atoi(opcion) != 1 && atoi(opcion) != 2 && atoi(opcion) != 3))
	            {
					getString("\n|Listado de TOPS|\n1-Top 3 de desperfectos más diagnosticados\n2-Top 3 de especialidades más estudiadas por los mecánicos\n3-Volver al menu\nElija una opcion posible: ", opcion);
	            }

				transformoOtraOpcion = atoi(opcion);

				switch(transformoOtraOpcion)
				{
					case 1:
						ListarTopDesperfectos(listaServicios, T, listaDiagnosticos, D, listaAuxiliar);
					break;

					case 2:
						ListarTopEspecialidadesEstudiadas(listaMecanicos, M, listaEspecialidades, E, listaAuxiliar);
					break;
				}
			break;

			case 7:
				printf("\n|Lista de servicios ordenados alfabeticamente por direccion de taller, en talleres de mas de 1 piso|\n");
				OrdenarServiciosPorDireccionTaller(listaServicios, T, listaMecanicos, M, listaTalleres, L, listaEspecialidades, E);
			break;
		}

	}while(transformoOpcion != 8);

	return EXIT_SUCCESS;
}
