// Code of ShenZhou
// shouwu.c ������

inherit ITEM;
#include <ansi.h>

void setup()
{}
int cure_ob(string);
void create()
{
	set_name("������", ({"heshou wu", "wu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ó������εĺ����ڡ�\n");
		set("value", 10000);
                set("no_sell", 1);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	if ( (int)me->query_condition("bonze_drug" ) > 0 )
        {
                me->add("max_neili", -1);
		me->apply_condition("bonze_drug", 30);
                message_vision(HIR "$N����һ֧�����ڣ�ֻ����ͷ�ؽ��ᣬ�������ڣ�ԭ����ʳ̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
		destruct(this_object());
        }
	if( random(2) == 1)
	{
        message_vision("$N����һ�ú����ڣ������������ġ�\n", me);
        destruct(this_object());
        return 1;
        }
	else
	{
	me->add("max_neili", 1);
	message_vision(HIG"$N����һ�ú����ڣ���ʱ�����ȫ������˻��� !\n"NOR, me);
	}
	me->apply_condition("bonze_drug", 
	this_player()->query_condition("bonze_drug")+30);
	destruct(this_object());
	return 1;
}

