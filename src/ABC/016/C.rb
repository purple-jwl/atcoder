n, m = gets.split.map(&:to_i)

edge = Array.new(n) { Array.new(n, 0) }
m.times do
  a, b = gets.split.map(&:to_i)
  edge[a - 1][b - 1] = edge[b - 1][a - 1] = 1
end

n.times do |i|
  queue = [i]
  min_dist = Array.new(n, 1000)
  min_dist[i] = 0

  until queue.empty? do
    j = queue.shift

    n.times do |k|
      next if edge[j][k] == 0
      next if min_dist[k] < min_dist[j] + 1
      min_dist[k] = min_dist[j] + 1
      queue << k
    end
  end

  puts min_dist.select { |x|
    x == 2
  }.size
end
