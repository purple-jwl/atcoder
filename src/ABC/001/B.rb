m = gets.chomp.to_i
v = 0

if m < 100 then
  v = 0
elsif m <= 5000 then
  v = m / 100
elsif m <= 30000 then
  v = m / 1000 + 50
elsif m <= 70000 then
  v = (m / 1000 - 30) / 5 + 80
else
  v = 89
end

puts "%02d" % v

# if m < 100 then
#   puts '00'
# elsif m < 1000 then
#   puts '0' + (m / 100).to_s
# elsif m <= 5000 then
#   puts (m / 100).to_s
# elsif m <= 30000 then
#   puts (m / 1000 + 50).to_s
# elsif m <= 70000 then
#   puts ((m / 1000 - 30) / 5 + 80).to_s
# else
#   puts '89'
# end
