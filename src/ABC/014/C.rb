# arr = Array.new(1000000 + 5, 0)
arr = [0] * (1_000_000 + 5)

gets.to_i.times do
  a, b = gets.split.map(&:to_i)
  arr[a] += 1
  arr[b + 1] -= 1
end

1000000.times do |i|
  arr[i + 1] += arr[i]
end

puts arr.max
