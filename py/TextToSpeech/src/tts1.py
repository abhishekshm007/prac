'''
Created on 01-Aug-2015

@author: abhishek
'''

from gtts import gTTS
from tempfile import TemporaryFile
tts = gTTS(text='Hello', lang='en')
f = TemporaryFile()
tts.write_to_fp(f)
f.close()
