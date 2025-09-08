emojis = {":)": "🙂",
    ":(": "🙁",
    ";)": "😉",
    ":D": "😄"
}

text= input("Enter your text:" )

for emoticons, emoji in emojis.items():
    text = text.replace(emoticons, emoji)

print(text)