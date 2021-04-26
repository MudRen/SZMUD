// Code of ShenZhou
// Room: /d/dali/chhill2.c

inherit ROOM;

int do_get(string);

void create()
{
	set("short", "�軨ɽ��");
	set("long", @LONG
�����ڲ軨ɽ���µ��ϣ��µ��ϱ������ïʢ�Ĳ軨���󲿷��Ƿ�Ʒ����ż
��Ҳ����һ�����Ʒ�������С�������Զ�Ǵ���ǵĳ�ǽ��
LONG);
	set("objects", ([
		__DIR__"obj/chahua" : 1,
		]));
	set("exits", ([
		"northup" : __DIR__"chhill3.c",
		"southdown"  : __DIR__"minov3",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
}
void init()
{
	add_action("do_get","get");
}
int do_get(string arg)
{
	object me, ob, weapon;
	me=this_player();

	if (arg=="cha" || arg=="chahua" || arg=="all" || arg=="cha hua")
	{
		if (!objectp(ob=present("cha", environment(me))))
		{
			tell_object(me, "����ûʲô��Ʒ�ֵĲ軨ֵ�����ߡ�\n");
			return 1;
		}
		if (!objectp(weapon=me->query_temp("weapon"))
			|| weapon->query("id")!="huachu")
		{
			tell_object(me, "��û�г��ֵĹ�������ֲ����軨��\n");
			return 1;
		}
		if (random(2)==1)
		{
			message_vision("$NС��������û�������軨�ĸ���������軨����������\n", me);
			ob->move(me);
		}
		else
		{
			message_vision("$N����ææ���ڲ軨��һ��С�İѸ��ڶ��ˣ��úõ�һ��軨�����ˡ�\n", me);
			destruct(ob);
		}
		return 1;
	}
	return 0;
}
