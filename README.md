# Lem-in
  
Summary: This project is meant to make you code an ant farm manager.  
  
### Usage
`make` then `./lem-in < mapfile`
  
### Arguments
Your program will receive the data describing the ant farm from the standard output
in the following format:  
  
**number_of_ants**  
**rooms**, which are defined by: name coord_x coord_y  
**links**, which are defined by: name1-name2  
All of it is broken by comments, which start with #  
  
### Example of map  
```
# Number of ants
15
# Begining of rooms
##start
1 23 3
2 16 7
# comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
# Begining of links
0-4
0-6
1-3
4-3
5-2
3-5
# another comment
4-2
2-1
7-6
7-2
7-4
6-5
# another comment
```

### Program output

You must to display your results on the standard output in the following format:
```
number_of_ants  |
the_rooms       | i.e reprinting the map
the_links       |
Lx-y Lz-w Lr-o ...
```
where x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y,
w, o represents the rooms’ names.  
  
Here is an example output
```
3
##start
0 1 0
##end
1 5 0
2 9 0
3 13 0
0-2
2-3
3-1

L1-2
L1-3 L2-2
L1-1 L2-3 L3-2
L2-1 L3-3
L3-1
```
