# Columbot2017

# Instructions for using git

To clone this repository, execute the following command:

    git clone https://github.com/CedarvilleAsee/Columbot2017

Before changing anything in the files, execute `git pull` to sync your local
repository with the one on github. For the curious, `git pull` is actually a
combination of `git fetch` and `git merge`.

`git status` will list the changes to your local repository, grouped by whether
they have been added to the staging area.

`git add <filename>` adds the specified file's changes to the staging area.

`git add -A` adds all changes to the staging area. After executing this, `git
status` will show that all changes have been added to the staging area.

`git commit -m "insert commit message"` submits changes to your own local repository. These changes will have the message associated with them; when you look back at the history of the repository, you will see this commit message.

`git push origin <branchname>` pushes the current commits to the online repository on github.

You should definitely try to get good at using git; if you ever get involved
with a team programming project in the future, you'll very likely have to use it
again. It's good practice to use git even for personal projects as well. [https://git-scm.com/book/en/v2](The Git Book) is a great resource for learning how to use git.
