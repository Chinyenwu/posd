git init

git remote add origin https://ssl-gitlab.csie.ntut.edu.tw/posd2020f_hw/109598080_hw.git

git config --global user.email welly592@gmail.com

git config --global user.name 109598080

git clone https://ssl-gitlab.csie.ntut.edu.tw/posd2020f_hw/109598080_hw.git

//git pull

make

./bin/ut_main

git add .

git commit -m "test"

git push -u origin master