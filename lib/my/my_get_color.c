/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday09-lucas.doolaeghe
** File description:
** get_color.c
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int rgb = 0;
    rgb += red << 16;
    rgb += green << 8;
    rgb += blue;
    return rgb;
}
