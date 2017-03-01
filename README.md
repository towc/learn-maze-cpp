# learn-maze-cpp
A learning experiment for c++

Only works in a linux terminal, as I've hardcoded the command `clear` in the code to clear the screen

# disclaimer
This is by no means ideal and uses hacks and bad practices all over, but the purpose was for me to learn c++ syntax, not to make something useful

# build
Whilst in a linux terminal, type `./build`, which simply runs the following command, if you want to use it yourself:

```bash
rm main.out; g++ -std=c++14 -Wall -Wextra -pedantic main.cpp Maze.cpp Coordinate.cpp Random.cpp -o main.out; ./main.out
```

# sample output

```

 Round: 1  pos: [1,1]

 xxxxxxxxxxxxxxxxxxxxx
 xo  x   x x         x
 xxx x x x x xxxxx x x
 x x   x x     x   x x
 x xxxxx xxxxx x xxx x
 x     x     x x x   x
 xxxxx xxxxx xxx x xxx
 x         x x   x   x
 x xxxxxxxxx x xxxxx x
 x x   x   x x   x x x
 x x x x x x xxx x x x
 x   x   x x   x x   x
 x xxxxxxx xxx x xxx x
 x x       x x x   x x
 x x xxxxx x x xxx x x
 x x     x   x x   x x
 x xxxxx xxx x x xxx x
 x x   x   x x   x x x
 x x x xxx xxxxxxx x x
 x   x  .x           x
 xxxxxxxxxxxxxxxxxxxxx

 next moves (hjkl/aswd+ENTER):  

```
