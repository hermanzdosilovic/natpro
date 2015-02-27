#!/bin/bash
sudo rm -rf ../test/fibonacci
mkdir -p ../test/fibonacci
let k=1
K=`printf "%02d" $k`
cat <<< "10" | python fibonacci.py > ../test/fibonacci/fibonacci.$K.in
let k++
for i in $(seq 50 50 200)
do
    K=`printf "%02d" $k`
    cat <<< "$i" | python fibonacci.py > ../test/fibonacci/fibonacci.$K.in
    let k++
done
echo 10000000000 > ../test/fibonacci/fibonacci.06.in
echo 10000000000000 > ../test/fibonacci/fibonacci.07.in
echo 10000000000000000 > ../test/fibonacci/fibonacci.08.in
echo 1000000000000000000 > ../test/fibonacci/fibonacci.09.in
echo 1000000000000000000000 > ../test/fibonacci/fibonacci.10.in

cd ..
for i in {1..10}
do
    K=`printf "%02d" $i`
    python fibonacci.py < test/fibonacci/fibonacci.$K.in > test/fibonacci/fibonacci.$K.out
done
