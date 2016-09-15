# n, _ = gets.split.map(&:to_i)
# dp = Array.new(n + 1) { Array.new(128, 0) }
# dp[0][0] = 1

# n.times do |i|
#   gets.split.map { |t|
#     t = t.to_i
#     128.times do |j|
#       dp[i + 1][j ^ t] |= dp[i][j]
#     end
#   }
# end

# puts dp[n][0] == 1 ? 'Found' : 'Nothing'

n, _ = gets.split.map(&:to_i)
t = [0]

n.times do
  t = t.product(gets.split.map(&:to_i)).map { |a| a[0] ^ a[1] }
end

puts t.include?(0) ? "Found" : "Nothing"
