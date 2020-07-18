#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // check if the namefile was specified
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // check if memory card is successfully opened
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file %s.\n", argv[1]);
        return 1;
    }

    //create vars that we gonna use and allocate memory for them
    FILE *img; //creating file pointer
    char filename[7];
    unsigned char *photo = malloc(512);
    int counter = 0;

    while (fread(photo, 512, 1, file))
    {
        // new jpg file found
        if (photo[0] == 0xff && photo[1] == 0xd8 && photo[2] == 0xff && (photo[3] & 0xf0) == 0xe0)
        {
            // close previous jpg file if it exists
            if (counter > 0)
            {
                fclose(img);
            }

            // create filename
            sprintf(filename, "%03d.jpg", counter);
            // open new image file
            img = fopen(filename, "w");

            // check if jpg file is successfully created
            if (img == NULL)
            {
                fclose(file);
                free(photo);
                fprintf(stderr, "Could not create output JPG %s", filename);
                return 3;
            }

            counter++;
        }

        //if any jpg file exists writes on the file currently opened
        if (counter > 0)
        {
            fwrite(photo, 512, 1, img);
        }
    }

    //frees memory and closes files
    fclose(img);
    fclose(file);
    free(photo);
    return 0;
}
