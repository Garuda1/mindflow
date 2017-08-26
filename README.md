# MindFlow
Virtual cluster processing library written in C

## What is MindFlow?

MindFlow is a C library meant to make virtual cluster processing easy. Simply put, MindFlow allows the user to create 2D matrices of simple, easy-to-use virtual machines called "nodes". Each node can interract with its adjacent nodes.

Nodes are mapped following this scheme:

           INPUT & OUTPUT
           |
           V
    +-----------------+      +-----------------+      +-----------------+      +-----------------+
    |NODE (0,0)       |      |NODE (0,1)       |      |NODE (0,2)       |      |NODE (0,3)       |
    +-----------------+      +-----------------+      +-----------------+      +-----------------+
    |                 |      |                 |      |                 |      |                 |
    |                 | <--+ |                 | <--+ |                 | <--+ |                 |
    |                 |      |                 |      |                 |      |                 |
    |                 | +--> |                 | +--> |                 | +--> |                 |
    |                 |      |                 |      |                 |      |                 |
    +-----------------+      +-----------------+      +-----------------+      +-----------------+
    
    + ^                      +  ^                     + ^                      +  ^
    | |                      |  |                     | |                      |  |
    | |                      |  |                     | |                      |  |
    v +                      v  +                     v +                      v  +
    
    +-----------------+      +-----------------+      +-----------------+      +-----------------+
    |NODE (1,0)       |      |NODE (1,1)       |      |NODE (1,2)       |      |NODE (1,3)       |
    +-----------------+      +-----------------+      +-----------------+      +-----------------+
    |                 |      |                 |      |                 |      |                 |
    |                 | <--+ |                 | <--+ |                 | <--+ |                 |
    |                 |      |                 |      |                 |      |                 |
    |                 | +--> |                 | +--> |                 | +--> |                 |
    |                 |      |                 |      |                 |      |                 |
    +-----------------+      +-----------------+      +-----------------+      +-----------------+
    
    +  ^                     +  ^                     +  ^                     +  ^
    |  |                     |  |                     |  |                     |  |
    |  |                     |  |                     |  |                     |  |
    v  +                     v  +                     v  +                     v  +
    
    +-----------------+      +-----------------+      +-----------------+      +-----------------+
    |NODE (2,0)       |      |NODE (2,1)       |      |NODE (2,2)       |      |NODE (2,3)       |
    +-----------------+      +-----------------+      +-----------------+      +-----------------+
    |                 |      |                 |      |                 |      |                 |
    |                 | <--+ |                 | <--+ |                 | <--+ |                 |
    |                 |      |                 |      |                 |      |                 |
    |                 | +--> |                 | +--> |                 | +--> |                 |
    |                 |      |                 |      |                 |      |                 |
    +-----------------+      +-----------------+      +-----------------+      +-----------------+
    
    + ^                      +  ^                     + ^                      +  ^
    | |                      |  |                     | |                      |  |
    | |                      |  |                     | |                      |  |
    v +                      v  +                     v +                      v  +
    
    +-----------------+      +-----------------+      +-----------------+      +-----------------+
    |NODE (3,0)       |      |NODE (3,1)       |      |NODE (3,2)       |      |NODE (3,3)       |
    +-----------------+      +-----------------+      +-----------------+      +-----------------+
    |                 |      |                 |      |                 |      |                 |
    |                 | <--+ |                 | <--+ |                 | <--+ |                 |
    |                 |      |                 |      |                 |      |                 |
    |                 | +--> |                 | +--> |                 | +--> |                 |
    |                 |      |                 |      |                 |      |                 |
    +-----------------+      +-----------------+      +-----------------+      +-----------------+
    
Writing to the left VM from the (0,0) node will send data to a buffer (the output buffer). Reading from the top VM from the same node will read data from another buffer (the input buffer). This way, the VM cluster can interract with the rest of the program dynamically. It is up to the user to create his own communication protocol.
