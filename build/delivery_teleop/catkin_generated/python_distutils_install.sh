#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/seounghyun/delivery_robot/src/delivery_teleop"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/seounghyun/delivery_robot/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/seounghyun/delivery_robot/install/lib/python2.7/dist-packages:/home/seounghyun/delivery_robot/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/seounghyun/delivery_robot/build" \
    "/usr/bin/python2" \
    "/home/seounghyun/delivery_robot/src/delivery_teleop/setup.py" \
     \
    build --build-base "/home/seounghyun/delivery_robot/build/delivery_teleop" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/seounghyun/delivery_robot/install" --install-scripts="/home/seounghyun/delivery_robot/install/bin"
