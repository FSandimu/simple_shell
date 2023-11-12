#include "simple_shell.h"

/**
 *
 *
 *
 */

typedef struct alias
{
	char *name;
	char *value;
	struct alias *next;
}
alias;
alias *head = NULL;
void add_alias(char *name, char *value)
{
	alias *new_alias = (alias *)malloc(sizeof(alias));
	new_alias->name = strdup(name);
	new_alias->value = strdup(value);
	new_alias->next = head;
	head = new_alias;
}

char *find_alias(char *name)
{
	alias *current = head;
	while (current != NULL)
	{
		if (strcmp(current->name, name) == 0)
		{
			return (current->value);
		}
		current = current->next;
	}
	return (NULL);
}

void alias_cmd(char *args)
{
	if (args == NULL)
	{
		alias *current = head;
		while (current != NULL)
		{
			printf("%s='%s'\n", current->name, current->value);
			current = current->next;
		}
	}
	else
	{
		char *name = strtok(args, "=");
		char *value = strtok(NULL, "=");
		if (value == NULL)
		{
			char *alias_value = find_alias(name);
			if (alias_value != NULL)
			{
				printf("%s='%s'\n", name, alias_value);
			}
			else
			{
				printf("No alias named %s\n", name);
			}
		}
		else
		{
			add_alias(name, value);
		}
	}
}

int main(void)
{
	alias_cmd(NULL); // Prints all aliases
	add_alias("l", "ls -la");
	alias_cmd("l"); // Prints the alias 'l'
	return (0);
}
