//Cracked by shenzhou
// Room: /d/sanbuguan/yichang.c
//Modified by jiuer 5/27/2002

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����ǡ�Ӣ�ҷ�������������Ǻ����ҷ����������������ֳ�֮
Ϊ�������������������ʱ������Ů���糾��ʶ�ú����ҡ����ݼ�Ůÿ
��ص�Ӣ�ҷ�����������Ը������λ�γ��İ����������飬�չ˺��
��ͬ�н��á�
LONG
        );
        set("exits", ([
			"east" : __DIR__"hill",
			]));
		
		set("outdoors", "sanbuguan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
