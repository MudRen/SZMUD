// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "��ɭ��");
	set("long", @LONG
��ȥ��������ɽ���ʹ�ɭ�֣������Ѿ���ľï���˼�
�����ˣ������Ǵ�����ԭ�Ĺٵ���·��
LONG
	);

	set("exits", ([
		"north" : __DIR__"heisenlin.c",
		"south" : __DIR__"dian1.c",
	]));

	set("cost", 2);
        set("tjjob", 2);
	set("outdoors", "dali");
	setup();
}
