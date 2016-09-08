n = gets.to_i

s = Hash.new(0)
n.times do
  s[gets.chomp] += 1
end

puts s.max_by {|k, v| v}[0]
