import * as fs from "fs";

function comb(n: number, r: number): number {
  let res = 1;

  for (let i = 0; i < r; i++) {
    res *= (n - i);
  }
  for (let i = 0; i < r; i++) {
    res /= (r - i);
  }

  return res;
}

function main(input: string[]) {
  const MAX_A = 200000;
  const n = Number(input[0]);
  const a = input[1].split(" ").map(Number);

  const cnt = Array(MAX_A + 1).fill(0);
  a.forEach(v => cnt[v]++);

  let ans = comb(n, 3);

  for (let i = 1; i <= MAX_A; i++) {
    if (cnt[i] >= 2) ans -= comb(cnt[i], 2) * (n - cnt[i]);
    if (cnt[i] >= 3) ans -= comb(cnt[i], 3);
  }

  console.log(ans);
}

const input = fs.readFileSync("/dev/stdin", "utf8").split("\n");
main(input);
