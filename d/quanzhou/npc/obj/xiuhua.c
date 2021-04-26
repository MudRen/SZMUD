// Code of ShenZhou
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void setup()
{}

void init()
{
        add_action("do_make", "make");
}

void create()
{
        set_name("�廨��", ({ "xiuhua zhen", "zhen", "needle" }));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ϸĥ���廨�룬���廨�õľ��ѹ��ߡ�\n");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N��Ĵָ��ʳָ���޼����һ��$n��\n");
                set("unwield_msg", "$N�����е�$n����޼䡣\n");
        }
        init_sword(10);
        setup();
}
int do_make(string arg)
{
	object  ob, *obj, me = this_player();
	int i;
	if( !arg || arg!="bilin zhen" )
                return notify_fail("��Ҫ��ʲô��\n");
	if( me->query_skill("poison", 1) < 120)
		return notify_fail("��Ķ��������������������ĵ���\n");
	if(! present("wugong ke", me) && !present("xiezi ke", me)
	&& !present("shedan", me) && !present("du zhusi", me)
	&& !present("shachong ke", me))
		return notify_fail("��û���㹻��ԭ�ϣ�\n");
        message_vision(CYN"$NС������ذ�һ���廨������ҩ���飬ע�������������һ������롣\n"NOR, me );
		ob = new("/d/xingxiu/obj/blzhen.c");
	        ob->move(me);
		me->add("jingli", -5);
	obj = all_inventory(me);
        for(i=sizeof(obj)-1; i>=0; i--) {
        if( obj[i]->query("name") == "����" || obj[i]->query("id") == "xiezi ke"
	|| obj[i]->query("id") == "shedan" || obj[i]->query("id") == "du zhusi"
	|| obj[i]->query("id") == "shachong ke")
	destruct(obj[i]);
        }	
		destruct(this_object());
        return 1;
}
