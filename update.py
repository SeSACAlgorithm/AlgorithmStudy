#!/usr/bin/env python

import os
from urllib import parse

HEADER="""# 
# 백준 & 프로그래머스 문제 풀이 목록

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
            if directory in ["백준", "프로그래머스"]:
                content += "# 📚 {}\n".format(directory)
            else:
                content += "### 🚀 {}\n".format(directory)
                content += "| 문제 | 링크 | 문제 | 링크 |\n"
                content += "| ----- | ----- | ----- | ----- |\n"
            directories.append(directory)

        # 모든 목록이 두 개씩 출력되도록 수정
        for i in range(0, len(files), 2):
            if category not in solveds:
                row_content = ""
                for j in range(2):  # 한 행에 두 개씩 출력
                    file_index = i + j
                    if file_index < len(files):
                        row_content += "|{}|[링크]({})|".format(category, parse.quote(os.path.join(root, files[file_index])))
                    else:  # 파일이 없는 경우 비어있는 열 추가
                        row_content += "| | |"
                content += row_content + "\n"
                solveds.append(category)
                print("category : " + category)

    with open("README.md", "w") as fd:
        fd.write(content)
        
if __name__ == "__main__":
    main()
