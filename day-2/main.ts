const decoder = new TextDecoder("utf-8");
const input = decoder.decode(Deno.readFileSync("input.txt"));

const splitted_input = input.split("\n");
const game_input = splitted_input.map((v) => v.split(" "));

const point_table = {
  X: 1,
  Y: 2,
  Z: 3,
  A: 1,
  B: 2,
  C: 3,
};

const result = calculate_result(game_input);

console.log(`result is ${result}`);

function calculate_result(game_input: string[][]): number {
  let total = 0;
  for (const input of game_input) {
    const result = calculate_game(input[0], input[1]);
    total += result;
  }
  return total;
}

function calculate_game(opponent: string, player: string): number {
  if (
    (opponent == "A" && player == "X") ||
    (opponent == "B" && player == "Y") ||
    (opponent == "C" && player == "Z")
  ) {
    //@ts-ignore
    return 3 + point_table[player];
  }

  let win = false;

  if (opponent == "A") {
    win = player == "Y";
  } else if (opponent == "B") {
    win = player == "Z";
  } else {
    win = player == "X";
  }
  //@ts-ignore
  return win ? 6 + point_table[player] : point_table[player];
}
