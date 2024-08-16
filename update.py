#!/usr/bin/env python

import os
import re
from urllib import parse
from collections import Counter

HEADER="""# 
# 백준 & 프로그래머스 & SWEA

## 목차
### [Ranking](#-Ranking) <br>
### [SWEA](#-SWEA) <br>
### [백준](#-백준) <br>
### [프로그래머스](#-프로그래머스) <br>

"""

def main():
    content = ""  # content 변수를 초기화
    directories = []
    solveds = []
    names = ['윤지', '석희', '경호', '정완', '정현', '재원', '태호']
    name_count = Counter()  # 파일 이름 빈도수를 계산할 Counter 추가
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
            if directory in ["SWEA", "백준", "프로그래머스"]:
                if directory == "SWEA" :
                    site_link = "SWEA"
                elif directory == "백준":
                    site_link = "https://www.acmicpc.net/problem/"
                elif directory == "프로그래머스":
                    site_link = "https://programmers.co.kr/learn/courses/30/lessons/"
                content += "# 📚 {}\n".format(directory)
            else:
                content += "<details>\n"
                content += "  <summary><b>"
                content += "🚀 {}</b></summary>\n\n".format(directory)
                content += "| 번호 | 문제 | &nbsp;&nbsp;깃&nbsp;&nbsp; | 윥 | 석 | 경 | 완 | 현 | 재 | 태 |\n"
                content += "| ----- | ----- | :-----: | ----- | ----- | ----- | ----- | ----- | ----- | ----- |\n"
            directories.append(directory)
        
        if category[0].isdigit():
            if category not in solveds:
                match = re.match(r'(\d+)', category)
                if match : 
                    number = int(match.group(1)) # 문제 번호
                    quetion_name = re.sub(r'^\d+\)\s*', '', category)
                    folder_link = parse.quote(os.path.join(root))
                    if site_link != "SWEA":
                        problem_link = site_link + str(number)
                        content += "|[{}]({})|{}|[링크]({})|".format(number, problem_link, quetion_name, folder_link)
                    else :
                        content += "|{}|{}|[링크]({})|".format(number, quetion_name, folder_link)
                    solveds.append(category)

            for name in names:
                count_flag = False  # 카운트 중복 방지를 위한 플래그
                for file in files:
                    if name in file:
                        content += "✔"
                        if not count_flag:
                            name_count[name] += 1  # 해당 이름이 파일에 있으면 카운트 증가
                            count_flag = True  # 한 파일당 한 번만 카운트되도록 설정
                    else:
                        continue
                content += "|"
                
            content += "\n"
                
    if directories:  # Check if there are any directories
        content += "\n</details>\n\n"  # Close the last details tag

    # 순위표 추가
    most_common_names = name_count.most_common(5)  # 5등까지
    standings = "# 🏆 Ranking\n"
    standings += "| 🥇 순위 | 👤 이름 | ✔ 횟수 |\n"
    standings += "| --- | --- | --- |\n"
    
    for i, (name, count) in enumerate(most_common_names, 1):
        if i == 1:
            medal = "🥇 1위"
        elif i == 2:
            medal = "🥈 2위"
        elif i == 3:
            medal = "🥉 3위"
        elif i == 4:
            medal = "🏅 4위"
        else:
            medal = "🎖️ 5위"
        
        standings += f"| {medal} | {name} | {count} |\n"
    
    content = HEADER + "\n" + standings + "\n" + content  # 목차 다음에 순위표 추가



    with open("README.md", "w") as fd:
        fd.write(content)
        
if __name__ == "__main__":
    main()
