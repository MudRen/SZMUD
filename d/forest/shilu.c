//Cracked by Yujie
///d/forest/shilu.c
// by yujie 10 / 2001

inherit ROOM;


void create()
{
        set("short", "ʯ·");
        set("long", @LONG
���Ǵӷ�����ʯ�ź�ͨ�����ְ��ɽ��ʯ·���������߾��ǳ��ְ��
��Ȼ��Ȫ������һ·��ɫ�ļѣ�����ʱ�������ﻨ�����Ʈ����
LONG );
        set("exits", ([
		"out"  : __DIR__"clhoulang3",
		"north": __DIR__"clwenquan",
	]));
	
        set("outdoors","forest");
        set("cost",1);
        
        setup();
        
        replace_program(ROOM);
     
}


