# FuzzyBilling

This is demo code for showing how a C program can be written using ncurses with certain level of generic code using function pointers.
It is not a production quality app. It was built within a single day but still shows some good coding practices to a certain extent.

## How to run
    gcc main.c -o billing -lncurses
    ./billing

## Inventory Management

The folder where you run the executable should have a file named db.txt.  
It needs to have entries in following manner:

    <Item name, %s> <quantity, %d> <cost, %f>

where `%s`, `%d` and `%f` are `scanf` format specifiers. Ensure item name does not have spaces

