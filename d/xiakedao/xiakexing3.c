//Cracked by Roath
// xiakedao/xiakexing3.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

#include <room.h>;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ӭ��ɼ��ĸ�������֡�ˮ��к�ء����������ϡ����г����ݻ���
��׵Ĵ���ʯש�����������ˡ�������¯�������ƣ������Ů������
������ϡ�Ǻ�����լһ�㡣
LONG );

      set("exits", ([
		"out" : __DIR__"xiakexing2",
		"north"   : __DIR__"xkx9",
		"south"   : __DIR__"xkx10",
		"east"   : __DIR__"xkx11",
		"west"   : __DIR__"xkx12",
		"enter"   : __DIR__"xiakexing4",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
