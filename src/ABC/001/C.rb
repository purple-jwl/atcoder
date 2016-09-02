def getDir(deg)
  dir = [
    'N', 'NNE', 'NE', 'ENE', 'E', 'ESE', 'SE', 'SSE',
    'S', 'SSW', 'SW', 'WSW', 'W', 'WNW', 'NW', 'NNW',
  ]

  deg = ((deg * 10 + 1125) % 36000) / 2250

  return dir[deg]
end

def getW(dis)
  w = 0

  if dis <= 0.2 then
    w = 0
  elsif dis <= 1.5 then
    w = 1
  elsif dis <= 3.3 then
    w = 2
  elsif dis <= 5.4 then
    w = 3
  elsif dis <= 7.9 then
    w = 4
  elsif dis <= 10.7 then
    w = 5
  elsif dis <= 13.8 then
    w = 6
  elsif dis <= 17.1 then
    w = 7
  elsif dis <= 20.7 then
    w = 8
  elsif dis <= 24.4 then
    w = 9
  elsif dis <= 28.4 then
    w = 10
  elsif dis <= 32.6 then
    w = 11
  else
    w = 12
  end

  return w
end

deg, dis = gets.split.map(&:to_i)

dis = (dis.to_f / 60).round(1)
w = getW(dis)
dir = w == 0 ? 'C' : getDir(deg)

puts "%s %d" % [dir, w]
