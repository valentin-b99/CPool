/*
** EPITECH PROJECT, 2018
** opening a windows
** File description:
** 
*/

#include <SFML/Graphics.h>

int    main(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {800, 600, 32};
    sfEvent event;

    window = sfRenderWindow_create(mode, "task01 window", sfDefaultStyle, NULL);
    if (!window)
        return (84);
    while (sfRenderWindow_isOpen(window)) {
	while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
