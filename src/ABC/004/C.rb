n = gets.to_i

c = (1..6).to_a

(n % 30).times { |i|
  c[i % 5], c[i % 5+ 1] = c[i % 5+ 1], c[i % 5]
}

puts c.join()
