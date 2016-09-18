#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
// int getline(char **, size_t *, FILE *);
// typedef struct command;

#define MAXARGS 20
struct command{
	char *script_name;
	char *arguments[MAXARGS];
};

struct command *parse_command(char *);

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	struct command *cmd;
	while (1) {
		printf("$");
		read = getline(&line, &len, stdin);
		cmd = parse_command(line);
		int count = 0;
		char *token;
		while((token=cmd->arguments[count++]))
		{
			printf("%d: %s\n",count, token);
		}
		printf("command parsed\n");
		// printf("%s\n", cmd->script_name);
		// if (cmd->options)
		// 	printf("%s\n", cmd->options);
		// if (cmd->arguments)
		// 	printf("%s\n", cmd->arguments);
		// free(cmd->script_name);
		// free(cmd->arguments);
		// free(cmd->options);
		pid_t pid;
		pid = fork();
		if (pid < 0) {
			printf("Fork Failed");
			return 1;
		}
		else if (pid == 0){
			printf("About to execute the command in child process\n");
			execv(cmd->script_name, cmd->arguments);
		}
		else {
			printf("pid in parent: %d", (int) pid);
			while(pid != wait(0));
			printf("command finished running");
			printf("%s\n", "About to free cmd memory");
			free(cmd);
			printf("%s\n", "freed cmd memory");			
		}
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
	char *token;
	token = strtok(line, " ");
	if (token)
	{
		cmd->script_name = token;
	}
	int count = 0;
	cmd->arguments[count] = token;
	while ((token = strtok(NULL, " "))!=NULL)
	{
		cmd->arguments[++count] = token;
	}
	cmd->arguments[++count] = 0;
	return(cmd);
}

// struct command parse_command(char *line)
// {
// 	struct command parsed_command;

// }osiefoiesubfgoshb
