function Main(input) {
  input = input.split('\n');

  var n = parseInt(input[0], 10);
  var a = [];
  for (var i = 0; i < n; i++) {
    a[i + 1] = parseInt(input[i + 1], 10);
  }

  var cur = 1;
  for (var i = 0; i < n + 100; i++) {
    if (a[cur] == 2) {
      console.log(i + 1);
      return;
    }
    cur = a[cur];
  }

  console.log(-1);
}

//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
