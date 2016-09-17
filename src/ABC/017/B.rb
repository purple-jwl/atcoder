# puts gets.chomp.gsub('ch', '').gsub('o', '').gsub('k', '').gsub('u', '') == '' ? 'YES' : 'NO'

puts gets.chomp.gsub(/ch|o|k|u/, '') == '' ? 'YES' : 'NO'
