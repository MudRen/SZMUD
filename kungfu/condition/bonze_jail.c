// Code of ShenZhou

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		me->move("/d/shaolin/guangchang1");
		message("vision",
			HIY "ֻ��ƹ��һ����������һ��������һ����\n"
			"ԭ����һ���������ļһ���������ﱻ���˳�����\n" NOR, environment(me), me);
		tell_object(me, HIY "ֻ��һ�����Ƽ���㣬��������ر��ӳ��˼�����\n" NOR);
		me->set("startroom", "/d/shaolin/guangchang1");
		return 0;
	}
	me->apply_condition("bonze_jail", duration - 1);
	return 1;
}
