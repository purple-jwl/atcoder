def f(n)
  n * (n + 1) / 2
end

n, a, b = gets.split.map(&:to_i)

l = a.lcm(b)

puts f(n) - a * f(n / a) - b * f(n / b) + l * f(n / l)
