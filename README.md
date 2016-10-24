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
first need to **clone** it on your `this` own local computer. This is done by issuing th
command:

    git clone <https://url.to.your/repository>

or, specifically for our project, you can execute

    git clone https://github.com/CedarvilleAsee/Columbot2017

Once the repository has been cloned on your computer, you can make changes to
the folder containing the files however you want. You may notice that there is a
`.git` folder in the repository; **don't touch it**. This folder contains  fsall
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

That's all; I hope that didn't seem too complicated.
## Github

Now that you now a little something about git, I'll explain how Github will tie
into all of this. I've been telling you that to put your changes onto github,
you would just push your changes to
[https://github.com/CedarvilleAsee/Columbot2017]. However, if we all did that,
it would get confusing, because some people might make a change, and it would
break something, messing everyone else up. Or perhaps two people would make
changes to the same thing, and then someone would lose what they did because
they did their's first, and they were overwritten. Also, not everyone has the
right permissions to be able to push changes to our central repository.

The way we want you to do it is the following:

- Go to the github repository for our project.
- Click the "fork" button; make sure you are signed in.
- Once you have forked our central repo, you should make all changes in your own
  forked repo.
- Once you have finished the thing you are working on, and believe that it
  should be added into the central repository, you should click the "Submit pull
  request" button on your repo. This will create a pull request on the main
  repo, and the team memebers can all participate on discussion of whether to
  accept the pull request. For most things in this project, I expect there won't
  be very much discussion, because we will probably discuss things prior to
  starting work on them.

There is one matter that you must keep track of. After you have forked, your
repository won't keep up to date as the main repository moves along. To
periodically make it the same, you need to **merge** the central repo with your
own. To do so, go to your local repo's directory and add the central repo as an
*upstream* repository:

    git remote add upstream https://github.com/CedarvilleAsee/Columbot2017

Typing

    git remote -v

will show you all your remote repositories, but you don't need to worry much
about that. After you have done this, you can merge the upstream repository with
your own by running:

    git fetch upstream

If all has gone well, you should be up to date on your local repository. You
must push your changes in order to be up to date on your github fork.

### If you get stuck

Note that I have not gone extremely in depth, whatever it may seem. Git is a
little complicated at first, but experience will make you better at it. You
should definitely try to get good at using git; if you ever get involved with a
team programming project in the future, you'll very likely have to use it again.
It's good practice to use git even for personal projects as well.
[https://git-scm.com/book/en/v2](The Git Book) is a great resource for learning
how to use git. There are a lot of other features that git provides, but we will
probably not need them for our purposes.

Remember that you can always come to me for help if you don't know what to do,
or you get stuck on something.

## Tentative States

We currently have a list of possible states that we could be in for our
two-robot solution. These are not necessarily in order.

  * Start
  * Line follow center
  * Left turn
  * Right turn
  * Wall follow
  * Avoid rocks
  * Line up for drop
  * Drop and pickup
  * Pickup and drop
  * Turn around
  * Move to line
  * Dump barrels
