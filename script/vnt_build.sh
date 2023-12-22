#!/bin/sh

startbuild()
{
        echo "begin start build"

        pkill rustc

        svn up ..
        #git pull

        cd ../
        mkdir -p bin/

        cargo build --release || exit 1
        
        cp -rfv target/release/vnt-cli bin/

        echo "end start build"

        cd script/
}

startbuild
