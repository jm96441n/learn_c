arr = (1..5000).to_a
name = 'a'
email = 'a@a.com'
arr.each do |num|
	`./step_ex17 db.dat s  #{num} #{name} #{email}`
	name = name.next
	email = email.next
end
