import camera
from graphics import *
from appuifw import *
import e32
import key_codes
import time
import random

def exit_key_callback():
    global running
    running=0
    lock.signal()

def fetch_random_image():
    global cardlist0,cardlist1,cardlist2,cardcount
    chosen_list_num = random.randint(0,2)
    if chosen_list_num == 0 and len(cardlist0)>0:
        chosen_list = cardlist0
    elif chosen_list_num == 1 and len(cardlist1)>0:
        chosen_list = cardlist1
	cardcount=cardcount+1
    elif chosen_list_num == 2 and len(cardlist2)>0:
        chosen_list = cardlist2
	cardcount=cardcount-1
    else:
        return fetch_random_image()
    chosen = random.choice(chosen_list)
    chosen_list.remove(chosen)
    c.text((160,20),chosen, fill=0xffffff)
    return chosen


def refresh(rect):
    global c
    # clear screen to black
    c.clear(0)
    # draw the photo there
    c.blit(img1,target=(0,0))
    c.blit(img2,target=(0,112))
    c.blit(img3,target=(80,0))
    c.blit(img4,target=(80,112))
    # print some explanatory white text
    c.text((160,10),u'Text test', fill=0xffffff) 
#    c.text((160,20),cardlist[0], fill=0xffffff) 
#    c.text((160,30),cardlist[1], fill=0xffffff) 
    c.text((160,40),u'Count: '+unicode(cardcount), fill=0xffffff) 


def start():
    turns=1
    while turns<13:
        global img1,img2,img3,img4#,cardlist0
        imgpath='e:\\Python\\pycardcount\\'
        img1=Image.open(imgpath+fetch_random_image())
        img2=Image.open(imgpath+fetch_random_image())
        img3=Image.open(imgpath+fetch_random_image())
        img4=Image.open(imgpath+fetch_random_image())
        refresh(())
        e32.ao_sleep(4)
	turns=turns+1
    lock.signal()

def init():
    global c,img1,img2,img3,img4,cardlist0,cardlist1,cardlist2,cardcount
    # create an initial image and store it to photo
    img1=Image.new((75,107))
    img2=Image.new((75,107))
    img3=Image.new((75,107))
    img4=Image.new((75,107))
    # clear the photo to black
    img1.clear(0)
    img2.clear(0)
    img3.clear(0)
    img4.clear(0)

    #List of all cards, split up into three, telling if the card is a type
    # which adds or substracts one from the card count
    cardlist0=[\
       u'hearts-7-75.png',u'hearts-8-75.png',u'hearts-9-75.png',\
       u'diamonds-7-75.png',u'diamonds-8-75.png',u'diamonds-9-75.png',\
       u'clubs-7-75.png',u'clubs-8-75.png',u'clubs-9-75.png',\
       u'spades-7-75.png',u'spades-8-75.png',u'spades-9-75.png']
    cardlist1=[\
       u'hearts-2-75.png',u'hearts-3-75.png',u'hearts-4-75.png',\
       u'hearts-5-75.png',u'hearts-6-75.png',\
       u'diamonds-2-75.png',u'diamonds-3-75.png',u'diamonds-4-75.png',\
       u'diamonds-5-75.png',u'diamonds-6-75.png',\
       u'clubs-2-75.png',u'clubs-3-75.png',u'clubs-4-75.png',\
       u'clubs-5-75.png',u'clubs-6-75.png',\
       u'spades-2-75.png',u'spades-3-75.png',u'spades-4-75.png',\
       u'spades-5-75.png',u'spades-6-75.png']
    cardlist2=[\
       u'hearts-10-75.png',u'hearts-j-75.png',u'hearts-q-75.png',\
       u'hearts-k-75.png',u'hearts-a-75.png',\
       u'diamonds-10-75.png',u'diamonds-j-75.png',u'diamonds-q-75.png',\
       u'diamonds-k-75.png',u'diamonds-a-75.png',\
       u'clubs-10-75.png',u'clubs-j-75.png',u'clubs-q-75.png',\
       u'clubs-k-75.png',u'clubs-a-75.png',\
       u'spades-10-75.png',u'spades-j-75.png',u'spades-q-75.png',\
       u'spades-k-75.png',u'spades-a-75.png']

    #Global card counter 
    cardcount=0

    # create the canvas
    c=Canvas(redraw_callback=refresh)
    app.body=c
    app.exit_key_handler=exit_key_callback

    # bind certain keys to certain callback functions
    c.bind(key_codes.EKeySelect, start)
    #c.bind(key_codes.EKeyLeftArrow, rotate_left_callback)
    #c.bind(key_codes.EKeyRightArrow, rotate_right_callback)
    #c.bind(key_codes.EKeyDownArrow, save_callback)
    #c.bind(key_codes.EKeyUpArrow, load_images)



#Start of main loop:
init()
running=1
# create an active object
lock=e32.Ao_lock()
while running:
    # draw the screen again and again
    refresh(())
    # Wait for something to happen (start a scheduler)
    lock.wait()

