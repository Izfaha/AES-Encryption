#include <stdint.h>
#include <stdio.h>

/*
    create state = array matrix 4x4

    State:
    | b0  b4  b8  b12 |
    | b1  b5  b9  b13 |
    | b2  b6  b10 b14 |
    | b3  b7  b11 b15 |
*/
/*
 *   create an alias to new name for a type
 */
typedef uint8_t state_t[4][4];

/*
 *   Create function to copy 16 byte to state (col per col) (form top to bottom)
 */
void load_states(state_t states, const uint8_t *input)
{
    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < 4; row++)
        {
            states[row][col] = input[col * 4 + row];
        }
    }
}

/*
    function to store state to array 16 bytes
*/
void store_states(uint8_t *output, const state_t states)
{
    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < 4; row++)
        {
            output[col * 4 + row] = states[row][col];
        }
    }
}

/*
    function to print state
*/
void print_states(const state_t states)
{
    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < 4; row++)
        {
            printf("%02x ", states[row][col]);
        }
        printf("\n"); // enter become 4x4
    }
}

// main function

int main(void)
{
    // add matrix state as your desire (should be 4x4 = 16 bytes)
    uint8_t plaintext[16] = {
        0x00, 0x11, 0x22, 0x33,
        0x44, 0x55, 0x66, 0x77,
        0x88, 0x99, 0xaa, 0xbb,
        0xcc, 0xdd, 0xee, 0xff};

    state_t states;
    load_states(states, plaintext);

    printf("==== State Representation ====\n");
    print_states(states);

    uint8_t back_to_array[16];
    store_states(back_to_array, states);

    printf("\nRecoverted bytes:\n");
    for (int i = 0; i < 16; i++)
        printf("%02x ", back_to_array[i]);
    printf("\n");

    return 0;
}