from distutils.core import setup, Extension

vdn_vcrypt_module = Extension('vdn_vcrypt',
                               sources = ['vcryptmodule.c',
                                          'vcrypt.c'],
                               include_dirs=['.'])

setup (name = 'vdn_vcrypt',
       version = '1.0',
       description = 'Bindings for vCrypt proof of work used by vDinar',
       ext_modules = [vdn_vcrypt_module])
