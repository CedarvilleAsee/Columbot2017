# Columbot2017

## Git

We're using [github](https://github.com) as a way of storing our code, keeping
track of our changes, and how our programmers are going to interact. Github is
built on top of git, so understanding how to use git is essential to understanding how to
use github.

Git is a program for managing source code (as well as any other things you want,
but it is primarily used by programmers); it operates on things called
**repositories**. The
[Columbot2017 Repository](https://github.com/CedarvilleAsee/Columbot2017) that
this file is on is a *git repository* that is stored on Github's servers, and is
public for all of our team to access.

### The process in detail

A git repository maintains the whole history of all our changes to anything that
you have put into the repository. To make a change to the git repository, we
first need to **clone** it on your own local computer. This is done by issuing th
command:

    git clone <https://url.to.your/repository>

or, specifically for our project, you can execute

    git clone https://github.com/CedarvilleAsee/Columbot2017

Once the repository has been cloned on your computer, you can make changes to
the folder containing the files however you want. You may notice that there is a
`.git` folder in the repository; **don't touch it**. This folder contains all
the information that git keeps track of; if you change it, your local git
repository will likely be messed up, and you will have to re-clone it on to your
computer. (You won't necessarily see this folder...it will always be there, but
because it starts with a ".", it is hidden by default).

After you have made changes in the folder, try executing the following command:

    git status

This command will tell you something like the following:

    On branch master
    Your branch is up-to-date with 'origin/master'.
    Changes to be committed:
      (use "git reset HEAD <file>..." to unstage)

    ...

    Changes not staged for commit:
      (use "git add <file>..." to update what will be committed)
      (use "git checkout -- <file>..." to discard changes in working directory)

    ...


    Untracked files:
      (use "git add <file>..." to include in what will be committed)

    ...

This output will help to illustrate how a change will make it back to the main
repository. At the bottom, notice that it points out the "untrack files". In
order to make git keep track of files, you need to do just what it says:

    git add <file-that-you-want-to-add>

Next, git shows us the changes to the files that are indeed being tracked, but
it tells us that the changes have not been **staged**. To stage them, do the following:

    git add <file-that-you-want-to-add>

Note that it's the same as the previous command. Lastly, the top part tells us
what changes we have made that still need to be **committed**. Committing just
means to add the change to your local repository. To commit your changes,
execute:

    git commit -m "your commit message"

This will add the commit to your local repository, and attach the message to it.
The final step to putting your changes on github is to **push** your repository.
Do this:

    git push

Git will then ask for your github username and password in order to push the
change to github.

### Simpler recap

Now that I've bombarded you with all this information, allow me to simplify this
process so that it is easier to remember.

- The first step whenever you want to start working on something is to **clone**
  the repository. You won't have to do this too often. Cloning just makes sure
  your local repository is up to date with the one on github.
- Once you have a cloned repository, you can go crazy with whatever changes you
  want to make.
- Get used to typing `git status`; it will become one of your best friends.
  After you've made changes to your folder, check the status, and it will tell
  you what you need to commit it. Note that you shouldn't commit after every
  single time you've saved your file. Just commit when you feel you've hit a
  good milestone, or done something worth slightly notable. For example, I will
  commit to my repository once I finish this repository.
- When you have finished for the time being, and are going to leave your project
  for a while, you should put your changes back onto github. Make sure you've
  committed all your changes. Then **push** your repository back up to github.

That's all; I hope that didn't seem too complicated. You should definitely try
to get good at using git; if you ever get involved with a team programming
project in the future, you'll very likely have to use it again. It's good
practice to use git even for personal projects as well.
[https://git-scm.com/book/en/v2](The Git Book) is a great resource for learning
how to use git. There are a lot of other features that git provides, but we will
probably not need them for our purposes.
