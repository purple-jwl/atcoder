n, k = gets.split.map(&:to_i)
s = gets.chomp
t = s.clone

for i in (0...n)
  for ch in ('a'..'z')
    j = t.slice(0...n).index(ch, i)

    next if j == nil

    t[i], t[j] = t[j], t[i]

    cnt = Array.new(26, 0)
    for ii in ((i + 1)...n)
      cnt[s[ii].ord - 'a'.ord] += 1
      cnt[t[ii].ord - 'a'.ord] -= 1
    end

    diff = 0
    for ii in (0...26)
      diff += cnt[ii].abs
    end
    diff /= 2
    diff += 1 if s[i] != t[i]

    if diff <= k
      k -= 1 if s[i] != t[i]
      break
    else
      t[i], t[j] = t[j], t[i]
    end
  end
end

puts t
