// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov61.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ι�������ˮ֮�ϰٶ�ߵĿ��С�����һ������������֮���ţ�
�����ִ��������һ������Ʒ�����Σ��Ų�����һ�����ַ�������������Ԯ����
�������գ�ʵ���ϵ�Ҳ��ʮ�����ѡ�һ��ɽ��Ю�Ž��¼����ɽ���ˮ����������
�е�һ���⡣
LONG);
	set("exits", ([
		"west" : __DIR__"minov60",
		"east" : __DIR__"minov85",
		]));
	set("area", "������");
	set("cost", 50);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
