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

def ins_sort(nums):
	length = len(nums)
	for i in range(1, length-1):
		key = nums[i]
		j = i-1
		while j >= 0 and key < nums[j]:
			nums[j+1] = nums[j]
			j = j-1
		nums[j+1] = key

nums = read_in("data")
ins_sort(nums)
write_out("result", nums)
