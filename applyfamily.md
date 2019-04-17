https://help.github.com/en/articles/basic-writing-and-formatting-syntax
# The functions of the apply family

### 1. apply(X, MARGIN, FUN, ...)
|Parameter|Description|
|---|---|
|X|an array, including a matrix.|
|MARGIN|a vector giving the subscripts which the function will be applied over. E.g., for a matrix 1 indicates rows, 2 indicates columns, c(1, 2) indicates rows and columns. Where X has named dimnames, it can be a character vector selecting dimension names.|
|FUN|the function to be applied: see ‘Details’. In the case of functions like +, %*%, etc., the function name must be backquoted or quoted.|
|...|optional arguments to FUN.|

apply(array/matrix, diemension(rows or columns) over which the function is applied, anonymous/built-in function, ...)

### 2. lapply(X, FUN, ...)
|Parameter|Description|
|---|---|
|X|a vector (atomic or list) or an expression object. Other objects (including classed objects) will be coerced by base::as.list.|
|FUN|the function to be applied to each element of X: see ‘Details’. In the case of functions like +, %*%, the function name must be backquoted or quoted.|
|...|optional arguments to FUN.|

lapply() -- same as apply() but returns a list
    _ Create a list of matrices
    _ MyList <- list(A,B,C)
    _ 
    _ Extract the 2nd column from `MyList` with the selection operator `[` with `lapply()`
    _ lapply(MyList,"[", , 2)
    _
    _ Extract the 1st row from `MyList`
    _ lapply(MyList,"[", 1, )

### 3. sapply()

### mapply()

### vapply()

### tapply()

### rapply()

### eapply()

sweep() by() aggregate() aplit() subset() outer() dendrapply() environment()
