// This file has been generated by Py++.

#include "boost/python.hpp"

#include "generators/include/python_CEGUIOpenGLRenderer.h"

#include "OpenGL3Renderer.pypp.hpp"

#include "OpenGL3Shader.pypp.hpp"

#include "OpenGL3StateChangeWrapper.pypp.hpp"

#include "OpenGLGeometryBufferBase.pypp.hpp"

#include "OpenGLRenderer.pypp.hpp"

#include "OpenGLRendererBase.pypp.hpp"

#include "OpenGLTextureTarget.pypp.hpp"

#include "OpenGLViewportTarget.pypp.hpp"

namespace bp = boost::python;

BOOST_PYTHON_MODULE(PyCEGUIOpenGLRenderer){
    register_OpenGLRendererBase_class();

    register_OpenGL3Renderer_class();

    register_OpenGL3Shader_class();

    register_OpenGL3StateChangeWrapper_class();

    register_OpenGLGeometryBufferBase_class();

    register_OpenGLRenderer_class();

    register_OpenGLTextureTarget_class();

    boost::python::scope().attr("CompileDate__") = __DATE__;

    boost::python::scope().attr("CompileTime__") = __TIME__;

    boost::python::scope().attr("__doc__") = "PyCEGUIOpenGLRenderer - version 0.8.0";

    boost::python::scope().attr("Version__") = "0.8.0";

    register_OpenGLViewportTarget_class();
}

