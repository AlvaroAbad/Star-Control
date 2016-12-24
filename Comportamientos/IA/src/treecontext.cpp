#include "..\include\treecontext.h"

void TreeContext::SetValueDouble(Keys key, double dValue)
{
	m_mapDoubles[key] = dValue;
}

void TreeContext::SetValuePoint(Keys key, double x, double y)
{
	ScreenPoint pValue;
	pValue.x = x;
	pValue.y = y;
	m_mapPoints[key] = pValue;
}

void TreeContext::SetValueEntity(Keys key, Entity * pValue)
{
	m_mapEntities[key] = pValue;
}

bool TreeContext::GetValueDouble(Keys key, double * pValue)
{
	bool bRet = false;
	std::map<Keys, double>::iterator it = m_mapDoubles.find(key);
	if (it != m_mapDoubles.end())
	{
		bRet = true;
		if (pValue)
			*pValue = m_mapDoubles[key];
	}

	return bRet;
}

bool TreeContext::GetValuePoint(Keys key, double* x, double*y)
{
	bool bRet = false;
	std::map<Keys, ScreenPoint>::iterator it = m_mapPoints.find(key);
	if (it != m_mapPoints.end())
	{
		bRet = true;
		if (x){
			*x = m_mapPoints[key].x;
		}
		if (y) {
			*y = m_mapPoints[key].y;
		}
	}

	return bRet;
}

bool TreeContext::GetValueEntity(Keys key, Entity ** pValue)
{
	bool bRet = false;
	std::map<Keys, Entity *>::iterator it = m_mapEntities.find(key);
	if (it != m_mapEntities.end())
	{
		bRet = true;
		if (pValue)
			*pValue = m_mapEntities[key];
	}

	return bRet;
}
