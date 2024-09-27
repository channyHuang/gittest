#pragma once

#include <osg/AutoTransform>
#include <osg/Group>
#include <osg/PolygonMode>
#include <osg/Switch>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osgText/Text>
#include <osgViewer/Renderer>
#include <osgViewer/Viewer>

class OsgManagerBase
{
public:
	static OsgManagerBase* getInstance() {
		if (m_pInstance == nullptr) {
			m_pInstance = new OsgManagerBase();
		}
		return m_pInstance;
	}

	virtual ~OsgManagerBase();
	// common scene operator
	void setViewer(osgViewer::Viewer& viewer);
	void switchScene();
	// picker
	void clearPick(int nPickNum = 0);
	void showPick(osg::Vec3& p);
	// show
	void readNode(const std::string& sFileName);
	void readOsgbLOD(const std::string& sFolder, const std::string& sTex);

	void obj2osgt(const std::string& str);
	void showModelObj(const std::string& sFolder, const std::string& sTex, bool bUseOsgLoad = true);
	
	void showModelUsingAssimp(std::string sFileName, std::string sTextureName);

protected:
	OsgManagerBase();

protected:
	static OsgManagerBase* m_pInstance;

	uint m_nSceneMaxIdx = 0, m_nSceneIdx = 0;
	float m_fScale = 2.82f; // 0.44 / 0.24
	osg::ref_ptr<osg::Switch> m_pSceneSwitcher = nullptr;
	osg::ref_ptr<osgViewer::Viewer> m_pViewer = nullptr;
	osg::ref_ptr<osg::Group> m_pRootGroup = nullptr;

	// picker
	std::vector<osg::Vec3> m_vPickPoints;
	osg::ref_ptr<osg::Group> m_pRootGeomDistance = nullptr;
};

