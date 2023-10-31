const INPUT_FILE = "input-1.txt";
const decoder = new TextDecoder("utf-8");
const buff = await Deno.readFile(INPUT_FILE);

const sack = decoder
  .decode(buff)
  .split("\n")
  .map((v) => [
    v
      .substring(0, v.length / 2)
      .trim()
      .split(""),
    v
      .substring(v.length / 2, v.length)
      .trim()
      .split(""),
  ]);

let point = 0;
sack.forEach(([first_sack, second_sack]) => {
  const map: Record<string, number> = {};
  for (let i = 0; i < first_sack.length; i++) {
    for (let j = 0; j < second_sack.length; j++) {
      if (first_sack[i] == second_sack[j]) {
        if (typeof map[first_sack[i]] == "undefined") {
          map[first_sack[i]] = 1;
        } else {
          map[first_sack[i]] += 1;
        }
      }
    }
  }
  point += get_priority(map);
});

console.log(point);

function get_priority(map: Record<string, number>): number {
  let point = 0;
  for (const [k, v] of Object.entries(map)) {
    point += get_point(k);
    console.log(`char = ${k}, priority = ${point}`);
  }
  return point;
}

function get_point(char: string): number {
  const charCode = char.charCodeAt(0);

  if (charCode < "a".charCodeAt(0)) {
    return char.charCodeAt(0) - "A".charCodeAt(0) + 27;
  } else {
    return char.charCodeAt(0) - "a".charCodeAt(0) + 1;
  }
}
