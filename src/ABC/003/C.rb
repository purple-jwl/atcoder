n, k = gets.split.map(&:to_i)
r = gets.split.map(&:to_i)

r.sort!

rating = 0.0

for i in ((n - k)...n) do
  rating = (rating + r[i]) / 2
end

puts rating
