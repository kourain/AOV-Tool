#os.system('pip install termcolor')
from os import listdir
import os
from termcolor import colored

os.system('TITLE AoV Track ID xml file 1.0')
os.system('color')

DIR_PATH = './INP/'

print(colored('AoV Track ID xml file By Kourain', 'green'))
print(colored('Ver: {}.{}'.format(1, 0), 'green'))

if os.path.isdir('INP')== 0 :
    os.mkdir('INP')
    print(colored('\n\tPut file in INP/\n', 'red'))
else:
    havefile=0
    for file in listdir(DIR_PATH):
        file_ext = file.split('.')[-1]
        if file_ext == 'xml':
                havefile=havefile+1
    if havefile>0:
        for file in listdir(DIR_PATH):
            file_ext = file.split('.')[-1]
            if file_ext in 'xml':
                with open(f'./INP/{file}', 'rb') as f:
                    
                    strin = f.read()
                    print("{}".format(file))
                    trackid =0
                    pos = strin.find(b"<Track trackName=")
                    while pos != -1:
                            posid = strin.find(b"guid=",pos)
                            guid = (strin[posid+6:posid+42]).decode()
                            print("id {} guid {}".format(trackid,guid))
                            trackid = trackid+1
                            #next track
                            pos = strin.find(b"<Track trackName=",posid)
                            
                print()
    else:
        print(colored('\n\t\tINP\ HAVE NO FILE!!!','red'))
print(colored('\nEND.','green'))
input()
