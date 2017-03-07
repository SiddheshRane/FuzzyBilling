# How to run
    gcc main.c -o billing -lncurses
    ./billing

# Inventory Management

The folder where you run the executable should have a file named db.txt.  
It needs to have entries in following manner:

    <Item name, %s> <quantity, %d> <cost, %f>

where `%s`, `%d` and `%f` are `scanf` format specifiers. Ensure item name does not have spaces