import pyttsx
engine = pyttsx.init()

rate = engine.getProperty('rate')
voices = engine.getProperty('voices')
for voice in voices:
    if voice.name == 'english':
        engine.setProperty('age', 10)
        print "Using voice:", (voice.name), voice.age
        engine.setProperty('rate', rate-0)
        
        engine.say("Hi there, how's you ?")
        engine.say("Violet        Indigo         Blue          Green         Yellow       Orange         Red")
        engine.say("Apple Banana Cherry Date Guava")
engine.runAndWait()
  
