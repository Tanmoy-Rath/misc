```R

setDTthreads(0)    # use all available cores (default)
getDTthreads()     # check how many cores are currently used


library(data.table)
data.table 1.12.2 using 2 threads (see ?getDTthreads).  Latest news: r-datatable.com
getOption("datatable.print.nrows")
[1] 100

DT <- data.table(
         ID = c("b","b","b","a","a","c"),
         a = 1:6,
         b = 7:12,
         c = 13:18
      )

class(DT$ID)# data.table doesnot create factor variables by default
[1] "character"

flights <- fread("flights14.csv")
# https://github.com/Tanmoy-Rath/misc/blob/master/R/datafiles/flights14.csv






```
