// Code of ShenZhou
inherit ITEM;
#include <ansi.h>
void setup()
{}

void init()
{
        add_action("do_make", "make");
}

void create()
{
        set_name("���" NOR, ({"liuhuang", "sulphur", "huang"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ǣ�ͨ������������ҩ��\n");
                set("value", 200);
        }
}

int do_make(string arg)
{
	object  ob, *obj, me = this_player();
	int i;
	if( !arg || arg!="lianxin dan" )
                return notify_fail("��Ҫ��ʲô��\n");
	if( me->query_skill("poison", 1) < 120)
		return notify_fail("��Ķ��������������������ĵ���\n");
	if(! present("wugong ke", me) && !present("xiezi ke", me)
	&& !present("shedan", me) && !present("du zhusi", me)
	&& !present("shachong ke", me))
		return notify_fail("��û���㹻��ԭ�ϣ�\n");
        message_vision(CYN"$NС������ذ�һ�鶾ҩ����Ƿ���һ��ע�������������һ�����ĵ���\n"NOR, me );
		ob = new("/d/xingxiu/obj/lianxin.c");
	        ob->move(me);
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
