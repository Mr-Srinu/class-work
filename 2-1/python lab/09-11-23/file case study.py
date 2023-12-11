import os,os.path
quit='7'
commands=('1','2','3','4','5','6','7')
menu="""1 List the current directory name
2 move up
3 move down
4 number of files inthe dictionary
5 size of the files in the dictionary
6 search for a filename
7 Quit the programm"""
def main():
    while True:
        print(os.getcwd())
        print(menu)
        cmd=acceptCommand()
        runCommand(cmd)
        if cmd==quit:
            print("have a nice day!")
            break
def acceptCommand():
    """Inputs and returns a legimate command number"""
    cmd=input("enter a number:")
    if cmd in commands:
        return cmd
    else:
        print("Error:command not recognized")
        return acceptCommand()
def runCommand(cmd):
    """Selects and runs a command"""
    if cmd=='1':
        listCurrentDir(os.getcwd())
    elif cmd=='2':
        moveUp()
    elif cmd=='3':
        moveDown(os.getcwd())
    elif cmd=='4':
        print("the total number of files is:",countFiles(os.getcwd()))
    elif cmd=='5':
        print("the total number of bytes is:",countBytes(os.getcwd()))
    elif cmd=='6':
        target=input("enter the search string:")
        fileList=findFiles(target,os.getcwd())
def listCurrentDir(dirName):
    """Prints a  list of cwd's contents"""
    lyst=os.listdir(dirName)
    for ele in lyst:
        print(ele)
def moveUp():
    """Moves up to the parent directory"""
    os.chdir("..")
def moveDown(currentDir):
    """Moves down to the named subdirectory"""
    newDir=input("enter the directory name:")
    if os.path.exists(currentDir+os.sep+newDir)and os.path.isdir(newDir):
        os.chdir(newDir)
    else:
        print("Error: no such name ")
def countFiles(path):
    c=0
    li=os.listdir(path)
    for ele in li:
        if os.path.isfile(ele):
            c+=1
        else:
            os.chdir(ele)
            c+=countFiles(os.getcwd())
            os.chdir("..")
    return c
def countBytes(path):
    c=0
    li=os.listdir(path)
    for ele in li:
        if os.path.isfile(ele):
            c+=os.path.getsize(ele)
        else:
            os.chdir(ele)
            c+=countBytes(os.getcwd())
            os.chdir("..")
    return c
def findFiles(target,path):
    files=[]
    li=os.listdir(path)
    for ele in li:
        if os.path.isfile(ele):
            if target in ele:
                print("file found")
        else:
            if ele not in li:
                print("string not found")
    return files

if __name__=="__main__":
    main()