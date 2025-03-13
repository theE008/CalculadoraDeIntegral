@echo off

rem Faz commit, só adicionei porque achei que seria legal

git add .
git commit -m %*
git push origin main