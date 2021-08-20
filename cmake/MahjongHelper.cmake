
#
# Install needed qt plugins to destination
#
# Usage:
#   install_qt_plugin(<qtTargets> <destination>)
#
# <qtTargets> is a list containing the Qt5 targets of the plugins (it has to be given to the macro using "" if it contains more than one target)
# <destination> directory where the files will be installed (will be appended to CMAKE_INSTALL_PREFIX)
#
#
macro(install_qt_plugins qtTargets destination)

    set(deps)

    foreach(target ${qtTargets})
        get_target_property(targetFile ${target} LOCATION)
        list(APPEND deps "${targetFile}")
    endforeach()

    install(FILES
        ${deps}
        DESTINATION "${destination}"
    )

endmacro(install_qt_plugins)
