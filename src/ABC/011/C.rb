n = gets.to_i
ng = 3.times.map { gets.to_i }

dp = Array.new(n + 1, 1000000)
dp[n] = 0

n.downto(0) do |i|
  next if ng.include?(i)
  1.upto(3) do |j|
    next if i - j < 0
    dp[i - j] = [dp[i] + 1, dp[i - j]].min
  end
end

puts dp[0] > 100 ? 'NO' : 'YES'
