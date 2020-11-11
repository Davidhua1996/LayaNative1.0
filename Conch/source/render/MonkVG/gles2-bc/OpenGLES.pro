######################################################################
# Automatically generated by qmake (2.01a) Mon Feb 4 13:38:40 2013
######################################################################

CONFIG -= qt
CONFIG += debug
TEMPLATE = lib
TARGET = gles2-bc
DEFINES += USE_SYSTEM_FMEMOPEN OPENGLES_DEBUG
DEPENDPATH += . OpenGLES11 OpenGLES20 OpenGLES20/shaders
INCLUDEPATH += . OpenGLES20/shaders OpenGLES11 OpenGLES20
LIBS += -lGLESv2 -lGLESv1_CM
# Input
HEADERS += OpenGLESConfig.h \
           OpenGLESContext.h \
           OpenGLESFile.h \
           OpenGLESImplementation.h \
           OpenGLESMath.h \
           OpenGLESPlatform.h \
           OpenGLESString.h \
           OpenGLESUtil.h \
           OpenGLES11/OpenGLES11Context.h \
           OpenGLES11/OpenGLES11Implementation.h \
           OpenGLES20/Attribute.h \
           OpenGLES20/MatrixStack.h \
           OpenGLES20/OpenGLES20Context.h \
           OpenGLES20/OpenGLES20Implementation.h \
           OpenGLES20/OpenGLESState.h \
           OpenGLES20/Shader.h \
           OpenGLES20/ShaderFile.h \
           OpenGLES20/ShaderProgram.h \
           OpenGLES20/ShaderSource.h \
           OpenGLES20/Uniform.h \
           OpenGLES20/shaders/all_shaders.h \
           OpenGLES20/shaders/alphaTest.frag.h \
           OpenGLES20/shaders/clipPlane.frag.h \
           OpenGLES20/shaders/clipPlane.vert.h \
           OpenGLES20/shaders/lighting.frag.h \
           OpenGLES20/shaders/lighting.vert.h \
           OpenGLES20/shaders/lightingPerFragment.frag.h \
           OpenGLES20/shaders/lightingPerFragment.vert.h \
           OpenGLES20/shaders/lightingPerVertex.vert.h \
           OpenGLES20/shaders/main.frag.h \
           OpenGLES20/shaders/main.vert.h \
           OpenGLES20/shaders/postprocess.frag.h \
           OpenGLES20/shaders/postprocess.vert.h \
           OpenGLES20/shaders/texture.frag.h \
           OpenGLES20/shaders/texture.vert.h \
           OpenGLES20/shaders/texture0.frag.h \
           OpenGLES20/shaders/texture0.vert.h \
           OpenGLES20/shaders/texture1.frag.h \
           OpenGLES20/shaders/texture1.vert.h \
           OpenGLES20/shaders/texture2.frag.h \
           OpenGLES20/shaders/texture2.vert.h
SOURCES += OpenGLESConfig.cpp \
           OpenGLESContext.cpp \
           OpenGLESFile.cpp \
           OpenGLESImplementation.cpp \
           OpenGLESString.cpp \
           OpenGLESUtil.cpp \
           OpenGLES11/OpenGLES11Context.cpp \
           OpenGLES11/OpenGLES11Implementation.cpp \
           OpenGLES20/Attribute.cpp \
           OpenGLES20/MatrixStack.cpp \
           OpenGLES20/OpenGLES20Context.cpp \
           OpenGLES20/OpenGLES20Implementation.cpp \
           OpenGLES20/OpenGLESState.cpp \
           OpenGLES20/Shader.cpp \
           OpenGLES20/ShaderFile.cpp \
           OpenGLES20/ShaderProgram.cpp \
           OpenGLES20/ShaderSource.cpp \
           OpenGLES20/Uniform.cpp
