#include "mecanico.h"


void InicializarListaAuxiliar(eDiagnostico listaDiagnosticos[], int sizeDiagnostico, eAuxiliar listaAuxiliar[])
{
	for(int i = 0; i < sizeDiagnostico; i++)
	{
		listaAuxiliar[i].id = listaDiagnosticos[i].id;
		listaAuxiliar[i].contador = 0;
	}
}

void MostrarListaDesperfectos(eDiagnostico listaDiagnosticos[], int sizeDiagnostico, eAuxiliar listaAuxiliar[], int sizeAuxiliar)
{
	int contador = 0;

	printf("< Lista TOP 3 Desperfectos >\n");
	printf("ID 		Diagnostico                 Clientes\n");
	for(int i = 0; i < sizeAuxiliar; i++)
	{
		for(int j = 0; j < sizeDiagnostico; j++)
		{
			if(listaAuxiliar[i].id == listaDiagnosticos[j].id)
			{
				contador++;

				if(contador < 4)
				{
					printf("%d %25s %18d\n", listaDiagnosticos[j].id, listaDiagnosticos[j].descripcion, listaAuxiliar[i].contador);
				}
			}
		}
	}
}

int PedirIdMecanico(eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	char pidoNumero[10];
	int id;

	MostrarListaMecanico(listaMecanicos, sizeMecanico, listaEspecialidades, sizeEspecialidad);
	getString("\nIngrese el ID del mecanico a elegir: ", pidoNumero);
	while(esNumerico(pidoNumero) == 0)
	{
		getString("\nIngrese un numero de ID correcto: ", pidoNumero);
	}

	id = atoi(pidoNumero);

	return id;
}

int BuscarIdMecanico(eMecanico listaMecanicos[], int sizeMecanicos, int idRecibido)
{
	int index = -1;

	for(int i = 0; i < sizeMecanicos; i++)
	{
		if(idRecibido == listaMecanicos[i].id)
		{
			index = i;
			break;
		}
	}

	return index;
}

int PedirIdDiagnostico(eDiagnostico listaDiagnosticos[], int sizeDiagnostico)
{
	int id;
	char pidoNumero[10];

	MostrarListaDiagnosticos(listaDiagnosticos, sizeDiagnostico);
	getString("\nIngrese el ID del diagnostico acorde al problema: ", pidoNumero);
	while(esNumerico(pidoNumero) == 0)
	{
		getString("\nIngrese un numero de ID posible: ", pidoNumero);
	}

	id = atoi(pidoNumero);

	return id;
}

int BuscarIdDiagnostico(eDiagnostico listaDiagnosticos[], int sizeDiagnostico, int id)
{
	int estaTodoOk = -1;

	for(int i = 0; i < sizeDiagnostico; i++)
	{
		if(listaDiagnosticos[i].id == id)
		{
			estaTodoOk = 1;
			break;
		}
	}

	return estaTodoOk;
}

void MostrarUnMecanico (eMecanico unMecanico, sEspecialidad unaEspecialidad)
{
	printf("\n%10d %20s %20d %28s %14d %20d", unMecanico.id, unMecanico.nombre, unMecanico.idEspecialidad, unaEspecialidad.descripcion, unMecanico.idTaller, unMecanico.numeroClientes);
}

void MostrarListaMecanico (eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	printf("\n|Listado de mecanicos|\n"
			"       <ID>            <Nombre>          <ID Especialidad>        <Especialidad>          <ID Taller>          <Clientes>");
	for(int i = 0; i < sizeMecanico; i++)
	{
		for(int j = 0; j < sizeEspecialidad; j++)
		{
			if(listaMecanicos[i].idEspecialidad == listaEspecialidades[j].id)
			{
				MostrarUnMecanico(listaMecanicos[i], listaEspecialidades[j]);
			}
		}
	}
}

void MostrarUnDiagnostico(eDiagnostico unDiagnostico)
{
	printf("\n %d           %s", unDiagnostico.id, unDiagnostico.descripcion);
}

void MostrarListaDiagnosticos(eDiagnostico listaDiagnosticos[], int sizeDiagnostico)
{
	printf("\n ID:         Diagnostico: ");
	for(int i = 0; i < sizeDiagnostico; i++)
	{
		MostrarUnDiagnostico(listaDiagnosticos[i]);
	}
}

void MostrarMecanicosLibres(eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	printf("\n|Listado de mecanicos libres|\n"
			"       <ID>            <Nombre>          <ID Especialidad>        <Especialidad>        <Clientes>");
	for(int i = 0;i < sizeMecanico; i++)
	{
		for(int j = 0; j < sizeEspecialidad; j++)
		{
			if(listaMecanicos[i].estado == LIBRE && listaMecanicos[i].numeroClientes == 0 && listaMecanicos[i].idEspecialidad == listaEspecialidades[j].id)
			{
				MostrarUnMecanico(listaMecanicos[i], listaEspecialidades[j]);
				break;
			}
		}
	}
}

void OrdenarMecanicosPorEspecialidad(eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	eMecanico aux;

	OrdenarEspecialidadesAlfabeticamente(listaEspecialidades, sizeEspecialidad);

	for(int i = 0; i < sizeEspecialidad; i++)
	{
		for(int j = 0; j < sizeMecanico; j++)
		{
			for(int l = j + 1; l < sizeMecanico; l++)
			{
				if(listaEspecialidades[i].id == listaMecanicos[j].idEspecialidad)
				{
					aux = listaMecanicos[j];
					listaMecanicos[j] = listaMecanicos[l];
					listaMecanicos[l] = aux;
				}
			}
		}
	}
}

void MostrarListaEspecialidadesMasEstudiadas(sEspecialidad listaEspecialidades[], int sizeEspecialidad, eAuxiliar listaAuxiliar[])
{
	int contador = 0;

	printf("|Lista TOP 3 Especialidades mas estudiadas|\n");
	printf("ID 		   Especialidad            Mecanicos\n");
	for(int i = 0; i < sizeEspecialidad; i++)
	{
		for(int j = 0; j < sizeEspecialidad; j++)
		{
			if(listaAuxiliar[i].id == listaEspecialidades[j].id)
			{
				contador++;

				if(contador < 4)
				{
					printf("%d %28s %16d\n", listaEspecialidades[j].id, listaEspecialidades[j].descripcion, listaAuxiliar[i].contador);
				}
			}
		}
	}
}

void ListarTopEspecialidadesEstudiadas(eMecanico listaMecanicos[], int sizeMecanico, sEspecialidad listaEspecialidades[], int sizeEspecialidad, eAuxiliar listaAuxiliar[])
{
	int maximo;
	eAuxiliar aux;

	for(int i = 0; i < sizeEspecialidad; i++)
	{
		listaAuxiliar[i].id = listaEspecialidades[i].id;
		listaAuxiliar[i].contador = 0;
	}

	for(int i = 0; i < sizeEspecialidad; i++)
	{
		for(int j = 0; j < sizeMecanico; j++)
		{
			if(listaMecanicos[j].idEspecialidad == listaAuxiliar[i].id)
			{
				listaAuxiliar[i].contador++;
			}
		}
	}

	for(int i = 0; i < sizeEspecialidad; i++)
	{
		if(i == 0 || listaAuxiliar[i].contador > maximo)
		{
			maximo = listaAuxiliar[i].contador;
		}
	}

	for(int i = 0; i < sizeEspecialidad; i++)
	{
		for(int j = i + 1; j < sizeEspecialidad; j++)
		{
			if(listaAuxiliar[i].contador < listaAuxiliar[j].contador)
			{
				aux = listaAuxiliar[i];
				listaAuxiliar[i] = listaAuxiliar[j];
				listaAuxiliar[j] = aux;
			}
		}
	}

	MostrarListaEspecialidadesMasEstudiadas(listaEspecialidades, sizeEspecialidad, listaAuxiliar);
}
