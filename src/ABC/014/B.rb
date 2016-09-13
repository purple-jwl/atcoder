x = gets.split[1].to_i
puts gets.split.map(&:to_i).each_with_index.inject(0) { |sum, (a, i)|
  # (x >> i) & 1 == 1 ? sum + a : sum
  x[i] == 1 ? sum + a : sum
}
