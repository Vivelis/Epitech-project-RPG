/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** main
*/

#include "proj.h"
#include "my.h"

int main(int ac, char **av)
{
    if (ac > 1) {
        if (my_strcmp(av[1], "-h") == 0) {
            my_putstr("USAGE\n\t./my_rpg\n\nDESCRIPTION\n\tmy_rpg is a ");
            my_putstr("simple rpg game done in 2 Weeks.\n");
            my_putstr("\nKEY-BINDING\n\tF4\tquit the game\n");
            my_putstr("\tArrows\tdeplacement of the player\n");
            my_putstr("\tP\tinteract with object\n");
            my_putstr("\tA\topen inventory and stats\n");
            my_putstr("\tEscape\tpause menu\n");
            return (1);
        } else
            return my_puterror("./my_rpg: retry with \"-h\".\n", 84);
    }
    my_rpg();
}
