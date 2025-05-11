import nltk
from rules import rules;
from nltk.tokenize import word_tokenize;
from nltk.stem import WordNetLemmatizer
from nltk.corpus import stopwords
import random
def process(str):
    str=str.lower()
    tokens=word_tokenize(str)
    print("Tokens after word tokenize: ",tokens)
    stop_words=set(stopwords.words('english'))
    tokens=[word for word in tokens if word not in stop_words]
    print("Tokens after removal of stopwords",tokens)
    lemmatizer=WordNetLemmatizer()
    tokens=[lemmatizer.lemmatize(word) for word in tokens]
    print("Tokens after lemmatization",tokens)
    for keys,values in rules.items():
        for key in keys:
            if key in tokens:
                return random.choice(values)
    return random.choice(["can you rephrase?","Sorry,unable to give answer"])
    
