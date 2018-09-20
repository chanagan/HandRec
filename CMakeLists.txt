cmake_minimum_required(VERSION 3.12)
MACRO(DBG_MSG _MSG)
    MESSAGE(STATUS "${CMAKE_CURRENT_LIST_FILE}(${CMAKE_CURRENT_LIST_LINE}): ${_MSG}")
ENDMACRO(DBG_MSG)

project(HandRec)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include("${wxWidgets_USE_FILE}")
DBG_MSG("found wxWidgets_USE_FILE : ${wxWidgets_USE_FILE}")

set (SRCS main.cpp main.h MainFrame.cpp MainFrame.h InventoryDocument.cpp InventoryDocument.h InvStockItem.cpp InvStockItem.h)

add_executable(HandRec ${SRCS})
#add_executable(first_wx_app main.cpp main.h)

target_link_libraries(HandRec ${wxWidgets_LIBRARIES} sqlite3)
