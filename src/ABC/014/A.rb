a = gets.to_i
b = gets.to_i

puts a % b == 0 ? 0 : b - a % b
