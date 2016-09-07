r, c = gets.split.map(&:to_i)
sy, sx = gets.split.map { |i| i.to_i - 1 }
gy, gx = gets.split.map { |i| i.to_i - 1 }
cell = Array.new(r).map { gets.split('').to_a }

# bfs
queue = []
queue.push([sy, sx, 0])
visited = Array.new(r).map { Array.new(c, false) }

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

# while ! queue.empty?
until queue.empty?
  y, x, step = queue.shift

  4.times do |i|
    ny = y + dy[i]
    nx = x + dx[i]
    next unless 0 <= ny && ny < r
    next unless 0 <= nx && nx < c
    next if cell[ny][nx] == '#'
    next if visited[ny][nx]

    # if ny == gy && nx == gx
    if [ny, nx] == [gy, gx]
      puts step + 1
      exit
    end

    visited[ny][nx] = true
    # queue.push([ny, nx, step + 1])
    queue << [ny, nx, step + 1]
  end
end
