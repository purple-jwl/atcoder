ax, ay, bx, by, cx, cy = gets.split.map(&:to_i)

s = (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)).abs.to_f / 2

puts s
