// Code of ShenZhou
// /d/emei/guiyun.c ���Ƹ� 
// Shan: 96/07/09

inherit ROOM;

void create()
{
        set("short", "���Ƹ�");
        set("long", @LONG
���Ƹ�ԭ���ƴ����������ʦ�ĵ������δ�������䣬ɮ��ʿ��������
�ؽ������Ƹ�������Ů�壬���Ͽɵִ���������ǹ����á�
LONG
        );
        set("exits", ([
		"southup" : __DIR__"yunu",
		"westup" : __DIR__"chunyang",
                "eastdown" : __DIR__"guanyin",
        ]));

        set("objects", ([
	          __DIR__"npc/m_dizi1" :2,
        ]));

	set("outdoors", "emei");

	set("cost", 0);
        setup();
	replace_program(ROOM);
}
