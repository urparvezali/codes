def max_rest_days(n, t, l, P):
    rest_days = 0
    total_points = 0
    tasks_completed = 0

    for day in range(1, n + 1):
        # If Monocarp decides to study
        if tasks_completed < 2 and (day % 7 == 1 or tasks_completed > 0):
            # Calculate points for attending a lesson
            total_points += l
            tasks_completed += 1
        else:
            # Monocarp rests
            rest_days += 1
            tasks_completed = 0  # Reset the completed tasks for the next study day

    # Calculate points for the remaining tasks
    total_points += min((n // 7) * t, 2 * t)

    # Check if the total points meet the requirement
    if total_points >= P:
        return rest_days
    else:
        return -1  # Monocarp cannot meet the requirement

def solution(T):
    n,P,l,t=map(int,input().split())

    result = max_rest_days(n, t, l, P)
    if result != -1:
        print(f"{result}")
    else:
        print("-1")


TT=1
TT=int(input())
for T in range(1,TT+1):
    solution(T)