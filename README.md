# Demo15_10_NAND_FLASH

# create a new repository on the command line
echo "# Demo15_10_NAND_FLASH" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M master
git remote add origin https://github.com/wenchm/Demo15_10_NAND_FLASH.git
git remote -v
git push -u origin master

# push an existing repository from the command line
git remote add origin https://github.com/wenchm/Demo15_10_NAND_FLASH.git
git branch -M master
git push -u origin master