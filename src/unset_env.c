/*
** EPITECH PROJECT, 2024
** miniset_boudin2rendu
** File description:
** set_boudin
*/

#include "../include/my.h"
#include "../include/mylist.h"

static int error_case(global_t *set_boudin, char *str)
{
    if (set_boudin->chaise == NULL)
        return 1;
    if (str == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
        return 1;
    }
    if (my_strcmp(str, "*") == 0)
        return 1;
    return 0;
}

static void supprimer(env_42_copy_t *same_code)
{
    free(same_code->name);
    free(same_code->data);
    free(same_code);
}

static void delete_prout(env_42_copy_t *same_code,
    env_42_copy_t *prev, global_t *set_boudin)
{
    if (same_code->next == NULL) {
        if (prev == NULL)
            set_boudin->chaise = NULL;
        else
            prev->next = NULL;
        supprimer(same_code);
    } else if (my_strcmp(same_code->name, set_boudin->chaise->name) == 0) {
        set_boudin->chaise = same_code->next;
        supprimer(same_code);
    } else {
        prev->next = same_code->next;
        supprimer(same_code);
    }
}

int unset_boudin(global_t *set_boudin, char *str)
{
    env_42_copy_t *same_code = set_boudin->chaise;
    env_42_copy_t *prev = NULL;

    if (error_case(set_boudin, str) != 0)
        return 1;
    while (same_code) {
        if (my_strcmp(same_code->name, str) == 0) {
            delete_prout(same_code, prev, set_boudin);
            return 1;
        }
        prev = same_code;
        same_code = same_code->next;
    }
    return 0;
}
