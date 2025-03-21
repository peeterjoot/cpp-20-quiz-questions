#./exe/gcd --a -50 --b 10
#./exe/gcd --a 50 --b 10
#./exe/gcd --a 50 --b -10

rm -f gcd.csv
for i in {1..10} ; do
for j in {1..10} ; do
    ./exe/gcd --csv --a $i --b $j >> gcd.csv
done
done

# compare file generated with Mathematica: 
#
# some = Flatten[Table[{a, b, GCD[a, b]}, {a, 1, 10}, {b, 1, 10}], 1] ; Export["gcd.csv", some ]
# (then sorted)
sort gcd.csv | diff -up - ~/winhome/gcd.csv
