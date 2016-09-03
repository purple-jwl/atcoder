s = gets.chomp
t = gets.chomp

atcoder = 'atcoder'

s.size.times { |i|
  if s[i] != t[i] then
    next if s[i] == '@' && atcoder.include?(t[i])
    next if t[i] == '@' && atcoder.include?(s[i])

    puts 'You will lose'
    exit
  end
}

puts 'You can win'
