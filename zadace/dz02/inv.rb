def sum(x)
    sol = 0
    while x > 0 do
        sol += $f[x]
        x -= (x & -x)
    end
    sol
end

def update(x)
    while x <= $N do
        $f[x] += 1
        x += (x & -x)
    end
end

A = Array.new
$f = Array.new(10000003, 0)
$N = gets.chomp.to_i
$N.times do |i|
    A << [gets.chomp.to_i, $N - i]
    $f[i] = 0
end
sol = 0
A.sort.each do |a|
    sol += sum(a[1])
    update(a[1])
end
puts sol
