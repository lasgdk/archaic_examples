import appuifw
import messaging
import e32

recv = appuifw.query(u"Type receivers number:", "number")
msg = appuifw.query(u"Type the payload:", "text")
count = appuifw.query(u"Type the number of messages:", "number")
i = 0
if appuifw.query(u"Send "+unicode(count)+" messages to "+unicode(recv),"query") == True:
    while i < count:
        messaging.sms_send(str(recv), msg+str(i))
	e32.ao_sleep(2)
	i = i+1
    appuifw.note(u"Messages sent", "info")
else:
    appuifw.note(u"Error, your Messages are not sent", "info")

