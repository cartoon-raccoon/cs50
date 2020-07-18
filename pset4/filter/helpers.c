#include "helpers.h"
#include <math.h>
#include <stdlib.h>

//each function accepts three args:
//height, width, and a RGBTRIPLE array called image
//the dimensions of the array are specified by the first two args
//*if you couldn't figure that out, man are you dumb*
//*why are you even taking cs50 man, just give up*

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //take every pixel, calculate the average value of its rgb values
    //assign that value to every value in the rgb triple
    float greyscale;
    for (int i = 0; i < height; i++) //for every row
    {
        for (int j = 0; j < width; j++) //for every element in that row
        {
            greyscale = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.000);
            image[i][j].rgbtBlue = greyscale;
            image[i][j].rgbtGreen = greyscale;
            image[i][j].rgbtRed = greyscale;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //for every row, swap pixels that are the same distance from their closest edge respectively
    int temp[3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //assigning to internal variables to make things easier to read
            RGBTRIPLE pixel = image[i][j];
            RGBTRIPLE opp_pixel = image[i][width - j - 1];

            //assigning temporary array for swap
            temp[0] = image[i][j].rgbtBlue;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtRed;

            //swapping pixel values
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtRed = temp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int blue_sum;
    int green_sum;
    int red_sum;
    float counter;

    //temp to store values, to copy back into original image
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blue_sum = 0;
            green_sum = 0;
            red_sum = 0;
            counter = 0.00; //counts how many kernel elements are active

            //iterating along the kernel, skips kernel elements that fall outside the image
            for (int h = -1; h < 2; h++)
            {
                if (i + h < 0 || i + h > height - 1) //edge cases (height)
                {
                    continue;
                }
                for (int w = -1; w < 2; w++)
                {
                    if (j + w < 0 || j + w > width - 1) //edge cases (width)
                    {
                        continue;
                    }
                    blue_sum += image[i + h][j + w].rgbtBlue;
                    green_sum += image[i + h][j + w].rgbtGreen;
                    red_sum += image[i + h][j + w].rgbtRed;
                    counter++;
                }
            }
            //updating temp with averages
            temp[i][j].rgbtBlue = round(blue_sum / counter);
            temp[i][j].rgbtGreen = round(green_sum / counter);
            temp[i][j].rgbtRed = round(red_sum / counter);
        }
    }

    //loading values back into original array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}

int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //initializing kernel filters
    double Gx[3][3] = {{-1.00, 0.00, 1.00}, {-2.00, 0.00, 2.00}, {-1.00, 0.00, 1.00}};
    double Gy[3][3] = {{-1.00, -2.00, -1.00}, {0.00, 0.00, 0.00}, {1.00, 2.00, 1.00}};

    double xBlue;
    double yBlue;
    double xGreen;
    double yGreen;
    double xRed;
    double yRed;

    //creating temporary image
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            xBlue = 0.0;
            yBlue = 0.0;
            xGreen = 0.0;
            yGreen = 0.0;
            xRed = 0.0;
            yRed = 0.0;
            //iterating across the kernel
            for (int h = -1; h < 2; h++)
            {
                if (i + h < 0 || i + h > height - 1)
                {
                    continue;
                }

                for (int w = -1; w < 2; w++)
                {
                    if (j + w < 0 || j + w > width - 1)
                    {
                        continue;
                    }
                    //calculating blue
                    xBlue += image[i + h][j + w].rgbtBlue * Gx[h + 1][w + 1];
                    yBlue += image[i + h][j + w].rgbtBlue * Gy[h + 1][w + 1];

                    //calculating green
                    xGreen += image[i + h][j + w].rgbtGreen * Gx[h + 1][w + 1];
                    yGreen += image[i + h][j + w].rgbtGreen * Gy[h + 1][w + 1];

                    //calculating red
                    xRed += image[i + h][j + w].rgbtRed * Gx[h + 1][w + 1];
                    yRed += image[i + h][j + w].rgbtRed * Gy[h + 1][w + 1];
                }
            }
            temp[i][j].rgbtBlue = limit(round(sqrt(pow(xBlue, 2) + pow(yBlue, 2))));
            temp[i][j].rgbtGreen = limit(round(sqrt(pow(xGreen, 2) + pow(yGreen, 2))));
            temp[i][j].rgbtRed = limit(round(sqrt(pow(xRed, 2) + pow(yRed, 2))));
        }
    }

    //transferring temp to proper
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}