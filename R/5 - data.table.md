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
#### Summary

The general form of data.table syntax is:

DT[i, j, by]

We have seen so far that,
Using i:

    We can subset rows similar to a data.frame- except you don’t have to use DT$ repetitively since columns within the frame of a data.table are seen as if they are variables.

    We can also sort a data.table using order(), which internally uses data.table’s fast order for performance.

We can do much more in i by keying a data.table, which allows blazing fast subsets and joins. We will see this in the “Keys and fast binary search based subsets” and “Joins and rolling joins” vignette.
Using j:

    Select columns the data.table way: DT[, .(colA, colB)].

    Select columns the data.frame way: DT[, c("colA", "colB")].

    Compute on columns: DT[, .(sum(colA), mean(colB))].

    Provide names if necessary: DT[, .(sA =sum(colA), mB = mean(colB))].

    Combine with i: DT[colA > value, sum(colB)].

Using by:

    Using by, we can group by columns by specifying a list of columns or a character vector of column names or even expressions. The flexibility of j, combined with by and i makes for a very powerful syntax.

    by can handle multiple columns and also expressions.

    We can keyby grouping columns to automatically sort the grouped result.

    We can use .SD and .SDcols in j to operate on multiple columns using already familiar base functions. Here are some examples:

        DT[, lapply(.SD, fun), by = ..., .SDcols = ...] - applies fun to all columns specified in .SDcols while grouping by the columns specified in by.

        DT[, head(.SD, 2), by = ...] - return the first two rows for each group.

        DT[col > val, head(.SD, 1), by = ...] - combine i along with j and by.

And remember the tip:

As long as j returns a list, each element of the list will become a column in the resulting data.table.

We will see how to add/update/delete columns by reference and how to combine them with i and by in the next vignette.
