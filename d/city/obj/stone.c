// Code of ShenZhou
// stone.c
// Jay 7/4/96

#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

string* names = ({
	"����ʯ","ʯ��","��ʯͷ",
});

string* longs = ({
	"����һ�鲻̫��Ķ���ʯ��\n",
	"����һ��������ǵ�ʯ�顣\n",
	"����һ������Ĵ�ʯͷ��\n",
});

void create()
{
    int i = random(sizeof(longs));

    set_name(names[i], ({"shikuai", "shi", "stone"}));
    set_weight(i*500 + 300); 
    if( clonep() )
       set_default_object(__FILE__);
    else {
       set("long", longs[i]);
	set("unit","��");
	set("wield_msg","$N����һ��ʯͷ׼��ս����\n");
	set("material", "stone");
    }
    init_hammer(i+1);
    setup();
}

void init()
{
	add_action("do_break", "break");
}

int do_break(string arg)
{
	object obj, me;

	if (!arg || (arg != "stone" && arg != "shikuai"))
		return notify_fail("ʲô��\n");

	me = this_player();
	if (me->query("neili") < 500)
		return notify_fail("�㹦�����㣬���ܻ�ʯ�ɷۣ�\n");
	message_vision(HIW"$N�������������������ʯͷ��ȥ��\n"NOR,me); 
	write(HIW"ֻ���á��ء���һ����ʯͷ��������飡\n"NOR);
	obj = new("/d/taohua/obj/shizi2");
	obj->move(me);
	me->add("neili", -(100+random(100)));
	destruct(this_object());
	return 1;
}
