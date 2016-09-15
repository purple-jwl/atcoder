gets
a = gets.split.map(&:to_f).select { |a| a > 0 }
puts (a.inject(:+) / a.size).ceil
