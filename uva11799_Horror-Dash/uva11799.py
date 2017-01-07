# python 3.5.2
# one linear scan to find the max value

strTestCase = input()
iTestCase = int(strTestCase)
lStudentSpeed = []

for i in range(1,iTestCase+1):
	iMaxSpeed = 0;
	strStudentSpeed = input()
	lStudentSpeed = strStudentSpeed.split(" ")
	for speed in lStudentSpeed:
		if (iMaxSpeed < int(speed)):
			iMaxSpeed = int(speed)
	print ("Case %d: %d"%(i,iMaxSpeed))

