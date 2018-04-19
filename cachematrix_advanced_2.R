## makeCacheMatrix() : Creates a matrix data type and returns a list containing its inbuilt functions
##	It has 4 inbuilt functions setm() , getm() , setinv(), getinv()
##		set_MATRIX() : resets the matrix to new values
##		get_MATRIX() : gets the matrix values
##		set_INVERSE() : Calculates and stores the inverse in memory. It works as follows :
##                      (1)  First it checks if inverse exists, and returns it if inverse exists
##                      (2)  If inverse doesnot exist, it checks if it is a square-matrix
##                      (3)  If it is not a square matrix, then inverse is not calculated.
##                      (4)  If it is a square-matrix, then inverse is calculated and stored in memory.
##		get_INVERSE() : gets the inverse from the memory cache

makeCacheMatrix <- function(MTRX = matrix(), calcin = FALSE, ...) {
        
        ## core_inv() : calculates and stores the inverse in memory
        core_inv <- function() {
                
                ## Now check whether the matrix is square-matrix or not
                ## This is done by getting the matrix diemensions, using dim()
                DIMS <- dim(MTRX, ...)
                if(DIMS[1] != DIMS[2]) {
                        message("Matrix diemensions are unequal. Inverse cannot be calculated.")
                        INV <<- NULL
                        return(NULL)
                }
                
                ## Calculates the Determinant of matrix to see if it is invertible or not
                ## Determinant is calculated using det()
                DT <- det(MTRX)
                if(DT == 0) {
                        message("Determinant is '0'. Inverse cannot be calculated.")
                        INV <<- NULL
                        return(NULL)
                }
                else {
                        message(paste0("Determinant is ",DT,". Proceeding to inverse calculation...", sep="", collapse=NULL))
                        INV <<- solve(MTRX, ...)
                        message("Calculation finished. Inverse can now be cached from memory.")
                        return(NULL)
                }
        }
        
        
        
        ## First, inverse is set to NULL
        if(calcin){core_inv()}
        else{
                INV <- NULL
                message("Inverse not set!! Set it by <object>$set_INVERSE()")
        }
        
        
        
        ## setinv() : checks if inverse exists, then proceeds to calculation
        setinv <- function() {
                
                ## First check whether inverse exists or not
                if(is.null(INV)) {
                        ## Proceed to core calculation function
                        core_inv()
                        return(NULL)
                }
                message("Inverse exists. Access using <object>$get_INVERSE()")
                return(NULL)
        }
        
        
        
        ## getinv() : gets the inverse from the memory cache
        getinv <- function() INV
        
        
        
        ## setm() : resets the matrix to new values
        setm <- function(mtx = matrix(), calinv = FALSE, ...) {
                MTRX <<- mtx
                message("Matrix successfully set to new values")
                if(calinv){core_inv()}
                else{
                        INV <<- NULL
                        message("Inverse not set!! Set it by <object>$set_INVERSE()")
                }
        }
        
        
        
        ## getm() : gets the matrix values
        getm <- function() MTRX
        
        
        
        ## The 4 functions are returned by as list elements
        list(set_MATRIX = setm, get_MATRIX = getm, set_INVERSE = setinv, get_INVERSE = getinv)
}








mm <- makeCacheMatrix(matrix(c(1,8,4,3,9,6,5,4,7,3,2,1), 4,3), calcin = TRUE)
mm$set_INVERSE()
mm$get_INVERSE()


mm <- makeCacheMatrix(matrix(1:9, 3,3), calcin = TRUE)
mm$set_INVERSE()


mm <- makeCacheMatrix(matrix(c(1,8,4,3,9,6,5,4,7), 3,3), calcin = TRUE)
mm$set_INVERSE()
mm$get_INVERSE()

mm$get_INVERSE() %*% mm$get_MATRIX()

mm$get_INVERSE()
mm$set_MATRIX(matrix(c(1,8,4,3,9,6,5,4,7), 3,3))
mm$get_INVERSE()