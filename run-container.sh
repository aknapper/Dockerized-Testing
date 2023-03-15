MOUNT_DIR=$PWD/../:/usr/src
WORKING_DIR=/usr/src/${PWD##*/}

echo "Starting container to test ${PWD##*/}..."
docker run -it --rm -v $MOUNT_DIR -w $WORKING_DIR knapper/ubuntu-cpputest
