textfile=set_Extro_2.txt
touch $textfile

for i in {1..10}
do
  echo "sampler$i set 2_Extro-$i;" >> $textfile
done
