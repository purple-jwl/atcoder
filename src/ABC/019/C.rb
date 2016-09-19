res = {}
gets
gets.split.map { |x|
  x = x.to_i
  x /= 2 while x % 2 == 0
  res[x.to_s] = 1
}
puts res.size
