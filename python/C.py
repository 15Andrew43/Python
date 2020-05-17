import sys
import traceback


def force_load(name):
	filename = name + '.py'
	file = open(filename, "r")
	lines = file.readlines()
	ldict = {}
	for i in range(len(lines)):
		try:
			exec(''.join(lines), globals(), ldict)
		except Exception:
			cl, exc, tb = sys.exc_info()
			line_number = traceback.extract_tb(tb)[-1][1]
			lines.pop(line_number - 1)
		except SyntaxError as se:
			lines.pop(se.lineno - 1)
	file.close()
	result = {}
	exec(''.join(lines), globals(), result)
	return result
