h, w, t = gets.split.map(&:to_i)

s = []
sx = sy = gx = gy = 0

h.times do |i|
  s << gets.chomp.split('').map.each_with_index { |ch, j|
    sy, sx = [i, j] if ch == 'S'
    gy, gx = [i, j] if ch == 'G'
    ch == 'S' ? '.' : ch
  }
end

dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]

puts (1..(t + 1)).bsearch { |b_cost|
  min_cost = Array.new(h) { Array.new(w, t + 1) }
  min_cost[sy][sx] = 0
  queue = [[sy, sx]]

  until queue.empty?
    y, x = queue.shift

    dir.each { |dy, dx|
      ny = y + dy
      nx = x + dx
      next unless 0 <= ny && ny < h
      next unless 0 <= nx && nx < w
      cost = (s[ny][nx] == '#' ? b_cost : 1)
      next unless min_cost[ny][nx] > min_cost[y][x] + cost
      min_cost[ny][nx] = min_cost[y][x] + cost
      next unless min_cost[ny][nx] <= t
      break if s[ny][nx] == 'G'
      queue << [ny, nx]
    }
  end

  min_cost[gy][gx] > t
} - 1
