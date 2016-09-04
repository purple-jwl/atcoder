c = []

for i in (0...4) do
  c.push(gets.split.reverse.join(' '))
end

c.reverse!

for i in (0...4) do
  puts c[i]
end
