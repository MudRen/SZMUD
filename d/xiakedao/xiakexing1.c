//Cracked by Roath
// xiakedao/xiakexing1.c
// modifiey by  aln  5 / 98

inherit __DIR__"no_pk_room";

#include <room.h>;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
��������������ʯ��������ͨ���ĸ�ʯ�ҡ�������ϰ�������С�
�书����������ܸ٣�Ҳ�ֱ��������˶�һɫ�಼�ᣣ�������
���Ӿ������³�����������ϣ���������ǰ�ľ�ʫ���ܸ١�һ���ɺ衹��
LONG );

      set("exits", ([
		"out" : __DIR__"gate",
		"north"   : __DIR__"xkx1",
		"south"   : __DIR__"xkx2",
		"east"   : __DIR__"xkx3",
		"west"   : __DIR__"xkx4",
		"enter" : __DIR__"xiakexing2",
      ]));

	create_door("out", "ʯ��", "enter", DOOR_CLOSED);
	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}

