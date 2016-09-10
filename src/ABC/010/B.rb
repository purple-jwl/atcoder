n = gets.to_i
a = gets.split.map(&:to_i)

ans = 0
a.each do |i|
  while i % 2 == 0 || i % 3 == 2
    ans += 1
    i -= 1
  end
end

puts ans

# _ = gets.to_i
# puts gets.split.map { |a|
#   a = a.to_i
#   count = 0
#   while a % 2 == 0 || a % 3 == 2
#     count += 1
#     a -= 1
#   end
#   count
# }.inject(:+)
