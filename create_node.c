#include "header.h"
/**
 * *add_node - add node in list
 * @head: head
 * @str: string
 * Return: List_t
 */
path_t *add_node(path_t **head, char *str)
{
	path_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(path_t));
	if (new == NULL)
		return (NULL);
    new->str = malloc((_strlen(str) + 1) * sizeof(char));
    if (new->str == NULL)
        return (NULL);
	new->str = _strcpy(new->str, str);
    new->str = _strcat(new->str, "/");
	new->len = _strlen(str);
	new->next = *head;
	*head = new;

	return (new);
}
/**
 * *create_node - create a node
 * @data: data from create
 * @separator: delimiter inside data
 * Return: new node
 */
path_t *create_node(char *data, char* separator)
{
    path_t *new;
    char *token;

    new = NULL;
    token = strtok(data, separator);
    while (token)
        add_node(&new, token), token = strtok(NULL, separator);
    free(token);

    return (new);
}