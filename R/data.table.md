<a href="https://www.r-exercises.com/2017/06/15/data-manipulation-with-data-table-part-1/">https://www.r-exercises.com/2017/06/15/data-manipulation-with-data-table-part-1/</a>

**1) Load the iris dataset, make it a data.table and name it iris_dt, print mean of Petal.Length, grouping by first letter of Species from iris_dt.**
```R
library(data.table)
iris_dt <- as.data.table(iris)

iris_dt[  ,  mean(Petal.Length)  ,  by=substring(Species,1,1)  ]
   substring    V1
1:         s 1.462
2:         v 4.906
```

**2) Load the diamonds dataset from ggplot2 package as dt (a data.table) ,Find mean price for each group of cut and color.**
```R
library(ggplot2)
dt <- as.data.table(diamonds)

dt[  order(cut,color)  , mean(price) ,  by=.(cut,color)  ]
          cut color       V1
 1:      Fair     D 4291.061
 2:      Fair     E 3682.312
 3:      Fair     F 3827.003
 4:      Fair     G 4239.255
 5:      Fair     H 5135.683
 6:      Fair     I 4685.446
 7:      Fair     J 4975.655
 8:      Good     D 3405.382
 9:      Good     E 3423.644
10:      Good     F 3495.750
11:      Good     G 4123.482
12:      Good     H 4276.255
13:      Good     I 5078.533
14:      Good     J 4574.173
15: Very Good     D 3470.467
16: Very Good     E 3214.652
17: Very Good     F 3778.820
18: Very Good     G 3872.754
19: Very Good     H 4535.390
20: Very Good     I 5255.880
21: Very Good     J 5103.513
22:   Premium     D 3631.293
23:   Premium     E 3538.914
24:   Premium     F 4324.890
25:   Premium     G 4500.742
26:   Premium     H 5216.707
27:   Premium     I 5946.181
28:   Premium     J 6294.592
29:     Ideal     D 2629.095
30:     Ideal     E 2597.550
31:     Ideal     F 3374.939
32:     Ideal     G 3720.706
33:     Ideal     H 3889.335
34:     Ideal     I 4451.970
35:     Ideal     J 4918.186
          cut color       V1
```

**3) Load the diamonds dataset from ggplot2 package as dt. Now group the dataset by price per carat and print top 5 in terms of count per group. Don't use head, use chaining in data.table to achieve this.**
```R
library(ggplot2)
dt <- as.data.table(diamonds)

dt[  ,  .N  ,  .(ppc=price/carat)  ][  order(-N)  ][  1:5  ]
        ppc   N
1: 2250.000 331
2: 1800.000 179
3: 4200.000 160
4: 2016.667 157
5: 2100.000 129
```

**4) Use the already loaded diamonds dataset and print the last two carat value of each cut.**
```R
dt[  ,  tail(carat,2)  ,  by=cut  ]
          cut   V1
 1:     Ideal 0.72
 2:     Ideal 0.75
 3:   Premium 0.72
 4:   Premium 0.86
 5:      Good 0.79
 6:      Good 0.72
 7: Very Good 0.70
 8: Very Good 0.70
 9:      Fair 1.04
10:      Fair 0.71
```

**5) In the same data set, find median of the columns x,y,z per cut. Use data.table’s methods to achieve this.**
```R
dt[  ,  lapply(.SD,median)  ,  cut  ,  .SDcols=c("x","y","z")  ]
         cut     x    y    z
1:     Ideal 5.250 5.26 3.23
2:   Premium 6.110 6.06 3.72
3:      Good 5.980 5.99 3.70
4: Very Good 5.740 5.77 3.56
5:      Fair 6.175 6.10 3.97
```

**6) Load the airquality dataset as data.table. Now I want to find Logarithm of wind rate for each month and for days greater than 15.**
```R
airq <- as.data.table(airquality)

airq[  Day>15  ,  .(log10(Wind))  ,  by=Month  ]
    Month        V1
 1:     5 1.0606978
 2:     5 1.0791812
 3:     5 1.2648178
 4:     5 1.0606978
 5:     5 0.9867717
 6:     5 0.9867717
 7:     5 1.2201081
 8:     5 0.9867717
 9:     5 1.0791812
10:     5 1.2201081
11:     5 1.1731863
12:     5 0.9030900
13:     5 1.0791812
14:     5 1.1731863
15:     5 0.7558749
16:     5 0.8692317
17:     6 1.1731863
18:     6 1.3159703
19:     6 0.9637878
20:     6 1.0606978
21:     6 1.0128372
22:     6 0.7993405
23:     6 0.2304489
24:     6 0.6627578
25:     6 0.7993405
26:     6 0.9030900
27:     6 0.9030900
28:     6 1.0128372
29:     6 1.0606978
30:     6 1.1731863
31:     6 0.9030900
32:     7 0.8388491
33:     7 1.0128372
34:     7 0.7993405
35:     7 0.7075702
36:     7 1.0606978
37:     7 0.8388491
38:     7 0.9867717
39:     7 1.0606978
40:     7 0.9344985
41:     7 0.9030900
42:     7 0.9344985
43:     7 1.0791812
44:     7 0.8692317
45:     7 0.8692317
46:     7 0.8692317
47:     7 0.9637878
48:     8 1.0128372
49:     8 0.7993405
50:     8 0.8692317
51:     8 1.0374265
52:     8 1.0128372
53:     8 1.1903317
54:     8 1.1553360
55:     8 1.1003705
56:     8 0.9867717
57:     8 0.5314789
58:     8 0.9030900
59:     8 0.7558749
60:     8 0.9867717
61:     8 0.3617278
62:     8 0.7993405
63:     8 0.7993405
64:     9 0.8388491
65:     9 1.1398791
66:     9 1.0128372
67:     9 1.0128372
68:     9 0.9030900
69:     9 1.1003705
70:     9 0.9637878
71:     9 1.0128372
72:     9 1.0128372
73:     9 1.2201081
74:     9 0.8388491
75:     9 1.1205739
76:     9 1.1553360
77:     9 0.9030900
78:     9 1.0606978
    Month        V1
```

**7) In the same data set, for all the odd rows, update Temp column by adding 10.**
```R
airq[  rep( c(TRUE,FALSE) , length=.N )  ,  Temp:=Temp+10L  ]

airq
     Ozone Solar.R Wind Temp Month Day
  1:    41     190  7.4   77     5   1
  2:    36     118  8.0   72     5   2
  3:    12     149 12.6   84     5   3
  4:    18     313 11.5   62     5   4
  5:    NA      NA 14.3   66     5   5
 ---                                  
149:    30     193  6.9   80     9  26
150:    NA     145 13.2   77     9  27
151:    14     191 14.3   85     9  28
152:    18     131  8.0   76     9  29
153:    20     223 11.5   78     9  30
```

**8) data.table comes with a powerful feature of updating column by reference as you have seen in the last exercise. Its even possible to update/create multiple columns. Now to test that in the airquality data.table that you have created previously, add 10 to Solar.R, Wind.**
```R
airq[  ,  c("Solar.R","Wind"):=.(Solar.R+10.0,Wind+10.0)  ]
airq
     Ozone Solar.R Wind Temp Month Day
  1:    41     200 17.4   77     5   1
  2:    36     128 18.0   72     5   2
  3:    12     159 22.6   84     5   3
  4:    18     323 21.5   62     5   4
  5:    NA      NA 24.3   66     5   5
 ---                                  
149:    30     203 16.9   80     9  26
150:    NA     155 23.2   77     9  27
151:    14     201 24.3   85     9  28
152:    18     141 18.0   76     9  29
153:    20     233 21.5   78     9  30

# Alternatively
airq[  ,  `:=`(Solar.R = Solar.R+10 , Wind = Wind+10)  ]
```

**9) Now you have a fairly good idea of how easy its to create multiple column. Its even possible to use delete multiple column using the same idea. In this exercise, use the same airquality data.table that you have created previously from airquality and delete Solar.R, Wind, Temp using a single expression.**
```R
airq[  ,  c("Solar.R","Wind","Temp"):=NULL  ]
```

**10) Load the airquality dataset as data.table again , I want to create two columns "a","b" which indicates temp in Celcius and Kelvin scale . Write a expression to achieve same:<br/>
Celcius = (Temp-32)\*5/9<br/>
Kelvin = Celcius+273.15**
```R
airq[  ,  c("a","b"):=list(celcius <- (Temp-32)*5/9, kelvin <- celcius+273.15)  ]
airq
     Ozone Solar.R Wind Temp Month Day        a        b
  1:    41     200 17.4   77     5   1 25.00000 298.1500
  2:    36     128 18.0   72     5   2 22.22222 295.3722
  3:    12     159 22.6   84     5   3 28.88889 302.0389
  4:    18     323 21.5   62     5   4 16.66667 289.8167
  5:    NA      NA 24.3   66     5   5 18.88889 292.0389
 ---                                                    
149:    30     203 16.9   80     9  26 26.66667 299.8167
150:    NA     155 23.2   77     9  27 25.00000 298.1500
151:    14     201 24.3   85     9  28 29.44444 302.5944
152:    18     141 18.0   76     9  29 24.44444 297.5944
153:    20     233 21.5   78     9  30 25.55556 298.7056
```
