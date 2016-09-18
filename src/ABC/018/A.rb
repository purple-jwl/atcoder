s = []
3.times do
  s << gets.to_i
end
puts s.map { |x| 3 - s.sort.index(x)}
