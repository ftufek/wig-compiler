#!/usr/bin/env python
import cgi
import cgitb
import os
import uuid
import pickle
import copy
import sys
import traceback
cgitb.enable()
__cgi_input = cgi.FieldStorage(keep_blank_values=1)
__session = os.environ["QUERY_STRING"].split("&")[0]
sys.stderr = sys.stdout
__vars = {}
__sid = 0
__next_logic = 1

def __str_sid():
	if __sid != 0:
		return "&sid="+str(__sid)
	else:
		return ""

def __action_name():
	return os.path.basename(__file__)+"?"+__session+__str_sid()

def __layout(page):
	return """<html><form action="{action}" method="POST">
	{page} <input type="submit" value="go">
	</form></html>""".format(action=__action_name(),page=page)

def __Welcome(__varDict):
	return """ <body>
    Welcome to the riddle game!
  </body> """.format(**(__varDict))

def __Pick(__varDict):
	return """ <body>
    There are 5 riddles. You are allowed to make 3 choices.
    <p> 
    Please enter a number from 1 to 5:
    <input name="choice" size=1 type="text">
  </body> """.format(**(__varDict))

def __Trials(__varDict):
	return """ <body>
    Number of riddles read so far is: {trials}.
  </body> """.format(**(__varDict))

def __Retry(__varDict):
	return """ <body> 
    You have made an invalid choice!
    <p>
    Please enter a number between 1 and 5 only:
   <input name="choice" size=1 type="text">    
  </body> """.format(**(__varDict))

def __Riddle1(__varDict):
	return """ <body>
   A man is standing in front of a painting of a man, and he
  tells us the following: Brothers and sisters have I none, 
  but this man's father is my fathers son. Who's on the painting?
  <p>
  a) The Son
  <p> 
  b) The Father
  <p> 
  c) Himself
  </body> """.format(**(__varDict))

def __Riddle1Sol(__varDict):
	return """ <body>
    The Solution: His son
  <p>
    An Explanation
  <p>
  We can replace my fathers son by myself since he is 
  the only child. Now remains: This man s father is myself,
  so this man is his son.
  <p>   
   </body> """.format(**(__varDict))

def __Riddle2(__varDict):
	return """ <body>
  It is dark in my bedroom and I want to get two socks of the same color 
  from my drawer, which contains 24 red and 24 blue socks. How many socks 
  do I have to take from the drawer to get at least two socks of the same
  color?
  <p>
  a) 2
  <p> 
  b) 3
  <p> 
  c) 48
  <p> 
  d) 25   
  </body> """.format(**(__varDict))

def __Riddle2Sol(__varDict):
	return """ <body>
   The Solution: 3
  <p>
   An Explanation
  <p>
  It is clear that taking 0, 1, or 2 socks is not sufficient. But if you take
  3 socks, then either the first and second sock you take have the same 
  color, or the third sock you take from the drawer has the same color as 
  one of the previous two.
  <p>  
  </body> """.format(**(__varDict))

def __Riddle3(__varDict):
	return """ <body>
  A hunter leaves his cabin early in the morning and walks one mile due 
  south. Here he sees a bear and starts chasing it for one mile due east 
  before he is able to shoot the bear. After shooting the bear, he drags it 
  one mile due north back to his cabin where he started that morning. What 
  color is the bear?
  <p>
  a) Brown
  <p> 
  b) White
  <p> 
  c) Can not tell
  </body> """.format(**(__varDict))

def __Riddle3Sol(__varDict):
	return """ <body>
  The Solution: White
  <p>
  An Explanation
  <p>
  He can walk one mile due south, then one mile due east and finally one mile
  due north where he finds his cabin again. This means that his cabin can 
  only be at the north pole, and for that reason the bear will be white.
  <p>            
  </body> """.format(**(__varDict))

def __Riddle4(__varDict):
	return """ <body>
  One day Alice meets the Lion and the Unicorn in the Forest of 
  Forgetfulness. She knows that the Lion lies on Mondays, Tuesdays, and 
  Wednesdays, and tells the truth on the other days of the week. The 
  Unicorn, on the other hand, lies on Thursdays, Fridays, and Saturdays, 
  but tells the truth on the other days of the week. Now they make the 
  following statements to Alice:
  <p> 
     [*] Lion: Yesterday was one of my lying days.
  <p> 
     [*] Unicorn: Yesterday was one of my lying days too.
  <p>
  What day is it?
  <p> 
  a) Sunday<br> 
  b) Monday<br> 
  c) Tuesday<br> 
  d) Wednesday<br>             
  e) Thursday<br> 
  f) Friday<br> 
  g) Saturday<br>                       
  </body> """.format(**(__varDict))

def __Riddle4Sol(__varDict):
	return """ <body>
   The Solution: Thursday
  <p>
   An Explanation
  <p>
  The only days the Lion can say that he lied on the previous day are Mondays
  and Thursdays. The only days the Unicorn can say this, are Thursdays and
  Sundays. Therefore, the only day they both say that is on Thursday.
  <p>          
  </body> """.format(**(__varDict))

def __Riddle5(__varDict):
	return """ <body>
   A certain street contains 100 buildings. They are numbered from 1 to 100.
   How many 9 are used in these numbers?
  <p>
  a) 19
  <p> 
  b) 20
  <p> 
  c) 21     
  </body> """.format(**(__varDict))

def __Riddle5Sol(__varDict):
	return """ <body>
   The Solution: 20
  <p>
   An Explanation
  <p>
  Just count the nines in the numbers: 9, 19, 29, 39, 49, 59, 69, 79, 89, 90,
  91, 92, 93, 94, 95, 96, 97, 98, 99.      
  <p>   
  </body> """.format(**(__varDict))

def __Fin(__varDict):
	return """ <body>   
  Thanks for playing this game!
  <p>
  <A href="/~mdini">BACK</A>                                                    
  </body> """.format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_b8920453-6d47-41ca-bcbc-123459b87c1a"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_b8920453-6d47-41ca-bcbc-123459b87c1a"
	try:
		with open(global_vars_file, "r") as f:
			global_vars = pickle.load(f)
			__vars = dict(__vars.items() + global_vars.items())
	except IOError:
		return

__vars["choice_161_31"] = 0
__global_vars.append("choice_161_31")
__vars["__call_stack"] = []
__vars["__return_value"] = 0
__returned_from_fn = False

def __call_fn(fn_name):
	global __vars
	call_stack_copy = copy.deepcopy(__vars["__call_stack"])
	del __vars["__call_stack"]
	old_vars = copy.deepcopy(__vars)
	__vars["__call_stack"] = call_stack_copy
	__vars["__call_stack"].append({"name":fn_name,"next_logic":1, "old_vars":old_vars})

def __set_fn_logic(n):
	global __vars
	__vars["__call_stack"][-1]["next_logic"] = n

def __return_from_fn(return_value):
	global __returned_from_fn
	global __vars
	call_stack_copy = copy.deepcopy(__vars["__call_stack"])
	__vars = __vars["__call_stack"][-1]["old_vars"]
	call_stack_copy.pop()
	__vars["__call_stack"] = call_stack_copy
	__returned_from_fn = True
	__vars["__return_value"] = return_value

def __continue_stack_execution():
	while True:
		if __vars["__call_stack"]:
			fn_name = __vars["__call_stack"][-1]["name"]
			fn_ln = __vars["__call_stack"][-1]["next_logic"]
			globals()["__logic_fn_"+fn_name+"_"+str(fn_ln)]()
		else:
			break
		if not __returned_from_fn:
			break

def __save_session_Guess():
	session_file = "Guess$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_Guess():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_Guess()
	__logic_session_Guess_1()

def __load_session_Guess(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("Guess$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	__continue_stack_execution()
	globals()["__logic_session_Guess_"+str(__next_logic)]()

def __session_Guess():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_Guess()
	else:
		__load_session_Guess(sid)

def __logic_session_Guess_1():
	global __vars
	global __next_logic
	__vars["total_164_32"] = 0
	__next_logic = 2
	__save_session_Guess()
	__logic_session_Guess_2()
def __logic_session_Guess_3():
	global __vars
	global __next_logic
	print(__layout(__Welcome({})))
	__next_logic = 4
	__save_session_Guess()
def __logic_session_Guess_4():
	global __vars
	global __next_logic
	print(__layout(__Pick({})))
	__next_logic = 5
	__save_session_Guess()
def __logic_session_Guess_5():
	global __vars
	global __next_logic
	__vars["i_165_32"] = int(__cgi_input.getvalue("choice"))
	__next_logic = 6
	__save_session_Guess()
	__logic_session_Guess_6()
def __logic_session_Guess_6():
	global __vars
	global __next_logic
	__next_logic = 7
	__save_session_Guess()
	__logic_session_Guess_7()
def __logic_session_Guess_8():
	global __vars
	global __next_logic
	print(__layout(__Retry({})))
	__next_logic = 9
	__save_session_Guess()
def __logic_session_Guess_9():
	global __vars
	global __next_logic
	__vars["i_165_32"] = int(__cgi_input.getvalue("choice"))
	__next_logic = 10
	__save_session_Guess()
	__logic_session_Guess_10()
def __logic_session_Guess_10():
	global __vars
	global __next_logic
	__next_logic = 7
	__save_session_Guess()
	__logic_session_Guess_7()
def __logic_session_Guess_7():
	global __vars
	global __next_logic
	if __vars["i_165_32"] > 5 or __vars["i_165_32"] == 0:
		__next_logic = 8
		__save_session_Guess()
		__logic_session_Guess_8()
	else:
		__next_logic = 11
		__save_session_Guess()
		__logic_session_Guess_11()
	
def __logic_session_Guess_12():
	global __vars
	global __next_logic
	print(__layout(__Riddle1({})))
	__next_logic = 13
	__save_session_Guess()
def __logic_session_Guess_13():
	global __vars
	global __next_logic
	print(__layout(__Riddle1Sol({})))
	__next_logic = 14
	__save_session_Guess()
def __logic_session_Guess_14():
	global __vars
	global __next_logic
	__next_logic = 15
	__save_session_Guess()
	__logic_session_Guess_15()
def __logic_session_Guess_11():
	global __vars
	global __next_logic
	if __vars["i_165_32"] == 1:
		__next_logic = 12
		__save_session_Guess()
		__logic_session_Guess_12()
	else:
		__next_logic = 15
		__save_session_Guess()
		__logic_session_Guess_15()
	
def __logic_session_Guess_16():
	global __vars
	global __next_logic
	print(__layout(__Riddle2({})))
	__next_logic = 17
	__save_session_Guess()
def __logic_session_Guess_17():
	global __vars
	global __next_logic
	print(__layout(__Riddle2Sol({})))
	__next_logic = 18
	__save_session_Guess()
def __logic_session_Guess_18():
	global __vars
	global __next_logic
	__next_logic = 19
	__save_session_Guess()
	__logic_session_Guess_19()
def __logic_session_Guess_15():
	global __vars
	global __next_logic
	if __vars["i_165_32"] == 2:
		__next_logic = 16
		__save_session_Guess()
		__logic_session_Guess_16()
	else:
		__next_logic = 19
		__save_session_Guess()
		__logic_session_Guess_19()
	
def __logic_session_Guess_20():
	global __vars
	global __next_logic
	print(__layout(__Riddle3({})))
	__next_logic = 21
	__save_session_Guess()
def __logic_session_Guess_21():
	global __vars
	global __next_logic
	print(__layout(__Riddle3Sol({})))
	__next_logic = 22
	__save_session_Guess()
def __logic_session_Guess_22():
	global __vars
	global __next_logic
	__next_logic = 23
	__save_session_Guess()
	__logic_session_Guess_23()
def __logic_session_Guess_19():
	global __vars
	global __next_logic
	if __vars["i_165_32"] == 3:
		__next_logic = 20
		__save_session_Guess()
		__logic_session_Guess_20()
	else:
		__next_logic = 23
		__save_session_Guess()
		__logic_session_Guess_23()
	
def __logic_session_Guess_24():
	global __vars
	global __next_logic
	print(__layout(__Riddle4({})))
	__next_logic = 25
	__save_session_Guess()
def __logic_session_Guess_25():
	global __vars
	global __next_logic
	print(__layout(__Riddle4Sol({})))
	__next_logic = 26
	__save_session_Guess()
def __logic_session_Guess_26():
	global __vars
	global __next_logic
	__next_logic = 27
	__save_session_Guess()
	__logic_session_Guess_27()
def __logic_session_Guess_23():
	global __vars
	global __next_logic
	if __vars["i_165_32"] == 4:
		__next_logic = 24
		__save_session_Guess()
		__logic_session_Guess_24()
	else:
		__next_logic = 27
		__save_session_Guess()
		__logic_session_Guess_27()
	
def __logic_session_Guess_28():
	global __vars
	global __next_logic
	print(__layout(__Riddle5({})))
	__next_logic = 29
	__save_session_Guess()
def __logic_session_Guess_29():
	global __vars
	global __next_logic
	print(__layout(__Riddle5Sol({})))
	__next_logic = 30
	__save_session_Guess()
def __logic_session_Guess_30():
	global __vars
	global __next_logic
	__next_logic = 31
	__save_session_Guess()
	__logic_session_Guess_31()
def __logic_session_Guess_27():
	global __vars
	global __next_logic
	if __vars["i_165_32"] == 5:
		__next_logic = 28
		__save_session_Guess()
		__logic_session_Guess_28()
	else:
		__next_logic = 31
		__save_session_Guess()
		__logic_session_Guess_31()
	
def __logic_session_Guess_31():
	global __vars
	global __next_logic
	__vars["total_164_32"] = __vars["total_164_32"] + 1
	print(__layout(__Trials({'trials':__vars["total_164_32"]})))
	__next_logic = 32
	__save_session_Guess()
def __logic_session_Guess_33():
	global __vars
	global __next_logic
	print(__layout(__Fin({})))
	__next_logic = 34
	__save_session_Guess()
def __logic_session_Guess_34():
	global __vars
	global __next_logic
	__next_logic = 35
	__save_session_Guess()
	__logic_session_Guess_35()
def __logic_session_Guess_32():
	global __vars
	global __next_logic
	if __vars["total_164_32"] == 3:
		__next_logic = 33
		__save_session_Guess()
		__logic_session_Guess_33()
	else:
		__next_logic = 35
		__save_session_Guess()
		__logic_session_Guess_35()
	
def __logic_session_Guess_35():
	global __vars
	global __next_logic
	__next_logic = 2
	__save_session_Guess()
	__logic_session_Guess_2()
def __logic_session_Guess_2():
	global __vars
	global __next_logic
	if __vars["total_164_32"] != 3:
		__next_logic = 3
		__save_session_Guess()
		__logic_session_Guess_3()
	else:
		__next_logic = 36
		__save_session_Guess()
		__logic_session_Guess_36()
	
def __logic_session_Guess_36():
	global __vars
	global __next_logic
	__next_logic = 35
	__save_session_Guess()
	__logic_session_Guess_35()
print "Content-type: text/html"
print
__load_global_vars()
if __session == "Guess":
	__session_Guess()
else:
	print __layout("Please select one of the following sessions: Guess")
__save_global_vars()

