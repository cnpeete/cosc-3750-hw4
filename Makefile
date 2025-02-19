# Makefile
# Cameron Peete
# COSC 3750 Spring 2025
# Homework 4
# 02/19/2025
#
# Creating a Makefile for Homework 4

CC=gcc
CFLAGS=-Wall -ggdb -I.

wycat: wycat.c
	$(CC) $(CFLAGS) wycat.c -o wycat
