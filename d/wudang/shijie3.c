// Code of ShenZhou
// shijie3.c ʯ��
// by Xiang

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
	������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ��������߹���һ������
�ڣ�һ�������£�̧ͷ��Լ�ɼ������������е������壬������ˮ���ȣ�������
��������������һ���Ʒ���
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"shijie2",
		"southup" : __DIR__"zixiao",
	]));
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

