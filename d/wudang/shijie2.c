// Code of ShenZhou
// shijie2.c ʯ��
// by Xiang

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
	������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ��������߹���һ������
�ڣ�һ�������£�̧ͷ��Լ�ɼ������������е������壬������ˮ���ȣ�������
��������
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"shibapan",
		"southup" : __DIR__"shijie3",
	]));
        set("objects", ([
                __DIR__"npc/guest" : 1]));
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

