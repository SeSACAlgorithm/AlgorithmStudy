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
    solveds = [];

    for root, dirs, files in os.walk("."):
        dirs.sort()
        if root == '.':
            for dir in ('.git', '.github'):
                try:
                    dirs.remove(dir)
                except ValueError:
                    pass
            continue

        category = os.path.basename(root)
        
        if category == 'images':
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

        files_count = len(files)
        for file in files:
            problem_name, ext = os.path.splitext(file)  # Extract problem name and extension
            if problem_name not in solveds:
                folder_link = parse.quote(os.path.join(root, file))  # Create link to the file
                content += "|{}|[링크]({})|".format(problem_name, folder_link)
                solveds.append(problem_name)
                names = ['윤', '석', '경', '정', '윤', '응']  # List of names
                for name in names:
                    if name in problem_name:  # Check if the name is in the problem name
                        content += "✔"  # If so, mark it as solved
                    else:
                        content += ""  # Otherwise, leave it empty
                    content += "|"
                content += "\n"
                
    if directories:  # Check if there are any directories
        content += "</details>\n\n"  # Close the last details tag

    with open("README.md", "w") as fd:
        fd.write(content)
        
if __name__ == "__main__":
    main()
