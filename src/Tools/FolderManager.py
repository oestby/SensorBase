import os
import sys
import shutil
import glob
import time as t

DATA_PATH = ""
FILE_NAME = "current"
FILE_EXTENSION = "csv"


def pathFolderStructure(path, exclude_files = False):
    #Scans the provided path for folders and files.
    #If the path does not exist it raises an error.
    if not os.path.exists(path):
        raise("The path provided does not exist.", path)
    working_dir = os.getcwd()
    os.chdir(path)
    if exclude_files:
        folders = [x for x in os.listdir() if os.path.isdir(x)]
    else:
        folders = glob.glob("*")

    os.chdir(working_dir)
    return folders


def createFolders():
    #Creates folders of the correct format
    folder_path = DATA_PATH + "/data" + t.strftime("/%Y/%b")
    if not os.path.exists(folder_path):
        os.makedirs(folder_path)
    return folder_path


def createFilename():
    #Creates filenames of the correct format based on my chosen file extension
    filename = t.strftime("%d") + "." + FILE_EXTENSION
    return filename

 
def parseArguments(arg):
    #Parses arguments passed to the program.
    global DATA_PATH
    global FILE_NAME
    global FILE_EXTENSION
    arguments = ["-d", "--directory",
                 "-t", "--target"]
    for arr in arguments:
        try: 
            i = arg.index(arr)
        except ValueError:
            continue
        
        if arr == "-d" or arr == "--directory":
            path = arg[i + 1]
            if os.path.exists(path):
                DATA_PATH = path
            else:
                raise("The path provided does not exist.", path)
        
        if arr == "-t" or arr == "--target":
            filedesc = arg[i + 1]
            if not filedesc in pathFolderStructure(DATA_PATH):
                raise("Files does not exist.", filedesc)
            filedesc = filedesc.split(".")
            FILE_NAME = filedesc[0]
            FILE_EXTENSION = filedesc[1]


def moveFile(target_path, filename):
    #Moves a file from cwd to the target path
    shutil.move(DATA_PATH + "/" + FILE_NAME + "." + FILE_EXTENSION,
                target_path + "/" + filename)

    
def main(argv):
    parseArguments(argv)
    new_folder_path = createFolders()
    new_filename = createFilename()
    moveFile(new_folder_path, new_filename)


if __name__ == '__main__':
    DATA_PATH = os.getcwd()
    print(DATA_PATH)
    main(sys.argv)
