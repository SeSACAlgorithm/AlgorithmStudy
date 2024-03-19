#!/usr/bin/env python

import os
from urllib import parse

HEADER = """# 
# 백준 & 프로그래머스 문제 풀이 목록

## 목차
### [백준](#-백준) <br>
### [프로그래머스](#-프로그래머스)

"""

# 추가된 이름 체크 배열
NAME_CHECK = {
    "윤지": False,
    "석희": False,
    "경호": False,
    "정완": False,
    "윤선": False,
    "응찬": False
}

def update_name_check(name, value):
    if name in NAME_CHECK:
        NAME_CHECK[name] = value

def main():
    content = ""
    content += HEADER

    directories = []
    solveds = []

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
            for name in NAME_CHECK.keys():
                if name in file:
                    update_name_check(name, True)
            if category not in solveds:
                for name in NAME_CHECK:
                    update_name_check(name, False)
                for name in NAME_CHECK.keys():
                    if name in file:
                        update_name_check(name, True)
                folder_link = parse.quote(os.path.join(root))
                content += "|{}|[링크]({})|".format(category, folder_link)
                solveds.append(category)
                for name, checked in NAME_CHECK.items():  # 이름 체크 배열 확인
                    if checked:
                        content += "✔|"  # 해당하는 이름에 ✔ 표시
                    else:
                        content += " |"  # 해당하는 이름에 공백 처리
                content += "\n"
                print("category : " + category)

    if directories:  # Check if there are any directories
        content += "</details>\n\n"  # Close the last details tag

    with open("README.md", "w") as fd:
        fd.write(content)


if __name__ == "__main__":
    main()
