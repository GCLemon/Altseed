@echo off
rem amcr-glfw�������pbat
rem 
rem git.exe�Ƀp�X��؂��Ă����Ă��������B
rem TortoiseGit�œ��l�̑��������ɂ́A
rem Submodule update��Dev\amcr-glfw\��Switch/checkout��Switch to ��branch��I���Amaseter��I��

git.exe submodule init
git.exe submodule update
cd .\Dev\amcr-glfw
git.exe checkout master
pause
