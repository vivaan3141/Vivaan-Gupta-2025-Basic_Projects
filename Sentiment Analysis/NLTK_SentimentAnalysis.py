import nltk
from nltk.sentiment import SentimentIntensityAnalyzer
analy = SentimentIntensityAnalyzer()

while (True):
    print ("Text")
    i=input()
    texts = [i]

    for text in texts:
        score = analy.polarity_scores(text)
        avgScore = score['compound']
    
        if avgScore >= 0.05:
            sen = "pos"
        elif avgScore <= -0.05:
            sen = "neg"
        else:
            sen = "mid"

        print("score:", avgScore, sen, "\n")
