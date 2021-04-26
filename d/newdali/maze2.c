// Code of ShenZhou
// Room: /d/dali/maze2.c

inherit ROOM;

int do_find(string);
int do_out();

void create()
{
	set("short", "�Թ�����");
	set("long", @LONG
�����Թ��е�һ��·�ڣ��������º�ɭɭ�Ķ�����ľ������С·����������
�������ѱ淽�򣬾ٲ�̤���ľ��ǰ����Ӳݣ��������̵�С�ȣ���������Ѫ���ܡ�
һ��Сľ׮�϶������ľ�ƣ��ֱ�ָ������С·������������ľ��ˮ��������
������ľϡ��Щ�������������߳�ȥ(out)�ķ���
LONG);
	set("exits", ([
		"��" : __FILE__,
		"ľ" : __FILE__,
		"ˮ" : __FILE__,
		"��" : __FILE__,
		"��" : __FILE__,
		]));
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("invalid_startroom", 1);
	setup();
}
void destruct_me(object me)
{
	destruct(me);
}
void init()
{
	object me;
	me=this_player();
	if(!userp(me) && me->query("id")!="fang dongbai" && me->query("id")!="a er" && me->query("id")!="a san" )
	{
		call_out("destruct_me",3,me);
		return;
	}
	if (me->query_skill("dodge",1)<100 && random(10)==1)
	{
		message_vision("$Nһ����С�ģ���������һ�裬����ཡ�һ��ˤ���˾����ԡ�\n", me);
		me->add("qi",-100);
		me->add("eff_qi",-100);
		message_vision("$N�����˰��죬�Ӿ����������˳��������������˴̣�ʹ���ѵ���\n", me);
	}
	add_action("do_find", "find");
	add_action("do_out", "out");
}
int valid_leave(object me, string dir)
{
	int mazepath;
	string walked,mpath;

	mazepath=me->query_temp("mazepath");

	mpath=sprintf("%d",mazepath);
//	tell_object(me, "���룺"+mpath+"\n");

	walked=sprintf("%d%d%d%d%d", (me->query_temp("mark/maze��")-1),(me->query_temp("mark/mazeľ")-1),(me->query_temp("mark/mazeˮ")-1),(me->query_temp("mark/maze��")-1),(me->query_temp("mark/maze��")-1));
//	tell_object(me, "�߹���"+walked+"\n");

	me->add("qi", -10);

	if (walked==mpath)
	{
		tell_object(me,"���˼ڤ�룬����ϸ�㣬�����ҵ����ƴ��Թ�֮����ֻ��ת��ת�������˳�ȥ��\n");
		set("exits/"+dir, "/d/dali/yingroom1.c");
		remove_call_out("closing");
		call_out("closing",1,dir);
		return 1;
	}
	if (dir=="��") me->add_temp("mark/maze��", 1);
	if (dir=="ľ") me->add_temp("mark/mazeľ", 1);
	if (dir=="ˮ") me->add_temp("mark/mazeˮ", 1);
	if (dir=="��") me->add_temp("mark/maze��", 1);
	if (dir=="��") me->add_temp("mark/maze��", 1);
	return ::valid_leave(me, dir);
}
void closing(string dir)
{
	set("exits/"+dir, __FILE__);
	return;
}
int do_find(string arg)
{
	object me;
	object *inv;
	int i;
	me=this_player();

	if (arg=="way" && me->query("family/master_id")=="yideng dashi")
	{
		inv=all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if (userp(inv[i])) return notify_fail("�㸺��̫���ˣ�û����·��ɽ��\n");
			if (inv[i]->query("id")=="corpse") return notify_fail("����ʬ��ȥ��ʦ����̫�ðɣ�\n");
		}
		tell_object(me, "�����ҿ���û��ע���㣬͵͵���������������˽�ȥ��\n");
		tell_object(me, "���һ��û��֪����С·����ɽ��������һ�ƴ�ʦ���ڵĵط���\n");
		me->move("/d/dali/yideng9.c");
		return 1;
	}
	return 0;
}
int do_out()
{
	object me;
	me=this_player();

	tell_object(me, "���˼ڤ�룬��ת�ҿ�����ã�����û��ʲô�취�ҵ�·��ֻ�ô�ԭ·���˻�ȥ��\n");
	me->set_temp("mark/maze��", 1);
	me->set_temp("mark/mazeľ", 1);
	me->set_temp("mark/mazeˮ", 1);
	me->set_temp("mark/maze��", 1);
	me->set_temp("mark/maze��", 1);
	me->delete_temp("mazepath");
	me->move("/d/dali/maze1.c");
	return 1;
}
