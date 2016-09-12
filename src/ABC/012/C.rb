product = 2025 - gets.to_i

10.times do |i|
  10.times do |j|
    if i * j == product
      puts "#{i} x #{j}"
    end
  end
end
