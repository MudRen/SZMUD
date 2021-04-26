// Code of ShenZhou
// Room: /u/qfy/quanzhou/qingyuan.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��Դ��");
	set("long", @LONG
�ӻ���Ȫ���ϣ��Ϳ���һ��ɽ�ţ����Ͽ��š���һ���졹�ĸ��֡��ź���
һ�ۿ�¥��¥�������һ��Ի�����ҡ�������Դ�����ഫ����������һ����
������׷��һ���˺�����Ĵ��ߵ����������������ʯ���У���������Ծ�
�ڶ����������ˣ�������������ɶ��������Ŵ˶���ɲ⣬��ͨ����������
LONG
	);

	set("outdoors", "quanzhou");

	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"shanlu1",
		"southdown" : __DIR__"huru",
		"westup" : __DIR__"nantai",
	]));
        set("fjing", 1);
        set("tjjob", 3);

	set("no_clean_up", 0);

	set("mang", 1);

	set("cost", 1);
	setup();
}

void init()
{
	object mang, me = this_player();

	if ( random(me->query("PKS")) > 50 && query("mang") >= 1
	&& random( me->query_kar() ) < 2 ) {
		message_vision(HIR"ͻȻ�䡸ɳɳ��֮��������һ�����ľ�������һ���ȷ��ɶ�������$N��\n"NOR, me);
		mang = new(__DIR__"npc/jumang");
        	mang->move(environment(me));
		remove_call_out("mang_attack");
		call_out("mang_attack", 1, me, mang);
		add("mang", -1);
		me->set_temp("mang", 1);
	}
}

int mang_attack(object me, object mang)
{
        mang->kill_ob(me);
        me->kill_ob(mang);
	remove_call_out("observe");
	call_out("observe", 1, me, mang);

	return 1;
}

int valid_leave(object me, string dir)
{
	object mang;

	if ( me->query_temp("mang") && objectp(mang = present("ju mang", environment(me))) ) {
		if ( living(mang) )
			return notify_fail("�������������㷢�����������޷��������ߣ�\n");
		else  
			return notify_fail("�������ѻ��˹�ȥ�����Խ����ز��������ϣ����޷�����\n");
	}

	if ( present("ju mang", me) )
		return notify_fail("����̫��̫���ˣ����俸����������ȴ����������\n");

	me->delete_temp("mang");

	return ::valid_leave(me, dir);
}

int observe(object me, object mang)
{
	object corpse;

	if ( !me->is_ghost() && !present("ju mang", environment(me)) ) return 1;

	if ( me->is_ghost() ) {
		message_vision("$N�ſ�Ѫ���ڣ������ؽ�ʬ�����¶�ȥ�����ű��λض���ȥ�ˡ�\n", mang);
		if ( objectp(corpse=present("corpse", environment(mang))) ) destruct(corpse);
		destruct(mang);
		return 1;
	}

	remove_call_out("observe");
	call_out("observe", 1, me, mang);
	return 1;
}
