//Cracked by Roath
// xiakedao/xiakexing2.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

#include <room.h>;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�˶�ͨ��ڶ���ʯ�ҡ�����ˮ�����ȣ�����ǡ��һ��ɽȪ������
�м��ĸ������������ʯ�ڡ�Ʈ�����ơ������������ɫ�᣻��ơ���
�����µ���������
LONG );

      set("exits", ([
		"out" : __DIR__"xiakexing1",
		"north"   : __DIR__"xkx5",
		"south"   : __DIR__"xkx6",
		"east"   : __DIR__"xkx7",
		"west"   : __DIR__"xkx8",
		"enter"   : __DIR__"xiakexing3",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
