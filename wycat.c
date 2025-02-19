/*
wycat.c
Author: Cameron Peete
Date: February 19, 2025

COSC 3750, Homework 4

This is a simple version of the cat utility
*/

#define BUFFER_SIZE 4096

#include<stdio.h>
#include<string.h>

int main(int argc, char **argv)
{
  FILE *file;

  char buffer[BUFFER_SIZE];

  size_t size = 1;
  int count = 1;

  if (argc == 1)
  {
    while ((size = fread(buffer, 1, BUFFER_SIZE, stdin)) > 0)
    {
      fwrite(buffer, 1, size, stdout);
    }
  }
  else
  {
    while (count < argc)
    {
      if (strcmp(argv[count], "-") == 0)
      {
        while ((size = fread(buffer, 1, BUFFER_SIZE, stdin)) > 0)
        {
          fwrite(buffer, 1, size, stdout);
        }
      }
      else
      {
        file = fopen(argv[count], "r");
        if (file == NULL)
        {
          perror("Error: File not found!\n");
        }
        else
        {
          while((size = fread(buffer, 1, BUFFER_SIZE, file)) > 0)
          {
            fwrite(buffer, 1, size, stdout);
          }
          fclose(file);
        }
      }
      count++;
    }
  }
  return 0;
}
