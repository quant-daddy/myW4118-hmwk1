#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int getline(char **, size_t *, FILE *);
// typedef struct command;
struct command{
	char *script_name;
	char *options;
	char *argument;
};

struct command *parse_command(char *);

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	char *token;
	struct command *cmd;
	while (1) {
		printf("$");
		read = getline(&line, &len, stdin);
		cmd = parse_command(line);
		printf("%s\n", cmd->script_name);
		if (cmd->options)
			printf("%s\n", cmd->options);
		if (cmd->argument)
			printf("%s\n", cmd->argument);
		// free(cmd->script_name);
		// free(cmd->argument);
		// free(cmd->options);
		printf("%s\n", "About to free cmd memory");
		free(cmd);
		printf("%s\n", "freed cmd memory");
		// token = strtok(line, " ");
		// printf("%s\n", token);
		// while ((token = strtok(NULL, " "))!=0)
		// 	printf("%s\n", token);
		// printf("size = %zu\n", sizeof(*line));
	};
	free(line);
	return 0;
}



struct command *parse_command(char *line)
{
	struct command *cmd = (struct command *) malloc(sizeof(struct command));
	// cmd->script_name = (char *)malloc(20*sizeof(char *));
	// cmd->argument = (char *)malloc(20*sizeof(char *));
	// cmd->options = (char *)malloc(20*sizeof(char *));
	char *token;
	token = strtok(line, " ");
	if (token)
	{
		cmd->script_name = token;
	}
	while ((token = strtok(NULL, " "))!=NULL)
	{
		if (((int)token[0])==45)
			cmd->options = &token[1];
		else
			cmd->argument = token;
	}
		
	return(cmd);
}

// struct command parse_command(char *line)
// {
// 	struct command parsed_command;

// }osiefoiesubfgoshb
