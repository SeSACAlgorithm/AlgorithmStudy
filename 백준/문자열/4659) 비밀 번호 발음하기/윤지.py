import sys

vowels = "aeiou"

for line in sys.stdin:
    line = line.strip()

    if line == "end":
        break
        
    is_acceptable = True

    # 조건 1
    has_vowel = any(char in vowels for char in line)
    if not has_vowel:
        is_acceptable = False

    # 조건 2
    if is_acceptable:
        count = 1
        is_vowel = line[0] in vowels
        for i in range(1, len(line)):
            if (line[i] in vowels) == is_vowel: 
                count += 1
                if count >= 3:
                    is_acceptable = False
                    break
            else:
                count = 1
                is_vowel = line[i] in vowels

    # 조건 3
    if is_acceptable:
        for i in range(1, len(line)):
            if line[i] == line[i - 1] and line[i] not in "eo":
                is_acceptable = False
                break

    if is_acceptable:
        print(f"<{line}> is acceptable.")
    else:
        print(f"<{line}> is not acceptable.")
