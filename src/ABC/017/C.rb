n, m = gets.split.map(&:to_i)

score = Array.new(m + 5, 0)
sum = 0

n.times do
  l, r, s = gets.split.map(&:to_i)
  score[l] += s
  score[r + 1] -= s
  sum += s
end

m.times do |i|
  score[i + 1] += score[i]
end

puts sum - score[1..m].min
