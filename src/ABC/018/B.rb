s = gets.chomp
gets.to_i.times do
  l, r = gets.split.map { |x| x.to_i - 1 }
  s[l..r] = s[l..r].reverse
end
puts s
