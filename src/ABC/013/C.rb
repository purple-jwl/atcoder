n, h = gets.split.map(&:to_i)
a, b, c, d, e = gets.split.map(&:to_i)

ans = a * n
(n + 1).times do |x|
  y = [(e * (n - x) - b * x - h) / (d + e) + 1, 0].max
  ans = [ans, a * x + c * y].min
end

puts ans
