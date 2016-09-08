n = gets.to_i
c = n.times.map { gets.to_i }

ans = 0
n.times do |i|
  cnt = 0
  n.times do |j|
    cnt += 1 if i != j && c[i] % c[j] == 0
  end
  ans += (cnt / 2 + 1).to_f / (cnt + 1)
end

puts "%.10f" % ans
