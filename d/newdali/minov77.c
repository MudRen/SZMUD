// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov77.c

inherit ROOM;

void create()
{
	set("short", "���ڳ�");
	set("long", @LONG
�����ѵ������Ͻ��ˣ����ڳ�����Ԫ�������ٽ�·��������ϲ������ǧ��
���������ϡ�٣��˵�����������Ĳ�Զ��ȴҲ���ϲ�����Ҫ�ؿ�֮һ�ˣ�
�Ǻ��Ϸ��ٹ�ͨ�̵Ŀڰ����ɴ˱�ȥ��ʮ���Ｔ��ϲ�ݳǣ��ϱ���Ԫ���в���̨
�Ĵ�ׯ������ٸ��ڴ���Щפ����
LONG);
	set("objects", ([
		__DIR__"npc/dalishibing" : 2,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov72",
		]));
	set("area", "���ڳ�");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
