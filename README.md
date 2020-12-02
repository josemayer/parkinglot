# Parking Lot Manager
A simple program that uses stack to manage a parking lot.

## Operations
| Input |             Action            |     Output     |
|:-----:|:-----------------------------:|:--------------:|
|   +X  |         Add X to input        |                |
|   #   | Park element in arrival order |     X: e>g     |
|   -X  |        Add X to output        | ... X: g>s ... |
|   $   |  Write states to garagem.txt  |                |

## Build Informations
```shell
gcc -o parkinglot parkinglot.c estruturas.h pilha.c
```

## Usage
```shell
./parkinglot
```