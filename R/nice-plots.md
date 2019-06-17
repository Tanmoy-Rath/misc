```R
ggplot(data = mpg) + 
        geom_jitter(mapping = aes(x = displ, y = hwy)) +
        facet_grid(drv ~ .)


                show.legend = FALSE
                     vs
        theme(legend.position = "none")




ggplot(data = mpg) +
        geom_smooth(mapping = aes(x = displ, y = hwy, group = drv))

ggplot(data = diamonds, mapping = aes(x = color, fill=cut)) +
        geom_bar()+
        facet_wrap(~ clarity)


ggplot(data = <DATA>) + 
        <GEOM_FUNCTION>(
                mapping = aes(<MAPPINGS>),
                stat = <STAT>, 
                position = <POSITION>
        ) +
        <COORDINATE_FUNCTION> +
        <FACET_FUNCTION>


```
