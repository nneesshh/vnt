#!/bin/sh

stopwork_release()
{
    cd ../bin/
    echo "begin stop server"
    #pkill server;
    #kill -9 $(sed -n 1p server.pid);
    kill -9 `cat gateserver.pid`
    kill -9 `cat battleserver.pid`
    kill -9 `cat crossserver.pid`
    kill -9 `cat gameserver.pid`
    kill -9 `cat worldserver.pid`
    kill -9 `cat commonserver.pid`
    kill -9 `cat dbserver.pid`
	kill -9 `cat socialserver.pid`
    #kill -9 `cat worldchatserver.pid`
    #pkill -9 `chat`
    echo "end stop server"
    cd ../script/

}


stopwork_debug()
{
    cd ../bin/Debug/
    echo "begin stop server"
    #pkill server;
    #kill -9 $(sed -n 1p server.pid);
    kill -9 `cat gateserver.pid`
    kill -9 `cat battleserver.pid`
    kill -9 `cat crossserver.pid`
    kill -9 `cat gameserver.pid`
    kill -9 `cat worldserver.pid`
    kill -9 `cat commonserver.pid`
    kill -9 `cat dbserver.pid`
	kill -9 `cat socialserver.pid`
    #kill -9 `cat worldchatserver.pid`
    #pkill -9 `chat`
    echo "end stop server"
    cd ../../script/

}


    case $1 in
                 -d)
             stopwork_debug
             ;;
                 -r)
             stopwork_release
             ;;
            *)
            stopwork_release
        ;;
   esac
