/*
** EPITECH PROJECT, 2022
** My_rpg
** File description:
** Special interaction
*/

#include "proj.h"

void mushroom_interaction(game_t *game, int y, int x)
{
    if (game->quest.init == 0)
        return;
    set_msg(game, "You found an Epimushroom");
    if (game->quest.mush_found < 5) {
        //Add mushroom to the inventory
    }
    game->map.special[y][x] = ' ';
    game->quest.mush_found++;
}

void pnj_quest_interaction(game_t *game)
{
    if (game->quest.init == 2)
        set_msg(game, "Merci encore pour ces champignons");
    if (game->quest.init == 1 && game->quest.mush_found == 1)
        set_msg(game, "N'oublie pas je veux 5 champignons");
    if (game->quest.init == 0 || 
    (game->quest.init == 1 && game->quest.mush_found == 0)) {
        game->quest.mush_found = 0;
        game->quest.init = 1;
        set_msg(game, "Bonjour aventurier va donc recuperer 5 Champignons\n");
    }
    if (game->quest.init == 1 && game->quest.mush_found < 5 &&
    game->quest.mush_found > 1)
        set_msg(game, "Tu y est presque tu auras bientot ta recompense");
    if (game->quest.init == 1 && game->quest.mush_found >= 5) {
        set_msg(game, "Felicitations merci pour tes champignons");
        game->quest.init = 2;
        //Offre qlq chose au joueur
    }
}

void help_interaction(game_t *game)
{
    if (game->quest.init == 0)
        set_msg(game, "Conseil: cherche un pnj au nord une quete t'attend");
    if (game->quest.init == 1 && game->quest.mush_found < 5)
        set_msg(game, "Conseil: les champignons pousse mieux sur le sol foncee");
    if (game->quest.init == 1 && game->quest.mush_found >= 5)
        set_msg(game, 
        "Conseil: retourne parler au pnj");
    if (game->quest.init == 2 && game->quest.slayed < 10)
        set_msg(game, "Conseil: test ton nouvelle equipement");
}
