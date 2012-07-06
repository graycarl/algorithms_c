#!/usr/bin/env python

def read_in(filename):
	f = file(filename, 'r')
	nums = []
	for s in f: nums.append(int(s))
	return nums

def write_out(filename, nums):
	strs = [ str(n) for n in nums]
	file(filename, 'w').write("\n".join(strs))
	return

def bob_sort(nums):
	length = len(nums)
	for i in range(0, length-1):
		for j in range(length-1, i, -1):
			if (nums[j] < nums[j-1]):
				n = nums[j]
				nums[j] = nums[j-1]
				nums[j-1] = n

nums = read_in("data")
bob_sort(nums)
write_out("result", nums)
