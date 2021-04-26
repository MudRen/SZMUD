// Code of ShenZhou
// Room: jishi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǳ���һƬ�����Ĺ㳡�������������̽���ëƤ��ҩ���Լ�������
��ļ��С����ڸ�����Բ���������ôһ�����У�������������࣬����
Ҳ��ȫ����ͬ�ķ��Σ���ͬ�����Զ����������￴�������������ҵ���Ⱥ��
��������ߺ�ȣ�������������
LONG
	);

	set("exits", ([
		"south" : __DIR__"nancheng",
                "east" : __DIR__"dongcheng",
                "north" : __DIR__"beicheng",
	]));
        set("objects",([
		__DIR__"npc/phshang" : 1,
	]));
        

        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}

