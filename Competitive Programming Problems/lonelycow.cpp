def lonely_photos(cow_lineup):
    # Initialize counter for lonely photos
    lonely_photos = 0

    # Iterate through the cow lineup
    for i in range(len(cow_lineup) - 2):
        # Get the breeds of the three consecutive cows
        cow1 = cow_lineup[i]
        cow2 = cow_lineup[i+1]
        cow3 = cow_lineup[i+2]

        # Check if any of the three cows are lonely
        if cow1 != cow2 or cow2 != cow3:
            lonely_photos += 1

    return lonely_photos

n=int(input())
s=input()
print(lonely_photos(s))