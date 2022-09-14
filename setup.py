from setuptools import setup, Extension, find_packages

setup(
	name='cgy_ext',
	version='0.0.1',
	packages=find_packages(),
	ext_modules=[Extension('cgy_ext', ['src/cgy_ext.c'])]
)
