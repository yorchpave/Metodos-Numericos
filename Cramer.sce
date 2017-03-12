mSize = input("Insert left side lenght of square matrix: ")
a = []
b = []

for i = 1: mSize
	for j = 1: mSize
		a(i, j) = input("Left side: A" + string(i) + string(j) + "= ")
	end
end

for i = 1: mSize
	b(i) = input("Right side: b" + string(i) + "= ")
end

detA = det(a)
[rX cX] = size(a)
sol = []

for i = 1: cX
	temp = a
	temp(:, i) = b(:)
	disp("x" + string(i) + " = " + string(det(temp) / detA))
end

