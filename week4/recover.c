#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BUFFER_SIZE = 512;

int main(int argc, char *argv[])
{
    // Only accept a single command-line argument
    if (argc != 2)
    {
        printf("Please provide a single command line argument!\n");
        return 1;
    }

    // Open and read the memory card! which is our argv[1]
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        // lets protect ourselves!
        printf("Failed to open the file\n");
        return 2;
    }
    // buffer
    BYTE buffer[BUFFER_SIZE];
    //our file pointer, filenames, and counter!
    FILE *img = NULL;
    char filename[8];
    int img_count = 0;

    // While there's still data left to read from the memory card
    while (fread(buffer, BUFFER_SIZE, 1, card) == 1)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if we have a file open, dont write just yet! Lets close them first!
            if (img != NULL)
            {
                fclose(img);
            }

            //lets make the file for those images!
            sprintf(filename, "%03i.jpg", img_count);
            img = fopen(filename, "w");
            img_count++;
        }
        // if a file is open, lest start writing!
        if (img != NULL)
        {
            fwrite(buffer, BUFFER_SIZE, 1, img);
        }
    }

    // lets close the files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
    return 0;
}
