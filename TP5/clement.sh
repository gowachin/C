#!/bin/bash

ligne=$(wc -l $1 | cut -d' ' -f1)
nb=$(expr $ligne / 4 )

i=0
while [ $i -lt $nb ]
do
    numligne=$( expr $i \* 4 + 1 )
    tail -n +$numligne $1 | head -n 4
    echo ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,"
    i=$(expr $i + 1 )
done

numligne=$( expr $i \* 4 + 1 )
tail -n +$numligne $1 | head -n 4
echo ''