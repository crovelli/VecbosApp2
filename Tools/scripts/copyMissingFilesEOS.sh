#!/bin/bash -f
#usage: ./copyMissingFilesEOS.sh DoubleElectron.list /eos/cms/store/group/phys_higgs/cmshww/emanuele/V14-5_2_X/Data2012/DoubleElectron runmeDoubleElectron.sh

filelist=$1
eosdir=$2
script=$3

# now look for the missing files
awk -F "/" '{print $12}' $filelist > orig
eos.select ls $eosdir | grep root > done
cat orig done > all
sort all > sorted
uniq -u sorted > tocopy
rm done orig all

# now make the script to copy
castordir=`cat $filelist | awk -F "default" '{print $1}' | uniq`
cat tocopy | awk '{print "xrdcp -v root://castorcms/" "'"$castordir"'" $1 " root://eoscms/" "'"$eosdir/"'" }' > $script

rm tocopy
echo "Done. Now run the script: source " $script

