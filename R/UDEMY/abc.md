```R
Lures Example Script
Error: unexpected symbol in "Lures Example"

### Cleaning a standard csv file - LureSales


summary(lures)
   Category           Product              Sales            Profit        
 Length:1001        Length:1001        Min.   :  4.25   Min.   :    2.61  
 Class :character   Class :character   1st Qu.: 27.00   1st Qu.:   11.94  
 Mode  :character   Mode  :character   Median : 51.12   Median :   21.63  
                                       Mean   : 55.11   Mean   :   68.97  
                                       3rd Qu.: 76.68   3rd Qu.:   37.86  
                                       Max.   :174.25   Max.   :32423.40  
                                       NA's   :1        NA's   :3         
  FirstName           LastName              Date           
 Length:1001        Length:1001        Min.   :2012-01-05  
 Class :character   Class :character   1st Qu.:2013-06-19  
 Mode  :character   Mode  :character   Median :2014-08-16  
                                       Mean   :2014-05-29  
                                       3rd Qu.:2015-06-19  
                                       Max.   :2016-01-03  
                                                           


# Converting Category to factor

lures$Category <- as.factor(lures$Category)


# Check the Category column

summary(lures)
  Category     Product              Sales            Profit          FirstName        
 Lake :368   Length:1001        Min.   :  4.25   Min.   :    2.61   Length:1001       
 Ocean:151   Class :character   1st Qu.: 27.00   1st Qu.:   11.94   Class :character  
 River:481   Mode  :character   Median : 51.12   Median :   21.63   Mode  :character  
 NA's :  1                      Mean   : 55.11   Mean   :   68.97                     
                                3rd Qu.: 76.68   3rd Qu.:   37.86                     
                                Max.   :174.25   Max.   :32423.40                     
                                NA's   :1        NA's   :3                            
   LastName              Date           
 Length:1001        Min.   :2012-01-05  
 Class :character   1st Qu.:2013-06-19  
 Mode  :character   Median :2014-08-16  
                    Mean   :2014-05-29  
                    3rd Qu.:2015-06-19  
                    Max.   :2016-01-03  
                                        


library(tidyr) # unite function


lures = unite(lures, col = "Name",
+               
+               c("FirstName", "LastName"), sep = " ")


# How does the end of the dataset look?

tail(lures) # problem in last observation
# A tibble: 6 x 6
  Category Product        Sales Profit Name           Date      
  <fct   <chr         <dbl <dbl<chr         <date   
1 River    Steelhead Iron  72.8   12.1 Laura KELLY    2013-06-06
2 River    Minnow Glitter  32.4   19.4 Laura MITCHELL 2013-06-06
3 River    Minnow Glitter  91.8   39.4 Mark KELLY     2015-12-19
4 River    Steelhead Iron  61.6   37.8 Deanra ADAMS   2014-06-20
5 River    Steelhead Iron  78.4   43.4 Alan COLLINS   2013-10-15
6 NA       NA              NA     NA   NA KING        2013-10-15


lures <- lures[1:1000,]


tail(lures)
# A tibble: 6 x 6
  Category Product        Sales Profit Name           Date      
  <fct   <chr         <dbl <dbl<chr         <date   
1 River    Minnow Glitter  10.8   12.1 Anthony TAYLOR 2013-09-06
2 River    Steelhead Iron  72.8   12.1 Laura KELLY    2013-06-06
3 River    Minnow Glitter  32.4   19.4 Laura MITCHELL 2013-06-06
4 River    Minnow Glitter  91.8   39.4 Mark KELLY     2015-12-19
5 River    Steelhead Iron  61.6   37.8 Deanra ADAMS   2014-06-20
6 River    Steelhead Iron  78.4   43.4 Alan COLLINS   2013-10-15


# Outlier detection - Boxplot

boxplot(lures$Profit)


library(outliers)


# Depending on the Boxplot we need to run this several times

lures$Profit <- rm.outlier(lures$Profit,
+                            
+                            fill = T, median = T)


boxplot(lures$Profit) # Check the column


library(Hmisc)


lures$Profit <- impute(lures$Profit, median)


summary(lures$Profit)

 3 values imputed to 21.6058 

    Min.  1st Qu.   Median     Mean  3rd Qu.     Max. 
   2.605   11.978   21.606   36.470   37.761 5442.300 


lures$Profit <- round(lures$Profit, digits = 2)


# Queries on the dataset


library(data.table)

lurestable <- data.table(lures)


class(lurestable)
[1] "data.table" "data.frame"


# How many instances with a profit above 65$ ?

lurestable[Profit 65, .N]
[1] 43



# How much profit by Category ?

lurestable[, sum(Profit), by = Category]
   Category       V1
1:     Lake 15493.78
2:    Ocean  5627.03
3:    River 15348.68
```
