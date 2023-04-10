import digit_count_module

output_thing = digit_count_module.get_digit_count_for_integers([12345, 123123123, 2, 234])
print(output_thing)

output_thing = digit_count_module.get_digit_count_for_integers([12, 984, 9456756, 6, 4, 2334, 1000])
print(output_thing)

output_thing = digit_count_module.get_digit_count_for_integers([1, 234234, 0])
print(output_thing)

output_thing = digit_count_module.get_digit_count_for_integers([100])
print(output_thing)

output_thing = digit_count_module.get_digit_count_for_integers([])
print(output_thing)
