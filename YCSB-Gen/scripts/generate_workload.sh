make


# echo "ReadOnly"

echo "random"
./ycsbc -P ../workloads/uniform.spec -F random_write_64000000.dat -O ../output_dat/random_readonly_uniform
./ycsbc -P ../workloads/zipfian.spec -F random_write_64000000.dat -O ../output_dat/random_readonly_zipfian
./ycsbc -P ../workloads/latest.spec -F random_write_64000000.dat -O ../output_dat/random_readonly_latest


# echo "lognormal"
# ./ycsbc -P ../workloads/uniform.spec -F lognormal_write_64000000.dat -O ../output_dat/lognormal_readonly_uniform
# ./ycsbc -P ../workloads/zipfian.spec -F lognormal_write_64000000.dat -O ../output_dat/lognormal_readonly_zipfian
# ./ycsbc -P ../workloads/latest.spec -F lognormal_write_64000000.dat -O ../output_dat/lognormal_readonly_latest

# echo "normal"
# ./ycsbc -P ../workloads/uniform.spec -F normal_write_64000000.dat -O ../output_dat/normal_readonly_uniform
# ./ycsbc -P ../workloads/zipfian.spec -F normal_write_64000000.dat -O ../output_dat/normal_readonly_zipfian
# ./ycsbc -P ../workloads/latest.spec -F normal_write_64000000.dat -O ../output_dat/normal_readonly_latest

echo "segment"
./ycsbc -P ../workloads/uniform.spec -F segment_write_64000000.dat -O ../output_dat/segment_readonly_uniform
./ycsbc -P ../workloads/zipfian.spec -F segment_write_64000000.dat -O ../output_dat/segment_readonly_zipfian
./ycsbc -P ../workloads/latest.spec -F segment_write_64000000.dat -O ../output_dat/segment_readonly_latest

echo "longitude"
./ycsbc -P ../workloads/uniform.spec -F longitude_write_64000000.dat -O ../output_dat/longitude_readonly_uniform
./ycsbc -P ../workloads/zipfian.spec -F longitude_write_64000000.dat -O ../output_dat/longitude_readonly_zipfian
./ycsbc -P ../workloads/latest.spec -F longitude_write_64000000.dat -O ../output_dat/longitude_readonly_latest

echo "longlat"
./ycsbc -P ../workloads/uniform.spec -F longlat_write_64000000.dat -O ../output_dat/longlat_readonly_uniform
./ycsbc -P ../workloads/zipfian.spec -F longlat_write_64000000.dat -O ../output_dat/longlat_readonly_zipfian
./ycsbc -P ../workloads/latest.spec -F longlat_write_64000000.dat -O ../output_dat/longlat_readonly_latest


echo "Mixed"
echo "longitude"
./ycsbc -P ../workloads/workloada.spec -F longitude_write_64000000.dat -O ../output_dat/longitude_ycsba
./ycsbc -P ../workloads/workloadb.spec -F longitude_write_64000000.dat -O ../output_dat/longitude_ycsbb
./ycsbc -P ../workloads/workloadc.spec -F longitude_write_64000000.dat -O ../output_dat/longitude_ycsbc
./ycsbc -P ../workloads/workloadd.spec -F longitude_write_64000000.dat -O ../output_dat/longitude_ycsbd
./ycsbc -P ../workloads/workloade.spec -F longitude_write_64000000.dat -O ../output_dat/longitude_ycsbe
./ycsbc -P ../workloads/workloadf.spec -F longitude_write_64000000.dat -O ../output_dat/longitude_ycsbf

echo "random"
./ycsbc -P ../workloads/workloada.spec -F random_write_64000000.dat -O ../output_dat/random_ycsba
./ycsbc -P ../workloads/workloadb.spec -F random_write_64000000.dat -O ../output_dat/random_ycsbb
./ycsbc -P ../workloads/workloadc.spec -F random_write_64000000.dat -O ../output_dat/random_ycsbc
./ycsbc -P ../workloads/workloadd.spec -F random_write_64000000.dat -O ../output_dat/random_ycsbd
./ycsbc -P ../workloads/workloade.spec -F random_write_64000000.dat -O ../output_dat/random_ycsbe
./ycsbc -P ../workloads/workloadf.spec -F random_write_64000000.dat -O ../output_dat/random_ycsbf

echo "longlat"
./ycsbc -P ../workloads/workloada.spec -F longlat_write_64000000.dat -O ../output_dat/longlat_ycsba
./ycsbc -P ../workloads/workloadb.spec -F longlat_write_64000000.dat -O ../output_dat/longlat_ycsbb
./ycsbc -P ../workloads/workloadc.spec -F longlat_write_64000000.dat -O ../output_dat/longlat_ycsbc
./ycsbc -P ../workloads/workloadd.spec -F longlat_write_64000000.dat -O ../output_dat/longlat_ycsbd
./ycsbc -P ../workloads/workloade.spec -F longlat_write_64000000.dat -O ../output_dat/longlat_ycsbe
./ycsbc -P ../workloads/workloadf.spec -F longlat_write_64000000.dat -O ../output_dat/longlat_ycsbf