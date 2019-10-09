function Main(input) {
  input = input.split('\n');

  var n = parseInt(input[0], 10);
  var a = input[1].split(' ').map(i => parseInt(i, 10));

  var ans = 0;
  for (var i = 0; i < n; i++) {
    while (a[i] % 2 == 0) {
      ans++;
      a[i] /= 2;
    }
  }

  console.log(ans);
}

//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
