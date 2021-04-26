// Code of ShenZhou
// square.c

inherit ROOM;

string day_event() {return NATURE_D->outdoor_room_event();}

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����ǻ�ɽ�ɵ����䳡������໪ɽ�ɵ����ڴ�ϰ���������ϱߵķ�
�����Ϲ���һ���ң����顸������Ϊ�������ǻ�ɽ���ż��ڵ��ӵľ�����
�����и���������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "north" : __DIR__"yunu",
	    "south" : __DIR__"buwei1",
	    "west" : __DIR__"wuqiku",   
	]));

	set("objects", ([
	    CLASS_D("huashan") + "/laodenuo" : 1,
	]));

	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("cost", 1);
	setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	object obj;

	myfam = (mapping)me->query("family");

	if ( objectp(obj=present("lao denuo", environment(me))) && living(obj) && !wizardp(me) ) {
	   if ( (!myfam || myfam["family_name"] != "��ɽ��") && dir == "west" )
	   	return notify_fail("�͵�ŵǷ��˵������λ"+RANK_D->query_respect(me)+"��ֹ���������Ǳ��ɵı�������\n");

	   if ( myfam && myfam["family_name"] != "��ɽ��" && !me->query_temp("marks/��") && dir == "south" )
		return notify_fail("�͵�ŵǷ��˵������λ"+RANK_D->query_respect(me)+"���а��������ʦ��\n");
	
	   if ( me->query_temp("marks/��") && dir == "west" )
		return notify_fail("�͵�ŵŭ������˵�������Ǹ�ȡ�˽�����ô������ȡ��\n");

	   if ( present("zixia book", me) )
		return notify_fail("�͵�ŵ�������������޷����ѣ�\n"); 
	}
/*
	if ( dir == "south" && (day_event() == "event_night" || day_event() == "event_midnight") )
        return notify_fail("��ɽ�������ϲ�������������������\n");
*/

	return ::valid_leave(me, dir);
}
