tx_a, ty_a, tx_b, ty_b, t, v = gets.split.map(&:to_i)

puts gets.to_i.times.any? {
  x, y = gets.split.map(&:to_i)
  d1 = Math.hypot(tx_a - x, ty_a - y)
  d2 = Math.hypot(tx_b - x, ty_b - y)
  d1 + d2 <= t * v
} ? 'YES' : 'NO'

# tx_a, ty_a, tx_b, ty_b, t, v = gets.split.map(&:to_i)

# flg = false
# gets.to_i.times do
#   x, y = gets.split.map(&:to_i)
#   d1 = Math.hypot(tx_a - x, ty_a - y)
#   d2 = Math.hypot(tx_b - x, ty_b - y)
#   flg = true if d1 + d2 <= t * v
# end

# puts flg ? 'YES' : 'NO'
