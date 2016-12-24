#ifndef SCM_IA_TREECONTEXT_H
#define SCM_IA_TREECONTEXT_H
#include <map>
class Entity;
class TreeContext
{
public:
	
	enum Keys {
		KEY_THREAT,
		KEY_DESTINY,
		KEY_ENEMYDISTANCE,
		KEY_ROTATION,
		KEY_WEAPONREADY,
		KEY_WEAPONRANGE
	};
	TreeContext() {};

	void SetValueDouble(Keys key, double dValue);
	void SetValuePoint(Keys key, double x, double y);
	void SetValueEntity(Keys key, Entity *pValue);

	bool GetValueDouble(Keys key, double *pValue = NULL);
	bool GetValuePoint(Keys key, double* x=nullptr, double*y=nullptr);
	bool GetValueEntity(Keys key, Entity**pValue = NULL);
protected:
	struct ScreenPoint
	{
		double x;
		double y;
	};
private:
	std::map<Keys, double> m_mapDoubles;
	std::map<Keys, ScreenPoint> m_mapPoints;
	std::map<Keys, Entity*>	m_mapEntities;
};
#endif // !SCM_IA_TREECONTEXT_H

