// Room: /d/chengdu/nandajie2.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
        set("long", @LONG
�������ڳɶ������ϴ���ϣ�����һ���������Ĵ�·��һֱ��
�������졣·�����������������ò����֡�һЩС��С������������
ЩС���������������ţ�����һ����������ᶽ�֣���һ����֪��Ϊ
ɶ���ᰲ���ˡ�
LONG );

        set("outdoors", "chengdu");

	set("exits", ([
		"north" : __DIR__"nandajie1",
		"south" : __DIR__"dananmen",
		"west" : __DIR__"southroad3",
		"east" : __DIR__"southroad1",
	]));

	setup();
	replace_program(ROOM);
}

