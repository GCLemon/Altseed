﻿
import aceutils
import itertools

aceutils.cdToScript()
aceutils.mkdir('../Downloads')

with aceutils.CurrentDir('../Downloads'):
	aceutils.rmdir(r"osm_bin")
	aceutils.rmdir(r"osm_bin_x64")

	aceutils.mkdir(r"osm_bin")
	aceutils.mkdir(r"osm_bin_x64")

	with aceutils.CurrentDir('osm_bin'):
		if aceutils.isWin():
			aceutils.call(aceutils.cmd_cmake+r'-D USE_MSVC_RUNTIME_LIBRARY_DLL:BOOL=OFF ../OpenSoundMixer/')
			aceutils.call('cmake --build . --config Debug')
			aceutils.call('cmake --build . --config Release')
		elif aceutils.isMac():
			aceutils.call(r'cmake -G "Unix Makefiles" "-DCMAKE_OSX_ARCHITECTURES=x86_64' + (';i386' if aceutils.Isi386() else '') + r'" -D CMAKE_BUILD_TYPE=Release ../OpenSoundMixer/')
			aceutils.call(r'make')
		else:
			aceutils.call(r'cmake -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Release ../OpenSoundMixer/')
			aceutils.call(r'make')

	with aceutils.CurrentDir('osm_bin_x64'):
		if aceutils.isWin():
			aceutils.call(aceutils.cmd_cmake_x64+r'-D USE_MSVC_RUNTIME_LIBRARY_DLL:BOOL=OFF ../OpenSoundMixer/')
			aceutils.call('cmake --build . --config Debug')
			aceutils.call('cmake --build . --config Release')

	if aceutils.isWin():
		aceutils.copy(r'OpenSoundMixer/src/OpenSoundMixer.h', r'../Dev/include/')

		aceutils.copy(r'osm_bin/Debug/OpenSoundMixer.lib', r'../Dev/lib/x86/Debug/')
		aceutils.copy(r'osm_bin/Release/OpenSoundMixer.lib', r'../Dev/lib/x86/Release/')
		
		aceutils.copy(r'osm_bin_x64/Debug/OpenSoundMixer.lib', r'../Dev/lib/x64/Debug/')
		aceutils.copy(r'osm_bin_x64/Release/OpenSoundMixer.lib', r'../Dev/lib/x64/Release/')

	else:
		aceutils.copy(r'OpenSoundMixer/src/OpenSoundMixer.h', r'../Dev/include/')
		aceutils.copy(r'osm_bin/lib/libOpenSoundMixer.a', r'../Dev/lib/')
