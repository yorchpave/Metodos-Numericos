a = input("A = ")
b = input("b = ")

X = [a b]
[rX cX] = size(X)
disp("Augmented matrix before gaussian elimination")
disp(X)

for p = 1:1:rX-1
    pivote = X(p,p);
    for i = p+1: 1: rX
        primFila = X(i,p)
        X(i, :) = X(i, :) - (X(p, :)/pivote)*primFila
    end
end
disp("Augmented matrix after gaussian elimination")
disp(X)

sol = []
sol(rX) = X(rX, cX)/X(rX, cX-1)
for i = rX-1: -1: 1
    s = X(i, cX)
    for j = rX: -1: i
        s = s - X(i, j)*sol(j)
    end
    sol(i) = s/X(i, i)
end

for i = 1: rX
    disp("x" + string(i) + " = " + string(sol(i)))
end
