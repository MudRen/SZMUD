// Code of ShenZhou
// hz_donglang2.c �����ֶ���
// Shan: 96/06/22

#include <room.h>
inherit ROOM;


void create()
{
        set("short", "�����ֶ���");
	set("long", @LONG
�����Ƕ��һ����ֶ��ȡ���������ͨ��ի�ã�����ͨ���㳡��
LONG
	);
	set("exits", ([
		"north" : __DIR__"hz_donglang1",
		"south" : __DIR__"hz_zhaitang",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 1);
	setup();
	replace_program(ROOM);

}


