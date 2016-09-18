r, c, k = gets.split.map(&:to_i)

k -= 1

queue = []
head = 0
tail = 0
min_dist = Array.new(r) { Array.new(c, r * c) }

r.times do |i|
  s = gets.chomp
  c.times do |j|
    if s[j] == 'x'
      queue << [i, j]
      tail += 1
      min_dist[i][j] = 0
    end
  end
end

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]
while head != tail
  y, x = queue[head]
  head += 1
  4.times do |i|
    ny = y + dy[i]
    nx = x + dx[i]
    next unless 0 <= ny && ny < r
    next unless 0 <= nx && nx < c
    next unless min_dist[ny][nx] > min_dist[y][x] + 1
    min_dist[ny][nx] = min_dist[y][x] + 1
    next unless min_dist[ny][nx] < k
    queue << [ny, nx]
    tail += 1
  end
end

ans = 0
for i in k...(r - k) do
  ans += min_dist[i][k...(c - k)].count { |v| v > k }
end

puts ans
