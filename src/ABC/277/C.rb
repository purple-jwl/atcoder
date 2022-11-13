n = gets.to_i

edge = Hash.new {|h, k| h[k] = []}
n.times do
  a, b = gets.split.map(&:to_i)
  edge[a] << b
  edge[b] << a
end

visited = Hash.new(false)
visited[1] = true
que = [1]

until que.empty? do
  cur = que.shift

  edge[cur].each do |to|
    next if visited[to]
    visited[to] = true
    que << to
  end
end

puts visited.keys.max
