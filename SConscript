# SConscript file
# Effectively the contents of a normal Sconstruct file -- allows the use of VarientDir for changing the build output directory

# Basic SConstruct file for use with SFML and a simple project/folder structure

execName = 'foth'

includeDirs = ['./include', './include/StateManager', '/usr/include',
               './include/ResourceManager']

env = Environment(CPPPATH = includeDirs,
                  LIBPATH = ['./lib', '/usr/lib'],
                  LIBS = ['sfml-window', 'sfml-system', 'sfml-graphics',
                          'sfml-state-man'],
                  CXXFLAGS = "-std=c++11")

env.Program(target = '../' + execName, source = Glob('src/*.cpp'))
