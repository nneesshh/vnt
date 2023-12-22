cd ..
cargo build --release 
xcopy target\release\vnt-cli.exe bin\ /y /d /q
cd script