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
- returns a "list"

|Parameter|Description|
|---|---|
|X|a vector (atomic or list) or an expression object. Other objects (including classed objects) will be coerced by base::as.list.|
|FUN|the function to be applied to each element of X: see ‘Details’. In the case of functions like +, %*%, the function name must be backquoted or quoted.|
|...|optional arguments to FUN.|
<details>
  <summary>Examples...Click to expand!!</summary>

    > x <- 1:4
    > lapply(x, runif)
    [[1]]
    [1] 0.2511177
    
    [[2]]
    [1] 0.2150691 0.6094760
    
    [[3]]
    [1] 0.3834446 0.7552710 0.3797362
    
    [[4]]
    [1] 0.7949721 0.9056911 0.9840262 0.5879480
    
    > lapply(x, runif, min=100, max=200)
    [[1]]
    [1] 100.9464
    
    [[2]]
    [1] 132.0792 155.9457
    
    [[3]]
    [1] 151.4918 108.9712 168.3251
    
    [[4]]
    [1] 170.9972 180.0232 194.4078 118.6646
    
    > # Anonymous function
    > x <- list(a=matrix(1:4,2,2), b=matrix(1:6,3,2))
    > x
    $a
         [,1] [,2]
    [1,]    1    3
    [2,]    2    4
    
    $b
         [,1] [,2]
    [1,]    1    4
    [2,]    2    5
    [3,]    3    6
    
    > # Select the first column
    > lapply(x, function(elt) elt[,1])
    $a
    [1] 1 2
    
    $b
    [1] 1 2 3
    
    # Advanced examples
    > x <- list(a = 1:10, beta = exp(-3:3), logic = c(TRUE,FALSE,FALSE,TRUE))
    > lapply(x, runif)
    $a
     [1] 0.32122467 0.06019516 0.04345645 0.05505382 0.62554280 0.96447029 0.82730287 0.31502824 0.21302545 0.73249612
     
    $beta
    [1] 0.49924102 0.72977197 0.08033604 0.43553048 0.23658045 0.79156780 0.25868432
     
    $logic
    [1] 0.9859838 0.7568737 0.9797782 0.2189478
    
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
</details>

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
- If the result is a list where every element is length 1, then a **"vector"** is returned.
- If the result is a list where every element is a vector of same length (>1), then a **"matrix"** is returned.
- If it can't figure things out, then a **"list"** is returned.

|Parameter|Description|
|---|---|
|X|a vector (atomic or list) or an expression object. Other objects (including classed objects) will be coerced by base::as.list.|
|FUN|the function to be applied to each element of X: see ‘Details’. In the case of functions like +, %*%, the function name must be backquoted or quoted.|
|...|optional arguments to FUN.|
|simplify|logical or character string; should the result be simplified to a vector, matrix or higher dimensional array if possible? For sapply it must be named and not abbreviated. The default value, TRUE, returns a vector or matrix if appropriate, whereas if simplify = "array" the result may be an array of “rank” (=length(dim(.))) one higher than the result of FUN(X[[i]]).|
|USE.NAMES|logical; if TRUE and if X is character, use X as names for the result unless it had names already. Since this argument follows ... its name cannot be abbreviated.|
    > x <- list(a = 1:10, beta = exp(-3:3), logic = c(TRUE,FALSE,FALSE,TRUE))
    > sapply(x, quantile)
             a        beta logic
    0%    1.00  0.04978707   0.0
    25%   3.25  0.25160736   0.0
    50%   5.50  1.00000000   0.5
    75%   7.75  5.05366896   1.0
    100% 10.00 20.08553692   1.0
    
    > i39 <- sapply(3:9, seq) # list of vectors
    > sapply(i39, fivenum)
         [,1] [,2] [,3] [,4] [,5] [,6] [,7]
    [1,]  1.0  1.0    1  1.0  1.0  1.0    1
    [2,]  1.5  1.5    2  2.0  2.5  2.5    3
    [3,]  2.0  2.5    3  3.5  4.0  4.5    5
    [4,]  2.5  3.5    4  5.0  5.5  6.5    7
    [5,]  3.0  4.0    5  6.0  7.0  8.0    9

### 4. vapply(X, FUN, FUN.VALUE, ..., USE.NAMES = TRUE)
|Parameter|Description|
|---|---|
|X|a vector (atomic or list) or an expression object. Other objects (including classed objects) will be coerced by base::as.list.|
|FUN|the function to be applied to each element of X: see ‘Details’. In the case of functions like +, %*%, the function name must be backquoted or quoted.|
|FUN.VALUE|a (generalized) vector; a template for the return value from FUN. See ‘Details’.|
|...|optional arguments to FUN.|
|USE.NAMES|logical; if TRUE and if X is character, use X as names for the result unless it had names already. Since this argument follows ... its name cannot be abbreviated.|

### mapply()

### tapply()

### rapply()

### eapply()

sweep() by() aggregate() aplit() subset() outer() dendrapply() environment()
