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
  char buffer[BUFFER_SIZE];
  size_t size = 1;
  size_t numElements = 1;
  int count = 1;

  if (argc == 1)
  {
    while (fread(buffer, size, numElements, stdin) > 0)
    {
      fwrite(buffer, size, numElements, stdout);
    }
  }
  else
  {
    while (count < argc)
    {
      if (strcmp(argv[count], "-") == 0)
      {
        while (fread(buffer, size, numElements, stdin) > 0)
        {
          fwrite(buffer, size, numElements, stdout);
        }
      }
      else
      {
        printf("The input was: %s\n", argv[count]);
      }
      count++;
    }
  }
  return 0;
}
