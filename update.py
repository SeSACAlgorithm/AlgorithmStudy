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
    
    directories = []
    problems = {}  # Dictionary to store problems and their solvers

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
                content += "| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |\n"
            directories.append(directory)

        names = ['윤지', '석희', '경호', '정완', '윤선', '응찬']
        for file in files:
            content += "\n"
            folder_link = parse.quote(os.path.join(root))
            content += "|[{}]({})|".format(category, folder_link)
            for name in names:
                if name in file:
                    if category not in problems:
                        problems[category] = set()  # Initialize set for the problem if not exists
                    problems[category].add(name)
                    content += "✔|"
                else:
                    content += "|"
                
    if directories:  # Check if there are any directories
        content += "\n</details>\n\n"  # Close the last details tag

    # Now, we iterate over the problems dictionary to generate the final table
    for problem, solvers in problems.items():
        content += "|{}|[링크]({})|".format(problem, "link_placeholder")
        for name in names:
            if name in solvers:
                content += "✔|"
            else:
                content += "|"
        content += "\n"

    with open("README.md", "w") as fd:
        fd.write(content)

        
if __name__ == "__main__":
    main()
