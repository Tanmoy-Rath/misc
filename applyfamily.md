# The functions of the apply family

### 1. apply(array or a matrix, the diemension(rows or columns) over which the function is applied, anonymous or built-in function, ...)

### 2. lapply() -- same as apply() but returns a list
_ Create a list of matrices
_ MyList <- list(A,B,C)
_ 
_ Extract the 2nd column from `MyList` with the selection operator `[` with `lapply()`
_ lapply(MyList,"[", , 2)
_
_ Extract the 1st row from `MyList`
_ lapply(MyList,"[", 1, )
