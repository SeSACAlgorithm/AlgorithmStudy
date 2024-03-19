#!/usr/bin/env python

import os
from urllib import parse

HEADER="""# 
# 백준 & 프로그래머스 문제 풀이 목록

## 목차
### [백준](#-백준) <br>
### [프로그래머스](#-프로그래머스)

"""

def main():
    content = ""
    content += HEADER
    
    directories = [];
    checkFolder = [];

    for root, dirs, files in os.walk("."):
        content += "root : "
        content += root
        content += "\nfiles : "
        content += files
        content += "\n"
        dirs.sort()
        if root == '.':
            for dir in ('.git', '.github'):
                try:
                    dirs.remove(dir)
                except ValueError:
                    pass
            continue

        questionFolder = os.path.basename(root)
        
        if questionFolder == 'images':
            continue
        
        directory = os.path.basename(os.path.dirname(root))
        
        if directory == '.':
            continue
            
        if directory not in directories:
            if directories:
                content += "</details>\n\n"
            if directory in ["백준", "프로그래머스"]:
                content += "# 📚 {}\n".format(directory)
            else:
                content += "<details>\n"
                content += "  <summary><b>"
                content += "🚀 {}</b></summary>\n\n".format(directory)
                content += "| 문제 | 링크 | 윥 | 석 | 경 | 정 | 윤 | 응 |\n"
                content += "| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |\n"
            directories.append(directory)

        for file in files:
            if questionFolder not in checkFolder:
                folder_link = parse.quote(os.path.join(root))
                content += "|{}|[링크]({})|".format(questionFolder, folder_link)
                checkFolder.append(questionFolder)
            names = ['윤지', '석희', '경호', '정완', '윤선', '응찬']
            for name in names:
                if name in file:
                    content += "✔"
                else:
                    content += ""
                content += "|"
            content += "\n"
                
    if directories:  # Check if there are any directories
        content += "</details>\n\n"  # Close the last details tag

    with open("README.md", "w") as fd:
        fd.write(content)
        
if __name__ == "__main__":
    main()