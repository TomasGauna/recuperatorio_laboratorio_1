#include "servicio.h"

eServicio PedirUnServicio()
{
	eServicio unServicio;

	unServicio.id = CalcularIdServicio();

//==========================================================================
	char aux[20];
	int validacion;


	getString("\nIngrese el nombre del cliente: ", aux);
	validacion = esSoloLetras(aux);
	while(validacion != 1)
	{
		getString("\n|ERROR|\nIngrese un nombre correcto: ", aux);
		validacion = esSoloLetras(aux);
	}

	strcpy(unServicio.nombreDelCliente, aux);
//==========================================================================

	unServicio.fecha.dia = PedirDia();
	unServicio.fecha.mes = PedirMes();
	unServicio.fecha.anio = PedirAnio();
	unServicio.idDiagnostico = -1;
	unServicio.idMecanico = -1;
	unServicio.cotizacion = -1;

	unServicio.estado = OCUPADO;

	return unServicio;
}

int BuscarEspacioLibre(eServicio listaServicios[], int sizeServicios)
{
	int index = -1;

	for(int i = 0; i < sizeServicios; i++)
	{
		if(listaServicios[i].estado == LIBRE)
		{
			index = i;
			break;
		}
	}

	return index;
}

int CalcularIdServicio()
{
	static int id = 1;
	return id++;
}

void PedirNombre(eServicio unServicio)
{
	char aux[20];
	int validacion;


	getString("\nIngrese el nombre del cliente: ", aux);
	validacion = esSoloLetras(aux);
	while(validacion != 1)
	{
		getString("\n|ERROR|\nIngrese un nombre correcto: ", aux);
		validacion = esSoloLetras(aux);
	}

	strcpy(unServicio.nombreDelCliente, aux);
}

int PedirDia()
{
	char numero[5];
	int validacion;
	int numeroValido;

	getString("\nIngrese el dia del servicio: ", numero);
	validacion = esNumerico(numero);

	while(validacion == 0 || atoi(numero) > 31 || atoi(numero) == 0)
	{
		getString("\nIngrese un dia de servicio posible: ", numero);
		validacion = esNumerico(numero);
	}

	numeroValido = atoi(numero);

	return numeroValido;
}

int PedirMes()
{
	char numero[5];
	int validacion;
	int numeroValido;

	getString("\nIngrese el mes del servicio: ", numero);
	validacion = esNumerico(numero);

	while(validacion != 1 || atoi(numero) > 12 || atoi(numero) == 0)
	{
		getString("\n|ERROR|\nIngrese un mes correcto: ", numero);
		validacion = esNumerico(numero);
	}

	numeroValido = atoi(numero);

	return numeroValido;
}

int PedirAnio()
{
	char numero[5];
	int validacion;
	int numeroValido;

	getString("\nIngrese el año del servicio: ", numero);
	validacion = esNumerico(numero);

	while(validacion != 1 || atoi(numero) > 2050 || atoi(numero) < 2021)
	{
		getString("\n|ERROR|\nIngrese un año correcto: ", numero);
		validacion = esNumerico(numero);
	}

	numeroValido = atoi(numero);

	return numeroValido;
}

int PedirIdServicio(eServicio listaServicios[], int sizeServicios)
{
	char pidoNumero[10];
	int id;

	getString("\nIngrese el ID del servicio: ", pidoNumero);
	while(esNumerico(pidoNumero) == 0)
	{
		getString("\n|ERROR|\nIngrese un numero de ID posible: ", pidoNumero);
	}

	id = atoi(pidoNumero);

	return id;
}

float PedirPrecio()
{
	char pidoPrecio[10];
	float precio;

	getString("\nIngrese el precio del servicio: ", pidoPrecio);
	while(esNumericoFlotante(pidoPrecio) == 0)
	{
		getString("\n|ERROR|\nIngrese un precio posible: ", pidoPrecio);
	}

	precio = atof(pidoPrecio);

	return precio;
}

int CargarListaDeServicios(eServicio listaServicios[], int sizeServicios)
{
	int cargado = -1;
	int index;

	index = BuscarEspacioLibre(listaServicios, sizeServicios);

	for(int i = 0; i < sizeServicios; i++)
	{
		if(index != -1)
		{
			listaServicios[index] = PedirUnServicio();
			cargado = 1;
			break;
		}
	}

	return cargado;
}

void MostrarUnServicio(eServicio unServicio)
{
	printf("\n%d  %17s  %20d/%d/%d   %22d %19d %20.2f",
	unServicio.id, unServicio.nombreDelCliente, unServicio.fecha.dia, unServicio.fecha.mes, unServicio.fecha.anio, unServicio.idMecanico, unServicio.idDiagnostico,unServicio.cotizacion);
}

void MostrarListaDeServicios(eServicio listaServicios[], int sizeServicios)
{
	printf("\nID        Nombre del cliente         Fecha del servicio              Mecanico           Diagnostico          Cotizacion");
	for(int i = 0; i  < sizeServicios; i++)
	{
		if(listaServicios[i].estado == OCUPADO)
		{
			MostrarUnServicio(listaServicios[i]);
		}
	}
}

int BuscarId(eServicio listaServicios[], int sizeServicios, int id)
{
	int index = -1;

	for(int i = 0; i < sizeServicios; i++)
	{
		if(listaServicios[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

int MostrarMenuModificacion(int opcionElegida, eServicio listaServicios[], int index, eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	char optionElegida[10];
	int transformoOpcion;
	int modifico = -1;
	int validacion;
	char aux[50];
	int auxEntero;
	int auxDia;
	int auxMes;
	int auxAnio;

	switch(opcionElegida)
	{
		case 1:
		//===================================================================================//

			getString("\nIngrese el nombre del cliente: ", aux);
			validacion = esSoloLetras(aux);
			while(validacion != 1)
			{
				getString("\n|ERROR|\nIngrese un nombre correcto: ", aux);
				validacion = esSoloLetras(aux);
			}
		//===================================================================================//

			getString("\nEl nombre del cliente esta por ser modificado. Desea continuar?\n1-SI\n2-NO\nElija una opcion: ", optionElegida);
			while(esNumerico(optionElegida) == 0 || (atoi(optionElegida) != 1 && atoi(optionElegida) != 2))
			{
				getString("\n|ERROR|\nEl nombre del cliente esta por ser modificado. Desea continuar?\n1-SI\n2-NO\nElija una opcion correcta: ", optionElegida);
			}

			transformoOpcion = atoi(optionElegida);

			if(transformoOpcion == 1)
			{
				strcpy(listaServicios[index].nombreDelCliente, aux);
				modifico = 1;
			}

		break;

		case 2:
			auxDia = PedirDia();
			auxMes = PedirMes();
			auxAnio = PedirAnio();

			getString("\nLa fecha del servicio esta por ser modificada. Desea continuar?\n1-SI\n2-NO\nElija una opcion: ", optionElegida);
			while(esNumerico(optionElegida) == 0 || (atoi(optionElegida) != 1 && atoi(optionElegida) != 2))
			{
				getString("\n|ERROR|\nLa fecha del servicio esta por ser modificada. Desea continuar?\n1-SI\n2-NO\nElija una opcion: ", optionElegida);
			}

			transformoOpcion = atoi(optionElegida);

			if(transformoOpcion == 1)
			{
				listaServicios[index].fecha.dia = auxDia;
				listaServicios[index].fecha.mes = auxMes;
				listaServicios[index].fecha.anio = auxAnio;
				modifico = 1;
			}
		break;

		case 3:

			if(listaServicios[index].idMecanico != -1)
			{
				auxEntero = PedirIdMecanico(listaMecanicos, sizeMecanico, listaEspecialidades, sizeEspecialidad);
				validacion = BuscarIdMecanico(listaMecanicos, sizeMecanico, auxEntero);
				for(int i = 0; i < sizeMecanico; i++)
				{
					if(validacion != -1)
					{
						getString("\nEl Id del mecanico esta por ser modificado. Desea continuar?\n1-SI\n2-NO\nElija una opcion: ", optionElegida);
						while(esNumerico(optionElegida) == 0 || (atoi(optionElegida) != 1 && atoi(optionElegida) != 2))
						{
							getString("\n|ERROR|\nEl Id del mecanico esta por ser modificado. Desea continuar?\n1-SI\n2-NO\nElija una opcion correcta: ", optionElegida);
						}

						transformoOpcion = atoi(optionElegida);

						if(transformoOpcion == 1)
						{
							listaServicios[index].idMecanico = auxEntero;
							modifico = 1;
						}
						break;
					}
				}

				if(modifico == -1)
				{
					printf("\n<No se ha encontrado el ID>");
				}
			}
			else
			{
				printf("\n|ERROR|\nTodavia no se ha asignado un mecanico.\n");
			}
		break;
	}

	return modifico;
}

int ModificarServicio(eServicio listaServicios[], int sizeServicios, eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	int modificado = -1;
	char opcionElegida[10];
	int transformoOpcion;
	int id;
	int index = -1;

	MostrarListaDeServicios(listaServicios, sizeServicios);
	id = PedirIdServicio(listaServicios, sizeServicios);
	index = BuscarId(listaServicios, sizeServicios, id);

	switch(index)
	{
		case -1:
			printf("\n<No se ha encontrado el ID>");
		break;

		default:
			getString("\nQue desea modificar?\n1-Nombre del cliente\n2-Fecha del servicio\n3-Mecanico\n4-Volver al menu\nElija el numero de la opcion: ", opcionElegida);

			while(esNumerico(opcionElegida) == 0 || (atoi(opcionElegida) != 1 && atoi(opcionElegida) != 2 && atoi(opcionElegida) != 3 && atoi(opcionElegida) != 4))
			{
				getString("\n|ERROR|\nQue desea modificar?\n1-Nombre del cliente\n2-Fecha del servicio\n3-Mecanico\n4-Volver al menu\nElija una opcion correcta: ", opcionElegida);
			}

			transformoOpcion = atoi(opcionElegida);
			modificado = MostrarMenuModificacion(transformoOpcion, listaServicios, index, listaMecanicos, sizeMecanico, listaEspecialidades, sizeEspecialidad);
		break;
	}
	return modificado;
}

int DarDeBaja(eServicio listaServicios[], int sizeServicios, eMecanico listaMecanicos[], int sizeMecanicos)
{
	int eliminado = -1;
	int id;
	int index;
	int indexMecanico;
	char optionElegida[10];
	int transformoOpcion;

	printf("\n|Lista de servicios|");
	MostrarListaDeServicios(listaServicios, sizeServicios);

	id = PedirIdServicio(listaServicios, sizeServicios);
	index = BuscarId(listaServicios, sizeServicios, id);

	if(index != -1 && id != 0)
	{
		if(listaServicios[index].idMecanico != -1)
		{
			indexMecanico = BuscarIdMecanico(listaMecanicos, sizeMecanicos, listaServicios[index].idMecanico);
			if(indexMecanico != -1)
			{
				printf("\nEl servicio con   ID: %d   Nombre: %s   Diagnostico: %d  está por ser eliminado.", listaServicios[index].id, listaServicios[index].nombreDelCliente,listaServicios[index].idDiagnostico);
				getString("\n¿Desea continuar? 1-SI   2-NO\nElija una opcion: ", optionElegida);
				while(esNumerico(optionElegida) == 0 || (atoi(optionElegida) != 1 && atoi(optionElegida) != 2))
				{
					printf("\n|ERROR|\nEl servicio con   ID: %d   Nombre: %s   Diagnostico: %d  está por ser eliminado.", listaServicios[index].id, listaServicios[index].nombreDelCliente,listaServicios[index].idDiagnostico);
					getString("\n¿Desea continuar? 1-SI   2-NO\nElija una opcion correcta: ", optionElegida);
				}

				transformoOpcion = atoi(optionElegida);

				if(transformoOpcion == 1)
				{
					listaServicios[index].estado = LIBRE;
					listaMecanicos[indexMecanico].numeroClientes --;
					eliminado = 1;
				}
			}
		}
		else
		{
			printf("\nEl servicio con   ID: %d   Nombre: %s   Diagnostico: %d  está por ser eliminado.", listaServicios[index].id, listaServicios[index].nombreDelCliente,listaServicios[index].idDiagnostico);
			getString("\n¿Desea continuar? 1-SI   2-NO\nElija una opcion: ", optionElegida);
			while(esNumerico(optionElegida) == 0 || (atoi(optionElegida) != 1 && atoi(optionElegida) != 2))
			{
				printf("\n|ERROR|\nEl servicio con   ID: %d   Nombre: %s   Diagnostico: %d  está por ser eliminado.", listaServicios[index].id, listaServicios[index].nombreDelCliente,listaServicios[index].idDiagnostico);
				getString("\n¿Desea continuar? 1-SI   2-NO\nElija una opcion correcta: ", optionElegida);
			}

			transformoOpcion = atoi(optionElegida);

			if(transformoOpcion == 1)
			{
				listaServicios[index].estado = LIBRE;
				eliminado = 1;
			}
		}
	}
	else
	{
		printf("\n<No se ha encontra el ID>");
	}

	return eliminado;
}

int DiagnosticarServicio(eServicio listaServicios[], int sizeServicios, eMecanico listaMecanicos[], int sizeMecanico, eDiagnostico listaDiagnosticos[], int sizeDiagnostico, sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	int diagnosticado = -1;
	int idServicio;
	int indexServicio;
	int idDiagnostico;
	int idMecanico;
	int indexMecanico;
	int verificar;
	float precio;

	printf("\n|Lista de servicios sin diagnosticar|");
	MostrarServiciosNoDiagnosticados(listaServicios, sizeServicios);

	idServicio = PedirIdServicio(listaServicios, sizeServicios);
	indexServicio = BuscarId(listaServicios, sizeServicios, idServicio);

	if(indexServicio != -1 && listaServicios[indexServicio].idDiagnostico == -1)
	{
		printf("|Lista de diagnosticos|");
		idDiagnostico = PedirIdDiagnostico(listaDiagnosticos, sizeDiagnostico);
		verificar = BuscarIdDiagnostico(listaDiagnosticos, sizeDiagnostico, idDiagnostico);

		if(verificar != -1)
		{
			idMecanico = PedirIdMecanico(listaMecanicos, sizeMecanico, listaEspecialidades, sizeEspecialidad);
			indexMecanico = BuscarIdMecanico(listaMecanicos, sizeMecanico, idMecanico);

			if(indexMecanico != -1)
			{
				listaServicios[indexServicio].idDiagnostico = idDiagnostico;

				listaMecanicos[indexMecanico].estado = OCUPADO;
				listaMecanicos[indexMecanico].numeroClientes++;
				listaServicios[indexServicio].idMecanico = idMecanico;

				precio = PedirPrecio();
				listaServicios[indexServicio].cotizacion = precio;
				diagnosticado = 1;

			}
			else
			{
				printf("\n|No se ha encontrado el ID del mecanico|\n");
			}
		}
		else
		{
			printf("\n|No se ha encontrado el ID del diagnostico|\n");
		}
	}
	else
	{
		printf("\n|No se ha encontrado el ID del servicio|\n");
	}

	return diagnosticado;
}

void MostrarServiciosNoDiagnosticados(eServicio listaServicios[], int sizeServicios)
{
	printf("\nID             Nombre                     Fecha                      Mecanico           Diagnostico        Cotizacion");
	for(int i = 0; i < sizeServicios; i++)
	{
		if(listaServicios[i].idDiagnostico == -1 && listaServicios[i].estado == OCUPADO)
		{
			MostrarUnServicio(listaServicios[i]);
		}
	}
}

void MostrarListaOrdenadaFecha(eServicio listaServicios[], int sizeServicios)
{
	eServicio aux;

	for(int i = 0; i < sizeServicios; i++)
	{
		for(int j = i + 1; j < sizeServicios; j++)
		{
			if(listaServicios[i].fecha.anio > listaServicios[j].fecha.anio)
			{
				aux = listaServicios[i];
				listaServicios[i] = listaServicios[j];
				listaServicios[j] = aux;
			}
			else
			{
				if(listaServicios[i].fecha.mes > listaServicios[j].fecha.mes)
				{
					aux = listaServicios[i];
					listaServicios[i] = listaServicios[j];
					listaServicios[j] = aux;
				}
				else
				{
					if(listaServicios[i].fecha.dia > listaServicios[j].fecha.dia)
					{
						aux = listaServicios[i];
						listaServicios[i] = listaServicios[j];
						listaServicios[j] = aux;
					}
				}
			}
		}
	}

	MostrarListaDeServicios(listaServicios, sizeServicios);
}

void MostrarCotizacionSegunFecha(eServicio listaServicios[], int sizeServicios, eDiagnostico listaDiagnosticos[], int sizeDiagnostico)
{
	int dia;
	int mes;
	int anio;
	float sumaTotal = 0;

	dia = PedirDia();
	mes = PedirMes();
	anio = PedirAnio();

	for(int i = 0; i < sizeServicios; i++)
	{
		if(listaServicios[i].fecha.anio == anio && listaServicios[i].fecha.mes == mes && listaServicios[i].fecha.dia == dia)
		{
			if(listaServicios[i].idDiagnostico == 200)
			{
				sumaTotal += listaServicios[i].cotizacion;
			}
		}
	}

	printf("\nLa suma es %.2f", sumaTotal);
}

void MostrarCotizacionPromedioPorMecanico(eMecanico listaMecanicos[], int sizeMecanico, eServicio listaServicios[], int sizeServicio, sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	int contador;
		float sumaPrecio;
		float promedio;

		for(int i = 0; i < sizeMecanico; i++)
		{
			for(int j = 0; j < sizeEspecialidad; j++)
			{
				if(listaMecanicos->idEspecialidad == listaEspecialidades->id)
				{
					if(listaMecanicos[i].estado == OCUPADO)
					{
						MostrarUnMecanico(listaMecanicos[i], listaEspecialidades[j]);

						contador = 0;
						sumaPrecio = 0;

						for(int j = 0; j < sizeServicio; j++)
						{
							if(listaMecanicos[i].id == listaServicios[j].idMecanico)
							{
								sumaPrecio += listaServicios[j].cotizacion;
								contador++;
								promedio = sumaPrecio / contador;
							}
						}
									printf("Promedio de cotizacion: %.2f \n", promedio);
					}
				}
			}
		}

}

void ListarTopDesperfectos(eServicio listaServicios[], int sizeServicios, eDiagnostico listaDiagnosticos[], int sizeDiagnostico, eAuxiliar listaAuxiliar[])
{
	/* No paso por parametro ni declaro dentro de la funcion el size de la lista auxiliar porque ese auxiliar
	 * auxilia(valga la redundancia) a la lista de diagnostico, por ende, utilizan el mismo size: int sizeDiagnostico.
	 */
		int maximo;
		eAuxiliar aux;

		InicializarListaAuxiliar(listaDiagnosticos, sizeDiagnostico, listaAuxiliar);

		for(int i = 0; i < sizeDiagnostico; i++)
		{
			for(int j = 0; j < sizeServicios; j++)
			{
				if(listaServicios[j].idDiagnostico == listaAuxiliar[i].id)
				{
					listaAuxiliar[i].contador++;
				}
			}
		}

		for(int i = 0; i < sizeDiagnostico; i++)
		{
			if(i == 0 || listaAuxiliar[i].contador > maximo)
			{
				maximo = listaAuxiliar[i].contador;
			}
		}

		for(int i = 0; i < sizeDiagnostico; i++)
		{
			for(int j = i + 1; j < sizeDiagnostico; j++)
			{
				if(listaAuxiliar[i].contador < listaAuxiliar[j].contador)
				{
					aux = listaAuxiliar[i];
					listaAuxiliar[i] = listaAuxiliar[j];
					listaAuxiliar[j] = aux;
				}
			}
		}

		MostrarListaDesperfectos(listaDiagnosticos, sizeDiagnostico, listaAuxiliar, sizeDiagnostico);
}

void MostrarMecanicosMasServicios(eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	int maximo;
	int index;

	for(int i = 0; i < sizeMecanico; i++)
	{
		if(i == 0 || maximo < listaMecanicos[i].numeroClientes)
		{
			maximo = listaMecanicos[i].numeroClientes;
			index = i;
		}
	}


	printf("\n|Mecanico con mas servicio|\n");
	printf("       <ID>            <Nombre>          <ID Especialidad>        <Especialidad>          <ID Taller>          <Clientes>");
	for(int i = 0; i < sizeEspecialidad; i++)
	{
		if(listaMecanicos[index].idEspecialidad == listaEspecialidades[i].id)
		{
			MostrarUnMecanico(listaMecanicos[index], listaEspecialidades[i]);
		}
	}
}

void ListarServiciosMarzoMayoPorEspecialidad(eServicio listaServicios[], int sizeServicio, sEspecialidad listaEspecialidad[], int sizeEspecialidad, eMecanico listaMecanicos[], int sizeMecanico)
{
	int idEspecialidad;
	int index;

	idEspecialidad = PedirIdEspecialidad(listaEspecialidad, sizeEspecialidad);
	index = BuscarIdEspecialidad(listaEspecialidad, sizeEspecialidad, idEspecialidad);

	if(index != -1)
	{
		printf("|Listado de servicios entre los meses de Marzo y Mayo del 2022 por la especialidad de %s|", listaEspecialidad[index].descripcion);
		printf("\nID           Nombre                       Fecha                      Mecanico           Diagnostico        Cotizacion");
		for(int i = 0; i < sizeServicio; i++)
		{
			for(int j = 0; j < sizeMecanico; j++)
			{
				if(listaServicios[i].fecha.mes < 6 && listaServicios[i].fecha.mes > 2 && listaServicios[i].fecha.anio == 2022 && listaMecanicos[j].id == listaServicios[i].idMecanico && listaMecanicos[j].idEspecialidad == listaEspecialidad[index].id)
				{
					MostrarUnServicio(listaServicios[i]);
				}
			}
		}
	}
	else
	{
		printf("\n|ERROR|\nNo se ha encontrado el ID de la especialidad");
	}
}

void ListarPromedioServiciosDiagnosticados(eServicio listaServicios[], int sizeServicio, eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidad[], int sizeEspecialidad)
{
	//Porcentaje de servicio diagnosticados que atiende cada mecánico en función del total de diagnósticos.
	int contadorDiagnosticos = 0;
	int contador;
	float porcentaje = 0;

	printf("\n|Listado de mecanicos|\n"
				"       <ID>            <Nombre>          <ID Especialidad>        <Especialidad>          <ID Taller>          <Clientes>");

	for(int i=0; i<sizeServicio; i++)
	{
		if(listaServicios[i].idDiagnostico != -1  && listaServicios[i].estado == OCUPADO)
		{
			contadorDiagnosticos++;
		}
	}

	for(int i = 0; i < sizeMecanico; i++)
	{
		for(int j = 0; j < sizeEspecialidad; j++)
		{
			if(listaMecanicos[i].estado == OCUPADO && listaMecanicos[i].idEspecialidad == listaEspecialidad[j].id)
			{
				MostrarUnMecanico(listaMecanicos[i], listaEspecialidad[j]);

				contador = 0;

				for(int j = 0; j < sizeServicio; j++)
				{
					if(listaMecanicos[i].id == listaServicios[j].idMecanico && listaServicios[i].idDiagnostico != -1)
					{
						contador++;

						porcentaje = (contador * 100) / contadorDiagnosticos;
					}
				}
				printf("\nPorcentaje diagnosticado: %.2f \n", porcentaje);
			}
		}
	}
}

void MostrarServiciosOrdenadosPorEspecialidad(eServicio listaServicios[], int sizeServicio, eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	OrdenarMecanicosPorEspecialidad(listaMecanicos, sizeMecanico, listaEspecialidades, sizeEspecialidad);

	printf("\n|Lista de servicios ordenado por especialidad del mecanico|\n");
	printf("<ID>          <Nombre del cliente>          <ID mecanico>            <Nombre del mecanico>          <Especialidad del mecanico>\n");
	for(int i = 0; i < sizeEspecialidad; i++)
	{
		for(int j = 0; j < sizeMecanico; j++)
		{
			for(int l = 0; l < sizeServicio; l++)
			{
				if(listaServicios[l].idMecanico == listaMecanicos[j].id && listaMecanicos[j].idEspecialidad == listaEspecialidades[i].id)
				{
					printf("%d %24s %25d %29s %34s\n", listaServicios[l].id, listaServicios[l].nombreDelCliente, listaServicios[l].idMecanico, listaMecanicos[j].nombre, listaEspecialidades[i].descripcion);
				}
			}
		}
	}
}
