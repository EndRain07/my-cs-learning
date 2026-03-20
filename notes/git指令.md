# =========================
# Git 常用指令表（入门版）
# =========================

# 1. 查看 Git 版本
git --version

# 2. 设置全局用户名
git config --global user.name "你的GitHub用户名"

# 3. 设置全局邮箱
git config --global user.email "你的GitHub邮箱"

# 4. 查看当前全局配置
git config --global --list

# 5. 初始化当前文件夹为 Git 仓库
git init

# 6. 查看当前仓库状态
git status

# 7. 把当前目录所有文件加入暂存区
git add .

# 8. 只添加某一个文件
git add 文件名

# 示例
git add first_hello.py

# 9. 提交一次版本
git commit -m "写这里的提交说明"

# 示例
git commit -m "Add first Python file"

# 10. 查看提交历史（简洁版）
git log --oneline

# 11. 查看远程仓库
git remote -v

# 12. 添加远程仓库
git remote add origin https://github.com/你的用户名/仓库名.git

# 示例
git remote add origin https://github.com/EndRain07/cs-learning.git

# 13. 把当前分支改名为 main
git branch -M main

# 14. 第一次推送到 GitHub
git push -u origin main

# 15. 之后普通推送
git push

# 16. 拉取远程更新
git pull

# 17. 查看当前有哪些分支
git branch

# 18. 新建分支
git branch 分支名

# 示例
git branch test

# 19. 切换分支
git checkout 分支名

# 示例
git checkout test

# 20. 新建并切换到新分支
git checkout -b 分支名

# 示例
git checkout -b test

# 21. 删除本地分支
git branch -d 分支名

# 22. 查看某个文件改了什么
git diff 文件名

# 示例
git diff first_hello.py

# 23. 查看所有未提交改动
git diff

# 24. 把某个文件移出暂存区
git restore --staged 文件名

# 示例
git restore --staged first_hello.py

# 25. 丢弃某个文件的未提交修改
git restore 文件名

# 示例
git restore first_hello.py

# 26. 新建 .gitignore 文件后常用检查
git status

# 27. 查看当前所在路径（PowerShell）
pwd

# 28. 切换到你的学习目录（PowerShell）
cd D:\CS-Learning

# 29. 查看当前目录文件（PowerShell）
ls

# 30. 查看远程仓库详细信息
git remote show origin