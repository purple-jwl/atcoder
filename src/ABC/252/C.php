<?php

fscanf(STDIN, "%d", $n);

$s = [];
for ($i = 0; $i < $n; $i++) {
  fscanf(STDIN, "%s", $s[$i]);
}

$ans = PHP_INT_MAX;
for ($i = 0; $i < 10; $i++) {
  $cnt = array_fill(0, 10, 0);
  foreach ($s as $_s) {
    $cnt[strpos($_s, (string)('0' + $i))]++;
  }
  $ans = min($ans, max(array_map(
    fn (int $key) => $key + 10 * ($cnt[$key] - 1),
    array_keys($cnt)
  )));
}

echo $ans . PHP_EOL;
