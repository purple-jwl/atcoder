puts 3.times.map {
  s, e = gets.split.map(&:to_i)
  s / 10 * e
}.inject(:+)
