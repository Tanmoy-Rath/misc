```R
> Lures Example Script
Error: unexpected symbol in "Lures Example"
> 
> ### Cleaning a standard csv file - LureSales
> 
> 
> summary(lures)
  Category     Product              Sales            Profit           Name          
 Lake :368   Length:1000        Min.   :  4.25   Min.   :  2.61   Length:1000       
 Ocean:151   Class :character   1st Qu.: 27.00   1st Qu.: 11.98   Class :character  
 River:481   Mode  :character   Median : 51.12   Median : 21.59   Mode  :character  
                                Mean   : 55.11   Mean   : 26.74                     
                                3rd Qu.: 76.68   3rd Qu.: 37.72                     
                                Max.   :174.25   Max.   :103.06                     
      Date           
 Min.   :2012-01-05  
 1st Qu.:2013-06-19  
 Median :2014-08-18  
 Mean   :2014-05-29  
 3rd Qu.:2015-06-19  
 Max.   :2016-01-03  
> 
> 
> # Converting Category to factor
> 
> lures$Category <- as.factor(lures$Category)
> 
> 
> # Check the Category column
> 
> summary(lures)
  Category     Product              Sales            Profit           Name          
 Lake :368   Length:1000        Min.   :  4.25   Min.   :  2.61   Length:1000       
 Ocean:151   Class :character   1st Qu.: 27.00   1st Qu.: 11.98   Class :character  
 River:481   Mode  :character   Median : 51.12   Median : 21.59   Mode  :character  
                                Mean   : 55.11   Mean   : 26.74                     
                                3rd Qu.: 76.68   3rd Qu.: 37.72                     
                                Max.   :174.25   Max.   :103.06                     
      Date           
 Min.   :2012-01-05  
 1st Qu.:2013-06-19  
 Median :2014-08-18  
 Mean   :2014-05-29  
 3rd Qu.:2015-06-19  
 Max.   :2016-01-03  
> 
> 
> library(tidyr) # unite function
> 
> 
> lures = unite(lures, col = "Name",
+               
+               c("FirstName", "LastName"), sep = " ")
Error: Unknown column `FirstName` 
Call `rlang::last_error()` to see a backtrace
> 
> 
> # How does the end of the dataset look?
> 
> tail(lures) # problem in last observation
# A tibble: 6 x 6
  Category Product        Sales Profit Name           Date      
  <fct>    <chr>          <dbl>  <dbl> <chr>          <date>    
1 River    Minnow Glitter  10.8   12.1 Anthony TAYLOR 2013-09-06
2 River    Steelhead Iron  72.8   12.1 Laura KELLY    2013-06-06
3 River    Minnow Glitter  32.4   19.4 Laura MITCHELL 2013-06-06
4 River    Minnow Glitter  91.8   39.4 Mark KELLY     2015-12-19
5 River    Steelhead Iron  61.6   37.8 Deanra ADAMS   2014-06-20
6 River    Steelhead Iron  78.4   43.4 Alan COLLINS   2013-10-15
> 
> 
> lures <- lures[1:1000,]
> 
> 
> tail(lures)
# A tibble: 6 x 6
  Category Product        Sales Profit Name           Date      
  <fct>    <chr>          <dbl>  <dbl> <chr>          <date>    
1 River    Minnow Glitter  10.8   12.1 Anthony TAYLOR 2013-09-06
2 River    Steelhead Iron  72.8   12.1 Laura KELLY    2013-06-06
3 River    Minnow Glitter  32.4   19.4 Laura MITCHELL 2013-06-06
4 River    Minnow Glitter  91.8   39.4 Mark KELLY     2015-12-19
5 River    Steelhead Iron  61.6   37.8 Deanra ADAMS   2014-06-20
6 River    Steelhead Iron  78.4   43.4 Alan COLLINS   2013-10-15
> 
> 
> # Outlier detection - Boxplot
> 
> boxplot(lures$Profit)
> 
> 
> library(outliers)
> 
> 
> # Depending on the Boxplot we need to run this several times
> 
> lures$Profit <- rm.outlier(lures$Profit,
+                            
+                            fill = T, median = T)
> 
> 
> boxplot(lures$Profit) # Check the column
> 
> 
> library(Hmisc)
Loading required package: lattice
Loading required package: survival
Loading required package: Formula
Loading required package: ggplot2

Attaching package: ‘Hmisc’

The following objects are masked from ‘package:base’:

    format.pval, units

> 
> 
> lures$Profit <- impute(lures$Profit, median)
> 
> 
> summary(lures$Profit)
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max. 
   2.61   11.98   21.59   26.57   37.59   89.52 
> 
> 
> lures$Profit <- round(lures$Profit, digits = 2)
> 
> 
> # Queries on the dataset
> 
> 
> library(data.table)
data.table 1.12.2 using 2 threads (see ?getDTthreads).  Latest news: r-datatable.com
> 
> lurestable <- data.table(lures)
> 
> 
> class(lurestable)
[1] "data.table" "data.frame"
> 
> 
> # How many instances with a profit above 65$ ?
> 
> lurestable[Profit > 65, .N]
[1] 39
> 
> 
> 
> # How much profit by Category ?
> 
> lurestable[, sum(Profit), by = Category]
   Category       V1
1:     Lake 10073.07
2:    Ocean  5464.09
3:    River 11035.76
> 
```
