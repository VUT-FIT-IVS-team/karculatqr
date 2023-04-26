#!/usr/bin/python3
import random
import sys
import argparse


def generate_numbers(filename, n):
	with open(filename, 'w') as f:
		for i in range(n):
			f.write(str(random.randint(i, i+1000)) + '\n')


def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('filename', help='The file to write the numbers to')
	parser.add_argument('n', help='The number of numbers to generate', type=int)
	args = parser.parse_args()
	generate_numbers(args.filename, args.n)


if __name__ == '__main__':
	main()
