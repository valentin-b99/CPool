/*
** EPITECH PROJECT, 2018
** display_an_image
** File description:
** 
*/

#include <SFML/Graphics.h>

int main()
{
    sfVideoMode mode = {225, 225, 32};
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent event;
    
    window = sfRenderWindow_create(mode, "task04 window", sfClose, NULL);
    if (!window)
        return (84);
    texture = sfTexture_createFromFile("./images/IE.jpg", NULL);
    if (!texture)
        return (84);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return (0);
}
