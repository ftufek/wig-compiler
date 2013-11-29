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

def __GetSeed(__varDict):
	return """ <body>
    Please enter an integer seed for the random number generator: 
    <input name="seed" size=5 type="text">
  </body> """.format(**(__varDict))

def __GameSeeded(__varDict):
	return """ <body>
    Ok, now the game can proceed, the generator is seeded. 
  </body> """.format(**(__varDict))

def __Init(__varDict):
	return """ <body>
    Please guess a number between 0 and 99:
    <input name="guess" size=2 type="text">
  </body> """.format(**(__varDict))

def __Retry(__varDict):
	return """ <body>
    That number is too large!
    <p>
    Please keep your guess between 0 and 99:
    <input name="guess" size=2 type="text">
  </body> """.format(**(__varDict))

def __Again(__varDict):
	return """ <body>
    That is not correct. Try a {correction} number:
    <input name="guess" size=2 type="text">
  </body> """.format(**(__varDict))

def __Done(__varDict):
	return """ <body>
    You got it, using {trys} guesses.
  </body> """.format(**(__varDict))

def __Record(__varDict):
	return """ <body>
    That makes you the new record holder,
    beating the old record of {old} guesses.
    <p>
    Please enter your name for the hi-score list
    <input name="name" size=20 type="text">
  </body> """.format(**(__varDict))

def __Finish(__varDict):
	return """ <body>
    Thanks for playing this exciting game.
  </body> """.format(**(__varDict))

def __List(__varDict):
	return """ <body>
    In {plays} plays of this game, the record
    holder is {holder} with {record} guesses.
  </body> """.format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_0377c816-426b-4624-a4d1-a6143a577b1c"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_0377c816-426b-4624-a4d1-a6143a577b1c"
	try:
		with open(global_vars_file, "r") as f:
			global_vars = pickle.load(f)
			__vars = dict(__vars.items() + global_vars.items())
	except IOError:
		return

__vars["plays_49_19"] = 0
__global_vars.append("plays_49_19")
__vars["record_49_19"] = 0
__global_vars.append("record_49_19")
__vars["seed_50_19"] = 0
__global_vars.append("seed_50_19")
__vars["holder_51_19"] = ""
__global_vars.append("holder_51_19")
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

def __logic_fn_nextRandom_1():
	global __vars
	global __next_logic
	
	__call_fn("nextRandom")
	__set_fn_logic(2)
	__logic_fn_nextRandom_2()
def __logic_fn_nextRandom_2():
	global __vars
	global __next_logic
	
	__vars["seed_50_19"] = 25173 * __vars["seed_50_19"] + 13849 % 65536
	__return_from_fn(__vars["seed_50_19"])
def __save_session_Seed():
	session_file = "Seed$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_Seed():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_Seed()
	__logic_session_Seed_1()

def __load_session_Seed(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("Seed$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	__continue_stack_execution()
	globals()["__logic_session_Seed_"+str(__next_logic)]()

def __session_Seed():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_Seed()
	else:
		__load_session_Seed(sid)

def __logic_session_Seed_1():
	global __vars
	global __next_logic
	print(__layout(__GetSeed({})))
	__next_logic = 2
	__save_session_Seed()
def __logic_session_Seed_2():
	global __vars
	global __next_logic
	__vars["seed_50_19"] = int(__cgi_input.getvalue("seed"))
	__next_logic = 3
	__save_session_Seed()
	__logic_session_Seed_3()
def __logic_session_Seed_3():
	global __vars
	global __next_logic
	print(__layout(__GameSeeded({})))
	__next_logic = 4
	__save_session_Seed()
def __logic_session_Seed_4():
	global __vars
	global __next_logic
	__next_logic = 3
	__save_session_Seed()
	__logic_session_Seed_3()
def __save_session_Play():
	session_file = "Play$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_Play():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_Play()
	__logic_session_Play_1()

def __load_session_Play(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("Play$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	__continue_stack_execution()
	globals()["__logic_session_Play_"+str(__next_logic)]()

def __session_Play():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_Play()
	else:
		__load_session_Play(sid)

def __logic_session_Play_1():
	global __vars
	global __next_logic
	global __vars
	__logic_fn_nextRandom_1()
	__next_logic = 2
	__save_session_Play()
	__logic_session_Play_2()
def __logic_session_Play_2():
	global __vars
	global __next_logic
	global __returned_from_fn
	if __returned_from_fn:
		__returned_from_fn = False
		__vars["2e50cb3f-da43-4439-9225-f24ede1b87ae"] = __vars["__return_value"]
		__next_logic = 3
		__save_session_Play()
		__logic_session_Play_3()
	else:
		__save_session_Play()
	
def __logic_session_Play_3():
	global __vars
	global __next_logic
	__vars["number_66_24"] = __vars["2e50cb3f-da43-4439-9225-f24ede1b87ae"] % 100
	__vars["plays_49_19"] = __vars["plays_49_19"] + 1
	__vars["guesses_66_24"] = 1
	print(__layout(__Init({})))
	__next_logic = 4
	__save_session_Play()
def __logic_session_Play_4():
	global __vars
	global __next_logic
	__vars["guess_66_24"] = int(__cgi_input.getvalue("guess"))
	__next_logic = 5
	__save_session_Play()
	__logic_session_Play_5()
def __logic_session_Play_5():
	global __vars
	global __next_logic
	__next_logic = 6
	__save_session_Play()
	__logic_session_Play_6()
def __logic_session_Play_7():
	global __vars
	global __next_logic
	print(__layout(__Retry({})))
	__next_logic = 8
	__save_session_Play()
def __logic_session_Play_8():
	global __vars
	global __next_logic
	__vars["guess_66_24"] = int(__cgi_input.getvalue("guess"))
	__next_logic = 9
	__save_session_Play()
	__logic_session_Play_9()
def __logic_session_Play_9():
	global __vars
	global __next_logic
	__next_logic = 6
	__save_session_Play()
	__logic_session_Play_6()
def __logic_session_Play_6():
	global __vars
	global __next_logic
	if __vars["guess_66_24"] > 99:
		__next_logic = 7
		__save_session_Play()
		__logic_session_Play_7()
	else:
		__next_logic = 10
		__save_session_Play()
		__logic_session_Play_10()
	
def __logic_session_Play_10():
	global __vars
	global __next_logic
	__next_logic = 11
	__save_session_Play()
	__logic_session_Play_11()
def __logic_session_Play_12():
	global __vars
	global __next_logic
	__vars["guesses_66_24"] = __vars["guesses_66_24"] + 1
	__next_logic = 13
	__save_session_Play()
	__logic_session_Play_13()
def __logic_session_Play_14():
	global __vars
	global __next_logic
	print(__layout(__Again({'correction':"lower"})))
	__next_logic = 15
	__save_session_Play()
def __logic_session_Play_15():
	global __vars
	global __next_logic
	__vars["guess_66_24"] = int(__cgi_input.getvalue("guess"))
	__next_logic = 16
	__save_session_Play()
	__logic_session_Play_16()
def __logic_session_Play_16():
	global __vars
	global __next_logic
	print(__layout(__Again({'correction':"higher"})))
	__next_logic = 17
	__save_session_Play()
def __logic_session_Play_17():
	global __vars
	global __next_logic
	__vars["guess_66_24"] = int(__cgi_input.getvalue("guess"))
	__next_logic = 18
	__save_session_Play()
	__logic_session_Play_18()
def __logic_session_Play_18():
	global __vars
	global __next_logic
	__next_logic = 20
	__save_session_Play()
	__logic_session_Play_20()
def __logic_session_Play_19():
	global __vars
	global __next_logic
	__next_logic = 20
	__save_session_Play()
	__logic_session_Play_20()
def __logic_session_Play_13():
	global __vars
	global __next_logic
	if __vars["guess_66_24"] > __vars["number_66_24"]:
		__next_logic = 14
		__save_session_Play()
		__logic_session_Play_14()
	else:
		__next_logic = 16
		__save_session_Play()
		__logic_session_Play_16()
	
def __logic_session_Play_20():
	global __vars
	global __next_logic
	__next_logic = 21
	__save_session_Play()
	__logic_session_Play_21()
def __logic_session_Play_22():
	global __vars
	global __next_logic
	print(__layout(__Retry({})))
	__next_logic = 23
	__save_session_Play()
def __logic_session_Play_23():
	global __vars
	global __next_logic
	__vars["guess_66_24"] = int(__cgi_input.getvalue("guess"))
	__next_logic = 24
	__save_session_Play()
	__logic_session_Play_24()
def __logic_session_Play_24():
	global __vars
	global __next_logic
	__next_logic = 21
	__save_session_Play()
	__logic_session_Play_21()
def __logic_session_Play_21():
	global __vars
	global __next_logic
	if __vars["guess_66_24"] > 99:
		__next_logic = 22
		__save_session_Play()
		__logic_session_Play_22()
	else:
		__next_logic = 25
		__save_session_Play()
		__logic_session_Play_25()
	
def __logic_session_Play_25():
	global __vars
	global __next_logic
	__next_logic = 11
	__save_session_Play()
	__logic_session_Play_11()
def __logic_session_Play_11():
	global __vars
	global __next_logic
	if __vars["guess_66_24"] != __vars["number_66_24"]:
		__next_logic = 12
		__save_session_Play()
		__logic_session_Play_12()
	else:
		__next_logic = 26
		__save_session_Play()
		__logic_session_Play_26()
	
def __logic_session_Play_26():
	global __vars
	global __next_logic
	print(__layout(__Done({'trys':__vars["guesses_66_24"]})))
	__next_logic = 27
	__save_session_Play()
def __logic_session_Play_28():
	global __vars
	global __next_logic
	print(__layout(__Record({'old':__vars["record_49_19"]})))
	__next_logic = 29
	__save_session_Play()
def __logic_session_Play_29():
	global __vars
	global __next_logic
	__vars["localholder_67_24"] = __cgi_input.getvalue("name")
	__next_logic = 30
	__save_session_Play()
	__logic_session_Play_30()
def __logic_session_Play_30():
	global __vars
	global __next_logic
	__vars["holder_51_19"] = __vars["localholder_67_24"]
	__vars["record_49_19"] = __vars["guesses_66_24"]
	__next_logic = 31
	__save_session_Play()
	__logic_session_Play_31()
def __logic_session_Play_27():
	global __vars
	global __next_logic
	if __vars["record_49_19"] == 0 or __vars["record_49_19"] > __vars["guesses_66_24"]:
		__next_logic = 28
		__save_session_Play()
		__logic_session_Play_28()
	else:
		__next_logic = 31
		__save_session_Play()
		__logic_session_Play_31()
	
def __logic_session_Play_31():
	global __vars
	global __next_logic
	print(__layout(__Finish({})))
	__next_logic = 32
	__save_session_Play()
def __logic_session_Play_32():
	global __vars
	global __next_logic
	__next_logic = 31
	__save_session_Play()
	__logic_session_Play_31()
def __save_session_HiScore():
	session_file = "HiScore$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_HiScore():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_HiScore()
	__logic_session_HiScore_1()

def __load_session_HiScore(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("HiScore$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	__continue_stack_execution()
	globals()["__logic_session_HiScore_"+str(__next_logic)]()

def __session_HiScore():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_HiScore()
	else:
		__load_session_HiScore(sid)

def __logic_session_HiScore_1():
	global __vars
	global __next_logic
	print(__layout(__List({'plays':__vars["plays_49_19"],'holder':__vars["holder_51_19"]
	,'record':__vars["record_49_19"]
	})))
	__next_logic = 2
	__save_session_HiScore()
def __logic_session_HiScore_2():
	global __vars
	global __next_logic
	__next_logic = 1
	__save_session_HiScore()
	__logic_session_HiScore_1()
print "Content-type: text/html"
print
__load_global_vars()
if __session == "Seed":
	__session_Seed()
elif __session == "Play":
	__session_Play()
elif __session == "HiScore":
	__session_HiScore()
else:
	print __layout("Please select one of the following sessions: Seed, Play, HiScore")
__save_global_vars()

