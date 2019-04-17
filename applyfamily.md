https://help.github.com/en/articles/basic-writing-and-formatting-syntax
# The functions of the apply family

### 1. apply(X, MARGIN, FUN, ...)
|Parameter|Description|
|---|---|
|X|an array, including a matrix.|
|MARGIN|a vector giving the subscripts which the function will be applied over. E.g., for a matrix 1 indicates rows, 2 indicates columns, c(1, 2) indicates rows and columns. Where X has named dimnames, it can be a character vector selecting dimension names.|
|FUN|the function to be applied: see ‘Details’. In the case of functions like +, %*%, etc., the function name must be backquoted or quoted.|
|...|optional arguments to FUN.|
    > x <- list(a = 1:10, beta = exp(-3:3), logic = c(TRUE,FALSE,FALSE,TRUE))
    > # compute the list mean for each list element
    > lapply(x, mean)
    $a
    [1] 5.5
    
    $beta
    [1] 4.535125
    
    $logic
    [1] 0.5
    
    > # median and quartiles for each list element
    > lapply(x, quantile, probs = 1:3/4)
    $a
     25%  50%  75% 
    3.25 5.50 7.75 
    
    $beta
          25%       50%       75% 
    0.2516074 1.0000000 5.0536690 
    
    $logic
    25% 50% 75% 
    0.0 0.5 1.0
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

### 3. sapply(X, FUN, ..., simplify = TRUE, USE.NAMES = TRUE)
|Parameter|Description|
|---|---|
|X|a vector (atomic or list) or an expression object. Other objects (including classed objects) will be coerced by base::as.list.|
|FUN|the function to be applied to each element of X: see ‘Details’. In the case of functions like +, %*%, the function name must be backquoted or quoted.|
|...|optional arguments to FUN.|
|simplify|logical or character string; should the result be simplified to a vector, matrix or higher dimensional array if possible? For sapply it must be named and not abbreviated. The default value, TRUE, returns a vector or matrix if appropriate, whereas if simplify = "array" the result may be an array of “rank” (=length(dim(.))) one higher than the result of FUN(X[[i]]).|
|USE.NAMES|logical; if TRUE and if X is character, use X as names for the result unless it had names already. Since this argument follows ... its name cannot be abbreviated.|

### mapply()

### vapply(X, FUN, FUN.VALUE, ..., USE.NAMES = TRUE)
|Parameter|Description|
|---|---|
|X|a vector (atomic or list) or an expression object. Other objects (including classed objects) will be coerced by base::as.list.|
|FUN|the function to be applied to each element of X: see ‘Details’. In the case of functions like +, %*%, the function name must be backquoted or quoted.|
|FUN.VALUE|a (generalized) vector; a template for the return value from FUN. See ‘Details’.|
|...|optional arguments to FUN.|
|USE.NAMES|logical; if TRUE and if X is character, use X as names for the result unless it had names already. Since this argument follows ... its name cannot be abbreviated.|

### tapply()

### rapply()

### eapply()

sweep() by() aggregate() aplit() subset() outer() dendrapply() environment()
