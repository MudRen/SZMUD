// Code of ShenZhou
// lingyun.c ������
// Shan: 96/06/22

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
���������ݣ�������һλ�а��Ŷ����������ڴ˸�ľ��ʯ���Զ����ˣ�
�ֽС���ɮ�ݡ���·����÷���£��ɼ�������÷�綹������֦��Ҷ�ж������ˣ�
���С���÷ֹ�ʡ�֮���á����ݱ�ͨϴ��أ������׶�ƺ��
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"xixiang",
		"southup" : __DIR__"leidong",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );
       set("fjing", 1);

	set("cost", 3);
	setup();
//	replace_program(ROOM);

}

void init()
{
	add_action("do_look", "look");
}

int do_look(string arg)
{
	object me = this_player();
	int t;
	mixed local;
	
	if ( arg != "÷" && arg != "��÷" && arg != "mei") 
		return command("look "+arg);

	local = localtime(time()*60);
        t = local[2]*60 + local[1];

	if ( t >= 660 && t < 840 ) {
		me->set("water", me->max_water_capacity());
		tell_object(me, HIG"��Ȼ���յ�ͷ����һ����������÷���ɵÿ������򣬲��پ��øɿʡ�\n"NOR);
		return 1;
	}
	
	tell_object(me, "һ�ſž�Ө����÷�����˿�������\n");

	return 1;
}
