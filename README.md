# pd-list.h (with pointers doubles)

En este archivo de cabecera contiene diversas funciones para manipular una lista. El tipo de lista que usa el archivo de cabecera es lista doblemente circular.
Se usó punteros dobles en cada función para tener en cuenta la dirección de memoria del puntero que se pasará en la invocación de dicha función y su principal propósito es poder acceder/modificar el contenido del puntero que se pasó por referencia.
También se usó de apoyo extra los siguientes `header files`: [pscanf.h](https://github.com/MrDave1999/pscanf.h) & [assertx.h](https://github.com/MrDave1999/assertx.h)

# Instalación

Agrega los ficheros `list.h` & `deletenode.h` en el directorio del proyecto, es decir, en el lugar donde esté el código fuente del programa. Luego de eso, puedes hacer esta inclusión en el archivo (.c):
```C
#include "list.h"
```

# Funciones

- `uint8_t CreateNode(node**const pastNode, node**const firstNode)` 

  Crea un nodo específico en la lista.

- `void PrintElementNodes(const node**const lastNode, const node**const firstNode, const uint8_t type)` 

  Imprime todos los elementos de una lista.

  Sí utilizas así la función:
  ```C
  printElementNodes(&lastNode, &firstNode, START);
  ```
  Los elementos se muestran de forma ascendente, como por ejemplo: 1, 2, 3, 4.

  La otra opción es invocarlo así:
  ```C
  printElementNodes(&lastNode, &firstNode, END);
  ```
  Los elementos se mostrarán de manera descendente, como por ejemplo: 4, 3, 2, 1.

- `uint8_t SearchElementNode(const node**const firstNode, const int data)`

  Busca un determinado elemento de un específico nodo.

- `uint8_t OrderList(node**const firstNode, const uint8_t type)` 

  Ordena una lista, ya sea de menor a mayor o de mayor a menor.

  ***Tipo de llamada***:

  **1.** Ordenar de menor a mayor:
  ```C
  OrderList(&firstNode, AS); //Ascendente
  ```
  **2.** Ordenar de mayor a menor:
  ```C
  OrderList(&firstNode, DES); //Descendente
  ```

- `uint8_t DeleteNodeForData(node**const lastNode, node**const firstNode, const int data)` 

  Libera un específico nodo de una lista. Donde el parámetro "data" es el elemento a borrar.

- `void DeleteOneNode(node**const firstNode)` 

  Libera el primer nodo de la lista.

- `void DeleteLastNode(node**const lastNode, node**const firstNode)` 

  Libera el último nodo de la lista.

- `void DeleteAllNode(node**const firstNode)` 

  Libera todos los nodos de la lista.

Los punteros dobles `firstNode` & `lastNode` se usan para tener guardada la dirección de memoria del puntero que pasas como referencia al momento de llamar la función.

# Uso

```C
#include "list.h" //list.h incluye deletenode.h de forma automática.
#define OPTIONS " <1-12>"

int main(void)
{  
	node* firstNode = NULL; 
	node* lastNode = NULL;
	int32_t data;
	int32_t option;
	while (1)
	{
		puts("-> Menu de Opciones:");
		puts("1. Insertar un elemento a la lista");
		puts("2. Eliminar todos los elementos");
		puts("3. Mostrar los elementos de forma ascendente");
		puts("4. Mostrar los elementos de forma descendente");
		puts("5. Buscar un elemento");
		puts("6. Eliminar un especifico elemento");
		puts("7. Eliminar el primer elemento");
		puts("8. Eliminar el ultimo elemento");
		puts("9. Ordenar elementos de la lista (de menor a mayor)");
		puts("10. Ordenar elementos de la lista (de mayor a menor)");
		puts("11. Cantidad de elementos agregados");
		puts("12. Salir del programa");
		dataread("%d", &option, "Ingrese una opcion" ""OPTIONS"");
		if ((option >= 2 && option <= 10) && (firstNode == NULL))
		{
			puts("ERROR: La lista esta vacia.");
			pauseprogram();
			continue;
		}
		switch (option)
		{
			case 1:
				CreateNode(&lastNode, &firstNode);
				break;

			case 2: 
				DeleteAllNode(&firstNode);
				break;

			case 3: 
				PrintElementNodes(&lastNode, &firstNode, START); 
				break;
			case 4:
				PrintElementNodes(&lastNode, &firstNode, END);
				break;
			case 5:
				while (1)
				{
					dataread("%d", &data, "Ingrese un elemento a buscar:");
					assertc(SearchElementNode(&firstNode, data), "")
					break;
				}
				break;

			case 6:
				while (1)
				{
					dataread("%d", &data, "Que elemento quieres eliminar de la lista?");
					assertc(DeleteNodeForData(&lastNode, &firstNode, data), "")
					break;
				}
				break;

			case 7:
			{
				DeleteOneNode(&firstNode);
				break;
			}
			case 8:
				DeleteLastNode(&lastNode, &firstNode);
				break;

			case 9:
				OrderList(&firstNode, AS);
				break;

			case 10:
				OrderList(&firstNode, DES);
				break;

			case 11:
				; int countNodes = 0;
				if (firstNode != NULL)
				{
					const node* aux = firstNode;
					while (1)
					{
						++countNodes;
						aux = aux->sig;
						if (aux == firstNode) break;
					}
				}
				printf("-> Total de elementos: %d\n", countNodes);
				break;

			case 12:
				if (firstNode != NULL)
					DeleteAllNode(&firstNode);
				pauseprogram();
				return 0;
			default: puts("\nIngrese una opcion valida" ""OPTIONS"");
		}
		pauseprogram();
	}
	return 0;
}   
```

# Créditos

[MrDave](https://github.com/MrDave1999) (for create pscanf.h, assertx.h and list.h/deletenode.h)

[Microsoft](https://www.microsoft.com/es-ec/) (for create stdio, stdlib and stdint.h)
