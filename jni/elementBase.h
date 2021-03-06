/**
 *******************************************************************************
 * @file elementBase.h
 * @brief ewol drawer element Base (header)
 * @author Edouard DUPIN
 * @date 14/03/2012
 * @par Project
 * EwolDrawer
 *
 * @par Copyright
 * Copyright 2010 Edouard DUPIN, all right reserved
 *
 *******************************************************************************
 */

#ifndef __ELEMENT_BASE_H__
#define __ELEMENT_BASE_H__

#include <etk/Types.h>
#include <etk/UString.h>
#include <ewol/OObject/2DColored.h>

namespace drawElement {
	typedef enum {
		DRAW_ELEMENT_TYPE_CIRCLE,
		DRAW_ELEMENT_TYPE_DISK,
		DRAW_ELEMENT_TYPE_MESH,
		DRAW_ELEMENT_TYPE_POLYGONE,
		DRAW_ELEMENT_TYPE_RECTANGLE,
	}elementType_te;
	class Base
	{
		public:
			Base(elementType_te type);
			virtual ~Base(void);
		private:
			etk::UString    m_name;
			elementType_te  m_type;
			bool            m_visible;
		public:
			void            SetName(etk::UString name) { m_name = name; };
			etk::UString    GetName(void) { return m_name; };
			elementType_te  GetType(void) { return m_type; };
			const char*     GetTypeChar(void);
			void            Show(void) { m_visible = true; };
			void            Hide(void) { m_visible = false; };
			bool            GetVisible(void) { return m_visible; };
		public:
			virtual void Draw(ewol::OObject2DColored &OObjects)=0;
	};
};

#include <elementCircle.h>
#include <elementDisk.h>
#include <elementMesh.h>
#include <elementPolygone.h>
#include <elementRectangle.h>

#endif

