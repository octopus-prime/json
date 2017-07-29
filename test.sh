docker rm -f json &>/dev/null || true
docker run -d -it --name json --privileged octopusprime/test
docker exec json mkdir json
docker cp . json:/json
docker exec json bash -c "
	cd json; 
	bjam toolset=$1 debug -j$2
"
docker cp json:/json/bin .
