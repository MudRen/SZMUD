//Cracked by Roath
// xiakedao/xiakexing5.c
// modified  by aln 5 / 98

inherit __DIR__"no_pk_room";

#include <room.h>;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�������������Щ��ͬ��ԭ��������˰�ߺ�Ļ�������֪��ʲ
�����á�����Ҳ�ǿ������ľ���ܸ٣����仨��������ȴ�Ǳ���Բ��
�Ƴ�Ů��֮�֡���Χ��Ļ�ʹ���һɫ���ơ�
LONG );

      set("exits", ([
		"out" : __DIR__"xiakexing4",
		"north"   : __DIR__"xkx17",
		"south"   : __DIR__"xkx18",
		"east"   : __DIR__"xkx19",
		"west"   : __DIR__"xkx20",
		"enter" : __DIR__"xiakexing6",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
