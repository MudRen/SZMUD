//Cracked by Roath
// xiakedao/yongdao3.c

inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
��֪�������ѽ�������ɽ����������Щ�Ŀİ�����ᵽһ��Ũ
�صĳ���������ʯ������Щ�ವ����̦��ż�������»���µĵ�����
�����������˾�����ʩһ����ɫ������
LONG );

      set("exits", ([
		"west" : __DIR__"yongdao1",
		"north" : __DIR__"dadong",
      ]));
      set("no_clean_up", 1);

	set("indoors", "xiakedao" );
	set("cost", 0);
    	set("objects", ([ 
		__DIR__ +"npc/shenlong" : 1, 
    	]));
    	set("no_fight", "1");

	setup();
}
void init()
{	add_action("do_kill", "kill");
}

#include "/d/xiakedao/kill.h"
