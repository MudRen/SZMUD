//Cracked by Roath
// xiakedao/xiakexing4.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

#include <room.h>;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�˶�����ȴ�ִ���ͬ��ȴ����������ɽһ�㡣ֻ��һɫ�첼�
ᣣ���֧�ִ�ĺ�������Ľǡ�һ��վ��������״󺺣������䵶��
�����Ϻ�ӣ�ʹ������д������۽���κ���壺��������项��
LONG );

      set("exits", ([
		"out" : __DIR__"xiakexing3",
		"north"   : __DIR__"xkx13",
		"south"   : __DIR__"xkx14",
		"east"   : __DIR__"xkx15",
		"west"   : __DIR__"xkx16",
		"enter"   : __DIR__"xiakexing5",
      ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
