t=gets.to_i

def diff (a, b)
  4.times.map{|i| (a>>i)%2==(b>>i)%2?0:1}.sum
end

def mbti_to_i (mbti)
  "ISFP".split("").each_with_index.map {|c, i| mbti[i] == c ? 1 << i : 0 }.sum
end

comb = 16.times.to_a.repeated_combination(3).to_a
comb.map! {|a,b,c| [[a,b,c], diff(a,b) + diff(b,c) + diff(a,c)] }
comb.sort! {|a, b| a[1] <=> b[1] }

t.times do
  gets;
  list = gets.split.map {|mbti| mbti_to_i mbti }
  comb.each do |arr,diff|
    success = arr.uniq.all? {|mbti| (list.count(mbti) >= arr.count(mbti) ? true : false) }
    if success
      puts diff
      break
    end
  end
end