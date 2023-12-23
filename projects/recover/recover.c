// All the libraries that this programs works.
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int BLOCK_SIZE = 512;
uint8_t buffer[BLOCK_SIZE];
uint8_t file_blocks[5000][BLOCK_SIZE];

// Functions that copies memory from the buffer to the file_blocks and reset the current memory.
void add_memory(int number_block);
void reset_memory(void);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");

    if (raw_file == NULL)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Varaibles counting the number of the files and the number of bloks in each file respectively.
    int file_number = 0;
    int blocks_number = 0;

    // Going through each buffer still it ends.
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (file_number == 0)
            {
                // Copying the information and start the variable blocks number and file number.
                add_memory(blocks_number);
                blocks_number++;
                file_number++;
            }
            else
            {
                // Create a name for the existing values of img working with.
                char *filename = malloc(sizeof(char) * 8);
                sprintf(filename, "%03i.jpg", file_number - 1);
                file_number++;

                // Write the values in a jpg file and closing it.
                FILE *img = fopen(filename, "w");
                free(filename);
                fwrite(file_blocks, BLOCK_SIZE, blocks_number, img);
                fclose(img);

                // Storing new values for the new img.
                reset_memory();
                blocks_number = 0;
                add_memory(blocks_number);
                blocks_number++;
            }
        }
        else if (blocks_number > 0)
        {
            add_memory(blocks_number);
            blocks_number++;
        }
    }

    char *filename = malloc(sizeof(char) * 8);
    sprintf(filename, "%03i.jpg", file_number - 1);

    FILE *img = fopen(filename, "w");
    free(filename);
    fwrite(file_blocks, BLOCK_SIZE, blocks_number, img);
    fclose(img);

    fclose(raw_file);
    return 0;
}

void add_memory(int number_block)
{
    for (int i = 0; i < BLOCK_SIZE; i++)
    {
        file_blocks[number_block][i] = buffer[i];
    }
}

void reset_memory(void)
{
    for (int i = 0; i < 5000; i++)
    {
        for (int j = 0; j < BLOCK_SIZE; j++)
        {
            file_blocks[i][j] = 0;
        }
    }
}