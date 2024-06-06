/*
** EPITECH PROJECT, 2024
** miniradiateur2rendu
** File description:
** copy_env
*/

#include "../include/my.h"
#include "../include/mylist.h"
#include <fcntl.h>
#include <sys/wait.h>

static void execute_command(global_t *radiateur, char *str)
{
    arguments(radiateur, str);
    if (cmd(radiateur) == true)
        return;
    if (radiateur->programme == true)
        execution(radiateur);
    if (dir_442(radiateur) == 0) {
        execution(radiateur);
    }
}

static int split_pipi(global_t *radiateur, char *cmd)
{
    radiateur->my_pid = fork();
    if (radiateur->my_pid == -1)
        return 1;
    else if (radiateur->my_pid == 0)
        execute_command(radiateur, cmd);
    else
        waitpid(radiateur->my_pid, NULL, 0);
    return 0;
}

int pipi_left(global_t *radiateur, char *filename, char *cmd)
{
    int file = open(filename, O_RDONLY);
    char *str = NULL;
    size_t size = 0;

    if (file == -1)
        return 1;
    if (dup2(file, STDIN_FILENO) == -1) {
        close(file);
        return 1;
    }
    close(file);
    while (getline(&str, &size, stdin) != -1) {
        if (str[0] != '\0' && str[my_strlen(str) -1] == '\n')
            str[my_strlen(str) -1] = '\0';
        my_strcat(str, " ");
        my_strcat(cmd, str);
    }
    split_pipi(radiateur, cmd);
    free(str);
    return 0;
}

static int split_caca(global_t *radiateur, int *pipefd, int file)
{
    close(file);
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(radiateur->my_pid, NULL, 0);
    return 0;
}

int caca_rigth(global_t *radiateur,
    char *filename, int *pipefd, char *cmd)
{
    int file =
        open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    radiateur->my_pid = fork();
    if (radiateur->my_pid == -1)
        return 1;
    if (radiateur->my_pid == 0) {
        if (dup2(file, STDOUT_FILENO) == -1)
            exit(1);
        close(file);
        close(pipefd[1]);
        if (dup2(pipefd[0], STDIN_FILENO) == -1) {
            close(pipefd[0]);
            exit(1);
        }
        close(pipefd[0]);
        execute_command(radiateur, cmd);
        exit(1);
    } else
        return split_caca(radiateur, pipefd, file);
}

static int pipeplane(global_t *radiateur, char **commands, int *pipefd)
{
    if (pipe(pipefd) == -1)
        return 1;
    radiateur->my_pid = fork();
    if (radiateur->my_pid == -1)
        return 1;
    else if (radiateur->my_pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        execute_command(radiateur, commands[0]);
        exit(1);
    } else {
        wait(NULL);
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        execute_command(radiateur, commands[1]);
    }
    return 0;
}

int caca(char **tab, global_t *radiateur, int *index)
{
    char **pipe = my_str_to_array(tab[*index], '|');
    char **right = my_str_to_array(tab[*index], '>');
    char **left = my_str_to_array(tab[*index], '<');
    char *commands[2] = {pipe[0], pipe[1]};
    int *pipefd = malloc(sizeof(int) * 2);

    if (left[1] != NULL)
        if (pipi_left(radiateur, left[1], left[0]) != 0)
            return 1;
    if (right[1] != NULL)
        if (caca_rigth(radiateur, right[1], pipefd, right[0]) != 0)
            return 1;
    if (pipe[1] != NULL)
        if (pipeplane(radiateur, commands, pipefd) != 0)
            return 1;
    return 0;
}
