```R
Data.frame Exercise Script
Error: unexpected symbol in "Data.frame Exercise"

# 1. Working with the iris dataset


# a. Get all rows of Species "versicolor" in a new dataframe, call this dataframe: iris.vers

iris.vers = subset(iris, Species == "versicolor"); iris.vers
    Sepal.Length Sepal.Width Petal.Length Petal.Width    Species
51           7.0         3.2          4.7         1.4 versicolor
52           6.4         3.2          4.5         1.5 versicolor
53           6.9         3.1          4.9         1.5 versicolor
54           5.5         2.3          4.0         1.3 versicolor
55           6.5         2.8          4.6         1.5 versicolor
56           5.7         2.8          4.5         1.3 versicolor
57           6.3         3.3          4.7         1.6 versicolor
58           4.9         2.4          3.3         1.0 versicolor
59           6.6         2.9          4.6         1.3 versicolor
60           5.2         2.7          3.9         1.4 versicolor
61           5.0         2.0          3.5         1.0 versicolor
62           5.9         3.0          4.2         1.5 versicolor
63           6.0         2.2          4.0         1.0 versicolor
64           6.1         2.9          4.7         1.4 versicolor
65           5.6         2.9          3.6         1.3 versicolor
66           6.7         3.1          4.4         1.4 versicolor
67           5.6         3.0          4.5         1.5 versicolor
68           5.8         2.7          4.1         1.0 versicolor
69           6.2         2.2          4.5         1.5 versicolor
70           5.6         2.5          3.9         1.1 versicolor
71           5.9         3.2          4.8         1.8 versicolor
72           6.1         2.8          4.0         1.3 versicolor
73           6.3         2.5          4.9         1.5 versicolor
74           6.1         2.8          4.7         1.2 versicolor
75           6.4         2.9          4.3         1.3 versicolor
76           6.6         3.0          4.4         1.4 versicolor
77           6.8         2.8          4.8         1.4 versicolor
78           6.7         3.0          5.0         1.7 versicolor
79           6.0         2.9          4.5         1.5 versicolor
80           5.7         2.6          3.5         1.0 versicolor
81           5.5         2.4          3.8         1.1 versicolor
82           5.5         2.4          3.7         1.0 versicolor
83           5.8         2.7          3.9         1.2 versicolor
84           6.0         2.7          5.1         1.6 versicolor
85           5.4         3.0          4.5         1.5 versicolor
86           6.0         3.4          4.5         1.6 versicolor
87           6.7         3.1          4.7         1.5 versicolor
88           6.3         2.3          4.4         1.3 versicolor
89           5.6         3.0          4.1         1.3 versicolor
90           5.5         2.5          4.0         1.3 versicolor
91           5.5         2.6          4.4         1.2 versicolor
92           6.1         3.0          4.6         1.4 versicolor
93           5.8         2.6          4.0         1.2 versicolor
94           5.0         2.3          3.3         1.0 versicolor
95           5.6         2.7          4.2         1.3 versicolor
96           5.7         3.0          4.2         1.2 versicolor
97           5.7         2.9          4.2         1.3 versicolor
98           6.2         2.9          4.3         1.3 versicolor
99           5.1         2.5          3.0         1.1 versicolor
100          5.7         2.8          4.1         1.3 versicolor


# b. Get a vector called "sepal.dif" with the difference between Sepal.Length and Sepal.Width of versicolor plants

sepal.dif = iris.vers$Sepal.Length - iris.vers$Sepal.Width; sepal.dif
 [1] 3.8 3.2 3.8 3.2 3.7 2.9 3.0 2.5 3.7 2.5 3.0 2.9 3.8 3.2 2.7 3.6 2.6 3.1 4.0 3.1 2.7 3.3 3.8 3.3 3.5 3.6 4.0 3.7
[29] 3.1 3.1 3.1 3.1 3.1 3.3 2.4 2.6 3.6 4.0 2.6 3.0 2.9 3.1 3.2 2.7 2.9 2.7 2.8 3.3 2.6 2.9


# c. Update (add) iris.vers with the new column (sepal.dif)

iris.vers = data.frame(iris.vers, sepal.dif); head(iris.vers)
   Sepal.Length Sepal.Width Petal.Length Petal.Width    Species sepal.dif
51          7.0         3.2          4.7         1.4 versicolor       3.8
52          6.4         3.2          4.5         1.5 versicolor       3.2
53          6.9         3.1          4.9         1.5 versicolor       3.8
54          5.5         2.3          4.0         1.3 versicolor       3.2
55          6.5         2.8          4.6         1.5 versicolor       3.7
56          5.7         2.8          4.5         1.3 versicolor       2.9



# 2. Classes of Variables (mtcars)


# a. Check the class of each variable in mtcars

head(mtcars)
                   mpg cyl disp  hp drat    wt  qsec vs am gear carb
Mazda RX4         21.0   6  160 110 3.90 2.620 16.46  0  1    4    4
Mazda RX4 Wag     21.0   6  160 110 3.90 2.875 17.02  0  1    4    4
Datsun 710        22.8   4  108  93 3.85 2.320 18.61  1  1    4    1
Hornet 4 Drive    21.4   6  258 110 3.08 3.215 19.44  1  0    3    1
Hornet Sportabout 18.7   8  360 175 3.15 3.440 17.02  0  0    3    2
Valiant           18.1   6  225 105 2.76 3.460 20.22  1  0    3    1

sapply(mtcars, class)
      mpg       cyl      disp        hp      drat        wt      qsec        vs        am      gear      carb 
"numeric" "numeric" "numeric" "numeric" "numeric" "numeric" "numeric" "numeric" "numeric" "numeric" "numeric" 


# b. Change am, cyl and vs to integer and store the new dataset as newmtc

attach(mtcars)

newmtc = data.frame(mpg, cyl = as.integer(cyl),
+                     
+                     disp, hp, drat, wt, qsec,
+                     
+                     vs = as.integer(vs), am = as.integer(am),
+                     
+                     gear, carb)


sapply(newmtc, class)
      mpg       cyl      disp        hp      drat        wt      qsec        vs        am      gear      carb 
"numeric" "integer" "numeric" "numeric" "numeric" "numeric" "numeric" "integer" "integer" "numeric" "numeric" 


# c. Round the newmtc dataframe to 1 digit

round(newmtc, 1)
    mpg cyl  disp  hp drat  wt qsec vs am gear carb
1  21.0   6 160.0 110  3.9 2.6 16.5  0  1    4    4
2  21.0   6 160.0 110  3.9 2.9 17.0  0  1    4    4
3  22.8   4 108.0  93  3.8 2.3 18.6  1  1    4    1
4  21.4   6 258.0 110  3.1 3.2 19.4  1  0    3    1
5  18.7   8 360.0 175  3.1 3.4 17.0  0  0    3    2
6  18.1   6 225.0 105  2.8 3.5 20.2  1  0    3    1
7  14.3   8 360.0 245  3.2 3.6 15.8  0  0    3    4
8  24.4   4 146.7  62  3.7 3.2 20.0  1  0    4    2
9  22.8   4 140.8  95  3.9 3.1 22.9  1  0    4    2
10 19.2   6 167.6 123  3.9 3.4 18.3  1  0    4    4
11 17.8   6 167.6 123  3.9 3.4 18.9  1  0    4    4
12 16.4   8 275.8 180  3.1 4.1 17.4  0  0    3    3
13 17.3   8 275.8 180  3.1 3.7 17.6  0  0    3    3
14 15.2   8 275.8 180  3.1 3.8 18.0  0  0    3    3
15 10.4   8 472.0 205  2.9 5.2 18.0  0  0    3    4
16 10.4   8 460.0 215  3.0 5.4 17.8  0  0    3    4
17 14.7   8 440.0 230  3.2 5.3 17.4  0  0    3    4
18 32.4   4  78.7  66  4.1 2.2 19.5  1  1    4    1
19 30.4   4  75.7  52  4.9 1.6 18.5  1  1    4    2
20 33.9   4  71.1  65  4.2 1.8 19.9  1  1    4    1
21 21.5   4 120.1  97  3.7 2.5 20.0  1  0    3    1
22 15.5   8 318.0 150  2.8 3.5 16.9  0  0    3    2
23 15.2   8 304.0 150  3.1 3.4 17.3  0  0    3    2
24 13.3   8 350.0 245  3.7 3.8 15.4  0  0    3    4
25 19.2   8 400.0 175  3.1 3.8 17.1  0  0    3    2
26 27.3   4  79.0  66  4.1 1.9 18.9  1  1    4    1
27 26.0   4 120.3  91  4.4 2.1 16.7  0  1    5    2
28 30.4   4  95.1 113  3.8 1.5 16.9  1  1    5    2
29 15.8   8 351.0 264  4.2 3.2 14.5  0  1    5    4
30 19.7   6 145.0 175  3.6 2.8 15.5  0  1    5    6
31 15.0   8 301.0 335  3.5 3.6 14.6  0  1    5    8
32 21.4   4 121.0 109  4.1 2.8 18.6  1  1    4    2



# 3. Advanced filtering of iris


# a. Use dplyr to filter for all data of Species "virginica" with a

# Sepal.Width of greater 3.5

library(dplyr)

Attaching package: ‘dplyr’

The following objects are masked from ‘package:stats’:

    filter, lag

The following objects are masked from ‘package:base’:

    intersect, setdiff, setequal, union


filter(iris, Sepal.Width 3.5, Species =="virginica")
  Sepal.Length Sepal.Width Petal.Length Petal.Width   Species
1          7.2         3.6          6.1         2.5 virginica
2          7.7         3.8          6.7         2.2 virginica
3          7.9         3.8          6.4         2.0 virginica


# b. How would you use R Base to get a dataframe of

# all data of Species "virginica" with a Sepal.Width of greater 3.5

# but without the last column Species in the dataframe?

iris[iris$Species == "virginica" & iris$Sepal.Width 3.5, 1:4]
    Sepal.Length Sepal.Width Petal.Length Petal.Width
110          7.2         3.6          6.1         2.5
118          7.7         3.8          6.7         2.2
132          7.9         3.8          6.4         2.0


# c. Get the row IDs of the rows matching the 2 filtering criteria provided above

row.names(iris[iris$Species == "virginica" & iris$Sepal.Width 3.5, 1:4])
[1] "110" "118" "132"



# 4. Manipulating dataframes at column level, dataset = iris


# a. Repeat each value of Sepal.Length and repeat the whole sequence as well

rep(iris$Sepal.Length, each = 2, times = 2)
  [1] 5.1 5.1 4.9 4.9 4.7 4.7 4.6 4.6 5.0 5.0 5.4 5.4 4.6 4.6 5.0 5.0 4.4 4.4 4.9 4.9 5.4 5.4 4.8 4.8 4.8 4.8 4.3
 [28] 4.3 5.8 5.8 5.7 5.7 5.4 5.4 5.1 5.1 5.7 5.7 5.1 5.1 5.4 5.4 5.1 5.1 4.6 4.6 5.1 5.1 4.8 4.8 5.0 5.0 5.0 5.0
 [55] 5.2 5.2 5.2 5.2 4.7 4.7 4.8 4.8 5.4 5.4 5.2 5.2 5.5 5.5 4.9 4.9 5.0 5.0 5.5 5.5 4.9 4.9 4.4 4.4 5.1 5.1 5.0
 [82] 5.0 4.5 4.5 4.4 4.4 5.0 5.0 5.1 5.1 4.8 4.8 5.1 5.1 4.6 4.6 5.3 5.3 5.0 5.0 7.0 7.0 6.4 6.4 6.9 6.9 5.5 5.5
[109] 6.5 6.5 5.7 5.7 6.3 6.3 4.9 4.9 6.6 6.6 5.2 5.2 5.0 5.0 5.9 5.9 6.0 6.0 6.1 6.1 5.6 5.6 6.7 6.7 5.6 5.6 5.8
[136] 5.8 6.2 6.2 5.6 5.6 5.9 5.9 6.1 6.1 6.3 6.3 6.1 6.1 6.4 6.4 6.6 6.6 6.8 6.8 6.7 6.7 6.0 6.0 5.7 5.7 5.5 5.5
[163] 5.5 5.5 5.8 5.8 6.0 6.0 5.4 5.4 6.0 6.0 6.7 6.7 6.3 6.3 5.6 5.6 5.5 5.5 5.5 5.5 6.1 6.1 5.8 5.8 5.0 5.0 5.6
[190] 5.6 5.7 5.7 5.7 5.7 6.2 6.2 5.1 5.1 5.7 5.7 6.3 6.3 5.8 5.8 7.1 7.1 6.3 6.3 6.5 6.5 7.6 7.6 4.9 4.9 7.3 7.3
[217] 6.7 6.7 7.2 7.2 6.5 6.5 6.4 6.4 6.8 6.8 5.7 5.7 5.8 5.8 6.4 6.4 6.5 6.5 7.7 7.7 7.7 7.7 6.0 6.0 6.9 6.9 5.6
[244] 5.6 7.7 7.7 6.3 6.3 6.7 6.7 7.2 7.2 6.2 6.2 6.1 6.1 6.4 6.4 7.2 7.2 7.4 7.4 7.9 7.9 6.4 6.4 6.3 6.3 6.1 6.1
[271] 7.7 7.7 6.3 6.3 6.4 6.4 6.0 6.0 6.9 6.9 6.7 6.7 6.9 6.9 5.8 5.8 6.8 6.8 6.7 6.7 6.7 6.7 6.3 6.3 6.5 6.5 6.2
[298] 6.2 5.9 5.9 5.1 5.1 4.9 4.9 4.7 4.7 4.6 4.6 5.0 5.0 5.4 5.4 4.6 4.6 5.0 5.0 4.4 4.4 4.9 4.9 5.4 5.4 4.8 4.8
[325] 4.8 4.8 4.3 4.3 5.8 5.8 5.7 5.7 5.4 5.4 5.1 5.1 5.7 5.7 5.1 5.1 5.4 5.4 5.1 5.1 4.6 4.6 5.1 5.1 4.8 4.8 5.0
[352] 5.0 5.0 5.0 5.2 5.2 5.2 5.2 4.7 4.7 4.8 4.8 5.4 5.4 5.2 5.2 5.5 5.5 4.9 4.9 5.0 5.0 5.5 5.5 4.9 4.9 4.4 4.4
[379] 5.1 5.1 5.0 5.0 4.5 4.5 4.4 4.4 5.0 5.0 5.1 5.1 4.8 4.8 5.1 5.1 4.6 4.6 5.3 5.3 5.0 5.0 7.0 7.0 6.4 6.4 6.9
[406] 6.9 5.5 5.5 6.5 6.5 5.7 5.7 6.3 6.3 4.9 4.9 6.6 6.6 5.2 5.2 5.0 5.0 5.9 5.9 6.0 6.0 6.1 6.1 5.6 5.6 6.7 6.7
[433] 5.6 5.6 5.8 5.8 6.2 6.2 5.6 5.6 5.9 5.9 6.1 6.1 6.3 6.3 6.1 6.1 6.4 6.4 6.6 6.6 6.8 6.8 6.7 6.7 6.0 6.0 5.7
[460] 5.7 5.5 5.5 5.5 5.5 5.8 5.8 6.0 6.0 5.4 5.4 6.0 6.0 6.7 6.7 6.3 6.3 5.6 5.6 5.5 5.5 5.5 5.5 6.1 6.1 5.8 5.8
[487] 5.0 5.0 5.6 5.6 5.7 5.7 5.7 5.7 6.2 6.2 5.1 5.1 5.7 5.7 6.3 6.3 5.8 5.8 7.1 7.1 6.3 6.3 6.5 6.5 7.6 7.6 4.9
[514] 4.9 7.3 7.3 6.7 6.7 7.2 7.2 6.5 6.5 6.4 6.4 6.8 6.8 5.7 5.7 5.8 5.8 6.4 6.4 6.5 6.5 7.7 7.7 7.7 7.7 6.0 6.0
[541] 6.9 6.9 5.6 5.6 7.7 7.7 6.3 6.3 6.7 6.7 7.2 7.2 6.2 6.2 6.1 6.1 6.4 6.4 7.2 7.2 7.4 7.4 7.9 7.9 6.4 6.4 6.3
[568] 6.3 6.1 6.1 7.7 7.7 6.3 6.3 6.4 6.4 6.0 6.0 6.9 6.9 6.7 6.7 6.9 6.9 5.8 5.8 6.8 6.8 6.7 6.7 6.7 6.7 6.3 6.3
[595] 6.5 6.5 6.2 6.2 5.9 5.9


# b. Get a new object which contains only the odd values of Sepal.Length

sep.lengthodd = iris[c(T,F),1]


# c. Get a new object which repeats each value from the new vector of exercise b

newsep.length = rep(sep.lengthodd, each = 2)


# d. Replace the Sepal.Length column of iris

# with the new Sepal.Length from exercise c, check if the replacement worked

iris$Sepal.Length = newsep.length; head(iris)
  Sepal.Length Sepal.Width Petal.Length Petal.Width Species
1          5.1         3.5          1.4         0.2  setosa
2          5.1         3.0          1.4         0.2  setosa
3          4.7         3.2          1.3         0.2  setosa
4          4.7         3.1          1.5         0.2  setosa
5          5.0         3.6          1.4         0.2  setosa
6          5.0         3.9          1.7         0.4  setosa






# 5. Big Data Example with diamonds (package: ggplot2)


# a. Get familiar with the dataset diamonds from ggplot

library(ggplot2)

Attaching package: ‘ggplot2’

The following object is masked from ‘mtcars’:

    mpg


? diamonds

summary(diamonds)
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
                                                   


# b. Attach the dataset

attach(diamonds)


# c. Get a subset of the diamonds dataset with all the rows that have

# a clarity of "SI2" and a depth of at least 70.

# Call the subset diam.sd and display it in the same line of code

diam.sd = subset(diamonds, clarity == "SI2" & depth >= 70); diam.sd
# A tibble: 6 x 10
  carat cut   color clarity depth table price     x     y     z
  <dbl<ord<ord<ord  <dbl<dbl<int<dbl<dbl<dbl>
1  1.5  Fair  I     SI2      70.1    58  4328  6.96  6.85  4.84
2  2    Fair  F     SI2      70.2    57 15351  7.63  7.59  5.34
3  0.7  Fair  D     SI2      71.6    55  1696  5.47  5.28  3.85
4  0.7  Fair  E     SI2      70.6    56  1828  5.45  5.35  3.81
5  1    Fair  G     SI2      70.2    58  2326  6     5.73  4.13
6  0.96 Fair  G     SI2      72.2    56  2438  6.01  5.81  4.28



# d. Which index positions have a clarity

# of SI2 and a depth of at least 70? (hint: row.id in tibble)

library(tibble)

diam.id = rowid_to_column(diamonds, var = "rowid")

diam.id = subset(diam.id, clarity == "SI2" & depth >= 70)

diam.id[,1]
# A tibble: 6 x 1
  rowid
  <int>
1  8015
2 26100
3 45689
4 47126
5 51008
6 51929


# e. Store the index positions as an integer object

index.pos = diam.id[,1]; index.pos
# A tibble: 6 x 1
  rowid
  <int>
1  8015
2 26100
3 45689
4 47126
5 51008
6 51929




# 6. Getting counts of filtered datasets (ggplot2 : diamonds)


# a. How many observations of diamonds have a cut of ideal and have less than 0.21 carat?

sum(cut == "Ideal" & carat < 0.21) # diamonds is attached to environment
[1] 3


# b. How many observations of diamonds have a combined x + y + z dimension greater than 40?

sum ((x + y + z) 40)
[1] 3


# c. How man observations of diamonds have either a price above 10000 or a depth of at least 70?

sum(price 10000 | depth >= 70)
[1] 5244




# 7. Filtering based on row and column ID (ggplot2, diamonds)


# a. Get a table with observations 67 and 982 of variables color and y

diamonds[c(67,982), c(3,9)]
# A tibble: 2 x 2
  color     y
  <ord<dbl>
1 I      4.42
2 F      5.76


# b. Get a table with the full info on observations 453, 792 and 10489

diamonds[c(453, 792, 10489), ]
# A tibble: 3 x 10
  carat cut       color clarity depth table price     x     y     z
  <dbl<ord    <ord<ord  <dbl<dbl<int<dbl<dbl<dbl>
1  0.71 Ideal     I     VVS2     60.2    56  2817  5.84  5.89  3.53
2  0.7  Very Good D     SI1      62.5    55  2862  5.67  5.72  3.56
3  1.01 Ideal     F     SI2      60      57  4796  6.55  6.51  3.92


# c. Get the first 10 rows of the dataset diamonds with the variables x, y, z

head(diamonds[ , c(8,9,10)],10)
# A tibble: 10 x 3
       x     y     z
   <dbl<dbl<dbl>
 1  3.95  3.98  2.43
 2  3.89  3.84  2.31
 3  4.05  4.07  2.31
 4  4.2   4.23  2.63
 5  4.34  4.35  2.75
 6  3.94  3.96  2.48
 7  3.95  3.98  2.47
 8  4.07  4.11  2.53
 9  3.87  3.78  2.49
10  4     4.05  2.39



# 8. Ordering data (ggplot2, diamonds)


# a. Create the object newdiam which is a subset of the first 1000 rows of diamonds

newdiam = diamonds[1:1000,]


# b. Order newdiam according to price, starting with the lowest

# hint: dplyr, arrange is a useful function for that!

library(dplyr)


head(arrange(newdiam, price))
# A tibble: 6 x 10
  carat cut       color clarity depth table price     x     y     z
  <dbl<ord    <ord<ord  <dbl<dbl<int<dbl<dbl<dbl>
1 0.23  Ideal     E     SI2      61.5    55   326  3.95  3.98  2.43
2 0.21  Premium   E     SI1      59.8    61   326  3.89  3.84  2.31
3 0.23  Good      E     VS1      56.9    65   327  4.05  4.07  2.31
4 0.290 Premium   I     VS2      62.4    58   334  4.2   4.23  2.63
5 0.31  Good      J     SI2      63.3    58   335  4.34  4.35  2.75
6 0.24  Very Good J     VVS2     62.8    57   336  3.94  3.96  2.48


# c. Order newdiam according to price, starting with the highest

head(arrange(newdiam, desc(price)))
# A tibble: 6 x 10
  carat cut       color clarity depth table price     x     y     z
  <dbl<ord    <ord<ord  <dbl<dbl<int<dbl<dbl<dbl>
1  1.12 Premium   J     SI2      60.6    59  2898  6.68  6.61  4.03
2  0.6  Very Good D     VVS2     60.6    57  2897  5.48  5.51  3.33
3  0.76 Premium   E     SI1      61.1    58  2897  5.91  5.85  3.59
4  0.54 Ideal     D     VVS2     61.4    52  2897  5.3   5.34  3.26
5  0.72 Ideal     E     SI1      62.5    55  2897  5.69  5.74  3.57
6  0.72 Good      F     VS1      59.4    61  2897  5.82  5.89  3.48


# d. Order newdiam like in c, but ties should be arranged with increasing depth

head(arrange(newdiam, desc(price), depth))
# A tibble: 6 x 10
  carat cut       color clarity depth table price     x     y     z
  <dbl<ord    <ord<ord  <dbl<dbl<int<dbl<dbl<dbl>
1  1.12 Premium   J     SI2      60.6    59  2898  6.68  6.61  4.03
2  0.72 Good      F     VS1      59.4    61  2897  5.82  5.89  3.48
3  0.6  Very Good D     VVS2     60.6    57  2897  5.48  5.51  3.33
4  0.76 Premium   E     SI1      61.1    58  2897  5.91  5.85  3.59
5  0.54 Ideal     D     VVS2     61.4    52  2897  5.3   5.34  3.26
6  0.74 Premium   D     VS2      61.8    58  2897  5.81  5.77  3.58



# 9. Sampling big dataframes, data = diamonds


# a. Use dplyr, sample_n to get the object diam750 which contains 750

# randomly sampled observations of diamonds

# I use seed nr 56 for reproduction

library(dplyr)


set.seed(56)


diam750 = sample_n(diamonds, 750)


# b. Get a summary of the new dataframe

summary(diam750)
     carat               cut      color      clarity        depth           table           price        
 Min.   :0.2300   Fair     : 25   D: 73   SI1    :171   Min.   :56.70   Min.   :53.00   Min.   :  361.0  
 1st Qu.:0.4000   Good     : 70   E:144   VS2    :154   1st Qu.:61.00   1st Qu.:56.00   1st Qu.:  982.2  
 Median :0.7050   Very Good:182   F:128   SI2    :141   Median :61.80   Median :57.00   Median : 2385.5  
 Mean   :0.8192   Premium  :187   G:169   VS1    :120   Mean   :61.77   Mean   :57.51   Mean   : 4066.9  
 3rd Qu.:1.0500   Ideal    :286   H:127   VVS2   : 72   3rd Qu.:62.60   3rd Qu.:59.00   3rd Qu.: 5400.8  
 Max.   :4.1300                   I: 65   VVS1   : 56   Max.   :69.70   Max.   :67.00   Max.   :18804.0  
                                  J: 44   (Other): 36                                                    
       x                y               z        
 Min.   : 3.910   Min.   :3.960   Min.   :0.000  
 1st Qu.: 4.700   1st Qu.:4.710   1st Qu.:2.913  
 Median : 5.700   Median :5.705   Median :3.535  
 Mean   : 5.765   Mean   :5.766   Mean   :3.556  
 3rd Qu.: 6.548   3rd Qu.:6.555   3rd Qu.:4.050  
 Max.   :10.000   Max.   :9.850   Max.   :6.430  
                                                 


# c. Plot a scatterplot of price vs depth

# use R Base plot, and the function "with" (less code)

with(diam750, plot(price, depth))




# 10. Working with tibbles - diamonds, use package tibble functions only

# Lets say newdiam consists of the first 100 rows, as well as price and carat


newdiam2 <- diamonds[1:100, c(7,1)]


# a. How do you know that this is a tibble?

head(newdiam2)
# A tibble: 6 x 2
  price carat
  <int<dbl>
1   326 0.23 
2   326 0.21 
3   327 0.23 
4   334 0.290
5   335 0.31 
6   336 0.24 

library(tibble)

is.tibble(newdiam2)
[1] TRUE
Warning message:
`is.tibble()` is deprecated, use `is_tibble()`.
This warning is displayed once per session. 


# b. Add a new row with a price of 336 with 0.32 carat

newdiam2 <- add_row(newdiam2, price = 336, carat = 0.32)

tail(newdiam2)
# A tibble: 6 x 2
  price carat
  <dbl<dbl>
1  2759  0.7 
2  2759  0.7 
3  2759  0.96
4  2760  0.73
5  2760  0.8 
6   336  0.32


# c. How many rows and columns does the tibble have?

tbl_sum(newdiam2)
 A tibble 
"101 x 2" 


# d. Print the object in a transposed way (glimpse)

glimpse(newdiam2)
Observations: 101
Variables: 2
$ price <dbl326, 326, 327, 334, 335, 336, 336, 337, 337, 338, 339, 340, 342, 344, 345, 345, 348, 351, 351, 35...
$ carat <dbl0.23, 0.21, 0.23, 0.29, 0.31, 0.24, 0.24, 0.26, 0.22, 0.23, 0.30, 0.23, 0.22, 0.31, 0.20, 0.32, 0...


# e. Does the tibble have a rowname?

has_rownames(newdiam2)
[1] FALSE
```
