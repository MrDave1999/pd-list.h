#ifndef _INC_DELETENODE
#define _INC_DELETENODE

uint8_t DeleteNodeForData(node**const lastNode, node**const firstNode, const int data)
{
	node* aux = *firstNode;
	uint8_t DetectElement = 0;
	while (1)
	{
		if (aux->data == data)
		{
			node*const aux2 = aux;
			DetectElement = 1;
			if (aux == *firstNode) 
			{
				if ((*firstNode)->sig == *firstNode) 
					*firstNode = NULL;
				else 
				{
					*firstNode = (*firstNode)->sig;
					(*firstNode)->ant = *lastNode;
					(*lastNode)->sig = *firstNode;
				}
			}
			else
			{
				node*const postNode = aux->sig;
				node*const pastNode = aux->ant;
				postNode->ant = pastNode;
				pastNode->sig = postNode;
				if (aux == *lastNode)
					*lastNode = pastNode;
			}
			aux = aux->sig;
			free(aux2);
			if (*firstNode == NULL) break;
			continue;
		}
		aux = aux->sig;
		if (aux == *firstNode) break;
	}
	assertr(DetectElement, "ERROR: No se pudo eliminar el elemento porque no existe.")
	puts("El elemento fue eliminado con exito.");
	return 1;
}

void DeleteOneNode(node**const firstNode)
{
	if ((*firstNode)->sig == *firstNode)
	{
		free(*firstNode);
		*firstNode = NULL;
	}
	else
	{
		node*const aux = *firstNode;
		node*const lastNode = (*firstNode)->ant;
		*firstNode = (*firstNode)->sig;
		(*firstNode)->ant = lastNode;
		lastNode->sig = *firstNode;
		free(aux);
	}
	puts("-> El primer elemento fue eliminado con exito."); 
}

void DeleteLastNode(node**const lastNode, node**const firstNode)
{
	if ((*firstNode)->sig == *firstNode)
	{
		free(*firstNode);
		*firstNode = NULL;
	}
	else
	{
		node*const aux = *lastNode;
		node*const pastNode = (*lastNode)->ant;
		pastNode->sig = *firstNode;
		(*firstNode)->ant = pastNode;
		*lastNode = pastNode;
		free(aux);
	}
	puts("-> El ultimo elemento fue eliminado con exito.");
}

void DeleteAllNode(node**const firstNode)
{
	node* aux = *firstNode;
	const node*const lastNode = (*firstNode)->ant; 
	while (aux != lastNode)
	{
		*firstNode = aux;
		aux = aux->sig;
		free(*firstNode);
	}
	free(aux);
	*firstNode = NULL;
	puts("-> Todos los elementos fueron eliminados.");
}

#endif /* _INC_DELETENODE */
