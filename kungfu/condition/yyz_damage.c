// Code of ShenZhou
// by oyxb
// by acep

#include <ansi.h>
string* xuedao = ({
        "�޹�Ѩ",
        "�ز�Ѩ",
        "�羮Ѩ",
        "�ճ�Ѩ",
        "����Ѩ",
        "���Ѩ",
        "����Ѩ",
        "�縮Ѩ",
        "����Ѩ",
        "�յ�Ѩ",
        "ǿ��Ѩ",
        "�ٺ�Ѩ",
        "����Ѩ",
        "����Ѩ",
        "����Ѩ",
        "��׵Ѩ",
        "��βѨ",
        "����Ѩ",
        "�͹�Ѩ",
        "�ٻ�Ѩ",
        "��̨Ѩ",
        "̫��Ѩ",
        "����Ѩ",
        "����Ѩ",
        "�βѨ",
        "������",
        "����Ѩ"
});


int update_condition(object me, int duration)
{
	object ob;
	if ( duration > 200 ) duration = 200;
	if (!living(me)) {
		message("vision", me->name() + "�ƺ���һ����\n", environment(me), me);
	}
	if (me->query("family/family_name")=="����μ�"
		&& me->query_skill("kurong-changong")) return 1;
	if (me->query_temp("yyzenemy")) {
		tell_object(me,HIR"��е�"+xuedao[random(sizeof(xuedao))]+"һ�����飬Ѫ����������ʱ�������ã�\n"NOR);
		me->start_busy(random(3));
		if (duration>=200) {
			if (ob = LOGIN_D->find_body(me->query_temp("yyzenemy")))
				me->receive_damage("qi", duration, ob);
			else me->receive_damage("qi", duration, "��һ��ָ�����ζ���");
		}
	}
	else me->receive_damage("qi", duration/3, "��һ��ָ�����ζ���");
	if (me->query_condition("yyz_damage")>(5+me->query_skill("force",1)/10))
		me->apply_condition("yyz_damage", duration - 5 - me->query_skill("force",1)/10);
	else return 0;
	return 1;
}
