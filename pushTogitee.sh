#!/bin/bash
read -p "Please input commit info:" -t 30 info
cd /home/zack/gitRepo/leecode
git add .
git commit -m "$info"
git push origin master


