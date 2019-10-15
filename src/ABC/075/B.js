function Main(input) {
  input = input.split('\n');

  var h = parseInt(input[0].split(' ')[0], 10);
  var w = parseInt(input[0].split(' ')[1], 10);

  var s = [];
  for (var i = 0; i < h; i++) {
    s.push(input[1 + i].split(''));
  }

  var cnt = new Array(h).fill([]).map(() => new Array(w).fill(0));

  var dx = [-1, -1, -1, 0, 0, 1, 1, 1];
  var dy = [-1, 0, 1, -1, 1, -1, 0, 1];

  for (var i = 0; i < h; i++) {
    for (var j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        for (var k = 0; k < 8; k++) {
          var y = i + dy[k];
          var x = j + dx[k];
          if (!(0 <= y && y < h)) continue;
          if (!(0 <= x && x < w)) continue;
          cnt[y][x]++;
        }
      }
    }
  }

  for (var i = 0; i < h; i++) {
    for (var j = 0; j < w; j++) {
      if (s[i][j] == '#') cnt[i][j] = -1;
    }
  }

  for (var i = 0; i < h; i++) {
    console.log(cnt[i].map(v => v == -1 ? '#' : v).join(''));
  }
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));
