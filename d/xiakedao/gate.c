//Cracked by Roath
// xiakedao/gate.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

#include <room.h>

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������������ͷ����ǰһ�����ص�ʯ�š����Ͽ������������
��׭���������С��������վã��Ǳʻ��İ���֮������������̦��Խ
���Եò�ɣ�������еľ�����Ȼ������
LONG );

        set("exits", ([
		"enter" : __DIR__"xiakexing1",
		"south" : __DIR__"yongdao10",
        ]));

        set("objects", ([
                __DIR__ +"npc/shaolin" : 1,
        ]));

	create_door("enter", "ʯ��", "out", DOOR_CLOSED);
	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
