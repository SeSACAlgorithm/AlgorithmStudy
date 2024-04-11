#!/usr/bin/env python

import os
import re
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
    
    directories = []
    solveds = []
    names = ['윤지', '석희', '경호', '정완', '윤선', '응찬', '정현', '재원', '시은', '은빈']
    site_link = ""

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
                if directory == "백준":
                    site_link = "https://www.acmicpc.net/problem/"
                elif directory == "프로그래머스":
                    site_link = "https://programmers.co.kr/learn/courses/30/lessons/"
                content += "# 📚 {}\n".format(directory)
            else:
                content += "<details>\n"
                content += "  <summary><b>"
                content += "🚀 {}</b></summary>\n\n".format(directory)
                content += "| 번호 | 문제 | 깃 | 윥 | 석 | 경 | 완 | 윤 | 응 | 현 | 재 | 시 | 은 |\n"
                content += "| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |\n"
            directories.append(directory)
        
        if category[0].isdigit():
            if category not in solveds:
                match = re.match(r'(\d+)', category)
                if match : 
                    number = int(match.group(1)) # 문제 번호
                    problem_link = site_link + str(number)
                    quetion_name = re.sub(r'^\d+\)\s*', '', category)
                    folder_link = parse.quote(os.path.join(root))
                    content += "|[{}]({})|{}|[링크]({})|".format(number, problem_link, quetion_name, folder_link)
                    solveds.append(category)

            for name in names:
                for file in files:
                    if name in file:
                        content += "✔"
                    else:
                        continue
                content += "|"
                
            content += "\n"
                
    if directories:  # Check if there are any directories
        content += "\n</details>\n\n"  # Close the last details tag

    with open("README.md", "w") as fd:
        fd.write(content)
        
if __name__ == "__main__":
    main()
