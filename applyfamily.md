https://help.github.com/en/articles/basic-writing-and-formatting-syntax
# The functions of the apply family

### 1. apply(X, MARGIN, FUN, ...)
>- It is most often used to apply a function to the rows or columns of a matrix.
>- It can be used with general arrays, e.g. taking the average of an array of matrices.
>- It is not really faster than writing a loop, but it works in one line!
>- apply() can immitate the functions below:
>- rowSums() = apply(x, 1, sum)
>- rowMeans() = apply(x, 1, mean)
>- colSums() = apply(x, 2, sum)
>- colMeans() = apply(x, 2, mean)
>- But the shortcut functions are much faster, apparent when used on a large matrix.
http://www.rdocumentation.org/packages/base/versions/3.5.3/topics/apply
<details>
  <summary>Argument description...Click to expand!!</summary>
  
|Argument|Description|
|---|---|
|X|an array, including a matrix.|
|MARGIN|a vector giving the subscripts which the function will be applied over. E.g., for a matrix 1 indicates rows, 2 indicates columns, c(1, 2) indicates rows and columns. Where X has named dimnames, it can be a character vector selecting dimension names.|
|FUN|the function to be applied: see ‘Details’. In the case of functions like +, %*%, etc., the function name must be backquoted or quoted.|
|...|optional arguments to FUN.|
</details>

<details>
  <summary>Examples...Click to expand!!</summary>

    > set.seed(18949)
    > x <- matrix(rnorm(200),20,10)
    > apply(x, 1, quantile, probs=c(0.25, 0.75))
              [,1]       [,2]       [,3]      [,4]
    25% -0.9914692 -0.1908423 -0.4300005 -1.255110
    75%  0.7904808  0.5512175  0.5697090  0.244837
              [,5]       [,6]       [,7]       [,8]
    25% -0.5256669 -0.4636574 -1.3609265 -0.7012947
    75%  0.4640788  0.3641334  0.1896196  0.8205340
              [,9]      [,10]      [,11]      [,12]
    25% -0.8150329 -0.344708  -0.5216225  0.2128561
    75%  0.7361397  0.813752   0.6109588  0.6443443
             [,13]      [,14]      [,15]      [,16]
    25% -0.77378447 0.2209238 -1.1365713 -0.7600171
    75%  0.08931413 0.7466569 -0.1099666  0.5997105
             [,17]      [,18]      [,19]      [,20]
    25% -0.1963744 -0.4609184 -1.1621672 -0.7849068
    75%  1.0905260  1.0427894 -0.3418321  0.3916902
    ###################################################################################################################
    
    > set.seed(18949)
    > a <- array(rnorm(2*5*3), c(2,5,3))
    > a
    , , 1
    
               [,1]       [,2]        [,3]       [,4]       [,5]
    [1,] -2.0702028 -1.4553385  0.40501198  0.2917507 -1.1514895
    [2,]  0.6493751 -0.1889221 -0.04674509 -1.5768760  0.1921096
    
    , , 2
    
               [,1]       [,2]       [,3]       [,4]      [,5]
    [1,] -0.3167998 -0.4482162 -1.1936750  0.5656030 0.1047564
    [2,]  0.1792631  0.8629761  0.7418777 -0.4702795 0.3604304
    
    , , 3
    
               [,1]       [,2]       [,3]       [,4]      [,5]
    [1,]  0.7002806 -0.2662845 -0.3091816 -0.2429141 0.7591960
    [2,] -0.6699911 -1.0847956 -0.4682024  0.7537504 0.4481469
    ###################################################################################################################    
    
    # c(1,2) preserves the 1st and 2nd dimensions and collapses the 3rd dimension
    > apply(a, c(1,2), mean)
                [,1]       [,2]        [,3]       [,4]        [,5]
    [1,] -0.56224065 -0.7232797 -0.36594820  0.2048132 -0.09584571
    [2,]  0.05288237 -0.1369139  0.07564341 -0.4311350  0.33356231
    
    > rowMeans(a, dims=2)
                [,1]       [,2]        [,3]       [,4]        [,5]
    [1,] -0.56224065 -0.7232797 -0.36594820  0.2048132 -0.09584571
    [2,]  0.05288237 -0.1369139  0.07564341 -0.4311350  0.33356231
</details>

---






### 2. lapply(X, FUN, ...)
>- returns a **"list"**

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
    ###################################################################################################################
    
    > lapply(x, runif, min=100, max=200)
    [[1]]
    [1] 100.9464
    
    [[2]]
    [1] 132.0792 155.9457
    
    [[3]]
    [1] 151.4918 108.9712 168.3251
    
    [[4]]
    [1] 170.9972 180.0232 194.4078 118.6646
    ###################################################################################################################
    
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
    ###################################################################################################################
    
    > # Select the first column
    > lapply(x, function(elt) elt[,1])
    $a
    [1] 1 2
    
    $b
    [1] 1 2 3
    ###################################################################################################################
    
    > # Select the 1st row
    > lapply(x, "[", 1,)
    $a
    [1] 1 3
    
    $b
    [1] 1 4
    ###################################################################################################################
    
    > # Select the 2nd column
    > lapply(x, "[", ,2)
    $a
    [1] 3 4
    
    $b
    [1] 4 5 6
    ###################################################################################################################
    
    # Advanced examples
    > x <- list(a = 1:10, beta = exp(-3:3), logic = c(TRUE,FALSE,FALSE,TRUE))
    > lapply(x, runif)
    $a
     [1] 0.32122467 0.06019516 0.04345645 0.05505382 0.62554280 0.96447029 0.82730287 0.31502824 0.21302545 0.73249612
     
    $beta
    [1] 0.49924102 0.72977197 0.08033604 0.43553048 0.23658045 0.79156780 0.25868432
     
    $logic
    [1] 0.9859838 0.7568737 0.9797782 0.2189478
    ###################################################################################################################
    
    > # compute the list mean for each list element
    > lapply(x, mean)
    $a
    [1] 5.5
    
    $beta
    [1] 4.535125
    
    $logic
    [1] 0.5
    ###################################################################################################################
    
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

---






### 3. sapply(X, FUN, ..., simplify = TRUE, USE.NAMES = TRUE)
>- If the result is a list where every element is length 1, then a **"vector"** is returned.<br/>
>- If the result is a list where every element is a vector of same length (>1), then a **"matrix"** is returned.<br/>
>- If it can't figure things out, then a **"list"** is returned.

|Parameter|Description|
|---|---|
|X|a vector (atomic or list) or an expression object. Other objects (including classed objects) will be coerced by base::as.list.|
|FUN|the function to be applied to each element of X: see ‘Details’. In the case of functions like +, %*%, the function name must be backquoted or quoted.|
|...|optional arguments to FUN.|
|simplify|logical or character string; should the result be simplified to a vector, matrix or higher dimensional array if possible? For sapply it must be named and not abbreviated. The default value, TRUE, returns a vector or matrix if appropriate, whereas if simplify = "array" the result may be an array of “rank” (=length(dim(.))) one higher than the result of FUN(X[[i]]).|
|USE.NAMES|logical; if TRUE and if X is character, use X as names for the result unless it had names already. Since this argument follows ... its name cannot be abbreviated.|
<details>
  <summary>Examples...Click to expand!!</summary>

    > x <- list(a = 1:10, beta = exp(-3:3), logic = c(TRUE,FALSE,FALSE,TRUE))
    > sapply(x, mean)
           a     beta    logic 
    5.500000 4.535125 0.500000
    # returned a "vector"
    
    > sapply(x, quantile)
             a        beta logic
    0%    1.00  0.04978707   0.0
    25%   3.25  0.25160736   0.0
    50%   5.50  1.00000000   0.5
    75%   7.75  5.05366896   1.0
    100% 10.00 20.08553692   1.0
    # returned a "matrix"
    
    > i39 <- sapply(3:9, seq) # list of vectors
    > sapply(i39, fivenum)
         [,1] [,2] [,3] [,4] [,5] [,6] [,7]
    [1,]  1.0  1.0    1  1.0  1.0  1.0    1
    [2,]  1.5  1.5    2  2.0  2.5  2.5    3
    [3,]  2.0  2.5    3  3.5  4.0  4.5    5
    [4,]  2.5  3.5    4  5.0  5.5  6.5    7
    [5,]  3.0  4.0    5  6.0  7.0  8.0    9
</details>

---






### 4. mapply(FUN, ..., MoreArgs = NULL, SIMPLIFY = TRUE, USE.NAMES = TRUE)
|Parameter|Description|
|---|---|
|FUN|function to apply, found via match.fun.|
|...|arguments to vectorize over (vectors or lists of strictly positive length, or all of zero length). See also ‘Details’.|
|MoreArgs|a list of other arguments to FUN.|
|SIMPLIFY|logical or character string; attempt to reduce the result to a vector, matrix or higher dimensional array; see the simplify argument of sapply.|
|USE.NAMES|logical; use names if the first ... argument has names, or if it is a character vector, use that character vector as the names.|
<details>
  <summary>Examples...Click to expand!!</summary>
    
    > mapply(rep, 1:4, 4:1)
    [[1]]
    [1] 1 1 1 1
    
    [[2]]
    [1] 2 2 2
    
    [[3]]
    [1] 3 3
    
    [[4]]
    [1] 4
    
    > mapply(rep, times = 1:4, x = 4:1)
    [[1]]
    [1] 4
    
    [[2]]
    [1] 3 3
    
    [[3]]
    [1] 2 2 2
    
    [[4]]
    [1] 1 1 1 1
    
    > mapply(rep, times = 1:4, MoreArgs = list(x = 42))
    [[1]]
    [1] 42
    
    [[2]]
    [1] 42 42
    
    [[3]]
    [1] 42 42 42
    
    [[4]]
    [1] 42 42 42 42
    
    > mapply(function(x, y) seq_len(x) + y,
            c(a =  1, b = 2, c = 3),  # names from first
            c(A = 10, B = 0, C = -10))
    $a
    [1] 11

    $b
    [1] 1 2
    
    $c
    [1] -9 -8 -7
    
    > word <- function(C, k) paste(rep.int(C, k), collapse = "")
    > utils::str(mapply(word, LETTERS[1:6], 6:1, SIMPLIFY = FALSE))
    List of 6
     $ A: chr "AAAAAA"
     $ B: chr "BBBBB"
     $ C: chr "CCCC"
     $ D: chr "DDD"
     $ E: chr "EE"
     $ F: chr "F"
</details>

---







### 5. vapply(X, FUN, FUN.VALUE, ..., USE.NAMES = TRUE)
|Parameter|Description|
|---|---|
|X|a vector (atomic or list) or an expression object. Other objects (including classed objects) will be coerced by base::as.list.|
|FUN|the function to be applied to each element of X: see ‘Details’. In the case of functions like +, %*%, the function name must be backquoted or quoted.|
|FUN.VALUE|a (generalized) vector; a template for the return value from FUN. See ‘Details’.|
|...|optional arguments to FUN.|
|USE.NAMES|logical; if TRUE and if X is character, use X as names for the result unless it had names already. Since this argument follows ... its name cannot be abbreviated.|

---






### 6. tapply(X, INDEX, FUN = NULL, ..., default = NA, simplify = TRUE)
|Parameter|Description|
|---|---|
|X|an atomic object, typically a vector.|
|INDEX|a list of one or more factors, each of same length as X. The elements are coerced to factors by as.factor.|
|FUN|the function to be applied, or NULL. In the case of functions like +, %*%, etc., the function name must be backquoted or quoted. If FUN is NULL, tapply returns a vector which can be used to subscript the multi-way array tapply normally produces.|
|...|optional arguments to FUN. Note: Optional arguments to FUN supplied by the ... argument are not divided into cells. It is therefore inappropriate for FUN to expect additional arguments with the same length as X.|
|default|(only in the case of simplification to an array) the value with which the array is initialized as array(default, dim = ..). Before R 3.4.0, this was hard coded to array()'s default NA. If it is NA (the default), the missing value of the answer type, e.g. NA_real_, is chosen (as.raw(0) for "raw"). In a numerical case, it may be set, e.g., to FUN(integer(0)), e.g., in the case of FUN = sum to 0 or 0L.|
|simplify|logical; if FALSE, tapply always returns an array of mode "list"; in other words, a list with a dim attribute. If TRUE (the default), then if FUN always returns a scalar, tapply returns an array with the mode of the scalar.|

---






### rapply()
---






### eapply()
---






sweep() by() aggregate() split() subset() slice() outer() dendrapply() environment()
