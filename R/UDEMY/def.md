```R
Script: Querying with data.table
Error: unexpected symbol in "Script: Querying with"

# get the library - only once
install.packages("data.table")
Installing package into ‘C:/Users/USER/Documents/R/win-library/3.4’
(as ‘lib’ is unspecified)
trying URL 'https://cran.rstudio.com/bin/windows/contrib/3.4/data.table_1.12.2.zip'
Content type 'application/zip' length 1926960 bytes (1.8 MB)
downloaded 1.8 MB

package ‘data.table’ successfully unpacked and MD5 sums checked

The downloaded binary packages are in
	C:\Users\USER\AppData\Local\Temp\Rtmp4ULhbR\downloaded_packages

# activation
library(data.table)
data.table 1.12.2 using 2 threads (see ?getDTthreads).  Latest news: r-datatable.com


set.seed(34)

# standard data.frame from R base
mydf = data.frame(a = c("Paul", "Kim", "Nora", "Sue", "Paul", "Kim"),
+                   b = c("A", "A", "B", "B", "B", "C"),
+                   c = rnorm(2)); mydf
     a b         c
1 Paul A -0.138890
2  Kim A  1.199813
3 Nora B -0.138890
4  Sue B  1.199813
5 Paul B -0.138890
6  Kim C  1.199813

head(mydf)
     a b         c
1 Paul A -0.138890
2  Kim A  1.199813
3 Nora B -0.138890
4  Sue B  1.199813
5 Paul B -0.138890
6  Kim C  1.199813

sapply(mydf, class)
        a         b         c 
 "factor"  "factor" "numeric" 


# data.table from the package

library(data.table)

set.seed(34)

mytable = data.table(a = c("Paul", "Kim", "Nora", "Sue", "Paul", "Kim"),
+                      b = c("A", "A", "B", "B", "B", "C"),
+                      c = rnorm(2)); mytable
      a b         c
1: Paul A -0.138890
2:  Kim A  1.199813
3: Nora B -0.138890
4:  Sue B  1.199813
5: Paul B -0.138890
6:  Kim C  1.199813

head(mytable)
      a b         c
1: Paul A -0.138890
2:  Kim A  1.199813
3: Nora B -0.138890
4:  Sue B  1.199813
5: Paul B -0.138890
6:  Kim C  1.199813

sapply(mytable, class)
          a           b           c 
"character" "character"   "numeric" 



# checking the class
class(mydf); class(mytable)
[1] "data.frame"
[1] "data.table" "data.frame"


# extracting elements from the data.frame/table

# rows
mydf[3,]
     a b        c
3 Nora B -0.13889

mytable[3,]
      a b        c
1: Nora B -0.13889

# what is the default extract when using simple box brackets?
mydf[3]
          c
1 -0.138890
2  1.199813
3 -0.138890
4  1.199813
5 -0.138890
6  1.199813

mytable[3]
      a b        c
1: Nora B -0.13889
# df extracts columns, dt rows

# columns: extraction in different form, column or vector
mydf[3]; mydf[,3]
          c
1 -0.138890
2  1.199813
3 -0.138890
4  1.199813
5 -0.138890
6  1.199813
[1] -0.138890  1.199813 -0.138890  1.199813 -0.138890  1.199813

mytable[,3] #does not work
           c
1: -0.138890
2:  1.199813
3: -0.138890
4:  1.199813
5: -0.138890
6:  1.199813

mytable[,c] # use the column name instead, this is paramater j of dt syntax
[1] -0.138890  1.199813 -0.138890  1.199813 -0.138890  1.199813

mytable[,.(c)] # in this notation you will get a dt as ouput again
           c
1: -0.138890
2:  1.199813
3: -0.138890
4:  1.199813
5: -0.138890
6:  1.199813

mytable[, list(c)] # gives the same output, . and list are aliases
           c
1: -0.138890
2:  1.199813
3: -0.138890
4:  1.199813
5: -0.138890
6:  1.199813

mytable[,.(cname = c)] # same command but renaming the column
       cname
1: -0.138890
2:  1.199813
3: -0.138890
4:  1.199813
5: -0.138890
6:  1.199813

mytable[, sum(b == "B")] # how many rows with "B"?
[1] 3
# this shows that with a dt we can even do calculations in the j parameter

mytable[b =="B", .N] # an alternative way with .N as number indicator, special symbol in dt
[1] 3

# selecting all rows with column b with character A
mytable[b == "A",]
      a b         c
1: Paul A -0.138890
2:  Kim A  1.199813

subset(mytable, b =="A") # same result with the subset command
      a b         c
1: Paul A -0.138890
2:  Kim A  1.199813

subset(mytable, b =="A", select = a) # use select to select a specific column
      a
1: Paul
2:  Kim

mydf[mydf$b == "A",] # note how the name of the df needs to be stated here
     a b         c
1 Paul A -0.138890
2  Kim A  1.199813

mytable[3:6, sum(c)] # sum col c from rows 3 to 6
[1] 2.121846

mytable[!3:6, sum(c)] # sum col c except rows 3 to 6
[1] 1.060923

mytable[rep(c(T,F), length=.N)] # extracting the uneven rows, new version of dt
      a b        c
1: Paul A -0.13889
2: Nora B -0.13889
3: Paul B -0.13889

# mytable[c(T, F)] does no longer work in dt

# using the by parameter
mytable[, by = b, .N] # count of the 3 types of b
   b N
1: A 2
2: B 3
3: C 1

mytable[, by = .(b,a), .N] # grouped by b and a, which in this case only gives 1s
   b    a N
1: A Paul 1
2: A  Kim 1
3: B Nora 1
4: B  Sue 1
5: B Paul 1
6: C  Kim 1

transpose(mytable) # transpose works on nearly all R objects (df, dt, lists)
                   V1               V2                 V3               V4                 V5               V6
1:               Paul              Kim               Nora              Sue               Paul              Kim
2:                  A                A                  B                B                  B                C
3: -0.138889971170897 1.19981289660638 -0.138889971170897 1.19981289660638 -0.138889971170897 1.19981289660638

mytable[order(-b, -a)] # ordering with order, b and a each descending
      a b         c
1:  Kim C  1.199813
2:  Sue B  1.199813
3: Paul B -0.138890
4: Nora B -0.138890
5: Paul A -0.138890
6:  Kim A  1.199813

setorder(mytable, -b,-a) # ordering descending, first b, than a
# note that set.. functions in the dt package modify the data
mytable
      a b         c
1:  Kim C  1.199813
2:  Sue B  1.199813
3: Paul B -0.138890
4: Nora B -0.138890
5: Paul A -0.138890
6:  Kim A  1.199813

# converting a data frame to a data table is easy
newmt = data.table(mtcars); class(newmt)
[1] "data.table" "data.frame"

# lets check which dt we have stored so far
tables()
      NAME NROW NCOL MB                        COLS KEY
1: mytable    6    3  0                       a,b,c    
2:   newmt   32   11  0 mpg,cyl,disp,hp,drat,wt,...    
Total: 0MB

# we can use an apply function to get each vector class
sapply(mytable, class)
          a           b           c 
"character" "character"   "numeric" 


## keys

# setting a key (at column a) to organize the table
mytable # note the order of col a
      a b         c
1:  Kim C  1.199813
2:  Sue B  1.199813
3: Paul B -0.138890
4: Nora B -0.138890
5: Paul A -0.138890
6:  Kim A  1.199813

setkey(mytable, a)
mytable # now the whole dataset is ordered alphabetically according to a
      a b         c
1:  Kim C  1.199813
2:  Kim A  1.199813
3: Nora B -0.138890
4: Paul B -0.138890
5: Paul A -0.138890
6:  Sue B  1.199813

key(mytable) # lets check which column the key is at
[1] "a"

mytable["Kim"] # now we can directly get access to rows by calling row values
     a b        c
1: Kim C 1.199813
2: Kim A 1.199813

mytable["A"] # this is only possible in the keyed column
   a    b  c
1: A <NANA

mytable[c("Kim", "Paul")] # of course we can get several key-values in a vector
      a b         c
1:  Kim C  1.199813
2:  Kim A  1.199813
3: Paul B -0.138890
4: Paul A -0.138890

mytable["Kim", .(c)] # lets now add the j parameter - here I am stating that
          c
1: 1.199813
2: 1.199813
# I only want column c as an output on "Kim", and it should be a data.table
# therefore the list alias

mytable["Kim", c] # without the list alias we only get a vector
[1] 1.199813 1.199813



## Exercises

library(ggplot2)

library(data.table)

?diamonds

newdiam = data.table(diamonds); class(newdiam)
[1] "data.table" "data.frame"

newdiam
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

summary(newdiam)
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
                                                   

## Exercise: big data with data.table

# 2 different ways how to find out how many diamonds >10000 in price

# how many diamonds >10K in price, sorted by color

# table with diamonds cut = "Idea" and the color is either "E" or "J"

# order the table by price

# extract a table with price and cut

# how many diamonds have combined xyz dimensions (sum) of 18 ?

# get the mean price for diamonds with a cut of "Ideal" and "Premium"

# get the number of diamonds with a price >10000 and a cut of "Premium


## Solutions

# 2 different ways in how to find out how many diamonds >10000 in price

nrow(subset(newdiam, price 10000))
[1] 5222

newdiam[price>10000,.N]
[1] 5222

# how many diamonds >10K in price, sorted by color

newdiam[price>10000,.N, by = color]
   color    N
1:     J  440
2:     E  590
3:     G 1090
4:     F  798
5:     I  879
6:     D  410
7:     H 1015

# table with diamonds cut = "Idea" and the color is either "E" or "J"

newdiam[cut == "Ideal" & (color == "E" | color == "J")]
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

# order the table by price

newdiam[order(price)]
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

# extract a table with price and cut

newdiam[, .(price, cut)]
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

# how many diamonds have combined xyz dimensions (sum) of 18 ?

newdiam[, sum((x + y + z)>18)]
[1] 8296

newdiam[(x + y + z)>18, .N]
[1] 8296

# get the mean price for diamonds with a cut of "Ideal" and "Premium"

newdiam[cut == "Ideal" | cut == "Premium", .(meanprice = mean(price)), by = cut] # keep it a list to name the output
       cut meanprice
1:   Ideal  3457.542
2: Premium  4584.258

# get the number of diamonds with a price >10000 and a cut of "Premium

newdiam[ price 10000 & cut =="Premium", .N]
[1] 1807

newdiam[, .N, price 10000 & cut =="Premium"]
   price     N
1: FALSE 52133
2:  TRUE  1807
```

<hr>

```R
library(ISLR)
library(data.table)
data.table 1.12.2 using 2 threads (see ?getDTthreads).  Latest news: r-datatable.com

dtcollege <- as.data.table(College, keep.rownames=T)
# dtcollege <- data.table(College, keep.rownames=T)

?College
summary(dtcollege)
      rn            Private        Apps           Accept          Enroll       Top10perc       Top25perc    
 Length:777         No :212   Min.   :   81   Min.   :   72   Min.   :  35   Min.   : 1.00   Min.   :  9.0  
 Class :character   Yes:565   1st Qu.:  776   1st Qu.:  604   1st Qu.: 242   1st Qu.:15.00   1st Qu.: 41.0  
 Mode  :character             Median : 1558   Median : 1110   Median : 434   Median :23.00   Median : 54.0  
                              Mean   : 3002   Mean   : 2019   Mean   : 780   Mean   :27.56   Mean   : 55.8  
                              3rd Qu.: 3624   3rd Qu.: 2424   3rd Qu.: 902   3rd Qu.:35.00   3rd Qu.: 69.0  
                              Max.   :48094   Max.   :26330   Max.   :6392   Max.   :96.00   Max.   :100.0  
  F.Undergrad     P.Undergrad         Outstate       Room.Board       Books           Personal         PhD        
 Min.   :  139   Min.   :    1.0   Min.   : 2340   Min.   :1780   Min.   :  96.0   Min.   : 250   Min.   :  8.00  
 1st Qu.:  992   1st Qu.:   95.0   1st Qu.: 7320   1st Qu.:3597   1st Qu.: 470.0   1st Qu.: 850   1st Qu.: 62.00  
 Median : 1707   Median :  353.0   Median : 9990   Median :4200   Median : 500.0   Median :1200   Median : 75.00  
 Mean   : 3700   Mean   :  855.3   Mean   :10441   Mean   :4358   Mean   : 549.4   Mean   :1341   Mean   : 72.66  
 3rd Qu.: 4005   3rd Qu.:  967.0   3rd Qu.:12925   3rd Qu.:5050   3rd Qu.: 600.0   3rd Qu.:1700   3rd Qu.: 85.00  
 Max.   :31643   Max.   :21836.0   Max.   :21700   Max.   :8124   Max.   :2340.0   Max.   :6800   Max.   :103.00  
    Terminal       S.F.Ratio      perc.alumni        Expend        Grad.Rate     
 Min.   : 24.0   Min.   : 2.50   Min.   : 0.00   Min.   : 3186   Min.   : 10.00  
 1st Qu.: 71.0   1st Qu.:11.50   1st Qu.:13.00   1st Qu.: 6751   1st Qu.: 53.00  
 Median : 82.0   Median :13.60   Median :21.00   Median : 8377   Median : 65.00  
 Mean   : 79.7   Mean   :14.09   Mean   :22.74   Mean   : 9660   Mean   : 65.46  
 3rd Qu.: 92.0   3rd Qu.:16.50   3rd Qu.:31.00   3rd Qu.:10830   3rd Qu.: 78.00  
 Max.   :100.0   Max.   :39.80   Max.   :64.00   Max.   :56233   Max.   :118.00  
dtcollege# prints head and tail
                                 rn Private  Apps Accept Enroll Top10perc Top25perc F.Undergrad P.Undergrad Outstate
  1:   Abilene Christian University     Yes  1660   1232    721        23        52        2885         537     7440
  2:             Adelphi University     Yes  2186   1924    512        16        29        2683        1227    12280
  3:                 Adrian College     Yes  1428   1097    336        22        50        1036          99    11250
  4:            Agnes Scott College     Yes   417    349    137        60        89         510          63    12960
  5:      Alaska Pacific University     Yes   193    146     55        16        44         249         869     7560
 ---                                                                                                                
773:        Worcester State College      No  2197   1515    543         4        26        3089        2029     6797
774:              Xavier University     Yes  1959   1805    695        24        47        2849        1107    11520
775: Xavier University of Louisiana     Yes  2097   1915    695        34        61        2793         166     6900
776:                Yale University     Yes 10705   2453   1317        95        99        5217          83    19840
777:   York College of Pennsylvania     Yes  2989   1855    691        28        63        2988        1726     4990
     Room.Board Books Personal PhD Terminal S.F.Ratio perc.alumni Expend Grad.Rate
  1:       3300   450     2200  70       78      18.1          12   7041        60
  2:       6450   750     1500  29       30      12.2          16  10527        56
  3:       3750   400     1165  53       66      12.9          30   8735        54
  4:       5450   450      875  92       97       7.7          37  19016        59
  5:       4120   800     1500  76       72      11.9           2  10922        15
 ---                                                                              
773:       3900   500     1200  60       60      21.0          14   4469        40
774:       4960   600     1250  73       75      13.3          31   9189        83
775:       4200   617      781  67       75      14.4          20   8323        49
776:       6510   630     2115  96       96       5.8          49  40386        99
777:       3560   500     1250  75       75      18.1          28   4509        99

mysubset <- dtcollege[40:60]

mysubset[ , round(mean(Enroll),1) ]
[1] 597.9




dtcollege[ !Outstate %between% c(8000,14000) ]
                                  rn Private  Apps Accept Enroll Top10perc Top25perc F.Undergrad P.Undergrad Outstate
  1:    Abilene Christian University     Yes  1660   1232    721        23        52        2885         537     7440
  2:       Alaska Pacific University     Yes   193    146     55        16        44         249         869     7560
  3:                Albright College     Yes  1038    839    227        30        63         973         306    15595
  4:               Alfred University     Yes  1732   1425    472        37        75        1830         110    16548
  5:               Allegheny College     Yes  2652   1900    484        44        77        1707          44    17080
 ---                                                                                                                 
381: Worcester Polytechnic Institute     Yes  2768   2314    682        49        86        2802          86    15884
382:         Worcester State College      No  2197   1515    543         4        26        3089        2029     6797
383:  Xavier University of Louisiana     Yes  2097   1915    695        34        61        2793         166     6900
384:                 Yale University     Yes 10705   2453   1317        95        99        5217          83    19840
385:    York College of Pennsylvania     Yes  2989   1855    691        28        63        2988        1726     4990
     Room.Board Books Personal PhD Terminal S.F.Ratio perc.alumni Expend Grad.Rate
  1:       3300   450     2200  70       78      18.1          12   7041        60
  2:       4120   800     1500  76       72      11.9           2  10922        15
  3:       4400   300      500  79       84      11.3          23  11644        80
  4:       5406   500      600  82       88      11.3          31  10932        73
  5:       4440   400      600  73       91       9.9          41  11711        76
 ---                                                                              
381:       5370   530      730  92       94      15.2          34  10774        82
382:       3900   500     1200  60       60      21.0          14   4469        40
383:       4200   617      781  67       75      14.4          20   8323        49
384:       6510   630     2115  96       96       5.8          49  40386        99
385:       3560   500     1250  75       75      18.1          28   4509        99
# between operator includes the limits too
# dtcollege[ !(Outstate >= 8000 & Outstate <= 14000) ]




dtcollege[  head(order(-Top10perc),10)  ,  rn  ]
 [1] "Massachusetts Institute of Technology" "Harvey Mudd College"                  
 [3] "University of California at Berkeley"  "Yale University"                      
 [5] "Duke University"                       "Harvard University"                   
 [7] "Princeton University"                  "Georgia Institute of Technology"      
 [9] "Brown University"                      "Dartmouth College"                    

dtcollege[  ,  EAratio:=.(Enroll/Accept)  ][  head(order(-EAratio),10)  ,  .(rn,EAratio,Enroll,Accept)  ]
                                   rn   EAratio Enroll Accept
 1:    California Lutheran University 1.0000000    247    247
 2:            Brewton-Parker College 0.9788274   1202   1228
 3:  Mississippi University for Women 0.9382716    380    405
 4:                Peru State College 0.9141717    458    501
 5:       Indiana Wesleyan University 0.8652482    366    423
 6: Brigham Young University at Provo 0.8543132   4615   5402
 7:               Columbia College MO 0.8354430    132    158
 8:         Hardin-Simmons University 0.8254717    350    424
 9:              University of Mobile 0.8126888    269    331
10:         National-Louis University 0.8040346    279    347
# if you do not need the EAratio as a column in original data, then do as below
# dtcollege[  , { Y <- Enroll/Accept ; K <- order(-Y) ; head(cbind(.SD[K],ratio=Y[K]),10) }  ,  .SDcols=c("rn","Enroll","Accept")  ]

dtcollege[  Room.Board<4000  ][  head(order(S.F.Ratio),10)  ,  .(rn,S.F.Ratio,Room.Board)  ]
                               rn S.F.Ratio Room.Board
 1:      University of Charleston       2.5       3540
 2:         Siena Heights College       7.2       3880
 3:        University of the Arts       7.5       3860
 4: Marian College of Fond du Lac       8.4       3400
 5:    Wisconsin Lutheran College       8.5       3700
 6:             Bethel College KS       8.8       3580
 7:           Buena Vista College       8.8       3797
 8:    Tennessee Wesleyan College       8.9       3640
 9:           Christendom College       9.3       3600
10:             Albertson College       9.4       3335




college.gradnr <- dtcollege[  ,  .(rn,Apps,Accept,Enroll,F.Undergrad,P.Undergrad)  ,  ]
# below reorders the original, unspecified columns are moved to end preserving their order
# setcolorder(dtcollege, c("rn","Apps","Accept","Enroll","F.Undergrad","P.Undergrad"))




dtcollege[  Apps > 10000, HighInterest:=1L  ];tail(dtcollege)
                                rn Private  Apps Accept Enroll Top10perc Top25perc F.Undergrad P.Undergrad Outstate
1: Worcester Polytechnic Institute     Yes  2768   2314    682        49        86        2802          86    15884
2:         Worcester State College      No  2197   1515    543         4        26        3089        2029     6797
3:               Xavier University     Yes  1959   1805    695        24        47        2849        1107    11520
4:  Xavier University of Louisiana     Yes  2097   1915    695        34        61        2793         166     6900
5:                 Yale University     Yes 10705   2453   1317        95        99        5217          83    19840
6:    York College of Pennsylvania     Yes  2989   1855    691        28        63        2988        1726     4990
   Room.Board Books Personal PhD Terminal S.F.Ratio perc.alumni Expend Grad.Rate   EAratio HighInterest
1:       5370   530      730  92       94      15.2          34  10774        82 0.2947277           NA
2:       3900   500     1200  60       60      21.0          14   4469        40 0.3584158           NA
3:       4960   600     1250  73       75      13.3          31   9189        83 0.3850416           NA
4:       4200   617      781  67       75      14.4          20   8323        49 0.3629243           NA
5:       6510   630     2115  96       96       5.8          49  40386        99 0.5368936            1
6:       3560   500     1250  75       75      18.1          28   4509        99 0.3725067           NA
dtcollege[  , HighInterest:=.(Apps > 10000)  ]
dtcollege[  , HighInterest:=NULL  ]




# dtcollege[  , undergradratio:=.(F.Undergrad/P.Undergrad) ,  ][  head(order(-undergradratio),10)  ,  .(rn,undergradratio,F.Undergrad,P.Undergrad)  ]
dtcollege[  , .(rn, undergradratio = round(F.Undergrad/P.Undergrad,2), F.Undergrad, P.Undergrad)  ][  head(order(-undergradratio),10)  ]
                                   rn undergradratio F.Undergrad P.Undergrad
 1:                College of Wooster        1704.00        1704           1
 2:                    Kenyon College        1445.00        1445           1
 3:          Hampden - Sydney College         945.00         945           1
 4:         Claremont McKenna College         887.00         887           1
 5:     Washington and Lee University         528.00        1584           3
 6: Hobart and William Smith Colleges         358.40        1792           5
 7:                   Amherst College         318.60        1593           5
 8:                  Colorado College         270.29        1892           7
 9:  Rensselaer Polytechnic Institute         268.19        4291          16
10:                  Davidson College         266.83        1601           6



# dtcollege[  ,  sum(Expend>20000)  ,  ]
dtcollege[  Expend>20000  ,  .N  ]
[1] 28

# dtcollege[  ,  sum((Room.Board+Books)>7000)  ,  ]
dtcollege[  Room.Board+Books>7000  ,  .N  ]
[1] 37

dtcollege[  ,  .N  ,  by=Private  ]
   Private   N
1:     Yes 565
2:      No 212




setkey(dtcollege, F.Undergrad, P.Undergrad)

dtcollege[  F.Undergrad<1000 & P.Undergrad<100  ]
                                 rn Private Apps Accept Enroll Top10perc Top25perc F.Undergrad P.Undergrad Outstate
 1:             Christendom College     Yes   81     72     51        33        71         139           3     8730
 2:      Wisconsin Lutheran College     Yes  152    128     75        17        41         282          22     9100
 3:       Montreat-Anderson College     Yes  263    223    103        10        24         316          20     8438
 4:               McPherson College     Yes  420    293     93        11        32         336          80     7950
 5:                  Bethel College     Yes  502    384    104        11        28         347          74     6200
 6:       Mount Saint Clare College     Yes  325    284     95        16        33         364          88     9900
 7:                Huron University     Yes  600    197    124         3         9         392          69     7260
 8:              St. John's College     Yes  323    278    122        31        51         393           4    16150
 9:                   Tabor College     Yes  257    183    109        19        41         396          38     7850
10:                   Wells College     Yes  318    240    130        40        85         416          19    14900
11:               Blackburn College     Yes  500    336    156        25        55         421          27     6500
12:                Bradford College     Yes  443    330    151         5        36         453          42    14080
13:              Bennington College     Yes  519    327    114        25        53         457           2    21700
14:           Warren Wilson College     Yes  440    311    112        25        49         466           7    10000
15:                  Eureka College     Yes  560    454    113        36        56         484          16    10955
16:              Huntington College     Yes  450    430    125        20        46         488          43     9950
17:                    King College     Yes  355    300    142        34        65         509          44     8664
18:             Agnes Scott College     Yes  417    349    137        60        89         510          63    12960
19:               Schreiner College     Yes  584    413    131        19        51         521          99     8955
20:             Sweet Briar College     Yes  462    402    146        36        68         527          41    14500
21:                 Erskine College     Yes  659    557    167        47        74         532          35    10485
22:          Green Mountain College     Yes  780    628    198         7        20         545          42    11750
23:                    Dana College     Yes  504    482    185        10        36         550          84     9130
24:                  Judson College     Yes  313    228    137        10        30         552          67     9414
25:                 Scripps College     Yes  855    632    139        60        83         569           7    17238
26:             Phillips University     Yes  692    576    174        19        50         597          83    10500
27:                Newberry College     Yes  872    722    154        14        36         601          36    10194
28:              St. Paul's College     Yes  651    581    243         8        17         617          34     5000
29:             Livingstone College     Yes  900    473    217        22        47         621          11     4400
30:               MacMurray College     Yes  740    558    177        12        29         628          63     9620
31:                Union College KY     Yes  484    384    177         9        45         634          78     7800
32:                Piedmont College     Yes  663    562    127        20        40         641          63     5640
33:                Converse College     Yes  440    407    149        35        70         643          80    12050
34: North Carolina Wesleyan College     Yes  812    689    195         7        24         646          84     8242
35:  Randolph-Macon Woman's College     Yes  696    616    169        35        66         653          56    13970
36:             Harvey Mudd College     Yes 1377    572    178        95       100         654           5    17230
37:       Mayville State University      No  233    233    153         5        12         658          58     4486
38:          Westminster College MO     Yes  662    553    184        20        43         665          37    10720
39:             Monmouth College IL     Yes  601    503    204        28        57         671          11    13000
40:               Albertson College     Yes  587    479    158        38        62         678          41    13500
41:                Milligan College     Yes  610    461    189        26        52         685          49     8200
42:         Salem-Teikyo University     Yes  489    384    120        23        52         700          45    10575
43:                Voorhees College     Yes 1465   1006    188        10        30         703          20     4450
44:          Fresno Pacific College     Yes  346    274    146        51        87         704          63     9900
45:                 Bethany College     Yes  878    816    200        16        41         706          62     8740
46:              Antioch University     Yes  713    661    252        25        44         712          23    15476
47:                   Ripon College     Yes  587    501    211        28        52         735          28    15200
48:                   Keuka College     Yes  461    381    174        10        43         738          55     9600
49:                  Pitzer College     Yes 1133    630    220        37        73         750          30    17688
50:                Bluffton College     Yes  692    514    209        20        50         760          81     9900
    Room.Board Books Personal PhD Terminal S.F.Ratio perc.alumni Expend Grad.Rate   EAratio
 1:       3600   400      800  92       92       9.3          17  10922        58 0.7083333
 2:       3700   500     1400  48       48       8.5          26   8960        50 0.5859375
 3:       3372   500     2958  42       50      11.1           4  11989        15 0.4618834
 4:       3750   600     2740  54       54       9.8          45   9754        48 0.3174061
 5:       2900   600      800  63       63      11.7          13   7623        35 0.2708333
 6:       3650   500     1200  32       37      13.6          43   6525        21 0.3345070
 7:       3090   600     1840  31       35      12.9           4   9249        21 0.6294416
 8:       5450   275      800  63       72       7.2          26  15622        64 0.4388489
 9:       3410   400     1500  55       70      10.0          15   7233        53 0.5956284
10:       5550   600      500  93       98       8.3          42  13935        69 0.5416667
11:       2700   500     1000  76       76      14.3          53   8377        51 0.4642857
12:       6270   500      900  57       80      10.2          21  15387        46 0.4575758
13:       4100   600      500  35       59      10.1          33  16364        55 0.3486239
14:       3052   400     1100  65       75      11.4          20   9430        63 0.3601286
15:       3450   330      670  62       87      10.6          31   9552        53 0.2488987
16:       3920   300     1300  76       76      11.8          25   9466        47 0.2906977
17:       3350   600     3000  65       68      10.7          25   8954        65 0.4733333
18:       5450   450      875  92       97       7.7          37  19016        59 0.3925501
19:       5900   500     1488  51       56      11.8          23   8545        52 0.3171913
20:       6000   500      600  91       99       6.5          48  18953        61 0.3631841
21:       3840   475     1246  76       80      13.5          47   7527        67 0.2998205
22:       2700   400      850  77       83      14.0          24   6475        76 0.3152866
23:       3322   450     1450  46       51      12.6          25   8686        54 0.3838174
24:       4554   500     1700  34       55      10.6          30   7840        56 0.6008772
25:       7350   600      800  95      100       8.2          41  18372        73 0.2199367
26:       3860   600      940  58       64      11.6          19   8990        39 0.3020833
27:       2600   500     1500  57       63      11.4          32   5788        83 0.2132964
28:       3650   600      600  45       45      14.0           8   8426        45 0.4182444
29:       3400   800      900  53       93      10.4          16   9268        92 0.4587738
30:       3750   550      950  49       55      10.8          33  10642        59 0.3172043
31:       2950   500      600  60       88      14.1           9   6864        64 0.4609375
32:       3620   600      750  89       89      13.2          17   7309        31 0.2259786
33:       3700   500      900  63       76      10.2          31  10965        75 0.3660934
34:       4230   600     1295  77       77      12.7          11  10090        52 0.2830189
35:       6110   370      920  88       97       9.2          24  16358        68 0.2743506
36:       6690   700      900 100      100       8.2          46  21569       100 0.3111888
37:       2516   600     1900  68       68      15.7          11   6971        51 0.6566524
38:       4050   600     1650  66       70      12.5          20   7925        62 0.3327306
39:       4100   400      460  91       91      11.6          43  11087        56 0.4055666
40:       3335   500      675  67       73       9.4          11   9727        55 0.3298539
41:       3300   550     1000  63       69      12.0          16   8128        64 0.4099783
42:       3952   400      620  46       24      13.0           9   8946        98 0.3125000
43:       2522   500     1200  43       43      22.9           3   5861        58 0.1868787
44:       3670   630     1818  59       59      10.5          14   8095        54 0.5328467
45:       3363   550     1700  62       68      11.6          29   7718        48 0.2450980
46:       3336   400     1100  69       82      11.3          35  42926        48 0.3812405
47:       4100   350      650  87       90       9.4          49  12472        64 0.4211577
48:       4550   600      750  55       94      13.3          43   7863        51 0.4566929
49:       5900   650      850 100      100      10.4          11  14820        73 0.3492063
50:       3990   400      900  76       71      13.3          19   9073        58 0.4066148
 [ reached getOption("max.print") -- omitted 28 rows ]

dtcollege[  .(393,4)  ]
                   rn Private Apps Accept Enroll Top10perc Top25perc F.Undergrad P.Undergrad Outstate Room.Board Books
1: St. John's College     Yes  323    278    122        31        51         393           4    16150       5450   275
   Personal PhD Terminal S.F.Ratio perc.alumni Expend Grad.Rate   EAratio
1:      800  63       72       7.2          26  15622        64 0.4388489
# dtcollege[  F.Undergrad==393 & P.Undergrad==4  ]




#  dtcollege[  ,  .SD  ,  .SDcols=!c("Apps","Accept","Enroll")  ]
dtcollege[  ,  !c("Apps","Accept","Enroll")  ]
                                       rn Private Top10perc Top25perc F.Undergrad P.Undergrad Outstate Room.Board Books
  1:                  Christendom College     Yes        33        71         139           3     8730       3600   400
  2:                       Wilson College     Yes        16        50         199         676    11428       5084   450
  3:                College of St. Joseph     Yes        12        21         201         173     8300       4850   450
  4:            Alaska Pacific University     Yes        16        44         249         869     7560       4120   800
  5:           Wisconsin Lutheran College     Yes        17        41         282          22     9100       3700   500
 ---                                                                                                                   
773:            Michigan State University      No        23        57       26640        4120    10658       3734   504
774:    Brigham Young University at Provo     Yes        48        82       27378        1253     2340       3580   860
775: Pennsylvania State Univ. Main Campus      No        48        93       28938        2025    10645       4060   512
776:        University of Texas at Austin      No        48        85       30017        5189     5130       3309   650
777:   Texas A&M Univ. at College Station      No        49        85       31643        2798     5130       3412   600
     Personal PhD Terminal S.F.Ratio perc.alumni Expend Grad.Rate   EAratio
  1:      800  92       92       9.3          17  10922        58 0.7083333
  2:      475  67       76       8.3          43  10291        67 0.3538462
  3:     1300  53       53       9.5          19   6936        76 0.4661017
  4:     1500  76       72      11.9           2  10922        15 0.3767123
  5:     1400  48       48       8.5          26   8960        50 0.5859375
 ---                                                                       
773:      600  93       95      14.0           9  10520        71 0.4093800
774:     1220  76       76      20.5          40   7916        33 0.8543132
775:     2394  77       96      18.1          19   8992        63 0.3335267
776:     3140  91       99      19.7          11   7837        65 0.5567280
777:     2144  89       91      23.1          29   8471        69 0.6076623
dtcollege[  ,  -c("Apps","Accept","Enroll")  ]
                                       rn Private Top10perc Top25perc F.Undergrad P.Undergrad Outstate Room.Board Books
  1:                  Christendom College     Yes        33        71         139           3     8730       3600   400
  2:                       Wilson College     Yes        16        50         199         676    11428       5084   450
  3:                College of St. Joseph     Yes        12        21         201         173     8300       4850   450
  4:            Alaska Pacific University     Yes        16        44         249         869     7560       4120   800
  5:           Wisconsin Lutheran College     Yes        17        41         282          22     9100       3700   500
 ---                                                                                                                   
773:            Michigan State University      No        23        57       26640        4120    10658       3734   504
774:    Brigham Young University at Provo     Yes        48        82       27378        1253     2340       3580   860
775: Pennsylvania State Univ. Main Campus      No        48        93       28938        2025    10645       4060   512
776:        University of Texas at Austin      No        48        85       30017        5189     5130       3309   650
777:   Texas A&M Univ. at College Station      No        49        85       31643        2798     5130       3412   600
     Personal PhD Terminal S.F.Ratio perc.alumni Expend Grad.Rate   EAratio
  1:      800  92       92       9.3          17  10922        58 0.7083333
  2:      475  67       76       8.3          43  10291        67 0.3538462
  3:     1300  53       53       9.5          19   6936        76 0.4661017
  4:     1500  76       72      11.9           2  10922        15 0.3767123
  5:     1400  48       48       8.5          26   8960        50 0.5859375
 ---                                                                       
773:      600  93       95      14.0           9  10520        71 0.4093800
774:     1220  76       76      20.5          40   7916        33 0.8543132
775:     2394  77       96      18.1          19   8992        63 0.3335267
776:     3140  91       99      19.7          11   7837        65 0.5567280
777:     2144  89       91      23.1          29   8471        69 0.6076623

dtcollege[  ,  Apps:Enroll  ]
      Apps Accept Enroll
  1:    81     72     51
  2:   167    130     46
  3:   141    118     55
  4:   193    146     55
  5:   152    128     75
 ---                    
773: 18114  15096   6180
774:  7365   5402   4615
775: 19315  10344   3450
776: 14752   9572   5329
777: 14474  10519   6392
dtcollege[  ,  3:5  ]
      Apps Accept Enroll
  1:    81     72     51
  2:   167    130     46
  3:   141    118     55
  4:   193    146     55
  5:   152    128     75
 ---                    
773: 18114  15096   6180
774:  7365   5402   4615
775: 19315  10344   3450
776: 14752   9572   5329
777: 14474  10519   6392
dtcollege[  ,  .(Apps,Accept,Enroll)  ]
      Apps Accept Enroll
  1:    81     72     51
  2:   167    130     46
  3:   141    118     55
  4:   193    146     55
  5:   152    128     75
 ---                    
773: 18114  15096   6180
774:  7365   5402   4615
775: 19315  10344   3450
776: 14752   9572   5329
777: 14474  10519   6392




dtcollege[  Apps<800 & Top10perc>40  ,  .N  ]
[1] 9

dtcollege[  Apps<900 & Outstate<10000 & Top10perc>30  ,  .N  ]
[1] 13

dtcollege[  Apps<1000 & (Top10perc>20 | Top25perc>30)  ,  .N  ]
[1] 234
```
