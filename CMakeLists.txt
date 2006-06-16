include_directories(${CMAKE_SOURCE_DIR}/lib ${CMAKE_SOURCE_DIR}/lib/interfaces ${CMAKE_SOURCE_DIR}/lib/util
    ${KDE3_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})


########### next target ###############

set(kdevvalgrind_PART_SRCS
    valgrind_dialog.cpp
    valgrind_part.cpp
    valgrindmodel.cpp
    valgrind_widget.cpp
    valgrinditem.cpp
)

kde4_automoc(${kdevvalgrind_PART_SRCS})

set(kdevvalgrind_PART_UI
    valgrind_dialog.ui
)

kde4_add_ui_files(kdevvalgrind_PART_SRCS ${kdevvalgrind_PART_UI})


kde4_add_plugin(kdevvalgrind ${kdevvalgrind_PART_SRCS})
target_link_libraries(kdevvalgrind ${KDE4_KDECORE_LIBS} ktexteditor kdevinterfaces)
kde4_install_libtool_file(${PLUGIN_INSTALL_DIR} kdevvalgrind)
install_targets(${PLUGIN_INSTALL_DIR} kdevvalgrind)


########### install files ###############

install_files(${SERVICES_INSTALL_DIR} FILES kdevvalgrind.desktop)
install_files(${DATA_INSTALL_DIR}/kdevvalgrind FILES kdevpart_valgrind.rc)
