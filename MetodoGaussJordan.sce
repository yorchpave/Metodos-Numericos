a = input("A = ")
b = input("b = ")

X = [a b]
[rX cX] = size(X)
disp("Augmented matrix before Gauss-Jordan elimination")
disp(X)

for p = 1:1:rX-1
    pivote = X(p,p);
    for i = p+1: 1: rX
        primFila = X(i,p)
        X(i,:) = X(i,:) - (X(p, :)/pivote)*primFila
    end
end

for i = rX: -1: 2
    pivote = X(i, i)
    for j = i-1: -1: 1
        primFila = X(j, i)
        X(j, :) = X(j, :) - (X(i, :)/pivote)*primFila
    end
end

for i = 1: rX
    f = X(i, i)
    X(i, :) = X(i, :)/f
end
disp("Augmented matrix after Gauss-Jordan elimination")
disp(X)

for i = 1: rX
    disp("x" + string(i) + " = " + string(X(i, cX)))
end
