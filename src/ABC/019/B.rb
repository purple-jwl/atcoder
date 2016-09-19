puts gets.chomp.split('')
      .chunk { |c| c }
      .map { |key, val| key + val.size.to_s }
      .join
