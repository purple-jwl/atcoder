a, b, c = gets.split.map(&:to_i)
f = 0
f += 1 if a + b == c
f += 2 if a - b == c
puts '!+-?'[f]
