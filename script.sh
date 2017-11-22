#! /bin/zsh

for i in `seq 1 $2`
do 
	rm -f sample.fillit
	ttms_gen/tetri-gen -v -f $1
	sleep 1
	(time ./fillit sample.fillit) 1>/dev/null
done
