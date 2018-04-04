require 'pry'
class Stack
	attr_accessor :head, :tail
	def initialize
		@head = nil
		@tail = nil
	end

	def push(value)
		if @head
			node = Node.new(data: value, next: @head)
		else
			node = Node.new(data: value)
		end
		@head = node
	end

	def pop
		puts "Stack Underflow" if isEmpty?
		@head = @head.next
	end

	def isEmpty?
		@head.nil?
	end

	def peek
		puts "Nothing to see here" if isEmpty?
		@head.print_node if @head
	end
end

class Node
	attr_reader :data
	attr_accessor :next
	def initialize(args)
		@data = args[:data]
		@next = args[:next] || nil
	end

	def print_node
		puts self.data
	end
end

stack = Stack.new

stack.push(10)
stack.peek
stack.push(20)
stack.peek
stack.push(30)
stack.peek
stack.pop
stack.peek
puts stack.isEmpty?
stack.pop
stack.peek
puts stack.isEmpty?
stack.pop
stack.peek
puts stack.isEmpty?
