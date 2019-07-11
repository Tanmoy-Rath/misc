```R
Script: Data cleaning
Error: unexpected symbol in "Script: Data cleaning"

### Cleaning your data - Restructuring with tidyr

library(tidyr)

library(dplyr) # also activate dplyr since it has helpful add on fuctions

Attaching package: ‘dplyr’

The following objects are masked from ‘package:stats’:

    filter, lag

The following objects are masked from ‘package:base’:

    intersect, setdiff, setequal, union


# import as csv, make sure to have heading activated
# if there is no heading R might not recognize all columns

bugs = Bug.Frequency # easier to code

head(bugs)
        region X..10.g X10...20.g X20...30.g X30...40.g X..40.g
1  Welsh Creek       5         34         54         23       8
2    River Inn      72         33         28         35       9
3  Spur Forest      34         65         23         67       2
4 Hamock Flats      28         23         34         45      11
5   Gelb Rocks      34         68         23         58       9

# lets redo the header line since the import worked poorly
names(bugs) <- c("Region", "<10 g", "10-20 g", "20-30 g", "30-40 g", ">40 g")

bugs
        Region <10 g 10-20 g 20-30 g 30-40 g >40 g
1  Welsh Creek     5      34      54      23     8
2    River Inn    72      33      28      35     9
3  Spur Forest    34      65      23      67     2
4 Hamock Flats    28      23      34      45    11
5   Gelb Rocks    34      68      23      58     9

?gather

# now we can convert to long form
gather(data = bugs, key = weight, value = counts, -Region)
         Region  weight counts
1   Welsh Creek   <10 g      5
2     River Inn   <10 g     72
3   Spur Forest   <10 g     34
4  Hamock Flats   <10 g     28
5    Gelb Rocks   <10 g     34
6   Welsh Creek 10-20 g     34
7     River Inn 10-20 g     33
8   Spur Forest 10-20 g     65
9  Hamock Flats 10-20 g     23
10   Gelb Rocks 10-20 g     68
11  Welsh Creek 20-30 g     54
12    River Inn 20-30 g     28
13  Spur Forest 20-30 g     23
14 Hamock Flats 20-30 g     34
15   Gelb Rocks 20-30 g     23
16  Welsh Creek 30-40 g     23
17    River Inn 30-40 g     35
18  Spur Forest 30-40 g     67
19 Hamock Flats 30-40 g     45
20   Gelb Rocks 30-40 g     58
21  Welsh Creek   >40 g      8
22    River Inn   >40 g      9
23  Spur Forest   >40 g      2
24 Hamock Flats   >40 g     11
25   Gelb Rocks   >40 g      9
# we are specifying the dataset, our key are the different weights in one column
# we put all the counts in 1 column, and we suppress a gathering of Region



# we can store it as a table
bugs.table = tbl_df(gather(data = bugs, key = weight, value = counts, -Region))

# we can of course change the order with the arrange function
arrange(bugs.table, Region)
# A tibble: 25 x 3
   Region       weight  counts
   <fct       <chr   <int>
 1 Gelb Rocks   <10 g       34
 2 Gelb Rocks   10-20 g     68
 3 Gelb Rocks   20-30 g     23
 4 Gelb Rocks   30-40 g     58
 5 Gelb Rocks   >40 g        9
 6 Hamock Flats <10 g       28
 7 Hamock Flats 10-20 g     23
 8 Hamock Flats 20-30 g     34
 9 Hamock Flats 30-40 g     45
10 Hamock Flats >40 g       11
# ... with 15 more rows

## alternative with package reshape2

library(reshape2)

Attaching package: ‘reshape2’

The following object is masked from ‘package:tidyr’:

    smiths


bugs.melt = melt(data = bugs, measure.vars = c(2:6), # here we use col IDs
+                  variable.name = "weight",
+                  value.name = "counts"); bugs.melt
         Region  weight counts
1   Welsh Creek   <10 g      5
2     River Inn   <10 g     72
3   Spur Forest   <10 g     34
4  Hamock Flats   <10 g     28
5    Gelb Rocks   <10 g     34
6   Welsh Creek 10-20 g     34
7     River Inn 10-20 g     33
8   Spur Forest 10-20 g     65
9  Hamock Flats 10-20 g     23
10   Gelb Rocks 10-20 g     68
11  Welsh Creek 20-30 g     54
12    River Inn 20-30 g     28
13  Spur Forest 20-30 g     23
14 Hamock Flats 20-30 g     34
15   Gelb Rocks 20-30 g     23
16  Welsh Creek 30-40 g     23
17    River Inn 30-40 g     35
18  Spur Forest 30-40 g     67
19 Hamock Flats 30-40 g     45
20   Gelb Rocks 30-40 g     58
21  Welsh Creek   >40 g      8
22    River Inn   >40 g      9
23  Spur Forest   >40 g      2
24 Hamock Flats   >40 g     11
25   Gelb Rocks   >40 g      9

## too much information in 1 column

age.sex <- data.frame(
+         name = c("Paul", "Kim", "Nora", "Sue", "Paul", "Kim"),
+         biometrics = c("179m", "173f", "174f", "159f", "188m", "163f"),
+         measurement = rnorm(6)); age.sex
  name biometrics measurement
1 Paul       179m   1.1569045
2  Kim       173f   0.7179864
3 Nora       174f   1.1045040
4  Sue       159f  -0.1905366
5 Paul       188m   0.1516832
6  Kim       163f   0.6769356

# here the column biometrics contains height in cm and sex at the same time
# this requires separation in many cases

# we can use separate to split the biometrics column in 2
separate(data = age.sex, col = biometrics,
+          into = c("height", "sex"), 3)
  name height sex measurement
1 Paul    179   m   1.1569045
2  Kim    173   f   0.7179864
3 Nora    174   f   1.1045040
4  Sue    159   f  -0.1905366
5 Paul    188   m   0.1516832
6  Kim    163   f   0.6769356
# number 3 indicates split, pos starts from left, - from right

# What can you do if you have two variables in the same column
# going from long form to wide form

sports <- data.frame(
+         name = c("Paul", "Paul", "Nora", "Nora", "Kim", "Kim"),
+         performance = c("top", "low", "top", "low", "top", "low"),
+         counts = c(11,3,18,2,9,1)); sports
  name performance counts
1 Paul         top     11
2 Paul         low      3
3 Nora         top     18
4 Nora         low      2
5  Kim         top      9
6  Kim         low      1

# here we have 2 variables the top and low performance in 1 column
# how do we split it up?

spread(data=sports, key = performance, value = counts)
  name low top
1  Kim   1   9
2 Nora   2  18
3 Paul   3  11

## lets check the alternative from the reshape2 package

# the argument names differ a bit, but the function structure looks very similar
dcast(data = sports, name ~ performance, value.var = "counts" )
  name low top
1  Kim   1   9
2 Nora   2  18
3 Paul   3  11
```
