CC="zig cc"

FLAGS="-Wall -Wextra"

INPUT="main.c"

$CC $FLAGS -o main $INPUT

./main