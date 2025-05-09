from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer
from rules import rules
import random
def query_process(usr_input):
    usr_input=usr_input.lower()
    tokens=word_tokenize(usr_input)
    stop_words=set(stopwords.words('english'))
    tokens=[word for word in tokens if word not in stop_words]
    lemmatizer=WordNetLemmatizer()
    tokens=[lemmatizer.lemmatize(token) for token in tokens]
    for keywords,responses in rules.items():
        for keyword in tokens:
            if(keyword in keywords):
                return random.choice(responses)
    return random.choice(["Can you rephrase?","Sorry!","Unable to answer!"])
def main():
    while(True):
        user_input=input("You >>")
        res=query_process(user_input)
        print("Bot >> "+res)
if __name__=="__main__":
    main()
