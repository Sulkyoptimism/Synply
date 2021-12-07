START "" InputFiles/aldaexample.alda
START "" InputFiles/synthexample.syn

cd %~dp0\Synth\
START Synth.exe
cd ..
START %~dp0\WatcherTest.exe