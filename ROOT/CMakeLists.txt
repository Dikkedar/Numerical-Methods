cmake_minimum_required(VERSION 3.10)

###
#   ROOT SUPPORT
###
# find_package(ROOT 6.16 CONFIG REQUIRED) # causes errors

# Trying to add flags to compiler, not working I think
set(CFLAGS "-pthread -std=c++11 -m64 -I/home/emil/rootdir/include
")
set(GLIBS "-L/home/emil/rootdir/lib -lGui -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lROOTVecOps -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -lROOTDataFrame -pthread -lm -ldl -rdynamic
")
add_definitions(${CFLAGS})
add_definitions(${GLIBS})

###

# Linear algebra project
project(linearROOT)
add_executable(linearROOT ROOTLinearAlgebra.cxx)

# Numerical integration project
project(integrationROOT)
add_executable(integrationROOT ROOTIntegration.cxx)

# Equation solving project
project(equationROOT)
add_executable(equationROOT ROOTEquations.cxx)
