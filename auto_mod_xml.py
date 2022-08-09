#os.system('pip install termcolor')
from os import listdir
import os
from termcolor import colored
import re

os.system('TITLE AoV Auto Modify File 1.0')
os.system('color')
#os.system('color 7F')

DIR_PATH = './INP/'

print(colored('AoV Auto Modify File By Kourain', 'green'))
print(colored('DISCORD: Kourain#1517', 'green'))
print(colored('Ver: stable {}.{}'.format(1, 0), 'green'))

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
        allfile=0
        modfile=0
        notmodfile=0
        effect = bytes(b'prefab_skill_effects/hero_skill_effects/')
        #print(delguid.decode())
        skilleffect=0
        streffect=b''
        
        print(colored('\n\tCheck file from "INP/"...','yellow'))
        print(colored('\t\tFound: {} file'.format(havefile),'yellow'))
        
        streffect = bytes(input(colored('\t\tId hero + namehero(ex: 520_veres): ','yellow')))
        print(colored('\t\t{}'.format(streffect.decode()),'red'))
        skinid=(input(colored('\tSkin ID: ', 'green')))
        
        heroid=int(int(skinid,base=10)/100)
        changeeffect = streffect + str.encode(skinid)  + b'\x2f'
        
        for file in listdir(DIR_PATH):
            file_ext = file.split('.')[-1]
            if file_ext in EXT:
                with open(f'./INP/{file}', 'rb') as f:
                    strin = f.read()
                    allfile=allfile+1
                    pos = re.search(effect,strin)
                    if pos != -1:
                        haveeffect=1
                        strin =  re.sub(streffect,changeeffect,strin)

                        if os.path.isdir('{}'.format(skinid)) == 0 :
                            os.mkdir('{}'.format(skinid))
                        with open(f'./{skinid}/{file}', 'wb') as f1:
                            f1.write(strin)
                        modfile=modfile+1

                    else:
                        notmodfile=notmodfile+1
                
        print(colored('\n\tSee {}/'.format(skinid),'green'))
        print(colored('\tComplete {} file'.format(allfile),'green'))
        print(colored('\tModified {} file'.format(modfile),'yellow'))
        print(colored('\tSkip {} file'.format(notmodfile),'red'))
    else:
        print(colored('\n\t\tINP\ HAVE 0 File!!!','red'))
print(colored('\nEND.','green'))

os.system('pause')
