n, m = gets.split.map(&:to_i)

(n + 1).times do |x|
  z = m - 2 * x - 3 * (n - x)
  y = n - x - z

  next if x < 0 || y < 0 || z < 0

  puts "#{x} #{y} #{z}"
  exit
end

puts '-1 -1 -1'
