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
                content += "\n</details>\n\n"
            if directory in ["백준", "프로그래머스"]:
                content += "# 📚 {}\n".format(directory)
            else:
                content += "<details>\n"
                content += "  <summary><b>"
                content += "🚀 {}</b></summary>\n\n".format(directory)
                content += "| 문제 | 링크 | 윥 | 석 | 경 | 정 | 윤 | 응 |\n"
                content += "| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |"
            directories.append(directory)

        solved_dict = {name: False for name in ['윤지', '석희', '경호', '정완', '윤선', '응찬']}
        prev_category = category
        for file in files:
            for name in solved_dict:
                if name in file:
                    solved_dict[name] = True
            if category != prev_category:
                folder_link = parse.quote(os.path.join(root))
                content += "\n|{}|[링크]({})|".format(category, folder_link)
                for name in solved_dict:
                    if solved_dict[name]:
                        content += "✔"
                    else:
                        content += ""
                    content += "|"
                    solved_dict[name] = False
                
                
    if directories:  # Check if there are any directories
        content += "\n</details>\n\n"  # Close the last details tag

    with open("README.md", "w") as fd:
        fd.write(content)
        
if __name__ == "__main__":
    main()
