// Code of ShenZhou
// /d/emei/fuhu.c ������
// Shan: 96/07/09

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����������ɽ��һ��ɲ�������ڸߴ����ľ�ּ䣬�����ľ���죬���
ʮ�����ꡣ����������ׯ�ϣ���ģ��ʢ�����ÿ����ƶ�Ρ�롣��ɲ���ڸ���
����Ũ��֮�У�������ȴ��һƬ��Ҷ���������Ͻ����±��ǹ����á�
LONG
        );
        set("exits", ([
                "east" : __DIR__"fuhuroad",
		"westup" : __DIR__"fuhuroad2",
        ]));

        set("objects", ([
                __DIR__"npc/m_dizi1": 1,
                __DIR__"npc/f_dizi1": 1,
        ]));

	set("outdoors", "emei");

	set("cost", 0);
        setup();
	replace_program(ROOM);
}
