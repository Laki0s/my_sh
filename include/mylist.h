/*
** EPITECH PROJECT, 2024
** minishell2rendu
** File description:
** mylist
*/

#pragma once

#include "stdbool.h"

typedef struct env_42_copy_s {
    char *data;
    char *name;
    struct env_42_copy_s *next;
} env_42_copy_t;

typedef struct global_s {
    char **arg;
    char **env;
    char *path;
    char *lol;
    bool programme;
    int i;
    __pid_t my_pid;
    char *cmd;
    env_42_copy_t *chaise;
} global_t;
