#include "monty.h"
/**
 * 
 * 
 * 
*/
void (*get_opcode(char *cmd))(stack_t **, unsigned int, FILE *)
{
    instruction_t op[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}
    };

    int i = 0;

    while (i < 8)
    {
        if (strcmp(cmd, op[i].opcode) == 0)
            return (op[i].f);
        i++;
    }
    return (NULL);
}