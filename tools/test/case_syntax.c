#include <stdio.h>
#include <stdint.h>
struct num2char{
    uint8_t number;
    char c;
}mapping_table[] = {
    {1, '!'},    // Shift + 1
    {2, '@'},    // Shift + 2
    {3, '#'},    // Shift + 3
    {4, '$'},    // Shift + 4
    {5, '%'},    // Shift + 5
    {6, '^'},    // Shift + 6
    {7, '&'},    // Shift + 7
    {8, '*'},    // Shift + 8
    {9, '('},    // Shift + 9
    {0, ')'},   // Shift + 0
    {'-', '_'},
    {'=', '+'},
    {'`', '~'},
    {',', '<'},
    {'.', '>'},
    {'/', '?'}   
};

