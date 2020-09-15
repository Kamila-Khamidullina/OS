if test ! -f RNums
then
	echo 0 > RNums
fi

for i in `seq 1 100`
do
	n=`tail -1 RNums`
	expr $n + 1 >>RNums
done