function Main(input) {
  input = input.split('\n');
  //文字列から10進数に変換するときはparseIntを使います
  var a = parseInt(input[0], 10);
  var b = parseInt(input[1], 10);
  var c = parseInt(input[2], 10);
  var x = parseInt(input[3], 10);

  var ans = 0;
  for (var i = 0; i <= a; i++) {
    for (var j = 0; j <= b; j++) {
      for (var k = 0; k <= c; k++) {
        if (i * 500 + j * 100 + k * 50 === x) ans++;
      }
    }
  }

  //出力
  console.log('%d', ans);
}

//*この行以降は編集しないでください（標準入出力から一度に読み込み、Mainを呼び出します）
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
