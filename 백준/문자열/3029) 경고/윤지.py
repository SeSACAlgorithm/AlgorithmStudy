def parse(time):
    hh, mm, ss = map(int, time.split(':'))
    return hh * 3600 + mm * 60 + ss

def seconds(seconds):
    hh = seconds // 3600
    mm = (seconds % 3600) // 60
    ss = seconds % 60
    return f"{hh:02}:{mm:02}:{ss:02}"

def calculate(current_time_str, throw_time_str):
    current_seconds = parse(current_time_str)
    throw_seconds = parse(throw_time_str)

    if throw_seconds >= current_seconds:
        wait_seconds = throw_seconds - current_seconds
    else:
        wait_seconds = (24 * 3600) - current_seconds + throw_seconds

    if wait_seconds == 0:
        wait_seconds = 24 * 3600

    return seconds(wait_seconds)

current_time = input()
throw_time = input()

ans = calculate(current_time, throw_time)
print(ans)
