# Merge sort in ruby before C implementation is ex18
require 'rspec'

def merge_sort(arr)
	if arr.length == 1
		return arr
	end

	first_half = arr[0...arr.length/2]
	second_half = arr[arr.length/2...arr.length]

	first_half = merge_sort(first_half)
	second_half = merge_sort(second_half)

	merge(first_half, second_half)
end

def merge(first, second)
	sorted_arr = []
	while first.length > 0 && second.length > 0
		if first[0] > second[0]
			sorted_arr << second.shift
		else
			sorted_arr << first.shift
		end
	end
	while first.length > 0
		sorted_arr << first.shift
	end

	while second.length > 0
		sorted_arr << second.shift
	end
	sorted_arr
end


RSpec.describe 'MergSort' do
	let(:arr1) { [7,2,5,3,9,1] }
	let(:arr2) { [3,7,2,4,3,8] }
	let(:arr3) { [5,8,2,3,5,6,2] }
	
	it 'sorts an array with one instance of each number in it' do
		expect(merge_sort(arr1)).to eq([1,2,3,5,7,9])
	end

	it 'sorts an array with multiple instances of a number in it' do
		expect(merge_sort(arr2)).to eq([2,3,3,4,7,8])
	end

	it 'sorts an array with an odd number of elements' do
		expect(merge_sort(arr3)).to eq([2,2,3,5,5,6,8])
	end
end
