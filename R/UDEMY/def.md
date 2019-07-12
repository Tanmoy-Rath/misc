```R
> Script: Querying with data.table
Error: unexpected symbol in "Script: Querying with"
> 
> # get the library - only once
> install.packages("data.table")
Installing package into ‘C:/Users/USER/Documents/R/win-library/3.4’
(as ‘lib’ is unspecified)
trying URL 'https://cran.rstudio.com/bin/windows/contrib/3.4/data.table_1.12.2.zip'
Content type 'application/zip' length 1926960 bytes (1.8 MB)
downloaded 1.8 MB

package ‘data.table’ successfully unpacked and MD5 sums checked

The downloaded binary packages are in
	C:\Users\USER\AppData\Local\Temp\Rtmp4ULhbR\downloaded_packages
> 
> # activation
> library(data.table)
data.table 1.12.2 using 2 threads (see ?getDTthreads).  Latest news: r-datatable.com
> 
> 
> set.seed(34)
> 
> # standard data.frame from R base
> mydf = data.frame(a = c("Paul", "Kim", "Nora", "Sue", "Paul", "Kim"),
+                   b = c("A", "A", "B", "B", "B", "C"),
+                   c = rnorm(2)); mydf
     a b         c
1 Paul A -0.138890
2  Kim A  1.199813
3 Nora B -0.138890
4  Sue B  1.199813
5 Paul B -0.138890
6  Kim C  1.199813
> 
> head(mydf)
     a b         c
1 Paul A -0.138890
2  Kim A  1.199813
3 Nora B -0.138890
4  Sue B  1.199813
5 Paul B -0.138890
6  Kim C  1.199813
> 
> sapply(mydf, class)
        a         b         c 
 "factor"  "factor" "numeric" 
> 
> 
> # data.table from the package
> 
> library(data.table)
> 
> set.seed(34)
> 
> mytable = data.table(a = c("Paul", "Kim", "Nora", "Sue", "Paul", "Kim"),
+                      b = c("A", "A", "B", "B", "B", "C"),
+                      c = rnorm(2)); mytable
      a b         c
1: Paul A -0.138890
2:  Kim A  1.199813
3: Nora B -0.138890
4:  Sue B  1.199813
5: Paul B -0.138890
6:  Kim C  1.199813
> 
> head(mytable)
      a b         c
1: Paul A -0.138890
2:  Kim A  1.199813
3: Nora B -0.138890
4:  Sue B  1.199813
5: Paul B -0.138890
6:  Kim C  1.199813
> 
> sapply(mytable, class)
          a           b           c 
"character" "character"   "numeric" 
> 
> 
> 
> # checking the class
> class(mydf); class(mytable)
[1] "data.frame"
[1] "data.table" "data.frame"
> 
> 
> # extracting elements from the data.frame/table
> 
> # rows
> mydf[3,]
     a b        c
3 Nora B -0.13889
> 
> mytable[3,]
      a b        c
1: Nora B -0.13889
> 
> # what is the default extract when using simple box brackets?
> mydf[3]
          c
1 -0.138890
2  1.199813
3 -0.138890
4  1.199813
5 -0.138890
6  1.199813
> 
> mytable[3]
      a b        c
1: Nora B -0.13889
> # df extracts columns, dt rows
> 
> # columns: extraction in different form, column or vector
> mydf[3]; mydf[,3]
          c
1 -0.138890
2  1.199813
3 -0.138890
4  1.199813
5 -0.138890
6  1.199813
[1] -0.138890  1.199813 -0.138890  1.199813 -0.138890  1.199813
> 
> mytable[,3] #does not work
           c
1: -0.138890
2:  1.199813
3: -0.138890
4:  1.199813
5: -0.138890
6:  1.199813
> 
> mytable[,c] # use the column name instead, this is paramater j of dt syntax
[1] -0.138890  1.199813 -0.138890  1.199813 -0.138890  1.199813
> 
> mytable[,.(c)] # in this notation you will get a dt as ouput again
           c
1: -0.138890
2:  1.199813
3: -0.138890
4:  1.199813
5: -0.138890
6:  1.199813
> 
> mytable[, list(c)] # gives the same output, . and list are aliases
           c
1: -0.138890
2:  1.199813
3: -0.138890
4:  1.199813
5: -0.138890
6:  1.199813
> 
> mytable[,.(cname = c)] # same command but renaming the column
       cname
1: -0.138890
2:  1.199813
3: -0.138890
4:  1.199813
5: -0.138890
6:  1.199813
> 
> mytable[, sum(b == "B")] # how many rows with "B"?
[1] 3
> # this shows that with a dt we can even do calculations in the j parameter
> 
> mytable[b =="B", .N] # an alternative way with .N as number indicator, special symbol in dt
[1] 3
> 
> # selecting all rows with column b with character A
> mytable[b == "A",]
      a b         c
1: Paul A -0.138890
2:  Kim A  1.199813
> 
> subset(mytable, b =="A") # same result with the subset command
      a b         c
1: Paul A -0.138890
2:  Kim A  1.199813
> 
> subset(mytable, b =="A", select = a) # use select to select a specific column
      a
1: Paul
2:  Kim
> 
> mydf[mydf$b == "A",] # note how the name of the df needs to be stated here
     a b         c
1 Paul A -0.138890
2  Kim A  1.199813
> 
> mytable[3:6, sum(c)] # sum col c from rows 3 to 6
[1] 2.121846
> 
> mytable[!3:6, sum(c)] # sum col c except rows 3 to 6
[1] 1.060923
> 
> mytable[rep(c(T,F), length=.N)] # extracting the uneven rows, new version of dt
      a b        c
1: Paul A -0.13889
2: Nora B -0.13889
3: Paul B -0.13889
> 
> # mytable[c(T, F)] does no longer work in dt
> 
> # using the by parameter
> mytable[, by = b, .N] # count of the 3 types of b
   b N
1: A 2
2: B 3
3: C 1
> 
> mytable[, by = .(b,a), .N] # grouped by b and a, which in this case only gives 1s
   b    a N
1: A Paul 1
2: A  Kim 1
3: B Nora 1
4: B  Sue 1
5: B Paul 1
6: C  Kim 1
> 
> transpose(mytable) # transpose works on nearly all R objects (df, dt, lists)
                   V1               V2                 V3               V4                 V5               V6
1:               Paul              Kim               Nora              Sue               Paul              Kim
2:                  A                A                  B                B                  B                C
3: -0.138889971170897 1.19981289660638 -0.138889971170897 1.19981289660638 -0.138889971170897 1.19981289660638
> 
> mytable[order(-b, -a)] # ordering with order, b and a each descending
      a b         c
1:  Kim C  1.199813
2:  Sue B  1.199813
3: Paul B -0.138890
4: Nora B -0.138890
5: Paul A -0.138890
6:  Kim A  1.199813
> 
> setorder(mytable, -b,-a) # ordering descending, first b, than a
> # note that set.. functions in the dt package modify the data
> mytable
      a b         c
1:  Kim C  1.199813
2:  Sue B  1.199813
3: Paul B -0.138890
4: Nora B -0.138890
5: Paul A -0.138890
6:  Kim A  1.199813
> 
> # converting a data frame to a data table is easy
> newmt = data.table(mtcars); class(newmt)
[1] "data.table" "data.frame"
> 
> # lets check which dt we have stored so far
> tables()
      NAME NROW NCOL MB                        COLS KEY
1: mytable    6    3  0                       a,b,c    
2:   newmt   32   11  0 mpg,cyl,disp,hp,drat,wt,...    
Total: 0MB
> 
> # we can use an apply function to get each vector class
> sapply(mytable, class)
          a           b           c 
"character" "character"   "numeric" 
> 
> 
> ## keys
> 
> # setting a key (at column a) to organize the table
> mytable # note the order of col a
      a b         c
1:  Kim C  1.199813
2:  Sue B  1.199813
3: Paul B -0.138890
4: Nora B -0.138890
5: Paul A -0.138890
6:  Kim A  1.199813
> 
> setkey(mytable, a)
> mytable # now the whole dataset is ordered alphabetically according to a
      a b         c
1:  Kim C  1.199813
2:  Kim A  1.199813
3: Nora B -0.138890
4: Paul B -0.138890
5: Paul A -0.138890
6:  Sue B  1.199813
> 
> key(mytable) # lets check which column the key is at
[1] "a"
> 
> mytable["Kim"] # now we can directly get access to rows by calling row values
     a b        c
1: Kim C 1.199813
2: Kim A 1.199813
> 
> mytable["A"] # this is only possible in the keyed column
   a    b  c
1: A <NA> NA
> 
> mytable[c("Kim", "Paul")] # of course we can get several key-values in a vector
      a b         c
1:  Kim C  1.199813
2:  Kim A  1.199813
3: Paul B -0.138890
4: Paul A -0.138890
> 
> mytable["Kim", .(c)] # lets now add the j parameter - here I am stating that
          c
1: 1.199813
2: 1.199813
> # I only want column c as an output on "Kim", and it should be a data.table
> # therefore the list alias
> 
> mytable["Kim", c] # without the list alias we only get a vector
[1] 1.199813 1.199813
> 
> 
> 
> ## Exercises
> 
> library(ggplot2)
> 
> library(data.table)
> 
> ?diamonds
> 
> newdiam = data.table(diamonds); class(newdiam)
[1] "data.table" "data.frame"
> 
> newdiam
       carat       cut color clarity depth table price    x    y    z
    1:  0.23     Ideal     E     SI2  61.5    55   326 3.95 3.98 2.43
    2:  0.21   Premium     E     SI1  59.8    61   326 3.89 3.84 2.31
    3:  0.23      Good     E     VS1  56.9    65   327 4.05 4.07 2.31
    4:  0.29   Premium     I     VS2  62.4    58   334 4.20 4.23 2.63
    5:  0.31      Good     J     SI2  63.3    58   335 4.34 4.35 2.75
   ---                                                               
53936:  0.72     Ideal     D     SI1  60.8    57  2757 5.75 5.76 3.50
53937:  0.72      Good     D     SI1  63.1    55  2757 5.69 5.75 3.61
53938:  0.70 Very Good     D     SI1  62.8    60  2757 5.66 5.68 3.56
53939:  0.86   Premium     H     SI2  61.0    58  2757 6.15 6.12 3.74
53940:  0.75     Ideal     D     SI2  62.2    55  2757 5.83 5.87 3.64
> 
> summary(newdiam)
     carat               cut        color        clarity          depth           table           price      
 Min.   :0.2000   Fair     : 1610   D: 6775   SI1    :13065   Min.   :43.00   Min.   :43.00   Min.   :  326  
 1st Qu.:0.4000   Good     : 4906   E: 9797   VS2    :12258   1st Qu.:61.00   1st Qu.:56.00   1st Qu.:  950  
 Median :0.7000   Very Good:12082   F: 9542   SI2    : 9194   Median :61.80   Median :57.00   Median : 2401  
 Mean   :0.7979   Premium  :13791   G:11292   VS1    : 8171   Mean   :61.75   Mean   :57.46   Mean   : 3933  
 3rd Qu.:1.0400   Ideal    :21551   H: 8304   VVS2   : 5066   3rd Qu.:62.50   3rd Qu.:59.00   3rd Qu.: 5324  
 Max.   :5.0100                     I: 5422   VVS1   : 3655   Max.   :79.00   Max.   :95.00   Max.   :18823  
                                    J: 2808   (Other): 2531                                                  
       x                y                z         
 Min.   : 0.000   Min.   : 0.000   Min.   : 0.000  
 1st Qu.: 4.710   1st Qu.: 4.720   1st Qu.: 2.910  
 Median : 5.700   Median : 5.710   Median : 3.530  
 Mean   : 5.731   Mean   : 5.735   Mean   : 3.539  
 3rd Qu.: 6.540   3rd Qu.: 6.540   3rd Qu.: 4.040  
 Max.   :10.740   Max.   :58.900   Max.   :31.800  
                                                   
> 
> ## Exercise: big data with data.table
> 
> # 2 different ways how to find out how many diamonds >10000 in price
> 
> # how many diamonds >10K in price, sorted by color
> 
> # table with diamonds cut = "Idea" and the color is either "E" or "J"
> 
> # order the table by price
> 
> # extract a table with price and cut
> 
> # how many diamonds have combined xyz dimensions (sum) of > 18 ?
> 
> # get the mean price for diamonds with a cut of "Ideal" and "Premium"
> 
> # get the number of diamonds with a price >10000 and a cut of "Premium
> 
> 
> ## Solutions
> 
> # 2 different ways in how to find out how many diamonds >10000 in price
> 
> nrow(subset(newdiam, price > 10000))
[1] 5222
> 
> newdiam[price>10000,.N]
[1] 5222
> 
> # how many diamonds >10K in price, sorted by color
> 
> newdiam[price>10000,.N, by = color]
   color    N
1:     J  440
2:     E  590
3:     G 1090
4:     F  798
5:     I  879
6:     D  410
7:     H 1015
> 
> # table with diamonds cut = "Idea" and the color is either "E" or "J"
> 
> newdiam[cut == "Ideal" & (color == "E" | color == "J")]
      carat   cut color clarity depth table price    x    y    z
   1:  0.23 Ideal     E     SI2  61.5    55   326 3.95 3.98 2.43
   2:  0.23 Ideal     J     VS1  62.8    56   340 3.93 3.90 2.46
   3:  0.31 Ideal     J     SI2  62.2    54   344 4.35 4.37 2.71
   4:  0.33 Ideal     J     SI1  61.1    56   403 4.49 4.55 2.76
   5:  0.26 Ideal     E    VVS2  62.9    58   554 4.02 4.06 2.54
  ---                                                           
4795:  0.70 Ideal     E     SI1  61.7    55  2745 5.71 5.74 3.53
4796:  0.51 Ideal     E    VVS1  61.9    54  2745 5.17 5.11 3.18
4797:  0.56 Ideal     E    VVS1  62.1    56  2750 5.28 5.29 3.28
4798:  0.77 Ideal     E     SI2  62.1    56  2753 5.84 5.86 3.63
4799:  0.71 Ideal     E     SI1  61.9    56  2756 5.71 5.73 3.54
> 
> # order the table by price
> 
> newdiam[order(price)]
       carat       cut color clarity depth table price    x    y    z
    1:  0.23     Ideal     E     SI2  61.5    55   326 3.95 3.98 2.43
    2:  0.21   Premium     E     SI1  59.8    61   326 3.89 3.84 2.31
    3:  0.23      Good     E     VS1  56.9    65   327 4.05 4.07 2.31
    4:  0.29   Premium     I     VS2  62.4    58   334 4.20 4.23 2.63
    5:  0.31      Good     J     SI2  63.3    58   335 4.34 4.35 2.75
   ---                                                               
53936:  2.00 Very Good     H     SI1  62.8    57 18803 7.95 8.00 5.01
53937:  2.07     Ideal     G     SI2  62.5    55 18804 8.20 8.13 5.11
53938:  1.51     Ideal     G      IF  61.7    55 18806 7.37 7.41 4.56
53939:  2.00 Very Good     G     SI1  63.5    56 18818 7.90 7.97 5.04
53940:  2.29   Premium     I     VS2  60.8    60 18823 8.50 8.47 5.16
> 
> # extract a table with price and cut
> 
> newdiam[, .(price, cut)]
       price       cut
    1:   326     Ideal
    2:   326   Premium
    3:   327      Good
    4:   334   Premium
    5:   335      Good
   ---                
53936:  2757     Ideal
53937:  2757      Good
53938:  2757 Very Good
53939:  2757   Premium
53940:  2757     Ideal
> 
> # how many diamonds have combined xyz dimensions (sum) of > 18 ?
> 
> newdiam[, sum((x + y + z)>18)]
[1] 8296
> 
> newdiam[(x + y + z)>18, .N]
[1] 8296
> 
> # get the mean price for diamonds with a cut of "Ideal" and "Premium"
> 
> newdiam[cut == "Ideal" | cut == "Premium", .(meanprice = mean(price)), by = cut] # keep it a list to name the output
       cut meanprice
1:   Ideal  3457.542
2: Premium  4584.258
> 
> # get the number of diamonds with a price >10000 and a cut of "Premium
> 
> newdiam[ price > 10000 & cut =="Premium", .N]
[1] 1807
> 
> newdiam[, .N, price > 10000 & cut =="Premium"]
   price     N
1: FALSE 52133
2:  TRUE  1807
```
