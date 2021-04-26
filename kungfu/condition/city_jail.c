// Code of ShenZhou

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		me->move("/d/city/yamen");
		message("vision",
			HIY "ֻ��ƹ��һ����������һ��������һ����\n"
			"ԭ����һ���������ļһ�������ﱻ���˳�����\n" NOR, environment(me), me);
		tell_object(me, HIY "ֻ��һ�����Ƽ���㣬��������ر��ӳ������ţ�\n" NOR);
		me->set("startroom", "/d/city/yamen");

		if(me->query_temp("armor/shoulder"))
		log_file("Jail", sprintf("%s(%s) released from city jail on %s.\n",
                	me->query("name"), me->query("id"), ctime(time())));

		return 0;
	}
	me->apply_condition("city_jail", duration - 1);
	return 1;
}
