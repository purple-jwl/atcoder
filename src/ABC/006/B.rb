n = gets.to_i

a = [-1, 0, 0, 1]

for i in (4..n) do
  # a.push((a[i - 1] + a[i - 2] + a[i - 3]) % 10007)
  a << (a[i - 1] + a[i - 2] + a[i - 3]) % 10007
end

puts a[n]
