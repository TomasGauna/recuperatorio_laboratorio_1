#include "especialidad.h"

void MostrarUnaEspecialidad(sEspecialidad unaEspecialidad)
{
	printf("\n%d         %s", unaEspecialidad.id, unaEspecialidad.descripcion);
}

void MostrarListaEspecialidades(sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	printf("\n|Listado de especialidades|\n");
	printf("<ID>       <Nombre>");
	for(int i = 0; i < sizeEspecialidad; i++)
	{
		MostrarUnaEspecialidad(listaEspecialidades[i]);
	}
}

int PedirIdEspecialidad(sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	char pidoNumero[10];
	int id;

	MostrarListaEspecialidades(listaEspecialidades, sizeEspecialidad);
	getString("\nIngrese el ID de la especialidad: ", pidoNumero);
	while(esNumerico(pidoNumero) == 0)
	{
		getString("\nIngrese un ID de especialidad posible: ", pidoNumero);
	}

	id = atoi(pidoNumero);

	return id;
}

int BuscarIdEspecialidad(sEspecialidad listaEspecialidades[], int sizeEspecialidad, int id)
{
	int index = -1;

	for(int i = 0; i < sizeEspecialidad; i++)
	{
		if(listaEspecialidades[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

void OrdenarEspecialidadesAlfabeticamente(sEspecialidad listaEspecialidades[], int sizeEspecialidad)
{
	sEspecialidad aux;

	for(int i = 0; i < sizeEspecialidad; i++)
	{
		for(int j = i + 1; j < sizeEspecialidad; j++)
		{
			if(strcmp(listaEspecialidades[i].descripcion, listaEspecialidades[j].descripcion) > 0)
			{
				aux = listaEspecialidades[i];
				listaEspecialidades[i] = listaEspecialidades[j];
				listaEspecialidades[j] = aux;
			}
		}
	}
}
