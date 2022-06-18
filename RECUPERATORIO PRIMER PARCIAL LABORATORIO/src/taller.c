#include "taller.h"

void MostrarUnTaller(Taller unTaller)
{
	printf("%d             %s           %d\n", unTaller.id, unTaller.direccion, unTaller.pisos);
}

void MostrarListaDeTalleres(Taller listaTalleres[], int sizeTalleres)
{
	printf("<ID>          <Direccion>         <Pisos>");
	for(int i = 0; i < sizeTalleres; i++)
	{
		MostrarUnTaller(listaTalleres[i]);
	}
}

void OrdenarTalleresAlfabeticamente(Taller listaTaller[], int sizeTaller)
{
	Taller aux;
	for(int i = 0; i < sizeTaller; i++)
	{
		for(int j = i + 1; j < sizeTaller; j++)
		{
			if(strcmp(listaTaller[i].direccion, listaTaller[j].direccion) > 0)
			{
				aux = listaTaller[j];
				listaTaller[j] = listaTaller[i];//BIEN
				listaTaller[i] = aux;
			}
		}
	}
}

void OrdenarMecanicosPorTaller(eMecanico listaMecanicos[], int sizeMecanico, Taller listaTaller[], int sizeTaller)
{
	eMecanico aux;

	OrdenarTalleresAlfabeticamente(listaTaller, sizeTaller);

	for(int i = 0; i < sizeTaller; i++)
	{
		for(int j = 0; j < sizeMecanico; j++)
		{
			for(int l = 0; l < sizeMecanico; l++)
			{
				if(listaMecanicos[j].idTaller == listaTaller[i].id)
				{
					aux = listaMecanicos[i];
					listaMecanicos[i] = listaMecanicos[j];
					listaMecanicos[j] = aux;
				}
			}
		}
	}
}

void OrdenarServiciosPorDireccionTaller(eServicio listaServicios[], int sizeServicio, eMecanico listaMecanicos[], int sizeMecanico, Taller listaTaller[], int sizeTaller, sEspecialidad listaEspecialidad[], int sizeEspecialidad)
{
	//servicios en talleres con mas de un piso ordenados alfabeticamente
	OrdenarMecanicosPorTaller(listaMecanicos, sizeMecanico, listaTaller, sizeTaller);

	printf("\nID             Nombre                 Mecanicos           Especialidad del mecanico        Direccion del Taller");

	for(int i = 0; i < sizeMecanico; i++)
	{
		for(int j = 0; j < sizeServicio; j++)
		{
			for(int k = 0; k < sizeEspecialidad; k++)
			{
				for(int l = 0; l < sizeTaller; l++)
				{
					if(listaMecanicos[i].id == listaServicios[j].idMecanico && listaMecanicos[i].idEspecialidad == listaEspecialidad[k].id && listaMecanicos[i].idTaller == listaTaller[l].id && listaTaller[l].pisos > 1)
					{
						printf("\n%d %18s %25s %26s %29s", listaServicios[j].id, listaServicios[j].nombreDelCliente, listaMecanicos[i].nombre, listaEspecialidad[k].descripcion, listaTaller[l].direccion);
					}
				}
			}
		}
	}
}
