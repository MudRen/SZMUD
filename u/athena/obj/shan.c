
// ����ܰ(Athena)
// OBJ��/u/athena/obj/shan.c

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void init()
{
        add_action("do_shan","hui");
}

void create()
{
	set_name(YEL "̴����" NOR, ({ "tanxiang shan", "shan"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("fen", 5);
		set("long", "���ǰ����ϵ���ľ�Ƴ����ȣ�ɢ����һ˿���㡣\n");
		set("value", 10000);
		set("material", "wood");
                set("no_get",1);
		set("wield_msg", HIY "$Nչ�����ӣ�����������ȷ硣\n" NOR);
		set("unwield_msg", HIY "$Nˢ��һ���������ӣ��Ż����С�\n" NOR);
	}
	init_sword(100);
	setup();
}

int do_shan(string arg)
{
       object me, ob;
       string name1, name2;

       if (!arg) return notify_fail("��Ҫ��˭��\n");
       me = this_player();
       ob = present(arg, environment(me));
       if (!ob) return notify_fail("�Ҳ����������.\n");
       if( this_object()->query("fen") <=0)
               return notify_fail("�����Ѿ��ù��ˡ�\n");
       name1 = (string)me->query("name");
       name2 = (string)ob->query("name");       
       tell_room(environment(me),
      HIY + name1+"�����Ӷ�"+name2+"������˻ӡ�\n\n", NOR,
       ({me, ob}));
       
       tell_object(ob, HIW "��о�������ʲô��ĩƮ�������ϡ�����\n" NOR);
       tell_object(me, HIW "�������Ӷ�"+name2+"����һ�ӡ�\n" NOR);
       this_object()->add("fen", -1);
       ob->delete("env/immortal");
       ob->unconcious();
       return 1;
}

